#include "SongCollection.h"

using namespace std;

SongCollection::SongCollection() {
	executeSongCollection();
}

void SongCollection::executeSongCollection() {
	bool isSorted{ false };
	int action{ -1 };
	while (action != 0) {
		action = m_userInterface.getUserAction(); //User main menu selection

		switch (action) {
		case 1: // Add song
			addSong(m_userInterface.getSongInformation());
			break;
		case 2: // Display non-sorted collection
			if (!isEmptyCollection()) {
				isSorted = false;
				m_userInterface.displaySongCollectionHeader(isSorted);
				displayCollection(isSorted);
			}
			break;
		case 3: // Display sorted song collection
			if (!isEmptyCollection()) {
				sortCollection();
				isSorted = true;
				m_userInterface.displaySongCollectionHeader(isSorted);
				displayCollection(isSorted);
				break;
			}
		case 0: // terminate
		default:
			break;
		}
	}
}

// Add song to collection
void SongCollection::addSong(array<string, 3> song) {
	string title{ song.at(0) };
	string artist{ song.at(1) };
	string genre{ song.at(2) };
	Song newSong(title, artist, genre);
	m_collection.push_back(newSong);
}

void SongCollection::displayCollection(bool isSorted) const {
	vector<Song> collection;
	if (isSorted) {
		 collection = m_sortedCollection; // Display alphabetically sorted collection
	}
	else {
		 collection = m_collection; // Display collection
	}
	
	auto song{ collection.begin() };

	string title{ "" };
	string artist{ "" };
	string genre{ "" };

	for (size_t i{ 0 }; i < collection.size(); i++) {
		title = song->getTitle();
		artist = song->getArtist();
		genre = song->getGenre();
		m_userInterface.displaySong(title, artist, genre);
		++song;
	}
}

void SongCollection::sortCollection() {
	m_sortedCollection = m_collection;
	sort(m_sortedCollection.begin(), m_sortedCollection.end());
}

bool SongCollection::isEmptyCollection() {
	bool isEmpty{ true };
	if (!m_collection.empty()) {
		isEmpty = false;
	}
	return isEmpty;
}
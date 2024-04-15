#include "SongCollection.h"

using namespace std;

SongCollection::SongCollection() {
	executeSongCollection();
}

bool isSorted{ false };
void SongCollection::executeSongCollection() {
	int action{ -1 };
	while (action != 0) {
		action = m_userInterface.getUserAction();

		switch (action) {
		case 1:
			addSong(m_userInterface.getSongInformation());
			break;
		case 2:
			isSorted = false;
			m_userInterface.displaySongCollectionHeader(isSorted);
			displayCollection(isSorted);
			break;
		case 3:
			sortCollection();
			isSorted = true;
			m_userInterface.displaySongCollectionHeader(isSorted);
			displayCollection(isSorted);
			break;
		case 0:
		default:
			break;
		}
	}
}

void SongCollection::addSong(array<string, 3> song) {
	string title{ song.at(0) };
	string artist{ song.at(1) };
	string genre{ song.at(3) };
	Song newSong(title, artist, genre);
	m_collection.push_back(newSong);
}

void SongCollection::displayCollection(bool isSorted) const {
	vector<Song> collection;
	if (isSorted) {
		 collection = m_sortedCollection;
	}
	else {
		 collection = m_collection;
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
	}
}

void SongCollection::sortCollection() {
	m_sortedCollection = m_collection;
	sort(m_sortedCollection.begin(), m_sortedCollection.end());
}
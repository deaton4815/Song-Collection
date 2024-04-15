#include "SongCollection.h"

using namespace std;

void SongCollection::addSong(string title, string artist, string genre) {

	Song newSong(title, artist, genre);
	m_songCollection.push_back(newSong);

}

void SongCollection::sortCollection() {


}
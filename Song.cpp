#include "Song.h"

using namespace std;

Song::Song(string title, string artist, string genre)
	: m_title(title)
	, m_artist(artist)
	, m_genre(genre)
{}

bool Song::operator< (const Song& song2) const {
	bool less_than{ false };
	if (song2.m_artist != this->m_artist) {
		less_than = this->m_artist < song2.m_artist;
	}
	else {
		less_than = this->m_title < song2.m_title;
	}
	return less_than;
}
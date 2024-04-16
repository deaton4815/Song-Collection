#include "Song.h"

using namespace std;

Song::Song() = default;
Song::Song(string title, string artist, string genre)
	: m_title(title)
	, m_artist(artist)
	, m_genre(genre)
{}

Song::Song(const Song& song) = default;

// Songs compared by artist name first
// Compared by song name if two songs are by the same artist
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

string Song::getTitle() const { return m_title; };
string Song::getArtist() const { return m_artist; };
string Song::getGenre() const { return m_genre; };
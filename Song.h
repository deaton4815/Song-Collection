/*
* Philip Deaton
*
* 605.604 - 04/24
*
* Class stores information for singular song
*/

#pragma once

#include <string>

class Song
{

public:

	Song();
	Song(std::string, std::string, std::string);
	Song(const Song&);

	bool operator< (const Song&) const;

	std::string getTitle() const;
	std::string getArtist() const;
	std::string getGenre() const;

private:

	std::string m_title;
	std::string m_artist;
	std::string m_genre;
};


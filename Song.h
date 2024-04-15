#pragma once

#include <string>

class Song
{

public:

	Song(std::string, std::string, std::string);

	bool operator< (const Song&) const;

private:

	std::string m_title;
	std::string m_artist;
	std::string m_genre;
};


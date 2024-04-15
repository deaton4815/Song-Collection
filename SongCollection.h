#pragma once

#include <vector>
#include <string>
#include <algorithm>

#include "Song.h"

class SongCollection
{

public:

private:

	std::vector<Song> m_collection;

	void addSong(std::string, std::string, std::string);
	void sortCollection();
};


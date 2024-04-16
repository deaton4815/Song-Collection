/*
* Philip Deaton
*
* 605.604 - 04/24
*
* Class stores and acts upon a collection of songs
*/
#pragma once

#include <vector>
#include <array>
#include <string>
#include <algorithm>

#include "Song.h"
#include "SongCollectionInterface.h"

class SongCollection
{

public:

	SongCollection();

private:

	std::vector<Song> m_collection;
	std::vector<Song> m_sortedCollection;
	SongCollectionInterface m_userInterface;

	void executeSongCollection();
	void addSong(std::array<std::string, 3>);
	void displayCollection(bool) const;
	void sortCollection();
	bool isEmptyCollection();
};


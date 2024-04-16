/*
* Philip Deaton
*
* 605.604 - 04/24
*
* Class handles user interface of song collection
*/
#pragma once

#include <iostream>
#include <array>
#include <string>

class SongCollectionInterface
{

public:

	int getUserAction() const;
	std::array<std::string, 3> getSongInformation() const;
	void displaySongCollectionHeader(bool);
	void displaySong(const std::string&, const std::string&, const std::string&) const;

private:

	const std::array<int, 4> m_legalMenuSelections{ 0, 1, 2, 3 };//Possible main menu selections

	void displayMenu() const;
	int getMenuSelection() const;
	bool isLegalMenuSelection(int) const;

	std::string getSongCharacteristic(const std::string&) const;
	bool isCorrectSongEntry(const std::string&, const std::string&, const std::string&) const;
};
#pragma once

#include <iostream>
#include <array>
#include <string>
#include <algorithm>

class SongCollectionInterface
{

public:

	int getUserAction() const;
	std::array<std::string, 3> getSongInformation() const;
	void displaySongCollectionHeader(bool);
	void displaySong(const std::string&, const std::string&, const std::string&) const;

private:

	std::array<int, 4> m_legalMenuSelections{ 0, 1, 2, 3 };

	void displayMenu() const;
	int getMenuSelection() const;
	bool isLegalMenuSelection(int) const;

	std::string getSongCharacteristic(const std::string&) const;
	bool isCorrectSongEntry(const std::string&, const std::string&, const std::string&) const;
};
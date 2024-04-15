#pragma once

#include <iostream>
#include <array>
#include <algorithm>

class SongCollectionInterface
{

public:

	int getUserAction() const;

private:

	array<int, 4> m_legalMenuSelections{ 0, 1, 2, 3 };

	void displayMenu() const;
	int getMenuSelection() const;

	bool isLegalMenuSelection(int) const;

};


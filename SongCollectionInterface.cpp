#include "SongCollectionInterface.h"

using namespace std;

int SongCollectionInterface::getUserAction() const {
	displayMenu();
	return getMenuSelection();
}

void SongCollectionInterface::displayMenu() const {
	cout << "\nPlease select from available options?" << endl << endl;

	cout << "1 - Add new song to collection" << endl;
	cout << "2 - Display song collection as entered" << endl;
	cout << "3 - Display song collection "
		<< "alphabetically sorted by artist name" << endl;

	cout << "\n0 - Terminate program" << endl;
}

int SongCollectionInterface::getMenuSelection() const {
	int selection{ -1 };
	while (!isLegalMenuSelection(selection)) {
		cout << "\nPlease enter slection number: ";
		cin >> selection;
	}
	return selection;
}

bool SongCollectionInterface::isLegalMenuSelection(int selection) const {
	bool isLegal{ false };
	if (any_of(m_legalMenuSelections.begin(), m_legalMenuSelections.end(), selection)) {
		isLegal = true;
	}
	return isLegal;
}
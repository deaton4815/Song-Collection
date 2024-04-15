#include "SongCollectionInterface.h"

using namespace std;

int SongCollectionInterface::getUserAction() const {
	displayMenu();
	return getMenuSelection();
}

array<string, 3> SongCollectionInterface::getSongInformation() const {
	cout << endl;

	string title{ "" };
	string artist{ "" };
	string genre{ "" };

	bool isCorrect{ false };
	while (!isCorrect) {
		title = getSongCharacteristic("title");
		artist = getSongCharacteristic("artist");
		genre = getSongCharacteristic("genre");

		isCorrect = isCorrectSongEntry(title, artist, genre);
	}
}

void SongCollectionInterface::displaySongCollectionHeader(bool isSorted) {
	if (isSorted) {
		cout << "\nSong collection sorted alphabetically by artist:";
	}
	else {
		cout << "\nSong collection ordered by user entry:";
	}
}

void SongCollectionInterface::displaySong(const string& title, const string& artist, const string& genre) const {
	cout << "\n" << title << " by " << artist << " (" << genre << ")";
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

string SongCollectionInterface::getSongCharacteristic(const string& label) const {
	string characteristic{ "" };
	cout << "\nPlease enter song " << label << ": ";
	cin >> characteristic;
	return characteristic;
}

bool SongCollectionInterface::isCorrectSongEntry(const string& title, const string& artist, const string& genre) const {
	cout << "\nSong entered:";
	displaySong(title, artist, genre);

	bool isCorrect{ false };
	char yes_no{ '\0' };
	while ((yes_no != 'y') || (yes_no != 'n')) {
		cout << "\nIs this correct (y/n)? ";
		cin >> yes_no;
	}
	
	if ('y' == yes_no) {
		isCorrect = true;
	}
	return isCorrect;
}
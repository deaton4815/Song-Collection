#include "SongCollectionInterface.h"

using namespace std;

//Display main menu and get selection
int SongCollectionInterface::getUserAction() const {
	displayMenu();
	return getMenuSelection();
}

//Get title, artist, and genre of song
array<string, 3> SongCollectionInterface::getSongInformation() const {
	cout << endl;

	string title{ "" };
	string artist{ "" };
	string genre{ "" };

	// Get song information and give user opportunity to correct potential typos
	bool isCorrect{ false };
	while (!isCorrect) { 
		cin.ignore(1024, '\n');
		title = getSongCharacteristic("title");
		artist = getSongCharacteristic("artist");
		genre = getSongCharacteristic("genre");
		isCorrect = isCorrectSongEntry(title, artist, genre);
	}
	array<string, 3> song{ title, artist, genre };
	return song;
}

//Headers when displaying song collection
void SongCollectionInterface::displaySongCollectionHeader(bool isSorted) {
	if (isSorted) {
		cout << "\nSong collection sorted alphabetically by artist:";
	}
	else {
		cout << "\nSong collection ordered by user entry:";
	}
}

// Display song information in following format: Title by Artist (Genre)
void SongCollectionInterface::displaySong(const string& title, const string& artist, const string& genre) const {
	cout << "\n" << title << " by " << artist << " (" << genre << ")";
}

// User main menu options
void SongCollectionInterface::displayMenu() const {
	cout << "\n\nPlease select from available options:" << endl << endl;

	cout << "1 - Add new song to collection" << endl;
	cout << "2 - Display song collection as entered" << endl;
	cout << "3 - Display song collection "
		<< "alphabetically sorted by artist name" << endl;

	cout << "\n0 - Terminate program" << endl;
}

// User main menu selection
int SongCollectionInterface::getMenuSelection() const {
	int selection{ -1 };
	while (!isLegalMenuSelection(selection)) {
		cout << "\nPlease enter slection number: ";
		cin >> selection;
	}
	return selection;
}

// Check that valid main menu selection was entered
bool SongCollectionInterface::isLegalMenuSelection(int selection) const {
	bool isLegal{ false };

	for (size_t i{ 0 }; i < m_legalMenuSelections.size(); i++) {
		if (m_legalMenuSelections.at(i) == selection) {
			isLegal = true;
		}
	}
	return isLegal;
}

// Get user entry for song attribute
string SongCollectionInterface::getSongCharacteristic(const string& label) const {
	string characteristic{ "" };
	cout << "Please enter song " << label << ": ";
	getline(cin, characteristic);
	return characteristic;
}

// Allow user to double-check song entry
bool SongCollectionInterface::isCorrectSongEntry(const string& title, const string& artist, const string& genre) const {
	cout << "\nSong entered:";
	displaySong(title, artist, genre);

	bool isCorrect{ false };
	char yes_no{ '\0' };
	while ((yes_no != 'y') && (yes_no != 'n')) {
		cout << "\nIs this correct (y/n)? ";
		cin >> yes_no;
	}
	
	if ('y' == yes_no) {
		isCorrect = true;
	}
	return isCorrect;
}
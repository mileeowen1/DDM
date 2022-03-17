/*
Name: Milee Owen
Class: CPSC 122, Spring 2020
Date: March 20, 2020
Programming Assignment: PA5
Description: Create a program that would arrange our music library based attributes such as song title, song artist, song genre, and rating. This assignment is a digital music manager (DMM) for managing a music library using classes.
Notes: Function definition cpp file
*/
#include "PA5.h"
/*************************************************************
 * Function: displayMenu()
 * Date Created: 02/29/20
 * Date Last Modified: 02/29/20
 * Description: This function displays the menu for the user
 *				to pick from.
 * Input parameters: none
 * Returns: nothing
 * Pre: nothing
 * Post: The display menu is displayed to the terminal.
 *************************************************************/
void displayMenu() {
	// displays the menu options
	cout << endl << "Welcome to the Digital Music Manager!!" << endl;
	cout << "Please choose from the following options: " << endl;
	cout << "1) Load library" << endl;
	cout << "2) Store library" << endl;
	cout << "3) Display library" << endl;
	cout << "4) Sort library" << endl;
	cout << "5) Search library" << endl;
	cout << "6) Play song clip" << endl;
	cout << "7) Add song" << endl;
	cout << "8) Remove song" << endl;
	cout << "9) Edit song" << endl;
	cout << "10) Exit" << endl;
	cout << "11) BONUS Insert song in order" << endl;
}
/*************************************************************
 * Function: getValidChoice()
 * Date Created: 02/29/20
 * Date Last Modified: 02/29/20          
 * Description: This function makes sure the user's input is
 *				valid.
 * Input parameters: none
 * Returns: the integer for user's choice
 * Pre: nothing
 * Post: An integer for the user's choice is returned.
 *************************************************************/
int getValidChoice() {
	int choice = -1;
	string temp;
	do {
		cout << "Choice: ";
		cin >> choice;
		if (choice < FIRST_OPTION || choice > LAST_OPTION) {
			cout << "That is not a valid option. Please try again." << endl;
		}
	} while (choice < FIRST_OPTION || choice > LAST_OPTION);
	getline(cin, temp); // flush the newline outta the buffer
	return choice;
}
/*************************************************************
 * Function: executeUserChoice()
 * Date Created: 02/29/20
 * Date Last Modified: 03/21/20          
 * Description: This function takes the user's choice and
 *				executes the corresponding functions.
 * Input parameters: The user's choice and a SongLibrary object 
 *				must be pass by reference.
 * Returns: nothing
 * Pre:  The user's choice and a SongLibrary object, that must 
 *				be pass by reference, had to have been
 *            	scanned in by the user.
 * Post: The class member functions are executed and messages
 *				are displayed.
 *************************************************************/
void executeUserChoice(int choice, SongLibrary& lib) {
	string userFile, userChoice;
	string userAttribute, newUserAttributeValue, userSearchAttribute, userSearchAttributeValue, userAttributeValue;
	Song songFound;
	Song userSong;
	Song * indexSong;
	string titleName, artistName, genreType, clipName, temp;
	int ratingValue, indexRemove, indexEdit, ind;
	bool foundSong;
	
	switch (choice) {
		case 1:
			// TODO: call a member function, something like lib.loadLibrary();
			// gets file for reading in and loads info to the library
			cout << "What file for reading in: ";
			getline(cin, userFile);
			lib.performLoad(userFile);
			break;
		case 2:
			// TODO: call a member function, something like lib.saveLibrary();
			// gets file for writing out and loads info from the library to the file
			cout << "What file for writing out: ";
			getline(cin, userFile);
			lib.performSave(userFile);
			break;
		case 3: 
			// TODO: call a member function, something like lib.displayLibrary();
			// displays the songs' attributes in the library
			lib.displayLibrary();
			break;
		case 4:
			// TODO: call a member function, something like lib.sortLibrary();
			// sorts the library songs by attribute entered by user
			cout << "What attribute for sorting: ";
			getline(cin, userAttribute);
			
			// prompt user for another entry if input does not match an attribute
			while (userAttribute != "title" && userAttribute != "artist" && userAttribute != "genre" && userAttribute != "clip" && userAttribute != "rating") {
				cout << "Not a valid attribute. Please re-enter your choice: ";
				getline(cin, userAttribute);
			}
			lib.performSort(userAttribute);
			break;
		case 5:
			// TODO: call a member function, something like lib.searchLibrary();
			// 
			cout << "Do you want to search for a song by index value or attribute value? (please enter 'index' or 'attribute'): ";
			getline(cin, userChoice);
			
			// prompt user for another entry if input does not match a choice
			while (userChoice != "index" && userChoice != "attribute") {
				cout << "Not a valid option. Please re-enter your choice: ";
				getline(cin, userChoice);
			}
			
			// search by index value
			if (userChoice == "index") {
				cout << "What song index to search: ";
				getline(cin, temp);
				ind = stoi(temp);
				if (ind < lib.getNumSongs()) {
					indexSong = lib.getSongsList();
					cout << "Title: " << (indexSong + ind)->getTitle() << endl;
					cout << "Artist: " << (indexSong + ind)->getArtist() << endl;
					cout << "Genre: " << (indexSong + ind)->getGenre() << endl;
					cout << "Clip: " << (indexSong + ind)->getClip() << endl;
					cout << "Rating: " << (indexSong + ind)->getRating() << endl;
				}
				else {
					cout << "Did not find song." << endl;
				}
			}
			
			// search by attribute
			else if (userChoice == "attribute") {
				cout << "What attribute type for searching: ";
				getline(cin, userSearchAttribute);
				while (userSearchAttribute != "title" && userSearchAttribute != "artist" && userSearchAttribute != "genre" && userSearchAttribute != "clip" && userSearchAttribute != "rating") {
					cout << "Not a valid attribute. Please re-enter your choice: ";
					getline(cin, userSearchAttribute);
				}
				cout << "What attribute name for searching: ";
				getline(cin, userSearchAttributeValue);
				foundSong = lib.performSearch(userSearchAttribute, userSearchAttributeValue, &songFound, &ind);
				
				if (foundSong == false) {
					cout << "Did not find song." << endl;
				}
				else {
					cout << "Title: " << songFound.getTitle() << endl;
					cout << "Artist: " << songFound.getArtist() << endl;
					cout << "Genre: " << songFound.getGenre() << endl;
					cout << "Clip: " << songFound.getClip() << endl;
					cout << "Rating: " << songFound.getRating() << endl;
				}
			}
			break;
		case 6:
		 	// TODO: call a member function, something like lib.playSongClipInLibrary();
		 	cout << "Do you want to play a song by index value or attribute value? (please enter 'index' or 'attribute'): ";
			getline(cin, userChoice);
			
			// prompt user for another entry if input does not match an attribute
			while (userChoice != "index" && userChoice != "attribute") {
				cout << "Not a valid option. Please re-enter your choice: ";
				getline(cin, userChoice);
			}
			
			// plays song by index value
			if (userChoice == "index") {
				cout << "What song index to play: ";
				getline(cin, temp);
				ind = stoi(temp);
				if (ind < lib.getNumSongs()) {
					lib.playSongClipInLibrary(ind);
				}
				else {
					cout << "Did not find index." << endl;
				}
			}
			
			// plays song by attribute
			else if (userChoice == "attribute") {
				cout << "What attribute type for playing: ";
				getline(cin, userAttribute);
				while (userAttribute != "title" && userAttribute != "artist" && userAttribute != "genre" && userAttribute != "clip" && userAttribute != "rating") {
					cout << "Not a valid attribute. Please re-enter your choice: ";
					getline(cin, userAttribute);
				}
				cout << "What attribute name for playing: ";
				getline(cin, userAttributeValue);
		 		foundSong = lib.performSearch(userAttribute, userAttributeValue, &songFound, &ind);
		 		if (foundSong == true) {
		 			lib.playSongClipInLibrary(ind);	
		 		}
		 		else {
		 			cout << "Song was not found for playing." << endl;
		 		}
		 	}
		 	break;
		case 7:
			// TODO: call a member function, something like lib.addSongToLibrary();
			
			// get's song information
			cout << "What song title to add: ";
			getline(cin, titleName);
			cout << "What song artist to add: ";
			getline(cin, artistName);
			cout << "What song genre to add: ";
			getline(cin, genreType);
			cout << "What song clip to add: ";
			getline(cin, clipName);
			cout << "What song rating to add: ";
			getline(cin, temp);
			ratingValue = stoi(temp);
			
			// creates a Song
			userSong.setTitle(titleName);
			userSong.setArtist(artistName);
			userSong.setGenre(genreType);
			userSong.setClip(clipName);
			userSong.setRating(ratingValue);
			lib.performAddSong(userSong);
			break;
		case 8:
			// TODO: call a member function, something like lib.removeSongFromLibrary();
			cout << "Do you want to remove a song by index value or attribute value? (please enter 'index' or 'attribute'): ";
			getline(cin, userChoice);
			
			// prompt user for another entry if input does not match a choice
			while (userChoice != "index" && userChoice != "attribute") {
				cout << "Not a valid option. Please re-enter your choice: ";
				getline(cin, userChoice);
			}
			
			// remove song by index value
			if (userChoice == "index") {
				cout << "What song index to remove: ";
				getline(cin, temp);
				indexRemove = stoi(temp);
				if (indexRemove < lib.getNumSongs()) {
					lib.performRemoveSong(indexRemove);
				}
				else {
					cout << "Did not find index for removal." << endl;
				}
			}
			
			// remove song by attribute
			else if (userChoice == "attribute") {
				cout << "What attribute type for searching: ";
				getline(cin, userSearchAttribute);
				while (userSearchAttribute != "title" && userSearchAttribute != "artist" && userSearchAttribute != "genre" && userSearchAttribute != "clip" && userSearchAttribute != "rating") {
					cout << "Not a valid attribute. Please re-enter your choice: ";
					getline(cin, userSearchAttribute);
				}
				cout << "What attribute name for searching: ";
				getline(cin, userSearchAttributeValue);
				foundSong = lib.performSearch(userSearchAttribute, userSearchAttributeValue, &songFound, &indexRemove);
				if (foundSong == true) {
		 			lib.performRemoveSong(indexRemove);
		 		}
		 		else {
		 			cout << "Song was not found for removal." << endl;
		 		}
			}
			break;
		case 9:
			// TODO: call a member function, something like lib.editSongInLibrary();
			cout << "Do you want to play a song by index value or attribute value? (please enter 'index' or 'attribute'): ";
			getline(cin, userChoice);
			
			// prompt user for another entry if input does not match a choice
			while (userChoice != "index" && userChoice != "attribute") {
				cout << "Not a valid option. Please re-enter your choice: ";
				getline(cin, userChoice);
			}
			
			// edits song by index value
			if (userChoice == "index") {
				cout << "What song index to edit: ";
				getline(cin, temp);
				indexEdit = stoi(temp);
				if (indexEdit < lib.getNumSongs()) {
					cout << "What attribute for editing: ";
					getline(cin, userAttribute);
					cout << "What is the new attribute value: ";
					getline(cin, newUserAttributeValue);
					if (userAttribute == "rating") {
						ratingValue = stoi(newUserAttributeValue);
						while (ratingValue < 1 || ratingValue > 5) {
							cout << "Not a valid rating. Please enter another value: ";
							getline(cin, newUserAttributeValue);
							ratingValue = stoi(newUserAttributeValue);
						}
					}
					lib.performEditSong(indexEdit, userAttribute, newUserAttributeValue);
				}
				else {
					cout << "Did not find index for editing." << endl;
				}
			}
			
			// edits song by attribute
			else if (userChoice == "attribute") {
				cout << "What attribute type for searching: ";
				getline(cin, userSearchAttribute);
				while (userSearchAttribute != "title" && userSearchAttribute != "artist" && userSearchAttribute != "genre" && userSearchAttribute != "clip" && userSearchAttribute != "rating") {
					cout << "Not a valid attribute. Please re-enter your choice: ";
					getline(cin, userSearchAttribute);
				}
				cout << "What attribute name for searching: ";
				getline(cin, userSearchAttributeValue);
				foundSong = lib.performSearch(userSearchAttribute, userSearchAttributeValue, &songFound, &ind);
				indexEdit = ind;
				if (foundSong == true) {
					cout << "What attribute for editing: ";
					getline(cin, userAttribute);
					while (userAttribute != "title" && userAttribute != "artist" && userAttribute != "genre" && userAttribute != "clip" && userAttribute != "rating") {
						cout << "Not a valid attribute. Please re-enter your choice: ";
						getline(cin, userAttribute);
					}
					cout << "What is the new attribute value: ";
					getline(cin, newUserAttributeValue);
					if (userAttribute == "rating") {
						ratingValue = stoi(newUserAttributeValue);
						while (ratingValue < 1 || ratingValue > 5) {
							cout << "Not a valid rating. Please enter another value: ";
							getline(cin, newUserAttributeValue);
							ratingValue = stoi(newUserAttributeValue);
						}
					}
					lib.performEditSong(indexEdit, userAttribute, newUserAttributeValue);
				}
				else {
					cout << "Song was not found for editing." << endl;
				}
			}	
			break;
		case 11:
			// TODO: call a member function, something like lib.insertSongInLibraryOrder();
			break;
		default:
			cout << "Unrecognized menu choice" << endl;
			break;
	}
}
/*************************************************************
 * Function: runDigitalMusicManager()
 * Date Created: 02/29/20
 * Date Last Modified: 02/29/20          
 * Description: This function runs the digital music manager.
 * Input parameters: none
 * Returns: nothing
 * Pre: nothing
 * Post: Runs the member functions called that execute the
 *				digital music manager.
*************************************************************/
void runDigitalMusicManager() {
	SongLibrary lib;
	
	int choice = -1;
	do {
		displayMenu();
		choice = getValidChoice();
		if (choice != QUIT_OPTION) {
			executeUserChoice(choice, lib);
		}
	} while (choice != QUIT_OPTION);
	cout << "Thanks for you using the Digital Music Manager!!" << endl;
}

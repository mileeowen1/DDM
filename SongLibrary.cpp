/*
Name: Milee Owen
Class: CPSC 122, Spring 2020
Date: March 20, 2020
Programming Assignment: PA5
Description: Create a program that would arrange our music library based attributes such as song title, song artist, song genre, and rating. This assignment is a digital music manager (DMM) for managing a music library using classes.
Notes: Class function definition cpp file
*/
#include "SongLibrary.h"
/*************************************************************
 * Function: SongLibrary()
 * Date Created: 02/29/20
 * Date Last Modified: 02/29/20          
 * Description: This function is the default value constructor
 *				and sets newly declared SongLibrary to default
 *				values.
 * Input parameters: none
 * Returns: nothing
 * Pre: Sets the values for the SongLibrary class.
 * Post: The values for the attributes are set to its default.
 *************************************************************/
SongLibrary::SongLibrary() {
	// initialize to empty list
	numSongs = 0;
	songs = NULL; 
}
/*************************************************************
 * Function: ~SongLibrary()
 * Date Created: 02/29/20
 * Date Last Modified: 03/21/20          
 * Description: This function is the destructor and it frees
 *				all dynamically allocated memory.
 * Input parameters: none
 * Returns: nothing
 * Pre: none
 * Post: When an object is about to be destoryed, memory is
 *				deallocated.
 *************************************************************/
// TODO: finish SongLibrary destructor
// be sure to properly free memory!!
SongLibrary::~SongLibrary() {
	// we have memory to free
	delete [] songs;
	songs = NULL; // good practice
	numSongs = 0; // good practice
}
/*************************************************************
 * Function: getNumSongs()
 * Date Created: 02/29/20
 * Date Last Modified: 02/29/20          
 * Description: This function is a getter that gets the number
 *				of songs in the library.
 * Input parameters: none
 * Returns: the number of songs
 * Pre: nothing
 * Post: The int for the number of songs is returned.
 *************************************************************/
int SongLibrary::getNumSongs() {
	return numSongs;
}
/*************************************************************
 * Function: setNumSongs()
 * Date Created: 02/29/20
 * Date Last Modified: 02/29/20          
 * Description: This function is a setter that sets the number
 *				of songs according to the user.
 * Input parameters: the int of the new number of songs
 * Returns: nothing
 * Pre: The int of the new number of songs had to have been
 *				scanned in by the user.
 * Post: The new number of songs replaces the old.
 *************************************************************/
void SongLibrary::setNumSongs(int newNumSongs) {
	numSongs = newNumSongs;
}
/*************************************************************
 * Function: getSongsList()
 * Date Created: 02/29/20
 * Date Last Modified: 02/29/20          
 * Description: This function is a getter that gets the songs
 *				in the library.
 * Input parameters: none
 * Returns: a pointer to a song object
 * Pre: nothing
 * Post: A pointer to a Song is returned, an array of Songs.
 *************************************************************/
Song * SongLibrary::getSongsList() {
	return songs;
}
/*************************************************************
 * Function: setSongsList()
 * Date Created: 02/29/20
 * Date Last Modified: 02/29/20          
 * Description: This function is a setter that sets the song
 *				pointer object according to the user.
 * Input parameters: the new Song object pointer
 * Returns: nothing
 * Pre: The new Song object pointer had to have been scanned
 *				in by the user.
 * Post: The new pointer to a song array replaces the old.
 *************************************************************/
void SongLibrary::setSongsList(Song * newSongsArr) {
	if (songs != NULL) {
		delete [] songs;
	}
	songs = newSongsArr;
}
/*************************************************************
 * Function: performLoad()
 * Date Created: 02/29/20
 * Date Last Modified: 03/21/20          
 * Description: The function reads songs from a library file
 *				into program memory.
 * Input parameters: the string for the file name
 * Returns: nothing
 * Pre: The string for the file name had to have been scanned
 *            	in by the user.
 * Post: The information of songs in a file is saved to a Song
 *				object.
 *************************************************************/
// TODO: finish this function
void SongLibrary::performLoad(string filename) {
	ifstream inputFile;
	string line;
	string titleName;
	string artistName;
	string genreType;
	string clipName;
	int ratingValue, i;
	int counter = 0;
	
	numSongs = 0;
	
	delete [] songs;
	
	// gets number of songs
	inputFile.open(filename);
	while (!inputFile.eof()) {
		getline(inputFile, line);
		if (inputFile.good()) {
			counter++;
		}
	}
	inputFile.clear();
	inputFile.seekg(0, ios::beg);
	numSongs = (counter + 1) / 6;
	songs = new Song[numSongs];
	
	// read in information and assign it to the struct array
	for (i = 0; i < numSongs; i++) {
		getline(inputFile, titleName);
		(songs + i)->setTitle(titleName);
		getline(inputFile, artistName);
		(songs + i)->setArtist(artistName);
		getline(inputFile, genreType);
		(songs + i)->setGenre(genreType);
		getline(inputFile, clipName);
		(songs + i)->setClip(clipName);
		getline(inputFile, line);
		ratingValue = stoi(line);
		(songs + i)->setRating(ratingValue);
		getline(inputFile, line);
	}
	
	inputFile.close();
}
/*************************************************************
 * Function: performSave()
 * Date Created: 02/29/20
 * Date Last Modified: 03/21/20          
 * Description: The function writes songs from a library file
 *				into an output file.
 * Input parameters: the string for the file name
 * Returns: nothing
 * Pre: The string for the file name had to have been scanned
 *            	in by the user.
 * Post: The attributes of songs is written in a file.
 *************************************************************/
// TODO: finish this function
void SongLibrary::performSave(string filename) {
	ofstream outputFile;
	int i;
	int num;
	
	outputFile.open(filename);
	
	num = getNumSongs();
	
	// outputs information to the file
	for (i = 0; i < num; i++) {
		outputFile << songs[i].getTitle() << endl;
		outputFile << songs[i].getArtist() << endl;
		outputFile << songs[i].getGenre() << endl;
		outputFile << songs[i].getClip() << endl;
		if (i < num - 1) {
			outputFile << songs[i].getRating() << endl << endl;
		}
		else {
			outputFile << songs[i].getRating() << endl;
		}
	}
	cout << endl;
	
	outputFile.close();
}
/*************************************************************
 * Function: performSort()
 * Date Created: 02/29/20
 * Date Last Modified: 03/21/20          
 * Description: The function sorts songs by an attribute chosen
 *				by the user.
 * Input parameters: the string for the attribute
 * Returns: nothing
 * Pre: The string for the attribute had to have been scanned
 *            	in by the user.
 * Post: The songs are sorted in order by the attribute.
 *************************************************************/
// TODO: finish this function
void SongLibrary::performSort(string attribute) {
	Song tempSong;
	int i;
	bool swap;
	
	// buble sort implementation for sorting by attribute
	do {
		swap = false;
		for (i = 0; i < (numSongs - 1); i++) {
			if ((songs + i)->getStringAttributeValue(attribute) > (songs + (i + 1))->getStringAttributeValue(attribute)) {
				tempSong = *(songs + i);
				*(songs + i) = *(songs + (i + 1));
				*(songs + (i + 1)) = tempSong;
				swap = true;
			}
		}
	} while (swap);
}
/*************************************************************
 * Function: performSearch()
 * Date Created: 02/29/20
 * Date Last Modified: 03/21/20          
 * Description: The function searchs for songs by an attribute
 *				and attribute name chosen by the user and the
 *				found song and index is returned by output param.
 * Input parameters: the string for the attribute and value, 
 *				pointer to Song object and int.
 * Returns: a boolean whether the song was found or not
 * Pre: The string for the attribute and value, pointer to Song
 *				object and int had to have been scanned in by
 *            	the user.
 * Post: A boolean whether the song was found or not is returned.
 *************************************************************/
// TODO: finish this function
bool SongLibrary::performSearch(string searchAttribute, string searchAttributeValue, Song * foundSong, int * index) {
	int i; 
	
	// searches for song by attribute and value and if found, it writes info to output parameters
	for (i = 0; i < numSongs; i++) {
		if ((songs + i)->getStringAttributeValue(searchAttribute) == searchAttributeValue) {
			*foundSong = *(songs + i);
			*index = i;
			return true;
		}
	}
	return false;
}
/*************************************************************
 * Function: performAddSong()
 * Date Created: 02/29/20
 * Date Last Modified: 03/21/20          
 * Description: The function adds a song to the library.
 * Input parameters: a song object
 * Returns: nothing
 * Pre: A song object for adding had to have been scanned
 *            	in by the user.
 * Post: A song is added to the end of the song library.
 *************************************************************/
// TODO: finish this function
void SongLibrary::performAddSong(Song newSong) {
	Song * newSongs = new Song[numSongs + 1];
	int i;

	for (i = 0; i < numSongs; i++) {
		*(newSongs + i) = *(songs + i);
	}
	
	// deallocate old array
	delete [] songs;
	songs = NULL;
	
	// adds new song to the end of library
	*(newSongs + i) = newSong;
	numSongs++;
	
	// make pointer point to new array
	songs = newSongs;
	newSongs = NULL;
}
/*************************************************************
 * Function: performRemoveSong()
 * Date Created: 02/29/20
 * Date Last Modified: 03/21/20          
 * Description: The function removes a song from the library.
 * Input parameters: the integer for the index to be removed
 * Returns: nothing
 * Pre: The integer for the index to be removed had to have
 *            	been scanned in by the user.
 * Post: A song is removed from the song library.
 *************************************************************/
// TODO: finish this function
// set songs to NULL if list becomes empty after remove
void SongLibrary::performRemoveSong(int indexToRemove) {
	int i;
	
	// set songs to NULL if list becomes empty after remove
	if (numSongs == 1) {
		numSongs = 0;
		delete [] songs;
		songs = NULL;
	}
	// removes song by index value according to user input
	else {
		numSongs--;
		Song * newSongs = new Song[numSongs];
		for (i = 0; i < indexToRemove; i++) {
			*(newSongs + i) = *(songs + i);
		}
		
		for (i = indexToRemove; i < numSongs; i++) {
			*(newSongs + i) = *(songs + (i + 1));
		}
		
		// deallocate old array
		delete [] songs;
		songs = NULL;
		
		// make pointer point to new array
		songs = newSongs;
		newSongs = NULL;
	}
}
/*************************************************************
 * Function: performEditSong()
 * Date Created: 02/29/20
 * Date Last Modified: 03/21/20          
 * Description: The function edits an attribute of a song from
 *				the library.
 * Input parameters: the integer for the index to be edited,
 *				the string for the attribute and new attribute
 * Returns: nothing
 * Pre: The integer for the index to be edited, the string for
 *				the attribute and new attribute had to have
 *            	been scanned in by the user.
 * Post: A song attribute is edited in the song library.
 *************************************************************/
// TODO: finish this function
void SongLibrary::performEditSong(int indexToEdit, string attribute, string newAttributeValue) {
	char c;
	
	attribute = convertToLowercase(attribute);
	c = char(attribute.at(0));
	
	// edits song attribute depending on the user's input
	switch (c) {
		case 't':
			(songs + indexToEdit)->setTitle(newAttributeValue);
			break;
		case 'a':
			(songs + indexToEdit)->setArtist(newAttributeValue);
			break;
		case 'g':
			(songs + indexToEdit)->setGenre(newAttributeValue);
			break;
		case 'c':
			(songs + indexToEdit)->setClip(newAttributeValue);
			break;
		case 'r':
			(songs + indexToEdit)->setRating(stoi(newAttributeValue));
			break;
	} 
}
/*************************************************************
 * Function: displayLibrary()
 * Date Created: 03/19/20
 * Date Last Modified: 03/21/20          
 * Description: The function displays all attributes of all
 *				songs from the library.
 * Input parameters: none
 * Returns: nothing
 * Pre: nothing
 * Post: All song attributes in library are displayed.
 *************************************************************/
void SongLibrary::displayLibrary() {
	int i;
	
	// displays all song attributes
	for (i = 0; i < numSongs; i++) {
		cout << "Title: " << songs[i].getTitle() << endl;
		cout << "Artist: " << songs[i].getArtist() << endl;
		cout << "Genre: " << songs[i].getGenre() << endl;
		cout << "Clip: " << songs[i].getClip() << endl;
		cout << "Rating: " << songs[i].getRating() << endl;
	}
}
/*************************************************************
 * Function: playSongClipInLibrary()
 * Date Created: 03/19/20
 * Date Last Modified: 03/21/20          
 * Description: The function plays the clip for a song in library.
 * Input parameters: the integer for the index to be played
 * Returns: nothing
 * Pre: The integer for the index of a song to be played had to
 * 				have been scanned in by the user.
 * Post: A song clip is played.
 *************************************************************/
void SongLibrary::playSongClipInLibrary(int index) {
	string commandStr1 = "cvlc --play-and-exit ";
	string commandStr2 = " 2> /dev/null &";
	string commandStr = commandStr1 + songs[index].getClip() + commandStr2;
	system(commandStr.c_str());
}

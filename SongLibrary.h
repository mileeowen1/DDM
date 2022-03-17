#ifndef SONG_LIBRARY_H
#define SONG_LIBRARY_H
/*
Name: Milee Owen
Class: CPSC 122, Spring 2020
Date: March 20, 2020
Programming Assignment: PA5
Description: Create a program that would arrange our music library based attributes such as song title, song artist, song genre, and rating. This assignment is a digital music manager (DMM) for managing a music library using classes.
Notes: Class function prototypes and header file
*/
#include <iostream>
#include <fstream>
#include "Song.h"

using namespace std;

class SongLibrary {
	private:
		int numSongs;
		Song * songs;
		// TODO: add your additional private attribute for the BONUS here
		// TODO: add your additional private member functions here
		
	public:
		SongLibrary();
		~SongLibrary();
		
		// getters and setters
		int getNumSongs();
		void setNumSongs(int);
		Song * getSongsList();
		void setSongsList(Song *);
		
		void performLoad(string);
		void performSave(string);
		void performSort(string);
		bool performSearch(string, string, Song *, int *);
		void performAddSong(Song);
		void performRemoveSong(int);
		void performEditSong(int, string, string);
		void performInsertSongInOrder(Song);

		// TODO: add your additional public member functions here
		void displayLibrary();
		void playSongClipInLibrary(int);
};

#endif

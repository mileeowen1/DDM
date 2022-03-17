#ifndef PA5_H
#define PA5_H
/*
Name: Milee Owen
Class: CPSC 122, Spring 2020
Date: March 20, 2020
Programming Assignment: PA5
Description: Create a program that would arrange our music library based attributes such as song title, song artist, song genre, and rating. This assignment is a digital music manager (DMM) for managing a music library using classes.
Notes: Function prototypes and header file
*/
#include <iostream>
#include <fstream>
#include "Song.h"
#include "SongLibrary.h"

using namespace std;

// constant variables
const int QUIT_OPTION = 10;
const int FIRST_OPTION = 1;
const int LAST_OPTION = 11;

// function prototypes
void displayMenu();
int getValidChoice();
void executeUserChoice(int, SongLibrary&);
void runDigitalMusicManager();

#endif

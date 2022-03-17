/*
Name: Milee Owen
Class: CPSC 122, Spring 2020
Date: March 20, 2020
Programming Assignment: PA5
Description: Create a program that would arrange our music library based attributes such as song title, song artist, song genre, and rating. This assignment is a digital music manager (DMM) for managing a music library using classes.
Notes: Class function definition cpp file
*/
#include "Song.h"
/*************************************************************
 * Function: convertToLowercase()
 * Date Created: 02/29/20
 * Date Last Modified: 03/21/20          
 * Description: This function converts the input string to all
 *				lower case.
 * Input parameters: the string for conversion
 * Returns: the converted string
 * Pre: The string for conversion had to have been scanned in
 *            	by the user.
 * Post: The string converted to all lower case is returned.
 *************************************************************/
// TODO: finish to convert s to all lower case and return lower case string
string convertToLowercase(string s) {
	int i;
	for (i = 0; i < s.length(); i++) {
		if (s.at(i) >= 'A' && s.at(i) <= 'Z') {
			s.at(i) += 32;
		}
	}
	return s;
}
/*************************************************************
 * Function: Song()
 * Date Created: 02/29/20
 * Date Last Modified: 03/21/20          
 * Description: This function is the default value constructor
 *				and sets newly declared Song to default values.
 * Input parameters: none
 * Returns: nothing
 * Pre: Sets the values for the Song class.
 * Post: The values for the attributes are set to its default.
 *************************************************************/
// TODO: finish Song default value constructor
Song::Song() {
	title = "";
	artist = "";
	genre = "";
	clip = "";
	rating = 1;
}
/*************************************************************
 * Function: Song()
 * Date Created: 02/29/20
 * Date Last Modified: 03/21/20          
 * Description: This function is the explicit value constructor
 *				and sets newly declared Song to values inputted
 *				by the user.
 * Input parameters: The strings for the song title, artist,
 *				genre, clip, and integer for rating.
 * Returns: nothing
 * Pre: The strings for the song title, artist,
 *				genre, clip, and integer for rating had to have
 *				been scanned in by the user.
 * Post: The values for the attributes are set to user's input.
 *************************************************************/
// TODO: finish Song explicit value constructor
// converts title, artist, and genre params to lower case
// calls setRating() to clip to bounds of [1, 5]
Song::Song(string titleParam, string artistParam, string genreParam, string clipParam, int ratingParam) {
	title = convertToLowercase(titleParam);
	artist = convertToLowercase(artistParam);
	genre = convertToLowercase(genreParam);
	clip = clipParam;
	setRating(ratingParam);
}
/*************************************************************
 * Function: getTitle()
 * Date Created: 02/29/20
 * Date Last Modified: 02/29/20          
 * Description: This function is a getter that gets the title
 *				of the song.
 * Input parameters: none
 * Returns: the title of the song
 * Pre: nothing
 * Post: The string for the title of the song is returned.
 *************************************************************/
string Song::getTitle() {
	return title;
}
/*************************************************************
 * Function: setTitle()
 * Date Created: 02/29/20
 * Date Last Modified: 02/29/20          
 * Description: This function is a setter that sets the title
 *				of the song according to the user.
 * Input parameters: the string of the new title
 * Returns: nothing
 * Pre: The string of the new title had to have been scanned in
 *				by the user.
 * Post: The new title replaces the old.
 *************************************************************/
void Song::setTitle(string newTitle) {
	title = convertToLowercase(newTitle);
}
/*************************************************************
 * Function: getArtist()
 * Date Created: 02/29/20
 * Date Last Modified: 02/29/20          
 * Description: This function is a getter that gets the artist
 *				of the song.
 * Input parameters: none
 * Returns: the artist of the song
 * Pre: nothing
 * Post: The string for the artist of the song is returned.
 *************************************************************/
string Song::getArtist() {
	return artist;
}
/*************************************************************
 * Function: setArtist()
 * Date Created: 02/29/20
 * Date Last Modified: 02/29/20          
 * Description: This function is a setter that sets the artist
 *				of the song according to the user.
 * Input parameters: the string of the new artist
 * Returns: nothing
 * Pre: The string of the new artist had to have been scanned in
 *				by the user.
 * Post: The new artist replaces the old.
 *************************************************************/
void Song::setArtist(string newArtist) {
	artist = convertToLowercase(newArtist);
}
/*************************************************************
 * Function: getGenre()
 * Date Created: 02/29/20
 * Date Last Modified: 02/29/20          
 * Description: This function is a getter that gets the genre
 *				of the song.
 * Input parameters: none
 * Returns: the genre of the song
 * Pre: nothing
 * Post: The string for the genre of the song is returned.
 *************************************************************/
string Song::getGenre() {
	return genre;
}
/*************************************************************
 * Function: setGenre()
 * Date Created: 02/29/20
 * Date Last Modified: 02/29/20          
 * Description: This function is a setter that sets the genre
 *				of the song according to the user.
 * Input parameters: the string of the new genre
 * Returns: nothing
 * Pre: The string of the new genre had to have been scanned in
 *				by the user.
 * Post: The new genre replaces the old.
 *************************************************************/
void Song::setGenre(string newGenre) {
	genre = convertToLowercase(newGenre);
}
/*************************************************************
 * Function: getClip()
 * Date Created: 02/29/20
 * Date Last Modified: 02/29/20          
 * Description: This function is a getter that gets the clip
 *				of the song.
 * Input parameters: none
 * Returns: the clip of the song
 * Pre: nothing
 * Post: The string for the clip of the song is returned.
 *************************************************************/
string Song::getClip() {
	return clip;
}
/*************************************************************
 * Function: setClip()
 * Date Created: 02/29/20
 * Date Last Modified: 02/29/20          
 * Description: This function is a setter that sets the clip
 *				of the song according to the user.
 * Input parameters: the string of the new clip
 * Returns: nothing
 * Pre: The string of the new clip had to have been scanned in
 *				by the user.
 * Post: The new clip replaces the old.
 *************************************************************/
void Song::setClip(string newClip) {
	clip = newClip;
}
/*************************************************************
 * Function: getRating()
 * Date Created: 02/29/20
 * Date Last Modified: 02/29/20          
 * Description: This function is a getter that gets the rating
 *				of the song.
 * Input parameters: none
 * Returns: the rating of the song
 * Pre: nothing
 * Post: The int for the rating of the song is returned.
 *************************************************************/
int Song::getRating() {
	return rating;
}
/*************************************************************
 * Function: setRating()
 * Date Created: 02/29/20
 * Date Last Modified: 02/29/20          
 * Description: This function is a setter that sets the clip
 *				of the song according to the user or clips
 *				the values by the min and max values.
 * Input parameters: the int of the new rating
 * Returns: nothing
 * Pre: The int of the new rating had to have been scanned in
 *				by the user.
 * Post: The new rating replaces the old or it is cliped.
 *************************************************************/
void Song::setRating(int newRating) {
	if (newRating < MIN_RATING || newRating > MAX_RATING) {
		cout << "Rating must be in [" << MIN_RATING << ", " << MAX_RATING << "]" << endl;
	}
	if (newRating < MIN_RATING) {
		rating = MIN_RATING;
	}
	else if (newRating > MAX_RATING) {
		rating = MAX_RATING;
	}
	else {
		rating = newRating;
	}
}
/*************************************************************
 * Function: getStringAttributeValue()
 * Date Created: 02/29/20
 * Date Last Modified: 03/21/20          
 * Description: This function takes the user's attribute choice
 *				and returns the attribute value of the song.
 * Input parameters: the string for the attribute
 * Returns: the string for the corresponding attribute
 * Pre: The string for the attribute had to have been scanned
 *            	in by the user.
 * Post: The getters are called and are assigned to attribute
 *				which is returned.
 *************************************************************/
// TODO: finish to return string value for given attribute "title", "artist", "genre", "clip", or "rating"
// call getters 
// return empty string if attribute doesn't match 
string Song::getStringAttributeValue(string attribute) {
	char c;
	
	attribute = convertToLowercase(attribute);
	c = char(attribute.at(0));
	
	switch (c) {
		case 't':
			attribute = getTitle();
			break;
		case 'a':
			attribute = getArtist();
			break;
		case 'g':
			attribute = getGenre();
			break;
		case 'c':
			attribute = getClip();
			break;
		case 'r':
			attribute = to_string(getRating());
			break;
		default:
			attribute = "";
			break;
	}
	
	return attribute;
}

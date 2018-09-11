// Iris Favorial, Yeseul An
// CSS343
// Prof: Min Chen
// Assignment4
// Program that implements the header file
// of the factory class of the movie class and its child classes.
// this basically has access to the movie class and all its child classes
// and this is what is used to create instances of the movies
// in the movierentalstore class so it can be stored in the trees.

#pragma once

#include "movie.h"
#include "comedy.h"
#include "drama.h"
#include "classic.h"

const char COMEDY = 'F';
const char CLASSIC = 'C';
const char DRAMA = 'D';

class MovieFactory
{
public:
	MovieFactory();
	~MovieFactory();

	static Movie* createMovie(const char type, istream&);
};

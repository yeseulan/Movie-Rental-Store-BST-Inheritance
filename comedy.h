// Iris Favoreal, Yeseul An
// CSS343
// Prof: Min Chen
// Assignment4
// declarations for comedy child class of movie

#pragma once

#include "movie.h"

using namespace std;

class Comedy : public Movie
{
public:
	Comedy();								// constructor
	~Comedy();								// destructor

	//setters
	void setYear(string year);

	//getters
	string getYear() const;

	//operator overloads
	bool operator==(const Movie& rhs) const;
	bool operator!=(const Movie& rhs) const;
	bool operator>(const Movie& rhs) const;
	bool operator<(const Movie& rhs) const;
};




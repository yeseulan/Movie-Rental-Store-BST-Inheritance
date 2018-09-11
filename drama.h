// Iris Favorial, Yeseul An
// CSS343
// Prof: Min Chen
// Assignment4
// Program that implements the header file of the
// drama child class of the movie parent class

#pragma once

#include "movie.h"

using namespace std;

class Drama : public Movie
{
public:
	Drama();
	~Drama();

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



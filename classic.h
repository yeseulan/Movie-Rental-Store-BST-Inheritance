// Iris Favorial, Yeseul An
// CSS343
// Prof: Min Chen
// Assignment4
// Program that implements...

//------------------------------------------------------------------------------------------
// Implementation and assumptions:
//   -- Major actor name is always consisted of two strings, one part is first name and
//      another part is last name
//   -- Major actor's name is formatted correctly, for example, there should be a space 
//      between an actor's first name and last name
//   -- Classic movie is uniquely identified by its set of sorting attributes, which are 
//      release date and major actor name
//-------------------------------------------------------------------------------------------

#pragma once
#include "movie.h"
#include "fstream"
#include <sstream>
#include <string>

using namespace std;

class Classic : public Movie
{
public:
	Classic();								// constructor
	~Classic();								// destructor

	//setters
    void setMonth(string month);
    void setYear(string year);
    void setDateandActor(string);

	//getters
    string getMonth() const;
    string getYear() const;
    string getActualYear() const;

	//operator overloads
	bool operator==(const Movie& rhs) const;
	bool operator!=(const Movie& rhs) const;
	bool operator>(const Movie& rhs) const;
	bool operator<(const Movie& rhs) const;

protected:
	string majorActor;					// stores majoractor's name
	string releaseDate;                 // stores release date
    string year;
    string month;
    string actualYear;
	void setActorandDate();				// sets actor name and date of a movie
};


// Iris Favorial, Yeseul An - Assignment 4 Implementation - CSS343
// purpose:
// The parent class of other movie subclasses including drama, classics, and comedy


#pragma once

#include <iostream>
#include <string>

using namespace std;

class Movie
{
	friend ostream& operator<<(ostream& ostream, const Movie&rhs);

public:
	enum MOVIES{COMEDY, CLASSIC, DRAMA, END};
	Movie();												// constructor
	virtual ~Movie();										// virtual destructor
    char getGenre() const;
    bool borrowIt();
    void returnIt();

	//setters
    void setStock(int stock);
	void setDirector(string director);
	void setTitle(string title);
	virtual void setYear(string year) = 0;
	bool setOtherMovie(Movie *& movie);

	//getters
    int getStock() const;
    string getDirector() const;
    string getTitle() const;
	virtual string getYear() const = 0;
	
	Movie * getOtherMovie() const;

	//operator overloads
	virtual bool operator==(const Movie& rhs) const = 0;
	virtual bool operator!=(const Movie& rhs) const = 0;
	virtual bool operator>(const Movie& rhs) const = 0;
	virtual bool operator<(const Movie& rhs) const = 0;

protected:
    char genre;
	int stock;
	string director;
	string title;
	string year;
	Movie *otherMovie;
};

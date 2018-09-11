#include "movie.h"

Movie::Movie()
{
	otherMovie = NULL;
}

Movie::~Movie()
{
}

char Movie::getGenre() const
{
    return genre;
}

bool Movie::borrowIt()
{
    if(stock > 0)
    {
        stock--;
        return true;
    }
    return false;
}

void Movie::returnIt()
{
    stock++;
}

void Movie::setStock(int stock)
{
    this->stock = stock;
}

void Movie::setDirector(string director)
{
    this->director = director;
}

void Movie::setTitle(string title)
{
    this->title = title;
}

int Movie::getStock() const
{
    return this->stock;
}

string Movie::getDirector() const
{
    return this->director;
}

string Movie::getTitle() const
{
    return this->title;
}

ostream & operator<<(ostream & ostream, const Movie & rhs)
{
    ostream << rhs.getGenre() << ", " << rhs.getStock() << ", " << rhs.getDirector();
    ostream << ", " << rhs.getTitle() << ", " << rhs.getYear() << endl;
	return ostream;
}

bool Movie::setOtherMovie(Movie *& movie)
{
	otherMovie = movie;
	return true;
}

Movie * Movie::getOtherMovie() const
{
	return otherMovie;
}

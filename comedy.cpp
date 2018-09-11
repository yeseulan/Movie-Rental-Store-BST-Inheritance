
#include <stdio.h>
#include "comedy.h"

Comedy::Comedy()
{
    genre = 'F';
}


Comedy::~Comedy()
{
}

void Comedy::setYear(string year)
{
	this->year = year;
}

string Comedy::getYear() const
{
	return this->year;
}

bool Comedy::operator==(const Movie & rhs) const
{
	return title == rhs.getTitle() && year == rhs.getYear();
}

bool Comedy::operator!=(const Movie & rhs) const
{
	if (*this == rhs)
	{
		return false;
	}
	return true;
}

bool Comedy::operator>(const Movie & rhs) const
{
	if (title > rhs.getTitle())
	{
		return true;
	}
	else if (title == rhs.getTitle())
	{
		if (year > rhs.getYear())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;
}

bool Comedy::operator<(const Movie & rhs) const
{
	if (*this == rhs)
	{
		return false;
	}
	else if (*this > rhs)
	{
		return false;
	}
	return true;
}

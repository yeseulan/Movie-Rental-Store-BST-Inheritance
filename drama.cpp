#include "drama.h"


Drama::Drama()
{
    genre = 'D';
}


Drama::~Drama()
{
}


void Drama::setYear(string year)
{
	this->year = year;
}


string Drama::getYear() const
{
	return this->year;
}

bool Drama::operator==(const Movie & rhs) const
{
	return director == rhs.getDirector() && title == rhs.getTitle();
}

bool Drama::operator!=(const Movie & rhs) const
{
	if (*this == rhs)
	{
		return false;
	}
	return true;
}

bool Drama::operator>(const Movie & rhs) const
{
	if (director > rhs.getDirector())
	{
		return true;
	}
	else if (director == rhs.getDirector())
	{
		if (title > rhs.getTitle())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool Drama::operator<(const Movie & rhs) const
{
	if (*this == rhs)
	{
		return false;
	}
	else if (*this > rhs)
	{
		return false;
	}
	else
	{
		return true;
	}
}


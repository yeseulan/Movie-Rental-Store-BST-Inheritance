//#include "stdafx.h"
#include "classic.h"

Classic::Classic()
{
    genre = 'C';
}

Classic::~Classic()
{
}

void Classic::setYear(string year)
{
	this->year = year;
	setActorandDate();
}

void Classic::setDateandActor(string info)
{
    stringstream file(info);
    
    string firstName;
    string lastName;
    file >> month;
    file >> actualYear;
    file >> firstName;
    file >> lastName;
    majorActor = firstName + " " + lastName;
    releaseDate = month + " " + year;
}

string Classic::getYear() const
{
	return this->year;
}
string Classic::getActualYear() const
{
    return actualYear;
}

string Classic::getMonth() const
{
    return this->month;
}

void Classic::setActorandDate()
{
    string line = getYear();
    stringstream stream(line);
    
    string firstName;
    string lastName;
    stream >> firstName;
    stream >> lastName;
    stream >> month;
    stream >> actualYear;

    majorActor = firstName + " " + lastName;
    releaseDate = month + " " + year;
}

bool Classic::operator==(const Movie & rhs) const
{
    const Classic* c = dynamic_cast<const Classic *>(&rhs);
    return actualYear == c->actualYear && month == c->month && majorActor == c->majorActor;
}

bool Classic::operator!=(const Movie & rhs) const
{
	if (*this == rhs)
	{
		return false;
	}
	return true;
}

bool Classic::operator>(const Movie & rhs) const
{
    const Classic* c = dynamic_cast<const Classic *>(&rhs);

    if (actualYear > c->actualYear)
    {
        return true;
    }
    else if(actualYear < c->actualYear)
    {
        return false;
    }
    if (month > c->month)
    {
        return true;
    }
    else if (month < c->month)
    {
        return false;
    }
    if (majorActor > c->majorActor)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Classic::operator<(const Movie & rhs) const
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

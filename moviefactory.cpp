#include "moviefactory.h"


MovieFactory::MovieFactory()
{
}

MovieFactory::~MovieFactory()
{
}

Movie *MovieFactory::createMovie(const char type, istream& file)
{
    file.get();
	Movie *newMovie = NULL;

	switch (type)
	{
		case 'F':
            newMovie = new Comedy;
			break;
		case 'C':
			newMovie = new Classic;
			break;
		case 'D':
			newMovie = new Drama;
			break;
		default:
        {
			cout << "Invalid movie type: " << type << endl;
            string clear;
            getline(file, clear, '\n');
			newMovie = NULL;
            return NULL;
        }
	}
    
    string stockString;
    int newStock;
    string director;
    string title;
    string otherInfo;
    
    getline(file, stockString, ',');
    stringstream num(stockString);
    num >> newStock;
    newMovie->setStock(newStock);
    file.get();
    
    getline(file, director, ',');
    newMovie->setDirector(director);
    file.get();
    
    getline(file, title, ',');
    newMovie->setTitle(title);
    file.get();
    
    getline(file, otherInfo, '\n');
    newMovie->setYear(otherInfo);
    
	return newMovie;
}


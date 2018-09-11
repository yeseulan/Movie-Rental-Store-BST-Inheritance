//
//  MovieRentalStore.cpp
//  hw4
//
//  Created by Iris Favoreal on 3/10/18.
//  Copyright © 2018 Iris Favoreal. All rights reserved.
//
#include <stdio.h>
#include "movieRentalStore.h"
#include "moviefactory.h"
#include "actionfactory.h"

MovieRentalStore::MovieRentalStore()
{
	BST<Movie*> comedyContainer('F');
    BST<Movie*> dramaContainer('D');
	BST<Movie*> classicContainer('C');
	movieContainers.push_back(comedyContainer);
    movieContainers.push_back(dramaContainer);
	movieContainers.push_back(classicContainer);
}

MovieRentalStore::~MovieRentalStore()
{

}

vector<BST<Movie*> > MovieRentalStore::getMovies()
{
    return movieContainers;
}

HashTable<Customer> MovieRentalStore::getCustomers()
{
    return customerContainer;
}

void MovieRentalStore::setCustomers(ifstream& file)
{
    cout << "***** creating customers *******" << endl;
	for (;;)
	{
		int custID;
		file >> custID;

		if (file.eof())
			break;

		string fName;
		string lName;

		file >> fName;
		file >> lName;

		Customer *newCustomer = new Customer;
		newCustomer->setCustomerData(custID, fName, lName);
		customerContainer.insert(newCustomer->getCustomerID(), newCustomer);
	}
}

void MovieRentalStore::setTransactions(ifstream& file)
{
    cout << "***** creating commands *******" << endl;

	for (;;)
	{
		char command = file.get();
		if (file.eof())
			break;

        Action *newAction = ActionFactory::createAction(command, file, movieContainers, customerContainer);
		if (newAction == NULL)
		{
			continue;
		}
	}
}

void MovieRentalStore::setMedia(ifstream& file)
{
    cout << "***** creating movies *******" << endl;

	for (;;)
	{
		char genre = file.get();
		if (file.eof())
			break;

		Movie* newMovie = MovieFactory::createMovie(genre, file);
		if (newMovie == NULL)
			continue;

		bool inserted = false;
		for (vector<BST<Movie*> >::iterator it = movieContainers.begin(); it != movieContainers.end(); it++)
		{
			if (newMovie->getGenre() == it->getGenre())
			{
				it->insert(newMovie);
				inserted = true;
				break;
			}
		}
		if (!inserted)
		{
			BST<Movie*> newContainer(genre);
			newContainer.insert(newMovie);
			movieContainers.push_back(newContainer);
		}
	}
}

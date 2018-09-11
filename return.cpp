//
//  MovieRentalStore.cpp
//  hw4
//
//  Created by Iris Favoreal on 3/10/18.
//  Copyright © 2018 Iris Favoreal. All rights reserved.
//

#include "return.h"
#include <iostream>
using namespace std;

Return::Return() {}

Return::~Return() 
{
}

void Return::execute()
{
	if (cust->checkedOut(m) == false)
	{
		cout << "Cannot return a movie that was never checked out." << endl;
		return;
	}
	m->returnIt();
	cust->returnedItem(m);
}

void Return::setMedia(Movie *newM)
{
	m = newM;
}

void Return::setCustomer(Customer *newC)
{
	cust = newC;
}

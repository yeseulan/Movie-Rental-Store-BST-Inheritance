// Iris Favorial, Yeseul An - Assignment 4 Implementation - CSS343
// purpose:
// The customer class contains the information of a customer including
// the ID, name and transactions
// Assumes that the customerID is unique and 4 digits number

#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <stdio.h>
#include "BST.h"
#include "movie.h"

const int ID_LENGH = 4;

using namespace std;

class Customer
{
	friend ostream& operator<<(ostream &ostream, const Customer &rhs);

public:
	Customer();													// constructor
	Customer(int id, string fName, string lName);				// constructor with parameter
	~Customer();												// destructor

	//setter
	void setCustomerData(int id, string fName, string lName);	// sets the customer data

	//getter
	int getCustomerID() const;									// returns customerID
	string getFirstName() const;								// returns customer fist name
	string getLastName() const;									// returns customer last name
//    const vector<string> getHistory() const;

	int getHashKey() const;										// hash key generator

//    void addHistory(string record);
	void borrowedItem(Movie *movie);							// add to the item to the borrowed list
	void returnedItem(Movie *movie);                            // remove the item from the borrwed list
    bool checkedOut(Movie*);
    void printHistory();

protected:
    struct Trans												// struct of Trans which contains customer action and movie
    {															// associated with the transaction
        char Action;
        Movie * m;
    };
	int customerID;
	string firstName;
	string lastName;
	vector<Trans*> History;										  // action history of a customer
    vector<Movie *> borrowed;                                     // borrowed list of items of a customer
};



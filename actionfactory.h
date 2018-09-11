// Yeseul An - Iris Favoreal - Assignment 4 Implementation - CSS 343
// purpose:
// this is an action factory which creates instances of all the child classes of the Action class



#pragma once
#include <stdio.h>
#include <iostream>
#include "inventory.h"
#include "history.h"
#include "borrow.h"
#include "return.h"
#include "movieRentalStore.h"

using namespace std;

class ActionFactory
{
public:
	ActionFactory();
	~ActionFactory();
    // calls on other functions to validate command and execute it as appropriate (consolidates all the functions in this class)
	static Action *createAction(const char command, ifstream &, vector<BST<Movie*> >&, HashTable<Customer>&);

private:
    // calls on other functions to validate customerID/customer exists/retrieve customer, validate Movie/retrieve Movie
    static Action *createHistory(ifstream &, HashTable<Customer>&);
	static Action *createBorrow(ifstream &, HashTable<Customer>&, vector<BST<Movie*> >&);
	static Action *createReturn(ifstream &, HashTable<Customer>&, vector<BST<Movie*> >&);
    
    // validates customerID format or that customer exists. if it exists, it returns a pointer to it.
	static Customer* checkCustomerID(int ID, HashTable<Customer>&);
    
    // calls on other functions to validate if a movie exists and returns a pointer
    static Movie* findMedia(char genre, istream &file, vector<BST<Movie*> >&);
    
    // calls the retrieve function in the corresponding tree of the correct genre to see if the movie exists.
    // if it exists, it returns a pointer to that movie
    static Movie* findClassics(istream&, vector<BST<Movie*> >& movieContainer);
    static Movie* findComedy(istream&, vector<BST<Movie*> >& movieContainer);
    static Movie* findDrama(istream&, vector<BST<Movie*> >& movieContainer);
    
    // validates the command has an existing genre or media type
	static bool validateMovie(char m);
	static bool validateGenre(char g);
};


// Yeseul An - Iris Favoreal - Assignment 4 Implementation - CSS 343
// purpose:
// consolidates and stores everything in the store (movies, customers, transactions)



#ifndef MovieRentalStore_h
#define MovieRentalStore_h

#include "BST.h"
#include "moviefactory.h"
#include "hashTable.h"
#include "customer.h"
#include <vector>
#include <iostream>
using namespace std;

class MovieRentalStore
{
public:
    
    // constructor creates 3 trees for each genre and stores them into a vector in this class
	MovieRentalStore();
    ~MovieRentalStore();
    
    // reads from file to create customers and push them into this class' hash table
	void setCustomers(ifstream&);
    
    // reads from file to create transaction instances which will execute a certain action
    void setTransactions(ifstream&);
    
    // reads from file to create movie instances and insert them into the corresponding tree stored in this class' vector
	void setMedia(ifstream&);
    
    vector<BST<Movie*> > getMovies();
    HashTable<Customer> getCustomers();

private:
	vector<BST<Movie*> > movieContainers;   // stores 3 trees, one for each genre, can store more if needed
	HashTable<Customer> customerContainer;  // stores all customers
};

#endif /* MovieRentalStore_h */

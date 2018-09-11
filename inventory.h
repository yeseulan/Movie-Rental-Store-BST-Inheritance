// Iris Favorial, Yeseul An - Assignment 4 Implementation - CSS343
// purpose:
// The inventory class which inherits from the action parent class. 
// Returns the inventory of the movies in the right order, which is 
// comedy, drama, classics


#ifndef inventory_hpp
#define inventory_hpp

#include <stdio.h>
#include <vector>
#include "BST.h"
#include "action.h"
#include "movie.h"

class Inventory : public Action
{
public:
    Inventory();								// constructor
    Inventory(vector<BST<Movie*> >&);			// constuctor with vector stores
    ~Inventory();								// destructor
    void execute();								// execute the inventory action
private:
    vector<BST<Movie*> > printMovies;			// vector that stores the each movie genre in BST
};

#endif

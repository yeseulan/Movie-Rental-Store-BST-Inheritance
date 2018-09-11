// Iris Favorial, Yeseul An - Assignment 4 Implementation - CSS343
// purpose:
// The return class inherits from the action parent class, whenever a customer
// returns items to the store, it updates the stocks and history appropriately

#pragma once
#include "action.h"
#include "movie.h"
#include "customer.h"


class Return : public Action
{
public:
	Return();							// constructor
	virtual	~Return();					// destructor
	void execute();						
	void setMedia(Movie*);				// updates the movie information
	void setCustomer(Customer*);		// updates the customer information
protected:
	Movie* m;							// Stores pointer for a DVD object
	Customer* cust;
};


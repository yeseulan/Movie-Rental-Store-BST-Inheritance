// Iris Favorial, Yeseul An - Assignment 4 Implementation - CSS343
// purpose:
// The history class which inherits from the action parent class. 
// Returns the history of a customer transacion and its associated 
// movies

#ifndef history_hpp
#define history_hpp

#include <iostream>
#include <fstream>
#include "action.h"
#include "customer.h"
using namespace std;

class History : public Action
{
public:
    History();							// constructor 
    ~History();							// destructor
    void setCustomer(Customer*);		// sets customer information
    void execute();						// Display history of the customer
private:
    Customer* cust;						// the customerID we search for the history
};

#endif

#ifndef borrow_hpp
#define borrow_hpp
#include "action.h"
#include "customer.h"


class Borrow : public Action
{
public:
	Borrow();
	~Borrow();
	void execute();
	void setMedia(Movie*);
	void setCustomer(Customer*);

protected:
	Movie* m;        // Stores pointer for a DVD object
	Customer* cust;
	// pure virtual function making this class abstract
};
#endif

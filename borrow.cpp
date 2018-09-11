#include "borrow.h"

Borrow::Borrow()
{
}

Borrow::~Borrow()
{
}

void Borrow::execute()
{
	if (m->borrowIt() == false)
	{
		cout << "Cannot borrow an item that is not in stock." << endl;
		return;
	}
	cust->borrowedItem(m);
}

void Borrow::setMedia(Movie *newM)
{
	m = newM;
}

void Borrow::setCustomer(Customer *newC)
{
	cust = newC;
}

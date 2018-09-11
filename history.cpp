//
//  MovieRentalStore.cpp
//  hw4
//
//  Created by Iris Favoreal on 3/10/18.
//  Copyright © 2018 Iris Favoreal. All rights reserved.
//

#include <stdio.h>
#include "history.h"

History::History() {}

History::~History() {}

void History::setCustomer(Customer* c)
{
    cust = c;
}

void History::execute()
{
    cust->printHistory();
}




//
//  MovieRentalStore.cpp
//  hw4
//
//  Created by Iris Favoreal on 3/10/18.
//  Copyright © 2018 Iris Favoreal. All rights reserved.
//

#include "inventory.h"


Inventory::Inventory(){}

Inventory::Inventory(vector<BST<Movie*> >& movies) : Action()
{
   // printMovies = movies;
   // execute();
     cout << "----------------------------- INVENTORY ------------------------------" << endl << endl;
    for(vector<BST<Movie*> >::iterator it = movies.begin(); it != movies.end(); it++)
        it->print();
    cout << "-------------------------------------------------------------------" << endl << endl;

}

Inventory::~Inventory(){}

void Inventory::execute()
{
 //   cout << "----------------------------- INVENTORY ------------------------------" << endl << endl;
 //   for(vector<BST<Movie*> >::iterator it = printMovies.begin(); it != printMovies.end(); it++)
 //       it->print();
 //   cout << "-------------------------------------------------------------------" << endl << endl;
}

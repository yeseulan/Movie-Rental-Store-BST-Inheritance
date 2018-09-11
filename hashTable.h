// Iris Favorial, Yeseul An - Assignment 4 Implementation - CSS343
// purpose:
// The hashtable class which is to hash using the customers unique ID
// Assumes that the customer has unique ID and they are properly formatted

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include "customer.h"

using namespace std;

template <class Type>
class HashTable
{
	static const int SIZE = 53;							// prime number, more than twice larger than customer size
public:
	HashTable()											// constructor
	{
		for(int i = 0; i < SIZE; i++)
		{
			table[i] = NULL;
		}
	}

	~HashTable()										// destructor
	{
        for (int i = 0; i < SIZE; i++)
        {
            if (table[i] != NULL)
            {
                ItemList *del = table[i];
                while (table[i] != NULL)
                {
                    table[i] = table[i]->next;
		    delete del->data;
                    delete del;
                    del = table[i];
                }
            }
        }
	}

	Type *retrieve(int key) const						// retrieve value in the table
	{
		int hashKey = key % SIZE;
		if (table[hashKey] == NULL)
		{
			return NULL;
		}

		else
		{
			ItemList *cur = table[hashKey];
			while (cur != NULL)
			{
				if (key == cur->key)
				{
					return cur->data;
				}
				else
				{
					cur = cur->next;
				}
			}
		}
		return NULL;
	}

	void insert(int key, Type *item)					// inserts an item to the hashtable
	{
		int hashKey = key % SIZE;
		ItemList *newItem = new ItemList;
		newItem->data = item;
		newItem->key = key;
		newItem->next = NULL;

		if (table[hashKey] == NULL)
		{
			table[hashKey] = newItem;
		}
		else
		{
			ItemList *cur = table[hashKey];
			while (cur->next != NULL)
			{
				if (key == cur->key)
				{
					delete newItem->data;
					delete newItem;
				}
				cur = cur->next;
			}
			cur->next = newItem;
		}
	}

private:
	struct ItemList							// the struct in the hashtable 
	{
		Type *data;
		int key;
		ItemList *next;
	};
	ItemList *table[SIZE];					// hashtable
};



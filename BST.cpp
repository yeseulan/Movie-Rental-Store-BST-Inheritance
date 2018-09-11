//
//  MovieRentalStore.cpp
//  hw4
//
//  Created by Iris Favoreal on 3/10/18.
//  Copyright © 2018 Iris Favoreal. All rights reserved.
//

#include <stdio.h>
#include "BST.h"

template<class DVDGenre>
BST<DVDGenre>::BST(char g)
{
    root = NULL;
    genre = g;
}

template <class DVDGenre>
BST<DVDGenre>::~BST()
{
    emptyTree(root);
}

template <class DVDGenre>
void BST<DVDGenre>::insert(DVDGenre newDVD)
{
    Node* newNode = new Node();
    newNode->data = newDVD;
    newNode->left = newNode->right = NULL;
    insertHelper(newNode, root);
}

template <class DVDGenre>
void BST<DVDGenre>::insertHelper(Node* n, Node* &cur)
{
    if(cur == NULL)
        cur = n;
    else if (*n->data > *cur->data)
        insertHelper(n, cur->right);
    else if (*n->data < *cur->data)
        insertHelper(n, cur->left);
    else
    {
        cur->data->returnIt();
        delete n->data;
        delete n;
        n = NULL;
    }
}

template <class DVDGenre>
bool BST<DVDGenre>::remove(DVDGenre someDVD)
{
    return true;
}

template <class DVDGenre>
DVDGenre BST<DVDGenre>::retrieve(DVDGenre someDVD)
{
    return retrieveHelper(someDVD, root);
}

template <class DVDGenre>
DVDGenre BST<DVDGenre>::retrieveHelper(DVDGenre someDVD, Node*& cur)
{
    if(cur == NULL)
        return NULL;
    else if(*someDVD < *cur->data)
        return retrieveHelper(someDVD, cur->left);
    else if(*someDVD > *cur->data)
        return retrieveHelper(someDVD, cur->right);
    else
        return cur->data;
}

template <class DVDGenre>
char BST<DVDGenre>::getGenre()
{
    return genre;
}

template <class DVDGenre>
void BST<DVDGenre>::print()
{
    printHelper(root);
}

template <class DVDGenre>
void BST<DVDGenre>::printHelper(Node*& cur)
{
    if (cur == NULL)
        return;
    
    printHelper(cur->left);
    cout << *cur->data << " ";
    printHelper(cur->right);
}

template <class DVDGenre>
void BST<DVDGenre>::emptyTree(Node*& cur)
{
    if(cur == NULL)
        return;
    
    emptyTree(cur->left);
    emptyTree(cur->right);
    
    if(cur->data != NULL)
    {
    delete cur->data;
    cur->data = NULL;
    }
    delete cur;
    cur = NULL;
}

template class BST<Movie*>;


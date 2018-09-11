// Yeseul An - Iris Favoreal - Assignment 4 Implementation - CSS 343
// purpose:
// used as a template data structure for the different types of movie child classes

#ifndef BST_h
#define BST_h
#include "movie.h"

template <class DVDGenre>
class BST
{
    // operator overload for printing out a movie type object
    friend ostream& operator<<(ostream& ostream, const Movie&rhs);
public:
    BST(char g);
    ~BST();
    void insert(DVDGenre);
    bool remove(DVDGenre);
    DVDGenre retrieve(DVDGenre);
    void print();
    char getGenre();
private:
    struct Node
    {
        DVDGenre data;
        Node * left;
        Node * right;
    };
    Node* root;
    char genre;
    void insertHelper(Node*, Node*&);
    DVDGenre retrieveHelper(DVDGenre, Node*&);
    void printHelper(Node*&);
    void emptyTree(Node*&);
};

#endif 


// Yeseul An - Iris Favoreal - Assignment 4 Implementation - CSS 343
// purpose:
// this is an abstract parent class of all transaction child classes: return, history, inventory, borrow

#ifndef action_hpp
#define action_hpp

#include <stdio.h>

class Action
{
public:
    Action();
    
    // made virtual so child instances through base pointers are deleted correctly
    // in order to prevent memory leaks
    virtual ~Action();
    
    // pure virtual declaration makes this class an abstract class
    virtual void execute() = 0;
private:
};
#endif /* action_hpp */

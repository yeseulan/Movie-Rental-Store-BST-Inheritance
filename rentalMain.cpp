

#include "movieRentalStore.h"
#include <iostream>
#include <fstream>

int main(int argc, const char * argv[])
{
    MovieRentalStore branch1;
    
    ifstream custFile("data4customers.txt");
    if(!custFile)
    {   
	 cout << "File could not be opened." << endl;
    }
    else
    {
        branch1.setCustomers(custFile);
    }
    
    ifstream movieFile("data4movies.txt");
    if(!movieFile)
    {    cout << "File could not be opened." << endl;}
    else
     {   branch1.setMedia(movieFile);}
    
    ifstream commandFile("data4commands.txt");
    if(!commandFile)
      {  cout << "File could not be opened." << endl;}
    else
       { branch1.setTransactions(commandFile);}
    
    return 0;
};


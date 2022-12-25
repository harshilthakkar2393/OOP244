/*
====================================================================
workshop -1 part -1 
====================================================================
Name: Harshil Dineshbhai Thakkar
Student Id: 160431219
E-mail : hthakkar8@myseneca.ca
Date :16-09-2022
OOP244 NEE  

--------------------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
====================================================================
*/

#ifndef SDDS_FILE_H
#define SDDS_FILE_H
#include "ShoppingRec.h"

namespace sdds
{
   
    const char *const SHOPPING_DATA_FILE = "shoppinglist.csv";
    
    bool openFileForRead();
    bool openFileForOverwrite();
    void closeFile();
    bool freadShoppingRec(ShoppingRec *rec);
    void fwriteShoppintRec(const ShoppingRec *rec);

}

#endif
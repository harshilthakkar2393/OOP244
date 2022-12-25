/*
====================================================================
workshop -10 part 1
====================================================================
Name: Harshil Dineshbhai Thakkar
Student Id: 160431219
E-mail : hthakkar8@myseneca.ca
Date :28-11-2022
OOP244 NEE

--------------------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
====================================================================
*/
#include <iostream>
#include "Collection.h"
#ifndef SDDS_SEARCH_H_
#define SDDS_SEARCH_H_
namespace sdds
{
    template <typename T>
    // takes an array of object, size of array (int) , char string and refrence of collection object as arguements.
    // returns true if the string matches any element in the array and adds the object to the object of collection type, and returns false otherwise.
    bool search(const T objArr[], int size, const char *key, Collection<T> &tempObj)
    {
        bool found = false;
        for (int i = 0; i < size; i++)
        {
           if(objArr[i]==key)//checking if the key matches any object from the array
           {
                found =true;
                tempObj.add(objArr[i]);// adding object to the collection object
           }
        }
        return found;
    }
}
#endif
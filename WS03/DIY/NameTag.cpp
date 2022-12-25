/*
====================================================================
workshop -3 part -2
====================================================================
Name: Harshil Dineshbhai Thakkar
Student Id: 160431219
E-mail : hthakkar8@myseneca.ca
Date :3-10-2022
OOP244 NEE

--------------------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
i only took inspiration for the bubbleSort algorithm from geekforgeeks
link is provided near function definition
====================================================================
*/
#include <iostream>
#include "NameTag.h"
#include "Utils.h"
using namespace std;

namespace sdds
{
    // This method sets the name, held by the NameTag object.
    void sdds::NameTag::set(const char *name)
    {
        if (name)
        {

            int len = 0;
            len = strlen(name);
            strcpy(charName, name, len);
        }
    }
}
/*
====================================================================
workshop -8 part 1
====================================================================
Name: Harshil Dineshbhai Thakkar
Student Id: 160431219
E-mail : hthakkar8@myseneca.ca
Date :16-11-2022
OOP244 NEE

--------------------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
====================================================================
*/
#include<iostream>
#include"Shape.h"
namespace sdds
{
    std::ostream &operator<<(std::ostream& os ,Shape &shape)
    {
        shape.draw(os);
        return os;
    }
    std::istream &operator>>(std::istream& is ,Shape &shape)
    {
        shape.getSpecs(is);
        return is;
    }
}























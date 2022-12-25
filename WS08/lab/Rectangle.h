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
#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H

#include "./LblShape.h"

namespace sdds
{
    class Rectangle : public LblShape
    {
        int m_width;
        int m_height;

    public:
        //--------------------------------------------------------
        // constructors and distructors
        //--------------------------------------------------------

        // default constructor
        Rectangle();

        // 3 args constructor
        Rectangle(const char *label, int width, int height);

        // distructor
        ~Rectangle();

        //--------------------------------------------------------
        // inherited virtual functions
        //--------------------------------------------------------

        // draw fucntion : returns nothing and takes ostream refrence as arguement
        virtual void draw(std::ostream &os) const;

        // getSpecs fucntion : returns nothing and takes istream refrence as arguement
        virtual void getSpecs(std::istream &is);
    };
}
#endif
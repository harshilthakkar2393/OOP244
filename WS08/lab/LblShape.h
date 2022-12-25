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
#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H
#include<iostream>
#include "./Shape.h"

namespace sdds
{
    class LblShape : public Shape
    {
        //--------------------------------------------------------
        // private data member
        //--------------------------------------------------------
        char *m_label;

    protected:
        //--------------------------------------------------------
        // Protected functions
        //--------------------------------------------------------

        // Returns the label of shape
        char *label() const;

    public:
        //--------------------------------------------------------
        // constructors and distructors
        //--------------------------------------------------------

        // default constructor
        LblShape();

        // 1 arg constructor
        LblShape(const char *label);

        // distructor
        ~LblShape();
        
        //--------------------------------------------------------
        // inherited virtual functions
        //--------------------------------------------------------

        // getSpecs fucntion : returns nothing and takes istream refrence as arguement
        virtual void getSpecs(std::istream &is);

        //--------------------------------------------------------
        // deleted operators and functions
        //--------------------------------------------------------
        LblShape &operator=(LblShape &rightHand) = delete;
        LblShape(LblShape &rightHand) = delete;
    };
}
#endif
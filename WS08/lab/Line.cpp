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
#include"./Line.h"

using namespace std;

namespace sdds
{
    //--------------------------------------------------------
    // constructors and distructors
    //--------------------------------------------------------

    // default constructor
    Line::Line():LblShape()
    {
        m_length=0;
    }

    // 2 args constructor
    Line::Line(const char *label, int length):LblShape(label)
    {
        m_length=length;
    }

    // distructor
    Line::~Line()
    {
        
    }

    //--------------------------------------------------------
    // inherited virtual functions
    //--------------------------------------------------------

    // draw fucntion : returns nothing and takes ostream refrence as arguement
    void Line::draw(std::ostream &os) const
    {
        if(m_length>0 && label()!=nullptr)
        {
            os.fill('=');
            os.width(m_length);
            os.setf(ios::left);
            os<<label();
            os.fill(' ');
            os.unsetf(ios::left);
            
        }
    }

    // getSpecs fucntion : returns nothing and takes istream refrence as arguement
    void Line::getSpecs(std::istream &is)
    {
        LblShape::getSpecs(is);
        is>>m_length;
        is.ignore(1000,'\n');
    }
}
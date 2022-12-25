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
#include <iostream>
#include<cstring>
#include "./Rectangle.h"

using namespace std;
namespace sdds
{
    //--------------------------------------------------------
    // constructors and distructors
    //--------------------------------------------------------

    // default constructor
    Rectangle::Rectangle() : LblShape()
    {
        m_height = 0;
        m_width = 0;
    }

    // 3 args constructor
    Rectangle::Rectangle(const char *label, int width, int height) : LblShape(label)
    {
        int len=strlen(label);
        if (height >= 3 && width >=(len+2))
        {

            m_height = height;
            m_width = width;
        }
        else
        {
            m_height = 0;
            m_width = 0;
        }
    }

    // distructor
    Rectangle::~Rectangle()
    {
    }

    //--------------------------------------------------------
    // inherited virtual functions
    //--------------------------------------------------------

    // draw fucntion : returns nothing and takes ostream refrence as arguement
    void Rectangle::draw(std::ostream &os) const
    {
        if (m_height > 0 && m_width > 0)
        {
            os << "+";
            for (int i = 0; i < (m_width - 2); i++)
            {
                os << "-";
            }
            os << "+" << endl;
            os << "|";
            os.setf(ios::left);
            os.width(m_width - 2);
            os << label();
            os << "|" << endl;
            for (int i = 0; i < (m_height - 3); i++)
            {
                os.width(m_width - 1);
                os.setf(ios::left);
                os << "|";
                os.unsetf(ios::left);
                os << "|" << endl;
            }
            os << "+";
            for (int i = 0; i < (m_width - 2); i++)
            {
                os << "-";
            }
            os << "+";
        }
    }

    // getSpecs fucntion : returns nothing and takes istream refrence as arguement
    void Rectangle::getSpecs(std::istream &is)
    {
        LblShape::getSpecs(is);
        is >> m_width;
        is.ignore(1000,',');
        is>> m_height;
        is.ignore(1000,'\n');
    }
}
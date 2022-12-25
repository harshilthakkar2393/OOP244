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
#include <cstring>
#include "./LblShape.h"

using namespace std;
namespace sdds
{
    //--------------------------------------------------------
    // Protected functions
    //--------------------------------------------------------

    // Returns the label of shape
    char *LblShape::label() const
    {
        return m_label;
    }

    //--------------------------------------------------------
    // constructors and distructors
    //--------------------------------------------------------

    // default constructor
    LblShape::LblShape()
    {
        m_label = nullptr;
    }

    // 1 arg constructor
    LblShape::LblShape(const char *label)
    {
        int len=strlen(label);
        if (label != nullptr && len > 0)
        {
            m_label = new char[len + 1];
            strcpy(m_label, label);
        }
        else
        {
            m_label = nullptr;
        }
    }

    // distructor
    LblShape::~LblShape()
    {
        delete[] m_label;
        m_label=nullptr;
    }

    //--------------------------------------------------------
    // inherited virtual functions
    //--------------------------------------------------------
    void LblShape::getSpecs(std::istream &is)
    {
        char proxyString [100];
        proxyString[0]='\0';
        is.getline(proxyString, 1000,',');
        if (proxyString != nullptr && strlen(proxyString) > 0)
        {
            delete[] m_label;
            m_label = new char[strlen(proxyString) + 1];
            strcpy(m_label, proxyString);
        }
    }

}
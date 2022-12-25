/*
====================================================================
workshop -9 part 1
====================================================================
Name: Harshil Dineshbhai Thakkar
Student Id: 160431219
E-mail : hthakkar8@myseneca.ca
Date :25-11-2022
OOP244 NEE

--------------------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
====================================================================
*/

#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include "./Text.h"

using namespace std;
namespace sdds
{
    //-----------------------------------------------
    // protected methods
    //-----------------------------------------------

    const char &Text::operator[](int index) const
    {
        return m_content[index];
    }

    //-----------------------------------------------
    // constructor and distructor
    //-----------------------------------------------

    Text::Text()
    {
        m_content = nullptr;
    }

    Text::Text(Text &rightHand)
    {
        this->m_content = nullptr;
        *this = rightHand;
    }

    Text::~Text()
    {
        delete[] m_content;
        m_content = nullptr;
    }

    //-----------------------------------------------
    // operator overloading
    //-----------------------------------------------
    Text &Text::operator=(Text &rightHand)
    {
        if (rightHand.m_content != nullptr && strlen(rightHand.m_content) > 0 && this != &rightHand)
        {
            delete[] m_content;
            m_content = nullptr;
            m_content = new char[strlen(rightHand.m_content) + 1];
            strcpy(this->m_content, rightHand.m_content);
        }
        return *this;
    }

    //-----------------------------------------------
    // virtual functions
    //-----------------------------------------------

    std::istream &Text::read(std::istream &istr)
    {
        unsigned int i = 0, length = getFileLength(istr);
        char proxyChar = 0;
        delete[] m_content;
        m_content = nullptr;
        m_content = new char[length + 1];
        while (i < length && istr.get(proxyChar) && !(istr.fail()))
        {
            m_content[i] = proxyChar;
            i++;
        }

        if (i > 0)
        {
            istr.clear();
            m_content[i] = '\0';
        }
        return istr;
    }
    std::ostream &Text::write(std::ostream &ostr) const
    {
        if (m_content != nullptr)
        {
            ostr << m_content;
        }
        return ostr;
    }

    //-----------------------------------------------
    // protected methods
    //-----------------------------------------------
    unsigned Text::getFileLength(std::istream &is)
    {
        unsigned len{};
        if (is)
        {
            // save the current read position
            std::streampos cur = is.tellg();
            // go to the end
            is.seekg(0, ios::end);
            // tell what is the positions (end position = size)
            len = unsigned(is.tellg());
            // now go back to where you were.
            is.seekg(cur);
        }
        return len;
    }

    //-----------------------------------------------
    // helper functions
    //-----------------------------------------------

    std::ostream &operator<<(std::ostream &ostr, const Text &rightHand)
    {
        rightHand.write(ostr);
        return ostr;
    }
    std::istream &operator>>(std::istream &istr, Text &rightHand)
    {
        rightHand.read(istr);
        return istr;
    }
}
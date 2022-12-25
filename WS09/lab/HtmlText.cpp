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

#include <iostream>
#include <cstring>
#include "./HtmlText.h"

using namespace std;
namespace sdds
{
    //-----------------------------------------------
    // constructor and distructor
    //-----------------------------------------------

    HtmlText::HtmlText() : Text()
    {
        m_title = nullptr;
    }

    HtmlText::HtmlText(const char *string) : Text()
    {
        m_title = nullptr;
        if (string != nullptr)
        {
            m_title = new char[strlen(string) + 1];
            strcpy(m_title, string);
        }
    }

    HtmlText::HtmlText(HtmlText &rightHand) : Text(rightHand)
    {
        m_title = nullptr;
        *this = rightHand;
    }

    HtmlText::~HtmlText()
    {
        delete[] m_title;
    }

    //-----------------------------------------------
    // operator overloading
    //-----------------------------------------------

    HtmlText &HtmlText::operator=(HtmlText &rightHand)
    {
        if (rightHand.m_title != nullptr && strlen(rightHand.m_title) > 0 && this != &rightHand)
        {
            (Text &)*this = rightHand;
            delete[] m_title;
            m_title = nullptr;
            m_title = new char[strlen(rightHand.m_title) + 1];
            strcpy(this->m_title, rightHand.m_title);
        }
        return *this;
    }

    //-----------------------------------------------
    // virtual functions
    //-----------------------------------------------
    std::ostream &HtmlText::write(std::ostream &ostr) const
    {
        int i = 0;
        int space = 0;
        ostr << "<html><head><title>";
        if (m_title == nullptr)
        {
            ostr << "No Title";
        }
        else
        {
            ostr << m_title;
        }
        ostr << "</title></head>" << endl;
        ostr << "<body>" << endl;
        if (m_title != nullptr)
        {

            ostr << "<h1>" << m_title << "</h1>" << endl;
        }
        while (operator[](i) != 0)
        {
            if (operator[](i) == ' ')
            {
                space++;
                if (space == 1)
                {
                    ostr << " ";
                }
                else if (space >= 2)
                {
                    ostr << "&nbsp;";
                }
            }
            else if (operator[](i) == '>')
            {
                space = 0;
                ostr << "&gt;";
            }
            else if (operator[](i) == '<')
            {
                space = 0;
                ostr << "&lt;";
            }
            else if (operator[](i) == '\n')
            {
                space = 0;
                ostr << "<br />" << endl;
            }
            else
            {
                space = 0;
                ostr << operator[](i);
            }
            i++;
        }
        ostr << "</body>" << endl
             << "</html>";
        return ostr;
    }
}
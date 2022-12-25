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

#ifndef SDDS_HTMLTEXT_H
#define SDDS_HTMLTEXT_H
#include "./Text.h"
namespace sdds
{
    class HtmlText : public Text
    {
        char *m_title;

    public:
        //-----------------------------------------------
        // constructor and distructor
        //-----------------------------------------------

        HtmlText();
        HtmlText(const char *string);
        HtmlText(HtmlText &rightHand);
        ~HtmlText();

        //-----------------------------------------------
        // operator overloading
        //-----------------------------------------------

        HtmlText &operator=(HtmlText &rightHand);

        //-----------------------------------------------
        // virtual functions
        //-----------------------------------------------

        virtual std::ostream &write(std::ostream &ostr = std::cout) const;
    };
}
#endif
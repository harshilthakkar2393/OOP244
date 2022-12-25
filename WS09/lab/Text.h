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

#ifndef SDDS_TEXT_H
#define SDDS_TEXT_H
#include <iostream>

namespace sdds
{
    class Text
    {
        char *m_content;

    protected:
        //-----------------------------------------------
        // protected methods
        //-----------------------------------------------
        const char &operator[](int index) const;

    public:
        //-----------------------------------------------
        // constructor and distructor
        //-----------------------------------------------
        Text();
        Text(Text &rightHand);
        ~Text();
        //-----------------------------------------------
        // protected methods
        //-----------------------------------------------
        unsigned getFileLength(std::istream &is);

        //-----------------------------------------------
        // operator overloading
        //-----------------------------------------------
        Text &operator=(Text &rightHand);

        //-----------------------------------------------
        // virtual functions
        //-----------------------------------------------
        virtual std::istream &read(std::istream &istr = std::cin);
        virtual std::ostream &write(std::ostream &ostr = std::cout) const;
    };

    //-----------------------------------------------
    // helper functions
    //-----------------------------------------------
    std::ostream &operator<<(std::ostream &ostr, const Text &rightHand);
    std::istream &operator>>(std::istream &istr, Text &rightHand);
}
#endif
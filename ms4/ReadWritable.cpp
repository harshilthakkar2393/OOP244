/* Citation and Sources...
Final Project Milestone 3
Module: ReadWritable
Filename: ReadWritable.cpp
Version 1.0
Author Harshil Dineshbhai Thakkar
Revision History
-----------------------------------------------------------
Date Reason
2022/22/11 Preliminary release
2022/22/11 Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
*/
#include <iostream>
#include "./ReadWritable.h"
using namespace std;
namespace sdds
{
    //--------------------------------------------------------
    // constructors and distructors
    //--------------------------------------------------------

    // default constructor
    ReadWritable::ReadWritable()
    {
        flag = false;
    }

    //--------------------------------------------------------
    // Public  Methods
    //--------------------------------------------------------

    // returns true if file is a csv type
    bool ReadWritable::isCsv() const
    {
        return flag;
    }

    // sets the value of the csv flag
    void ReadWritable::setCsv(bool value)
    {
        flag = value;
    }

    //--------------------------------------------------------
    // helper functions
    //--------------------------------------------------------

    std::ostream &operator<<(std::ostream &ostr, const ReadWritable &rightHand)
    {
        rightHand.write(ostr);
        return ostr;
    }

    std::istream &operator>>(std::istream &istr, ReadWritable &rightHand)
    {
        rightHand.read(istr);
        return istr;
    }
}
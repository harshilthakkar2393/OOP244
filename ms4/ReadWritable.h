/* Citation and Sources...
Final Project Milestone 3
Module: ReadWritable
Filename: ReadWritable.h
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
#ifndef SDDS_READWRITABLE_H__
#define SDDS_READWRITABLE_H__
#include <iostream>

namespace sdds
{
    class ReadWritable
    {
        bool flag;

    public:
        //--------------------------------------------------------
        // constructors and distructors
        //--------------------------------------------------------
        ReadWritable();
        virtual ~ReadWritable(){};

        //--------------------------------------------------------
        // Public  Methods
        //--------------------------------------------------------
        bool isCsv() const;
        void setCsv(bool value);

        //--------------------------------------------------------
        // virtual functions
        //--------------------------------------------------------
        virtual std::ostream &write(std::ostream &ostr = std::cout) const = 0;
        virtual std::istream &read(std::istream &istr = std::cin) = 0;
    };
    //--------------------------------------------------------
    // helper functions
    //--------------------------------------------------------
    std::ostream &operator<<(std::ostream &ostr, const ReadWritable &rightHand);
    std::istream &operator>>(std::istream &istr, ReadWritable &rightHand);
}
#endif
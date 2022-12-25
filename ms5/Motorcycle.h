/* Citation and Sources...
Final Project Milestone 4
Module: Motorcycle
Filename: Motorcycle.h
Version 1.0
Author Harshil Dineshbhai Thakkar
Revision History
-----------------------------------------------------------
Date Reason
2022/28/11 Preliminary release
2022/28/11 Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
*/
#ifndef SDDS_MOTORCYCLE_H__
#define SDDS_MOTORCYCLE_H__
#include<iostream>
#include"Utils.h"
#include "./Vehicle.h"

namespace sdds
{
    class Motorcycle:public Vehicle
    {
        bool sideCar;
        
        public:

        //--------------------------------------------------------
        // constructors and distructors
        //--------------------------------------------------------

        Motorcycle();
        Motorcycle(const char *lPlate, const char *mModel);
        Motorcycle(const Motorcycle& rightHand);
        ~Motorcycle(){};

        //--------------------------------------------------------
        // operator overloading
        //--------------------------------------------------------
        Motorcycle& operator=(const Motorcycle& rightHand);

        //--------------------------------------------------------
        // virtual functions
        //--------------------------------------------------------
        virtual std::ostream &writeType(std::ostream &ostr = std::cout) const;
        virtual std::ostream &write(std::ostream &ostr = std::cout) const;
        virtual std::istream &read(std::istream &istr = std::cin);
    };
}
#endif
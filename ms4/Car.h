/* Citation and Sources...
Final Project Milestone 4
Module: Car
Filename: Car.h
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

#ifndef SDDS_CAR_H__
#define SDDS_CAR_H__
#include<iostream>
#include"Utils.h"
#include "./Vehicle.h"

namespace sdds
{
    class Car:public Vehicle
    {
        bool carwash;
        
        public:

        //--------------------------------------------------------
        // constructors and distructors
        //--------------------------------------------------------

        Car();
        Car(const char *lPlate, const char *mModel);
        Car(const Car& rightHand);
        ~Car(){};

        //--------------------------------------------------------
        // operator overloading
        //--------------------------------------------------------
        Car& operator=(const Car& rightHand);

        //--------------------------------------------------------
        // virtual functions
        //--------------------------------------------------------
        virtual std::ostream &writeType(std::ostream &ostr = std::cout) const;
        virtual std::ostream &write(std::ostream &ostr = std::cout) const;
        virtual std::istream &read(std::istream &istr = std::cin);
    };
}
#endif
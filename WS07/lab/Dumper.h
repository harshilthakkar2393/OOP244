/*
Name: Harshil Dineshbhai Thakkar
Email: hthakkar8@myseneca.ca
Student ID: 160431219
Data: Dumper.h
Section: NEE
*/
#ifndef SDDS_Dumper_H
#define SDDS_Dumper_H
#include <iostream>
#include "VehicleBasic.h"

namespace sdds
{
    class Dumper : public VehicleBasic
    {
        //===================================
        //  Data Members 
        //===================================
        double maxLoad;
        double currentLoad;

    public:
        //===================================
        // Constructors 
        //===================================
        Dumper();
        Dumper(const char *lNumber, int year, double capacity, const char *address);

        //===================================
        // Member Functions
        //===================================
        bool loaddCargo(double cargo);
        bool unloadCargo();
        std::ostream &write(std::ostream &os = std::cout) const;
        std::istream &read(std::istream &in = std::cin);
    };
    //===================================
    // Helper Functions
    //===================================
    std::ostream &operator<<(std::ostream & os,const Dumper &Dumper);
    std::istream &operator>>(std::istream &in,Dumper &Dumper);

}
#endif

/*
Name: Harshil Dineshbhai Thakkar
Email: hthakkar8@myseneca.ca
Student ID: 160431219
Data: VehicleBasic.h
Section: NEE
*/

#ifndef SDDS_VehicleBasic_H
#define SDDS_VehicleBasic_H

#include <iostream>

#define MAX_LISENCE_PLATE_SIZE 9
#define Max_ADDRESS_SIZE 64
#define DEFAULT_ADDRESS "Factory"

namespace sdds
{
    class VehicleBasic
    {
        //===================================
        //  Data Members
        //===================================

        char lisencePlateNumber[MAX_LISENCE_PLATE_SIZE + 1];
        char currentAddress[Max_ADDRESS_SIZE + 1];
        int builtYear;

    public:
        //===================================
        // Constructors
        //===================================
        VehicleBasic();
        VehicleBasic(const char *lNumber, int year);

        //===================================
        // Member Functions
        //===================================

        void NewAddress(const char *address);
        std::ostream &write(std::ostream &os = std::cout) const;
        std::istream &read(std::istream &in = std::cin);
    };

    //===================================
    // Helper Functions
    //===================================
    std::ostream &operator<<(std::ostream &os, const VehicleBasic &vehicle);
    std::istream &operator>>(std::istream &in, VehicleBasic &vehicle);
}

#endif

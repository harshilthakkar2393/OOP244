/*
Name:Harshil Dineshbhai Thakkar
Email: Hthakkar8@myseneca.ca
Student ID: 160431219
Data: Dumper.cpp
Section: NEE
*/
#include <iostream>
#include "Dumper.h"
#include "./Utils.h"
#include "VehicleBasic.h"

using namespace std;
namespace sdds
{
    //===================================
    // Constructors
    //===================================

    // Default constructor
    Dumper::Dumper()
    {
        maxLoad = 0;
        currentLoad = 0;
    }

    // 4 arg constructor
    Dumper::Dumper(const char *lNumber, int year, double capacity, const char *address) : VehicleBasic(lNumber, year)
    {
        maxLoad = capacity;
        currentLoad = 0;
        NewAddress(address);
    }

    //===================================
    // Member Functions
    //===================================

    // load cargo fucntion : loads cargo in the dumper if there is enough space and returns true , false otherwise
    bool Dumper::loaddCargo(double cargo)
    {
        bool isLoaded = false;
        if ((currentLoad + cargo) <= maxLoad)
        {
            currentLoad += cargo;
            isLoaded = true;
        }
        return isLoaded;
    }

    // unload cargo fucntion : unloads cargo in the dumper if there cargo and returns true , false otherwise
    bool Dumper::unloadCargo()
    {
        bool isUnLoaded = false;
        if (currentLoad == 0)
        {
            isUnLoaded = false;
        }
        else
        {
            currentLoad = 0;
            isUnLoaded = true;
        }
        return isUnLoaded;
    }

    // write function: prints the objects
    std::ostream &Dumper::write(std::ostream &os) const
    {
        VehicleBasic::write();
        os << " | " << currentLoad << "/" << maxLoad;
        return os;
    }

    // read function: prompts user for input and stores the values
    std::istream &Dumper::read(std::istream &in)
    {
        VehicleBasic::read();
        cout << "Capacity: ";
        in >> maxLoad;
        cout << "Cargo: ";
        in >> currentLoad;
        return in;
    }

    //===================================
    // Helper Functions
    //===================================

    std::ostream &operator<<(std::ostream &os, const Dumper &Dumper)
    {
        return Dumper.write();
    }
    std::istream &operator>>(std::istream &in, Dumper &Dumper)
    {
        return Dumper.read();
    }
}

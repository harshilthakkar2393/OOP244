/*
Name: Harshil Dineshbhai Thakkar
Email: hthakkar8@myseneca.ca
Student ID: 160431219
Data: VehicleBasic.cpp
Section: NEE
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "./Utils.h"
#include "VehicleBasic.h"

using namespace std;
namespace sdds
{

    //===================================
    // Constructors
    //===================================

    // Default constructor
    VehicleBasic::VehicleBasic()
    {
        strcpy(currentAddress, DEFAULT_ADDRESS);
        builtYear = 0;
        lisencePlateNumber[0] = '\0';
    }

    // 2 args constructor
    VehicleBasic::VehicleBasic(const char *lNumber, int year)
    {
        strcpy(lisencePlateNumber, lNumber);
        strcpy(currentAddress, DEFAULT_ADDRESS);
        builtYear = year;
    }

    //===================================
    // Member Functions
    //===================================

    // New address fucntion: changes the current address to new address is the are not same
    void VehicleBasic::NewAddress(const char *address)
    {
        if (strcmp(currentAddress, address) != 0)
        {
            char proxyString[21];
            proxyString[0] = '\0';
            cout << "|";
            cout.setf(ios::right);
            strcpy(proxyString, lisencePlateNumber); // copying liscense plate number with limit 8
            cout.width(8);
            cout << proxyString;
            cout.unsetf(ios::right);

            cout << "| |";

            strcpy(proxyString, currentAddress, 20); // copying current address with limit 20
            cout.setf(ios::right);
            cout.width(20);
            cout << proxyString;
            cout.unsetf(ios::right);

            cout << " ---> ";

            strcpy(proxyString, address, 20); // copying new address with limit 20
            cout.setf(ios::left);
            cout.width(20);
            cout << address;
            cout.unsetf(ios::left);

            cout << "|";
            cout << endl;
            strcpy(currentAddress, address); // setting current address to new address
        }
    }

    // write function: prints the objects
    std::ostream &VehicleBasic::write(std::ostream &os) const
    {
        os << "| " << builtYear << " | " << lisencePlateNumber << " | " << currentAddress;
        return os;
    }

    // read function: prompts user for input and stores the values
    std::istream &VehicleBasic::read(std::istream &in)
    {
        cout << "Built year: ";
        in >> builtYear;
        cout << "License plate: ";
        in >> lisencePlateNumber;
        cout << "Current location: ";
        in >> currentAddress;
        return in;
    }

    //===================================
    // Helper Functions
    //===================================

    std::ostream &operator<<(std::ostream &os, const VehicleBasic &vehicle)
    {
        return vehicle.write();
    }
    std::istream &operator>>(std::istream &in, VehicleBasic &vehicle)
    {
        return vehicle.read();
    }
}

/* Citation and Sources...
Final Project Milestone 3
Module: Vehicle
Filename: Vehicle.cpp
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
#include "Utils.h"
#include "./Vehicle.h"
using namespace std;
namespace sdds
{
    //--------------------------------------------------------
    // constructors and distructors
    //--------------------------------------------------------

    // default constructor
    Vehicle::Vehicle() : ReadWritable()
    {

        setEmpty();
    }

    // 2 args constructor
    Vehicle::Vehicle(const char *lPlate, const char *mModel) : ReadWritable()
    {

        setEmpty();
        setNumberPlate(lPlate);
        setMakeModel(mModel);
    }

    // copy constructor
    Vehicle::Vehicle(Vehicle &rightHand)
    {

        setEmpty();
        *this = rightHand;
    }

    // distructor
    Vehicle::~Vehicle()
    {

        delete[] makeAndModel;
        makeAndModel = nullptr;
    }

    //--------------------------------------------------------
    // Protected Methods
    //--------------------------------------------------------

    //set empty: this functions sets object to an empty state
    void Vehicle::setEmpty()
    {

        numberPlate[0] = '\0';
        makeAndModel = nullptr;
        parkingSpot = 0;
    }

    // is empty : this functions returns true if object is empty and false otherwise.
    bool Vehicle::isEmpty() const
    {

        return (!(makeAndModel != nullptr && strlen(makeAndModel) > 2 && numberPlate != nullptr && strlen(numberPlate) > 0 && parkingSpot > -1));
    }
    
    // returns license plate number
    const char *Vehicle::getLicensePlate() const
    {

        return numberPlate;
    }

    // returns make and model
    const char *Vehicle::getMakeModel() const
    {

        return makeAndModel;
    }

    // sets the makeandmodel based on the arguement 
    void Vehicle::setMakeModel(const char *mModel)
    {

        if (mModel != nullptr && strlen(mModel) >= 2)
        {
            delete[] makeAndModel;
            makeAndModel = new char[strlen(mModel) + 1];
            strcpy(makeAndModel, mModel);
        }
        else
        {
            makeAndModel = nullptr;
        }
    }

    // sets the number plate based on the arguement
    void Vehicle::setNumberPlate(const char *lPlate)
    {
        numberPlate[0] = '\0';
        if (lPlate != nullptr && strlen(lPlate) > 0 && strlen(lPlate) < 9)
        {
            strcpy(numberPlate, lPlate, 8);
            for (int i = 0; i < strlen(numberPlate) && numberPlate[i] != '\0'; i++)
            {

                numberPlate[i] = toupper(numberPlate[i]);
            }
        }
    }

    //--------------------------------------------------------
    // operator overloading
    //--------------------------------------------------------
   
    Vehicle &Vehicle::operator=(Vehicle &rightHand)
    {

        if (!(rightHand.isEmpty()) && this != &rightHand)
        {
            delete[] makeAndModel;
            makeAndModel = nullptr;
            setMakeModel(rightHand.makeAndModel);
            setNumberPlate(rightHand.numberPlate);
            this->parkingSpot = rightHand.parkingSpot;
        }
        return *this;
    }
    
    bool Vehicle::operator==(const Vehicle &rightHand) const
    {

        return (strcmp(this->numberPlate, rightHand.numberPlate) == 0);
    }
    
    bool Vehicle::operator==(const char *liscensePlate) const
    {
        bool equal = true;
        for (int i = 0; i < strlen(liscensePlate); i++)
        {
            if (numberPlate[i] != toupper(liscensePlate[i]))
            {
                equal = false;
            }
        }
        return equal;
    }

    //--------------------------------------------------------
    // Public  Methods
    //--------------------------------------------------------S
    
    // returns the parking spot
    int Vehicle::getParkingSpot() const
    {

        return parkingSpot;
    }

    // sets the parking spot 
    void Vehicle::setParkingSpot(int spot)
    {
        this->parkingSpot = spot;
    }

    // reads data from the console 
    void Vehicle::readFromConsole()
    {
        setNumberPlate(getValidLNumber());
        setMakeModel(getValidMakeAndModel());
    }

    // reads the data from a file 
    std::istream &Vehicle::readFromCsv(std::istream &istr)
    {
        int proxySpot = 0;
        char proxyString[61];
        proxyString[0] = '\0';
        istr >> proxySpot;
        setParkingSpot(proxySpot);
        istr.ignore(1000, ',');
        istr.getline(proxyString, 9, ',');
        setNumberPlate(proxyString);
        istr.getline(proxyString, 61, ',');
        setMakeModel(proxyString);
        return istr;
    }

    //--------------------------------------------------------
    // virtual functions
    //--------------------------------------------------------S
    
    // prints the object 
    std::ostream &Vehicle::write(std::ostream &ostr) const
    {

        if (!(this->numberPlate[0] == '\0' || this->makeAndModel == nullptr) && parkingSpot > -1)
        {
            writeType(ostr);
            if (isCsv())
            {
                ostr << getParkingSpot() << "," << getLicensePlate() << "," << getMakeModel() << ",";
            }
            else
            {
                ostr << "Parking Spot Number: ";
                if (parkingSpot > 0)
                {
                    ostr << parkingSpot;
                }
                else
                {
                    ostr << "N/A";
                }
                ostr << endl;
                ostr << "License Plate: " << getLicensePlate() << endl;
                ostr << "Make and Model: " << getMakeModel() << endl;
            }
        }
        else
        {
            ostr << "Invalid Vehicle Object" << endl;
        }
        return ostr;
    }

    // reads the data from inout stream and store it in the object 
    std::istream &Vehicle::read(std::istream &istr)
    {
        if (isCsv())
        {
            readFromCsv(istr);
        }
        else
        {
            readFromConsole();
        }
        return istr;
    }

}
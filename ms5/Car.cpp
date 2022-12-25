/* Citation and Sources...
Final Project Milestone 4
Module: Car
Filename: Car.cpp
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
#include "./Car.h"
using namespace std;
namespace sdds
{
    //--------------------------------------------------------
    // constructors and distructors
    //--------------------------------------------------------

    Car::Car() : Vehicle()
    {
        carwash = 0;
    }
    Car::Car(const char *lPlate, const char *mModel) : Vehicle(lPlate, mModel)
    {
        carwash = 0;
    }
    Car::Car(const Car &rightHand) : Vehicle(rightHand)
    {
        carwash = 0;
        *this = rightHand;
    }

    //--------------------------------------------------------
    // operator overloading
    //--------------------------------------------------------
    Car &Car::operator=(const Car &rightHand)
    {
        if (this != &rightHand && !rightHand.isEmpty())
        {
            (Vehicle &)*this = rightHand;
            carwash = rightHand.carwash;
        }
        return *this;
    }

    //--------------------------------------------------------
    // virtual functions
    //--------------------------------------------------------
    std::ostream &Car::writeType(std::ostream &ostr) const
    {
        if (isCsv())
        {
            ostr << "C,";
        }
        else
        {
            ostr << "Vehicle type: Car" << endl;
        }
        return ostr;
    }
    std::ostream &Car::write(std::ostream &ostr) const
    {
        if (getLicensePlate() != nullptr && getMakeModel() != nullptr)
        {
            Vehicle::write(ostr);
            if (isCsv())
            {

                ostr << carwash << endl;
            }
            else
            {
                if (carwash)
                {
                    ostr << "With Carwash" << endl;
                }
                else
                {
                    ostr << "Without Carwash" << endl;
                }
            }
        }
        else
        {
            ostr << "Invalid Car Object" << endl;
        }
        return ostr;
    }
    std::istream &Car::read(std::istream &istr)
    {
        char response[5];
        response[0] = 0;
        bool valid = false;
        if (isCsv())
        {

            Vehicle::read(istr);
            istr >> carwash;
            istr.ignore(1000, '\n');
        }
        else
        {
            cout << endl<<"Car information entry" << endl;
            Vehicle::read(istr);
            cout << "Carwash while parked? (Y)es/(N)o: ";
            do
            {
                istr >> response;
                istr.ignore(1000, '\n');
                if ((response[0] == 'y' || response[0] == 'Y' || response[0] == 'n' || response[0] == 'N') && strlen(response) == 1)
                {
                    valid = true;
                    if (response[0] == 'y' || response[0] == 'Y')
                    {
                        carwash = 1;
                    }
                    else
                    {
                        carwash = 0;
                    }
                }
                else
                {
                    cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
                }
            } while (!valid);
        }
        return istr;
    }
}
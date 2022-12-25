/* Citation and Sources...
Final Project Milestone 4
Module: Motorcycle
Filename: Motorcycle.cpp
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
#include "./Motorcycle.h"
using namespace std;
namespace sdds
{
    //--------------------------------------------------------
    // constructors and distructors
    //--------------------------------------------------------

    Motorcycle::Motorcycle() : Vehicle()
    {
        sideCar = 0;
    }
    Motorcycle::Motorcycle(const char *lPlate, const char *mModel) : Vehicle(lPlate, mModel)
    {
        sideCar = 0;
    }
    Motorcycle::Motorcycle(const Motorcycle &rightHand) : Vehicle(rightHand)
    {
        sideCar = 0;
        *this = rightHand;
    }

    //--------------------------------------------------------
    // operator overloading
    //--------------------------------------------------------
    Motorcycle &Motorcycle::operator=(const Motorcycle &rightHand)
    {
        if (this != &rightHand && !rightHand.isEmpty())
        {
            (Vehicle &)*this = rightHand;
            sideCar = rightHand.sideCar;
        }
        return *this;
    }

    //--------------------------------------------------------
    // virtual functions
    //--------------------------------------------------------
    std::ostream &Motorcycle::writeType(std::ostream &ostr) const
    {
        if (isCsv())
        {
            ostr << "M,";
        }
        else
        {
            ostr << "Vehicle type: Motorcycle" << endl;
        }
        return ostr;
    }
    std::ostream &Motorcycle::write(std::ostream &ostr) const
    {
        if (getLicensePlate() != nullptr && getMakeModel() != nullptr)
        {
            Vehicle::write(ostr);
            if (isCsv())
            {

                ostr << sideCar << endl;
            }
            else
            {
                if (sideCar)
                {
                    ostr << "With Sidecar"<< endl;
                }
            }
        }
        else
        {
            ostr << "Invalid Motorcycle Object" << endl;
        }
        return ostr;
    }
    std::istream &Motorcycle::read(std::istream &istr)
    {
        char response[5];
        response[0] = 0;
        bool valid = false;
        if (isCsv())
        {

            Vehicle::read(istr);
            istr >> sideCar;
            istr.ignore(1000, '\n');
        }
        else
        {
            cout <<endl<< "Motorcycle information entry" << endl;
            Vehicle::read(istr);
            cout << "Does the Motorcycle have a side car? (Y)es/(N)o: ";
            do
            {
                istr >> response;
                istr.ignore(1000, '\n');
                if ((response[0] == 'y' || response[0] == 'Y' || response[0] == 'n' || response[0] == 'N') && strlen(response) == 1)
                {
                    valid = true;
                    if (response[0] == 'y' || response[0] == 'Y')
                    {
                        sideCar = 1;
                    }
                    else
                    {
                        sideCar = 0;
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
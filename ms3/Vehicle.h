/* Citation and Sources...
Final Project Milestone 3
Module: Vehicle
Filename: Vehicle.h
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

#ifndef SDDS_VEHICLE_H__
#define SDDS_VEHICLE_H__
#include "./ReadWritable.h"
#define MAX_NUMBER_PLATE_LENGTH 8
namespace sdds
{
    class Vehicle : public ReadWritable
    {
        char numberPlate[MAX_NUMBER_PLATE_LENGTH + 1];
        char *makeAndModel;
        int parkingSpot;

    protected:
        //--------------------------------------------------------
        // Protected Methods
        //--------------------------------------------------------
        void setEmpty();
        bool isEmpty() const;
        const char *getLicensePlate() const;
        const char *getMakeModel() const;
        void setMakeModel(const char *mModel);
        void setNumberPlate(const char *lPlate);

    public:
        //--------------------------------------------------------
        // constructors and distructors
        //--------------------------------------------------------

        Vehicle();
        Vehicle(const char *lPlate, const char *mModel);
        Vehicle(Vehicle &rightHand);
        ~Vehicle();

        //--------------------------------------------------------
        // Public  Methods
        //--------------------------------------------------------
        int getParkingSpot() const;
        void setParkingSpot(int spot);
        void readFromConsole();
        std::istream &readFromCsv(std::istream &istr);

        //--------------------------------------------------------
        // operator overloading
        //--------------------------------------------------------
        Vehicle &operator=(Vehicle &rightHand);
        bool operator==(const Vehicle &rightHand) const;
        bool operator==(const char *liscensePlate) const;
        //--------------------------------------------------------
        // virtual functions
        //--------------------------------------------------------
        virtual std::ostream &write(std::ostream &ostr = std::cout) const;
        virtual std::istream &read(std::istream &istr = std::cin);
        virtual std::ostream &writeType(std::ostream &ostr = std::cout) const = 0;
    };

}
#endif
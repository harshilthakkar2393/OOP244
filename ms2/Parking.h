/* Citation and Sources...
Final Project Milestone 1
Module: Menu
Filename: parking.h
Version 1.0
Author Harshil Dineshbhai Thakkar
Revision History
-----------------------------------------------------------
Date Reason
2022/7/11 Preliminary release
2022/13/11 Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
*/
#ifndef SDDS_PARKING_H__
#define SDDS_PARKING_H__
#include "./Menu.h"
#include "./Utils.h"

namespace sdds
{
    class Parking
    {

        //---------------------------------------------
        // Data members
        //---------------------------------------------

        char *fileName;
        Menu parkingMenu;
        Menu vehicleSelection;
        bool isValid;

        //---------------------------------------------
        // Operator overloading : restricted
        //---------------------------------------------

        Parking(Parking &rightHand) = delete;
        Parking &operator=(Parking &rightHand) = delete;

        //---------------------------------------------
        // Member functions : private
        //---------------------------------------------

        // isEmpty function that returns true if the Parking is in an invalid empty State or false otherwise
        bool isEmpty();

        // This function does not receive or return anything and at this stage only prints (appropriate message)
        void parkingStatus();

        // displays the Vehicle Selection sub-menu
        void parkVehicle();

        // does not receive or return anything and only prints the corresponding message
        void returnVehicle();

        // does not receive or return anything and only prints the corresponding message
        void listParkedVehicles();

        // does not receive or return anything and only prints the corresponding message
        void findVehicle();

        // this option ends the parking application for the day
        bool closeParking();

        // this option ends the parking application temporarily
        bool exitParking();

        // loads data from a file
        bool loadData();

        // saves data in a file
        void save();

        // gets a valid response from the user
        bool validResponse();

    public:
        //---------------------------------------------
        // Constructors and distructor
        //---------------------------------------------

        // deafult constructor
        Parking();

        // one argument constructor
        Parking(const char *file);

        // distructor
        ~Parking();

        //---------------------------------------------
        // Member functions : public
        //---------------------------------------------

        // this function runs the entire application by calling other functions
        int run();
    };
}
#endif // !
/* Citation and Sources...
Final Project Milestone 1
Module: Menu
Filename: parking.cpp
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
#include <iostream>
#include "./Parking.h"

using namespace std;

namespace sdds
{
    //---------------------------------------------
    // Constructors and distructor
    //---------------------------------------------

    // deafult constructor
    Parking::Parking()
    {
        fileName = nullptr;
        isValid = false;
    }

    // one argument constructor
    Parking::Parking(const char *file)
    {
        fileName = nullptr;
        isValid = false;
        if (file != nullptr && strlen(file) > 0)//checking if file is valid
        {
            isValid = true;
            fileName = new char[strlen(file) + 1];
            strcpy(fileName, file);

            if (loadData())//checking if loading was sucessfull
            {
                isValid = true;

                // setting parking menu 
                parkingMenu = "Parking Menu, select an action:";
                parkingMenu << "Park Vehicle"
                            << "Return Vehicle"
                            << "List Parked Vehicles"
                            << "Find Vehicle"
                            << "Close Parking (End of day)"
                            << "Exit Program";

                // setting sub-menu    
                vehicleSelection = "Select type of the vehicle:";
                vehicleSelection.setIndent(1);
                vehicleSelection << "Car"
                                 << "Motorcycle"
                                 << "Cancel";
            }
        }
        else
        {
            cout << "Error in data file" << endl;
        }
    }

    // distructor
    Parking::~Parking()
    {
        if (!isEmpty())
        {
            save();
            delete[] fileName;
            fileName = nullptr;
        }
    }

    //---------------------------------------------
    // Member functions : private
    //---------------------------------------------

    // isEmpty function that returns true if the Parking is in an invalid empty State or false otherwise
    bool Parking::isEmpty()
    {
        return !isValid;
    }

    // This function does not receive or return anything and at this stage only prints (appropriate message)
    void Parking::parkingStatus()
    {
        cout << "****** Valet Parking ******" << endl;
    }

    // displays the Vehicle Selection sub-menu
    void Parking::parkVehicle()
    {
        switch (int(vehicleSelection))
        {
        case 1:
        {
            printFrame("Parking Car");
            break;
        }
        case 2:
        {
            printFrame("Parking Motorcycle");
            break;
        }
        case 3:
        {
            printFrame("Cancelled parking");
            break;
        }
        default:
        {
            break;
        }
        }
    }

    // does not receive or return anything and only prints the corresponding message
    void Parking::returnVehicle()
    {
        printFrame("Returning Vehicle");
    }

    // does not receive or return anything and only prints the corresponding message
    void Parking::listParkedVehicles()
    {
        printFrame("Listing Parked Vehicles");
    }

    // does not receive or return anything and only prints the corresponding message
    void Parking::findVehicle()
    {
        printFrame("Finding a Vehicle");
    }

    // this option ends the parking application for the day
    bool Parking::closeParking()
    {
        bool response =false;
        cout << "This will close the parking; All the vehicles will be removed!" << endl
             << "Are you sure? (Y)es/(N)o: ";
        response = validResponse();
        if (response)
        {
            cout << "Ending application!" << endl;
        }
        return response;
    }

    // this option ends the parking application temporarily
    bool Parking::exitParking()
    {
        bool response=false;
        cout << "This will terminate the application and save the data!" << endl
             << "Are you sure? (Y)es/(N)o: ";
        response = validResponse();
        if (response)
        {
            cout << "Exiting application!" << endl;
        }
        return response;
    }

    // loads data from a file
    bool Parking::loadData()
    {
        bool isLoaded = false;
        if (!isEmpty())
        {
            cout << "---------------------------------" << endl;
            cout << "loading data from " << fileName << endl;
            cout << "---------------------------------" << endl
                 << endl;
            isLoaded = true;
        }
        return isLoaded;
    }

    // saves data in a file
    void Parking::save()
    {
        if (!isEmpty())
        {
            cout << "---------------------------------" << endl;
            cout << "Saving data into " << fileName << endl;
            cout << "---------------------------------" << endl
                 << endl;
        }
    }

    // gets a valid response from the user
    bool Parking::validResponse()
    {
        bool validR = false;
        bool isYes = false;
        char option = '\0';
        while (!validR)
        {
            cin >> option;
            if (option == 'y' || option == 'Y')
            {
                validR = true;
                isYes = true;
            }
            else if (option == 'N' || option == 'n')
            {
                validR = true;
            }
            else
            {
                cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
            }
        }
        return isYes;
    }

    //---------------------------------------------
    // Member functions : public
    //---------------------------------------------

    // this function runs the entire application by calling other functions
    int Parking::run()
    {
        bool exit = false;
        int returnOption = 1;
        if (!isEmpty())
        {
            returnOption = 0;
            while (!exit)
            {
                parkingStatus();
                switch (int(parkingMenu))
                {
                case 1: // park vehicle
                {
                    parkVehicle();
                    break;
                }
                case 2: // return vehicle
                {
                    returnVehicle();
                    break;
                }
                case 3: // list parked vehicle
                {
                    listParkedVehicles();
                    break;
                }
                case 4: // find vehicle
                {
                    findVehicle();
                    break;
                }
                case 5: // close parking
                {
                    exit = closeParking();
                    break;
                }
                case 6: // exit parking
                {
                    exit = exitParking();
                    break;
                }
                default:
                {
                    break;
                }
                }
            }
        }
        return returnOption;
    }
}
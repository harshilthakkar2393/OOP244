/* Citation and Sources...
Final Project Milestone 2
Module: Menu
Filename: parking.cpp
Version 3.0
Author Harshil Dineshbhai Thakkar
Revision History
-----------------------------------------------------------
Date Reason
2022/7/11 Preliminary release
2022/6/12 Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
*/
#include <iostream>
#include <fstream>
#include "Utils.h"
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
        noOfSpots = 0;
        noOfParkedVehicles = 0;
        setVehiclesEmpty();
    }

    // 2 argument constructor
    Parking::Parking(const char *file, int noOfSpots)
    {
        fileName = nullptr;
        isValid = false;
        this->noOfSpots = 0;
        noOfParkedVehicles = 0;
        setVehiclesEmpty();

        if (file != nullptr && strlen(file) > 0) // checking if file is valid
        {
            isValid = true;
            fileName = new char[strlen(file) + 1];
            strcpy(fileName, file);

            if (loadData()) // checking if loading was sucessfull
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
            if (noOfSpots >= 10 && noOfSpots < 100)
            {
                this->noOfSpots = noOfSpots;
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

            for (int i = 0; i < noOfSpots; i++)
            {
                if (vehicles[i] != nullptr)
                {
                    vehicles[i]->deallocate();
                    delete vehicles[i];
                    vehicles[i] = nullptr;
                }
            }
        }
        delete[] fileName;
        fileName = nullptr;
    }

    //---------------------------------------------
    // Member functions : private
    //---------------------------------------------

    // returns next index or the empty parking spot
    int Parking::nextSpot()
    {
        int index = -1;
        bool found = false;
        for (int i = 0; i < maxNoOfSpots && !found; i++)
        {
            if (vehicles[i] == nullptr)
            {
                found = true;
                index = i;
            }
        }
        return index;
    }

    // returns the total available parking spots
    int Parking::availableSpots()
    {
        int count = 0;
        for (int i = 0; i < noOfSpots; i++)
        {
            if (vehicles[i] == nullptr)
            {
                count++;
            }
        }
        return count;
    }

    // returns the indes of the vehicle who's liscense plate matches the arguement
    int Parking::findIndex(const char *lplate)
    {
        bool found = false;
        int index = -1;
        for (int i = 0; i < noOfSpots && !found; i++)
        {
            if (vehicles[i])
            {

                if (vehicles[i]->operator==(lplate))
                {
                    found = true;
                    index = i;
                }
            }
        }
        return index;
    }
    // isEmpty function that returns true if the Parking is in an invalid empty State or false otherwise
    bool Parking::isEmpty()
    {
        return !isValid;
    }

    // sets all vehicle pointers to null
    void Parking::setVehiclesEmpty()
    {
        for (int i = 0; i < maxNoOfSpots; i++)
        {
            vehicles[i] = nullptr;
        }
    }
    // This function does not receive or return anything and at this stage only prints (appropriate message)
    void Parking::parkingStatus()
    {
        cout << "****** Valet Parking ******" << endl;
        cout << "*****  Available spots: ";
        cout.setf(ios::left);
        cout.width(4);
        cout << availableSpots();
        cout.unsetf(ios::left);
        cout << " *****" << endl;
    }

    // displays the Vehicle Selection sub-menu
    void Parking::parkVehicle()
    {
        if (availableSpots() > 0)
        {

            switch (int(vehicleSelection))
            {
            case 1:
            {
                int spot = nextSpot();
                vehicles[spot] = new Car();
                vehicles[spot]->setParkingSpot(spot + 1);
                vehicles[spot]->setCsv(false);
                vehicles[spot]->read();
                cout << endl
                     << "Parking Ticket" << endl;
                vehicles[spot]->write();
                cout << endl;
                break;
            }
            case 2:
            {
                int spot = nextSpot();
                vehicles[spot] = new Motorcycle();
                vehicles[spot]->setParkingSpot(spot + 1);
                vehicles[spot]->setCsv(false);
                vehicles[spot]->read();
                cout << endl
                     << "Parking Ticket" << endl;
                vehicles[spot]->write();
                cout << endl;
                break;
            }
            case 3:
            {
                cout << "Parking Cancelled" << endl;
                break;
            }
            default:
            {
                break;
            }
            }
        }
        else
        {
            cout << "Parking is full" << endl;
        }
        cout << "Press <ENTER> to continue....";
        cin.ignore(1000, '\n');
    }

    // does not receive or return anything and only prints the corresponding message
    void Parking::returnVehicle()
    {
        char proxyPlate[9];
        int index = -1;
        proxyPlate[0] = '\0';
        cout << "Return Vehicle" << endl;
        strcpy(proxyPlate, getValidLNumber());
        index = findIndex(proxyPlate);
        if (index > -1)
        {
            cout << endl
                 << "Returning:" << endl;
            vehicles[index]->setCsv(false);
            vehicles[index]->write();
            cout << endl;
            vehicles[index]->deallocate();
            delete vehicles[index];
            vehicles[index] = nullptr;
        }
        else
        {
            for (int i = 0; i < strlen(proxyPlate) && proxyPlate[i] != '\0'; i++)
            {
                proxyPlate[i] = toupper(proxyPlate[i]);
            }
            cout << endl
                 << "License plate " << proxyPlate << " Not found" << endl
                 << endl;
        }
        cout << "Press <ENTER> to continue....";
        cin.ignore(1000, '\n');
    }

    // does not receive or return anything and only prints the corresponding message
    void Parking::listParkedVehicles()
    {
        cout << "*** List of parked vehicles ***" << endl;

        for (int i = 0; i < noOfSpots; i++)
        {
            if (vehicles[i] != nullptr)
            {
                vehicles[i]->setCsv(false);
                vehicles[i]->write();
                cout << "-------------------------------" << endl;
            }
        }
        cout << "Press <ENTER> to continue....";
        cin.ignore(1000, '\n');
    }

    // does not receive or return anything and only prints the corresponding message
    void Parking::findVehicle()
    {
        char proxyString[9];
        int index = 0;
        proxyString[0] = '\0';
        cout << "Vehicle Search" << endl;
        strcpy(proxyString, getValidLNumber());
        index = findIndex(proxyString);
        if (index > -1)
        {
            cout << endl;
            cout << "Vechicle found: " << endl;
            vehicles[index]->setCsv(false);
            vehicles[index]->write();
            cout << endl;
        }
        else
        {
            for (int i = 0; i < strlen(proxyString) && proxyString[i] != '\0'; i++)
            {
                proxyString[i] = toupper(proxyString[i]);
            }
            cout << endl
                 << "License plate " << proxyString << " Not found" << endl
                 << endl;
        }
        cout << "Press <ENTER> to continue....";
        cin.ignore(1000, '\n');
    }

    // this option ends the parking application for the day
    bool Parking::closeParking()
    {
        bool response = false;
        if (isEmpty())
        {
            cout << "Closing Parking" << endl;
            response = true;
        }
        else
        {

            cout << "This will Remove and tow all remaining vehicles from the parking!" << endl
                 << "Are you sure? (Y)es/(N)o: ";
            response = validResponse();
            if (response)
            {
                cout << "Closing Parking" << endl;
                for (int i = 0; i < noOfSpots; i++)
                {
                    if (vehicles[i] != nullptr)
                    {

                        cout << endl;
                        cout << "Towing request" << endl;
                        cout << "*********************" << endl;
                        vehicles[i]->setCsv(false);
                        vehicles[i]->write();
                        vehicles[i]->deallocate();
                        delete vehicles[i];
                        vehicles[i] = nullptr;
                    }
                    noOfParkedVehicles = 0;
                }
            }
        }
        return response;
    }

    // this option ends the parking application temporarily
    bool Parking::exitParking()
    {
        bool response = false;
        cout << "This will terminate the program!" << endl
             << "Are you sure? (Y)es/(N)o: ";
        response = validResponse();
        if (response)
        {
            cout << "Exiting program!" << endl;
        }
        return response;
    }

    // loads data from a file
    bool Parking::loadData()
    {
        bool isLoaded = false;
        char c = 0;
        if (!isEmpty())
        {
            ifstream in(fileName);
            if (in.is_open())
            {
                do
                {
                    c = in.get();
                    if (c == 'M' || c == 'm')
                    {
                        Motorcycle proxy;
                        proxy.setCsv(true);
                        in.ignore(1);
                        proxy.read(in);
                        if (proxy.getParkingSpot() > -1 && proxy.getParkingSpot() < maxNoOfSpots)
                        {
                            vehicles[proxy.getParkingSpot() - 1] = new Motorcycle(proxy);
                        }
                    }
                    else if (c == 'C' || c == 'C')
                    {
                        Car proxy;
                        proxy.setCsv(true);
                        in.ignore(1);
                        proxy.read(in);
                        if (proxy.getParkingSpot() > -1 && proxy.getParkingSpot() < maxNoOfSpots)
                        {
                            vehicles[proxy.getParkingSpot() - 1] = new Car(proxy);
                        }
                    }
                    else
                    {
                    }
                } while (c != EOF);
                in.close();
                isLoaded = true;
            }
        }
        return isLoaded;
    }
    // saves data in a file
    void Parking::save()
    {
        ofstream out(fileName);
        if (out.is_open())
        {
            for (int i = 0; i < noOfSpots; i++)
            {
                if (vehicles[i] != nullptr)
                {
                    vehicles[i]->setCsv(true);
                    vehicles[i]->write(out);
                }
            }
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
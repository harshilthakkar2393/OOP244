/*
====================================================================
workshop -4 part -2
====================================================================
Name: Harshil Dineshbhai Thakkar
Student Id: 160431219
E-mail : hthakkar8@myseneca.ca
Date :10-10-2022
OOP244 NEE

--------------------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
====================================================================
*/
#include <iostream>
#include "TourBus.h"
using namespace std;

namespace sdds
{
    // if bus is valid then returns true , false otherwise .
    bool sdds::TourBus::validTour() const
    {
        bool isValid = false;
        if (noOfPassenger == PRIVATE_TOUR || noOfPassenger == MINI_TOUR_BUS || noOfPassenger == FULL_SIZE_BUS)
        {
            isValid = true;
        }
        return isValid;
    }

    // starts the tour . prints details of passangers if valid and borded , errors otherwise.
    void sdds::TourBus::startTheTour() const
    {
        bool isValid = false;
        bool isBoarded = true;
        isValid = validTour();
        isBoarded = IsBoarded();

        if (isValid && isBoarded)
        {
            cout << "Starting the tour...." << endl;
            displayTickets();
        }
        else if (isValid)
        {
            cout << "Cannot start the tour, the bus is not fully boarded!" << endl;
        }
    }

    // sets name of passengers.
    TourBus &sdds::TourBus::board()
    {
        char proxyString[41];
        proxyString[0] = '\0';
        cout << "Boarding " << noOfPassenger << " Passengers:" << endl;
        for (int i = 0; i < noOfPassenger; i++)
        {
            cout << i + 1 << "/" << noOfPassenger << "- Passenger Name: ";
            cin.getline(proxyString, 40);
            if (proxyString != nullptr)
            {
                ticket[i].issue(proxyString);
            }
        }

        return *this;
    }

    // displays all tickets in details in a formated form .
    void sdds::TourBus::displayTickets() const
    {
        cout << "Passenger List:" << endl;
        cout << "|Row | Passenger Name                           | Num |" << endl;
        cout << "+----+------------------------------------------+-----+" << endl;
        for (int i = 0; i < noOfPassenger; i++)
        {
            cout << "|";
            cout.setf(ios::right);
            cout.width(3);
            cout << i + 1;
            cout.unsetf(ios::right);
            cout << " ";
            ticket[i].display();
            cout << endl;
        }
        cout << "+----+------------------------------------------+-----+\n"
             << endl;
    }

    // returns true is bus is fully boarded , false otherwise.
    bool sdds::TourBus::IsBoarded() const
    {
        bool isBoarded = true;
        for (int i = 0; i < noOfPassenger; i++)
        {
            if (!(ticket[i].valid()))
            {
                isBoarded = false;
            }
        }
        return isBoarded;
    }

    // no arguement constructor
    sdds::TourBus::TourBus()
    {
        noOfPassenger = 0;
        ticket = nullptr;
    }

    // One arguement constructor
    sdds::TourBus::TourBus(int num)
    {
        noOfPassenger = num;
        ticket = nullptr;
        ticket = new TourTicket[num];
    }

    // distructor
    sdds::TourBus::~TourBus()
    {
        delete[] ticket;
    }
}
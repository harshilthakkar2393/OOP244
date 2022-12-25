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
#ifndef SDDS_TOURBUS_H_
#define SDDS_TOURBUS_H_
#include"TourTicket.h"
#define PRIVATE_TOUR 4
#define MINI_TOUR_BUS 16
#define FULL_SIZE_BUS 22 

namespace sdds
{
    class TourBus
    {
        int noOfPassenger;
        TourTicket* ticket;


        // displays all tickets in details in a formated form .
        void displayTickets()const;

        // returns true is bus is fully boarded , false otherwise.
        bool IsBoarded()const;
        
        public:
        
        // if bus is valid then returns true , false otherwise .
        bool validTour()const;

        // starts the tour . prints details of passangers if valid and borded , errors otherwise.
        void startTheTour()const;

        // sets name of passengers.
        TourBus& board();

        // no arguement constructor
        TourBus();

        // One arguement constructor 
        TourBus(int);
        
        // distructor
        ~TourBus();
    };
}
#endif
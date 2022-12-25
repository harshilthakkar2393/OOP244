/*
====================================================================
workshop -4 part -1
====================================================================
Name: Harshil Dineshbhai Thakkar
Student Id: 160431219
E-mail : hthakkar8@myseneca.ca
Date :04-10-2022
OOP244 NEE

--------------------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
====================================================================
*/
#include <iostream>
#include "Utils.h"
#include "Seat.h"

using namespace std;

namespace sdds
{
    //------------------------------
    // Attributes & Private methods
    //------------------------------

    // returns true if the row number and the seating letter, together correctly address a seat in the airplane
    bool sdds::Seat::validate(int row, char letter) const
    {
        bool isValid = false;
        if ((row >= 1 && row <= 4) && (letter == 'A' || letter == 'B' || letter == 'E' || letter == 'F')) // checking for buisness class
        {
            isValid = true;
        }
        else if ((row >= 7 && row <= 15) && (letter == 'A' || letter == 'B' || letter == 'C' || letter == 'D' || letter == 'E' || letter == 'F')) // checking for economy plus class
        {
            isValid = true;
        }
        else if ((row >= 20 && row <= 38) && (letter == 'A' || letter == 'B' || letter == 'C' || letter == 'D' || letter == 'E' || letter == 'F')) // checking for economy class
        {
            isValid = true;
        }
        else
        {
            isValid = false;
        }
        return isValid;
    }

    // allocates memory for passenger name and copies values into the allocated memory
    // returns the refrence of the current object
    Seat &sdds::Seat::alAndCp(const char *str)
    {
        int len = 0;
        this->passengerName = NULL;
        reset();
        if (str && strlen(str)>0)
        {
            len = strlen(str);
            this->passengerName = new char[len + 1];
            strcpy(this->passengerName, str, len);
        }
        return *this;
    }

    //------------------------------
    // Safe Empty state and Seating
    //------------------------------

    // This function resets the object into a safe empty state
    Seat &sdds::Seat::reset()
    {
        delete[] passengerName;
        passengerName = nullptr;
        seatRow = 0;
        seatLetter = '\0';
        return *this;
    }

    // returns if the object is in an empty state (true =empty / false= !empty)
    bool sdds::Seat::isEmpty() const
    {
        bool is_Empty = true;
        if (this->passengerName!=nullptr)
        {
            is_Empty = false;
        }
        return is_Empty;
    }

    // returns true if the seats are assigned and valid othervise false
    bool sdds::Seat::assigned() const
    {
        bool isAssigned = false;
        if (seatRow > 0 && seatLetter != '\0')
        {
            isAssigned = validate(seatRow, seatLetter);
        }
        return isAssigned;
    }

    //-----------------------------
    // Constructors and destructor
    //-----------------------------

    // No argument constructor
    sdds::Seat::Seat()
    {
        passengerName = nullptr;
        seatRow = 0;
        seatLetter = '\0';
    }

    // One argument constructor
    sdds::Seat::Seat(const char *passengerName)
    {
        alAndCp(passengerName);
        seatRow = 0;
        seatLetter = '\0';
    }

    // Three argument constructor
    sdds::Seat::Seat(const char *passengerName, int row, char letter)
    {
        alAndCp(passengerName);
        seatRow = row;
        seatLetter = letter;
    }

    // Destructor
    sdds::Seat::~Seat()
    {
        reset();
    }

    //----------------------------
    // Modifier and Query Methods
    //----------------------------

    // this function first validates the row and letter & if valid then sets the values else sets to zero.
    Seat &sdds::Seat::set(int row, char letter)
    {
        if (validate(row, letter))
        {
            this->seatRow = row;
            this->seatLetter = letter;
        }
        else
        {
            this->seatRow = 0;
            this->seatLetter = '\0';
        }
        return *this;
    }

    // Returns the row attribute value.
    int sdds::Seat::row() const
    {
        return this->seatRow;
    }

    // Returns the letter attribute value.
    char sdds::Seat::letter() const
    {

        return this->seatLetter;
    }

    // Returns the value of the passenger name pointer attribute.
    const char *sdds::Seat::passenger() const
    {
        return this->passengerName;
    }

    //--------------
    // Input/Output
    //--------------

    // prints the passenger and seat information
    std::ostream &sdds::Seat::display(std::ostream &coutRef) const
    {
        char proxyString[41];
        proxyString[0]='\0';
        if (!isEmpty())
        {
            strcpy(proxyString, this->passengerName, 40);
            coutRef.setf(ios::left);
            coutRef.fill('.');
            coutRef.width(40);
            coutRef << proxyString;
            coutRef.unsetf(ios::left);
            coutRef.fill(' ');
            coutRef << " ";
            if (validate(this->seatRow, this->seatLetter))
            {
                coutRef << this->row() << this->letter();
            }
            else
            {
                cout << "___";
            }
        }
        else
        {
            coutRef << "Invalid Seat!";
        }
        return coutRef;
    }

    // Extracts the passanger name, seat row letter and number in three local function scope variables
    std::istream &sdds::Seat::read(std::istream &cinRef)
    {
        reset();
        char proxyString[71];
        int proxyRow = 0;
        char proxyLetter = '\0';
        cinRef.getline(proxyString, 71, ',');
        if (!cin.fail())
        {
            if (proxyString!=nullptr)
            {
                *this = alAndCp(proxyString);
            }
            cinRef >> proxyRow >> proxyLetter;
            if (!cin.fail())
            {
                set(proxyRow, proxyLetter);
            }
            else
            {
                cinRef.clear();
                cinRef.ignore(10000, '\n');
            }
            cinRef.ignore(1000, '\n');
        }
        else
        {
            cinRef.ignore(10000, '\n');
        }
        return cinRef;
    }
}
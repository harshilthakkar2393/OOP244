/*
====================================================================
workshop -3 part -1
====================================================================
Name: Harshil Dineshbhai Thakkar
Student Id: 160431219
E-mail : hthakkar8@myseneca.ca
Date :30-09-2022
OOP244 NEE

--------------------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
i only took inspiration for the bubbleSort algorithm from geekforgeeks
link is provided near function definition
====================================================================
*/
#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_

namespace sdds
{
    class CC
    {
        char *cardHolderName;
        short int CVV;
        short int expMonth;
        short int expYr;
        unsigned long long creditCardNumber;
        // This function validates the credit card information .
        // it will return true if all the conditions are met, otherwise it will return false
        bool validate(const char *name,
                      unsigned long long cardNo,
                      short cvv,
                      short expMon,
                      short expYear) const;
        // This function prints a 16-digit number in a set of 4-digit numbers separated by spaces
        void prnNumber() const;

    public:
        // Sets the object to a safe empty state by setting all the values to zero and nullptr.
        void set();

        // it deallocates the cardholder's name and then calls the set() to set the object to a safe empty state.
        void cleanUp();

        // Returns if the CC object is in a safe empty state or not; by returning true if the cardholder name pointer attribute
        // of the object is nullptr, otherwise, it will return false.
        bool isEmpty() const;

        // it will dynamically keep a copy of the name in the name attribute and set the rest of the attributes to their corresponding values.
        void set(const char *cc_name, unsigned long long cc_no, short cvv, short expMon, short expYear);

        // this function will attempt to read all the values from the console
        // they will be validated and then stored in the object.
        // The function will return true if the values are stored in the object and false otherwise
        bool read();

        // displays data in a formatted from
        void display(int row = 0) const;
    };
}
#endif
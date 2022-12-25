/*
====================================================================
workshop -1 part -1 
====================================================================
Name: Harshil Dineshbhai Thakkar
Student Id: 160431219
E-mail : hthakkar8@myseneca.ca
Date :16-09-2022
OOP244 NEE  

--------------------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
====================================================================
*/

#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H

namespace sdds
{
    void flushkeys();
    bool ValidYesResponse(char ch);
    bool yes();
    void readCstr(char cstr[], int len);
    int readInt(int min, int max);
}

#endif
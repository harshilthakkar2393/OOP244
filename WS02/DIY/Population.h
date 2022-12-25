/*
====================================================================
workshop -2 part -2
====================================================================
Name: Harshil Dineshbhai Thakkar
Student Id: 160431219
E-mail : hthakkar8@myseneca.ca
Date :26-09-2022
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

namespace sdds {


//Loads data from a file, and returns true if data 
//was successfully loaded, false otherwise.
bool load(const char filename[]);

//prints data in a formated form
void display();

//deallocates dynamically allocated memory
void deallocateMemory();

}
#endif // SDDS_POPULATION_H_
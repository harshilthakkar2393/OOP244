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
#ifndef SDDS_UTILS_H_
#define SDDS_uTILS_H_
namespace sdds
{
    struct Population
    {
        char m_postal[4];
        int m_population;
    };
    //sorts the array in asscending  order using bubble sort algorithm based on population
     void bubbleSortPopulation(Population *newPopulation,int size);

}
#endif
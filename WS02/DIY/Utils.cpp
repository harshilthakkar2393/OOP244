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
#include<iostream>
#include"Utils.h"

using namespace std;
namespace sdds
{
    //sorts the array in asscending  order using bubble sort algorithm based on population
    // orignal inspiration taken from: https://www.geeksforgeeks.org/cpp-program-for-bubble-sort/
     void bubbleSortPopulation(Population *newPopulation,int size)
     {
        bool isUnsorted;
        Population proxyPopulation;
        do {
            isUnsorted = false;
            for (int i = 0; i < (size - 1); i++) 
            {
                if (newPopulation[i].m_population > newPopulation[i+1].m_population)
                {
                    isUnsorted = true;
                    for (; i < (size- 1); i++)
                     {
                        if (newPopulation[i].m_population > newPopulation[i+1].m_population) 
                        {
                            proxyPopulation=newPopulation[i];
                            newPopulation[i]=newPopulation[i+1];
                            newPopulation[i+1]=proxyPopulation;
                        }
                    }
                }
            }
        } while (isUnsorted);

     }
   
}
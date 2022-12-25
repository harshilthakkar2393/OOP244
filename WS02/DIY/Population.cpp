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
#include <iostream>
#include"Utils.h"
#include "File.h"
#include "Population.h"
using namespace std;
namespace sdds
{

    Population *newPopulation = nullptr;
        int totalNoOfRecords;

    // Loads data from a file, and returns true if data
    // was successfully loaded, false otherwise.
    bool load(const char filename[])
    {
        bool isOpened = openFile(filename);
        if (isOpened)
        {
            totalNoOfRecords = noOfRecords();
            newPopulation = new Population[totalNoOfRecords];
        }
         else
        {
            cout << "Could not open data file: FILENAME" << endl;
        }
        
       return  load(newPopulation,filename);
    }

    // prints data in a formated form
    void display()
    {
        int i=0;
        int totalPopulation=0;

        bubbleSortPopulation(newPopulation,totalNoOfRecords);//sorting the array before printing it 
        
        cout<<"Postal Code: population"<<endl;
        cout<<"-------------------------"<<endl;

        for(i=0;i<totalNoOfRecords;i++)
        {
            cout<<i+1<<"- "<<newPopulation[i].m_postal<<":  "<<newPopulation[i].m_population<<endl;
            totalPopulation+=newPopulation[i].m_population;//calculating total
        }
        cout<<"-------------------------"<<endl;
        cout<<"Population of Canada: "<<totalPopulation<<endl;
    }

    // deallocates dynamically allocated memory
    void deallocateMemory()
    {
        delete [] newPopulation;
    }

}
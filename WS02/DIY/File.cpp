/***********************************************************************
// OOP244 Workshop 2 p2: tester program
//
// File  File.cpp
// Version 1.0
// Date  2022/09/17
// Author   Fardad Soleimanloo
// Description
// This file is incomplete and to be completed by students
// Revision History
// -----------------------------------------------------------
// Name Harshil Thakkar  Date  26/09/2022  Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include "Utils.h"
#include "File.h"

using namespace std;
namespace sdds
{
    FILE *fptr;
    // Opens a file and keeps the file pointer in the File.cpp (file scope)
    bool openFile(const char filename[])
    {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }
    // Finds and returns the number of records kept in the file
    // to be used for the dynamic memory allocation of the records in the program
    int noOfRecords()
    {
        int noOfRecs = 0;
        char ch;
        while (fscanf(fptr, "%c", &ch) == 1)
        {
            noOfRecs += (ch == '\n');
        }
        rewind(fptr);
        return noOfRecs;
    }
    // Closes the open file
    void closeFile()
    {
        if (fptr)
            fclose(fptr);
    }
    
    // Loads data from a file, and returns true if data
    // was successfully loaded, false otherwise.
    bool load(Population *newPopulation, const char filename[])
    {
        int totalNoOfRecords = 0;
        int actualNoOfRecords = 0;
        bool isLoaded = false;
        int i = 0;
       
            totalNoOfRecords = noOfRecords();
           
            for (i = 0; i < totalNoOfRecords && feof(fptr) == 0; i++) // reading and storing data from file
            {
                fscanf(fptr, "%[^,],%d\n", newPopulation[i].m_postal, &newPopulation[i].m_population);
                actualNoOfRecords = i;
            }
            actualNoOfRecords++;
            if (actualNoOfRecords != totalNoOfRecords)
            {
                cout << "Error: incorrect number of records read; the data is possibly corrupted!" << endl;
            }
            else
            {
                isLoaded=true;
            }

        closeFile();
        return isLoaded;
    }

}
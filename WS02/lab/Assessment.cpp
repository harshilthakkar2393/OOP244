/*
====================================================================
workshop -2 part -1
====================================================================
Name: Harshil Dineshbhai Thakkar
Student Id: 160431219
E-mail : hthakkar8@myseneca.ca
Date :23-09-2022
OOP244 NEE

--------------------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
====================================================================
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Assessment.h"
#include "Utils.h"
using namespace std;

namespace sdds
{

    // Reads one integer from the fptr file into the value reference and returns true if
    // it was successful, otherwise, it will return false
    bool read(int &value, FILE *fptr)
    {
        bool isRead = false;
        int noOfAssessments = 0;
        if (fptr) // checks if file is valid / not empty
        {
            fscanf(fptr, "%d\n", &noOfAssessments);
            if (noOfAssessments > 0) // validating input data
            {
                isRead = true;
                value = noOfAssessments;
            }
        }
        return isRead;
    }

    // Reads one double from the fptr file into the value reference and returns true
    // if it was successful, otherwise, it will return false
    bool read(double &value, FILE *fptr)
    {
        bool isRead = false;
        double proxyNumber = 0.00;
        if (fptr) // checks if file is valid / not empty
        {
            fscanf(fptr, "%lf", &proxyNumber);
            if (proxyNumber > 0) // validating input data
            {
                isRead = true;
                value = proxyNumber;
            }
        }
        return isRead;
    }

    // Skips a comma and then reads a cstring no longer than 60 characters from the
    // fptr file into the address, `cstr`  and returns true if it was successful, otherwise, it will return false
    bool read(char *cstr, FILE *fptr)
    {
        bool isRead = false;
        char proxyString[61];
        proxyString[0] = '\0'; // checks if file is valid / not empty
        if (fptr)
        {

            fscanf(fptr, ",%60[^\n]\n", proxyString);
            if (strlen(proxyString) > 0) // validating input data
            {
                isRead = true;
                strcpy(cstr, proxyString);
            }
        }
        return isRead;
    }

    // First it will try to read a double value for the mark and a string for title into a temporary
    // local double variable and a 60 character lone cString (+1 for null).
    bool read(Assessment &asmnt, FILE *fptr)
    {
        bool isRead = false;
        double proxyNumber=0;
        char proxyString[61];
        proxyString[0]='\0';
        bool isNumRead=false;
        bool isStrRead=false;
        isNumRead=read(proxyNumber, fptr);
        isStrRead=read(proxyString, fptr);
        if (fptr) // checks if file is valid / not empty
        {
            if (isNumRead && isStrRead ) // checking if data has been extracted sucessfully
            {
                
                asmnt.m_mark = new double;
                asmnt.m_title = new char[strlen(proxyString) + 1];
                isRead = true;
                *asmnt.m_mark = proxyNumber;
                strcpy(asmnt.m_title, proxyString);
            }
        }
        return isRead;
    }

    // This function will receive a reference of a dynamic Assessment array and its size.
    // The function then will delete the dynamic Assessment array
    void freeMem(Assessment *&aptr, int size=0)
    {

        for (int i = 0; i < size; i++) // deleting individual data member
        {
            delete aptr[i].m_mark;
            delete[] aptr[i].m_title;       
        }
        delete[] aptr;
        aptr = nullptr;
    }

    // This read function receives a reference of an Assessment pointer (to hold a dynamic array)
    //  and a file pointer from which it will read the assessment records into a newly allocated dynamic array.
    int read(Assessment *&aptr, FILE *fptr)
    {
        int sizeOfRecords = 0;
        int actuallSize = 0;

        read(sizeOfRecords, fptr);
        aptr =nullptr;
        aptr = new Assessment[sizeOfRecords];

        for (int i = 0; i < sizeOfRecords && feof(fptr) == 0; i++) // reading and storing data from file
        {
            read(aptr[i], fptr);
            actuallSize = i;
        }
        actuallSize++;

        
        if (sizeOfRecords != actuallSize)
        {

            actuallSize = 0;
            freeMem(aptr, sizeOfRecords);
        }
        return actuallSize;
    }
}
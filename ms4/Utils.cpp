/***********************************************************************
// Utils Module
// File  utils.cpp
// Version 3.0
// Date 22/11/2022
// Author Harshil Thakkar
// Description
// Estra Classes and functions needed in the project
// Revision History
// -----------------------------------------------------------
// Name   Harshil Dineshbhai Thakkar         Date 13-11/2022           Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include <cctype>
#include "Utils.h"
using namespace std;
namespace sdds
{
    char proxyString[61];

    //==================================================================================
    // Code/functions Provided by professors in previous workshops
    //==================================================================================
    int strlen(const char *str)
    {
        int len = 0;
        while (str[len])
        {
            len++;
        }
        return len;
    }
    void strcpy(char *des, const char *src, int len)
    {
        int i;
        for (i = 0; src[i] && (len < 0 || i < len); i++)
        {
            des[i] = src[i];
        }
        des[i] = 0; // turning the char array des in to a cString by null terminating it.
    }
    int strcmp(const char *s1, const char *s2)
    {
        int i;
        for (i = 0; s1[i] && s2[i] && s1[i] == s2[i]; i++)
            ;
        return s1[i] - s2[i];
    }
    //==================================================================================

    //==================================================================================
    // Helper fucntions for ms2
    //==================================================================================
    void printFrame(const char *title)
    {
        cout << "---------------------------------" << endl;
        cout << title << endl;
        cout << "---------------------------------" << endl
             << endl;
    }
    //==================================================================================
    // Helper fucntions for ms3.2
    //==================================================================================

    const char *getValidLNumber()
    {
        proxyString[0] = '\0';
        bool valid = false;
        cout << "Enter License Plate Number: ";
        do
        {
            cin.getline(proxyString,8);
            if (strlen(proxyString) > 0 && strlen(proxyString) <= 8)
            {
                valid = true;
            }
            else
            {
                cout << "Invalid License Plate, try again: ";
            }
        } while (!valid);
        return proxyString;
    }
    const char *getValidMakeAndModel()
    {
        proxyString[0] = '\0';
        bool valid = false;
        cout << "Enter Make and Model: ";
        do
        {
            cin.getline(proxyString,60);
            if (strlen(proxyString) >= 2 && strlen(proxyString) <= 60)
            {
                valid = true;
            }
            else
            {
                cout << "Invalid Make and model, try again: ";
            }
        } while (!valid);
        return proxyString;
    }
}
/***********************************************************************
// Utils Module
// File  utils.cpp
// Version 1.0
// Date 6/11/2022
// Author Harshil Thakkar
// Description
// Estra Classes and functions needed in the project
// Revision History
// -----------------------------------------------------------
// Name   Harshil Dineshbhai Thakkar         Date 6-11/2022           Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include "Utils.h"

namespace sdds
{
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

}
/***********************************************************************
// Utils Module
// File  utils.h
// Version 3.0
// Date 22/11/2022
// Author Harshil Dineshbhai Thakkar
// Description
// Estra Classes and functions needed in the project
// Revision History
// -----------------------------------------------------------
// Name Harshil Dineshbhai THakkar  Date  13/11/2022          Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_UTILS_H__
#define SDDS_UTILS_H__
namespace sdds
{
    //==================================================================================
    // Code/functions Provided by professors in previous workshops
    //==================================================================================
    int strlen(const char *str);
    // copies up to len chars from src to des
    // if len is negative, it will copy up to null char
    // resulting a cstring in des in any case
    void strcpy(char *des, const char *src, int len = -1);
    int strcmp(const char *s1, const char *s2);
    //==================================================================================

    //==================================================================================
    // Helper fucntions for ms2
    //==================================================================================
    void printFrame(const char *title);

    //==================================================================================
    // Helper fucntions for ms3.2
    //==================================================================================
    const char *getValidLNumber();
    const char *getValidMakeAndModel();

}
#endif // !

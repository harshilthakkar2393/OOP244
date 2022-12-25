/*
====================================================================
workshop -1 part -2 
====================================================================
Name: Harshil Dineshbhai Thakkar
Student Id: 160431219
E-mail : hthakkar8@myseneca.ca
Date :21-09-2022
OOP244 NEE  

--------------------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
====================================================================
*/
#ifndef SDDS_WORD_H
#define SDDS_WORD_H

namespace sdds
{
const int MAX_NO_OF_DEFINE =8;
const int  MAX_NO_OF_CHAR_FOR_TYPES= 64;
const int  MAX_NO_OF_CHAR_FOR_DEF= 1024;
    struct Word
    {
        char word[MAX_NO_OF_CHAR_FOR_TYPES + 1];
        char typeOfWord [MAX_NO_OF_DEFINE][MAX_NO_OF_CHAR_FOR_TYPES + 1];
        char define[MAX_NO_OF_DEFINE] [MAX_NO_OF_CHAR_FOR_DEF + 1];
        int numberOfDefine;
    };

}

#endif
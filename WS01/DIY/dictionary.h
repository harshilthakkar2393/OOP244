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
#ifndef SDDS_DICTIONARY_H
#define SDDS_DICTIONARY_H
#include "word.h"

namespace sdds
{
const int  MAX_NO_OF_WORDS =100;
    struct Dictionary
    {
        Word words[MAX_NO_OF_WORDS];
        int totalNoOfWords;
    };

    // Loads from a file a set of words with their definition.
    int LoadDictionary(const char *filename);

    // Save all the words existing in the dictionary into a file.
    void SaveDictionary(const char *filename);

    // Searches in the dictionary for the word and display all the definitions found.
    void DisplayWord(const char *word);

    // Adds a word to the dictionary.
    void AddWord(const char *word, const char *type, const char *definition);

    // Searches in the dictionary for a word and update its definition and type.
    int UpdateDefinition(const char *word, const char *type, const char *definition);

    int findWord(const char *word);
    void clearBuffer();
}

#endif
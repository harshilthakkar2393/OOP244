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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "dictionary.h"

using namespace std;

namespace sdds
{
    Dictionary dictionary;
    FILE *fptr = nullptr;
    // Loads from a file a set of words with their definition.
    int LoadDictionary(const char *filename)
    {
        dictionary={0};
        int index = -1;
        FILE *fptr = nullptr;
        char proxyLine[MAX_NO_OF_CHAR_FOR_DEF + 1];
        int isLoaded = 0;
        int numberOfWords = 0;
        int numberOfDefines = 0;
        if (filename != nullptr)
        {
            fptr = fopen(filename, "r");
        }
        if (fptr) // checks is the pointer is not a nullptr
        {
            // reading file until the end of file or max capacity of struct is reached
            while (numberOfWords < MAX_NO_OF_WORDS && feof(fptr) == 0)
            {
                // reads each line and stores in a proxyLine for further analysis
                fgets(proxyLine, MAX_NO_OF_CHAR_FOR_DEF + 1, fptr);

                // checks if first char of line is a tab ('\t')
                if (proxyLine[0] == 9)
                {
                    index = -1;

                    // searches for ':' char and stores its position
                    for (int i = 0; (unsigned)i < strlen(proxyLine) && index == -1; i++)
                    {
                        if (proxyLine[i] == 58) // checks if the char is a ':'
                        {
                            index = i; // stores the index
                        }
                    }

                    // seperates the type of the word and stores it
                    for (int i = 0; i < index - 1; i++)
                    {
                        dictionary.words[numberOfWords - 1].typeOfWord[numberOfDefines][i] = proxyLine[i + 1];
                    }

                    // remove new line character in the end of the string
                    proxyLine[strlen(proxyLine) - 1] = '\0'; 

                    // seperates the defination of the word and stores it
                    for (int i = 1; (unsigned)i < strlen(proxyLine); i++)
                    {
                        dictionary.words[numberOfWords - 1].define[numberOfDefines][i - 1] = proxyLine[index + 1 + i];
                    }

                    dictionary.words[numberOfWords - 1].numberOfDefine = numberOfDefines + 1;
                    numberOfDefines++;
                    strcpy(proxyLine, "\0"); 
                }

                // checking if the first char is a letter (a-z,A-Z)
                else if (proxyLine[0] >= 97 && proxyLine[0] <= 122)
                {
                    // storing the word
                    for (int i = 0; (unsigned)i < strlen(proxyLine) - 1; i++)
                    {
                        dictionary.words[numberOfWords].word[i] = proxyLine[i];
                    }

                    dictionary.totalNoOfWords = numberOfWords + 1;
                    numberOfDefines = 0;
                    numberOfWords++;
                }
            }
        }
        else
        {
            isLoaded = 1;
        }

        if (fptr)
        {

            fclose(fptr);
        }
        return isLoaded;
    }

    // Save all the words existing in the dictionary into a file.
    void SaveDictionary(const char *filename)
    {

        FILE *fptr = nullptr;
        if (filename != nullptr)
        {
            fptr = fopen(filename, "w");
        }
        for (int i = 0; i < MAX_NO_OF_WORDS; i++) // saves each word
        {
            if (strlen(dictionary.words[i].word) != 0) 
            {
                fprintf(fptr, "%s\n", dictionary.words[i].word);
                for (int j = 0; j < MAX_NO_OF_DEFINE; j++) // saves each defination and the type
                {
                     if (strlen(dictionary.words[i].define[j]) != 0)
                    {

                        fprintf(fptr, "\t%s: %s\n", dictionary.words[i].typeOfWord[j], dictionary.words[i].define[j]);
                    }
                }
                fprintf(fptr, "\n");
            }
        }

        if (fptr)
        {

            fclose(fptr);
        }
    }

    // Searches in the dictionary for the word and display all the definitions found.
    void DisplayWord(const char *word)
    {
        int index = findWord(word);
        if (index != -1) // if word exists , then displays word , type and defines
        {
            cout << "FOUND: [" << word << "] has [" << dictionary.words[index].numberOfDefine << "] definitions:" << endl;
            for (int i = 0; i < dictionary.words[index].numberOfDefine; i++)
            {
                cout << i + 1 << ". {" << dictionary.words[index].typeOfWord[i] << "} " << dictionary.words[index].define[i] << endl;
            }
        }
        else
        {
            cout << "NOT FOUND: word [" << word << "] is not in the dictionary." << endl;
        }
    }

    // Adds a word to the dictionary.
    void AddWord(const char *word, const char *type, const char *definition)
    {
        int index = findWord(word);
        if (index == -1) // checks if word exists , if not then adds it
        {

            strcpy(dictionary.words[(dictionary.totalNoOfWords)].word, word);
            strcpy(dictionary.words[(dictionary.totalNoOfWords)].typeOfWord[(dictionary.words[(dictionary.totalNoOfWords)].numberOfDefine)], type);
            strcpy(dictionary.words[(dictionary.totalNoOfWords)].define[(dictionary.words[(dictionary.totalNoOfWords)].numberOfDefine)], definition);
            dictionary.totalNoOfWords++;
            dictionary.words[(dictionary.totalNoOfWords - 1)].numberOfDefine++;
        }
        else // if word exists ,then adds a new defination
        {
            strcpy(dictionary.words[index].typeOfWord[(dictionary.words[index].numberOfDefine)], type);
            strcpy(dictionary.words[index].define[(dictionary.words[index].numberOfDefine)], definition);
            dictionary.words[index].numberOfDefine++;
        }
    }

    // Searches in the dictionary for a word and update its definition and type.
    int UpdateDefinition(const char *word, const char *type, const char *definition)
    {
        int isUpdated = 0;
        int definNo = 1;
        int index = findWord(word);
        if (index != -1)
        {
            if (dictionary.words[index].numberOfDefine > 1) // checks is word has multiple definations
            {
                cout << "The word [" << word << "] has multiple definitions:" << endl;
                for (int i = 0; i < dictionary.words[index].numberOfDefine; i++)
                {
                    cout << i + 1 << ". {" << dictionary.words[index].typeOfWord[i] << "} " << dictionary.words[index].define[i] << endl;
                }
                cout << "Which one to update? ";
                cin >> definNo;
            }

            strcpy(dictionary.words[index].typeOfWord[definNo - 1], type);
            strcpy(dictionary.words[index].define[definNo - 1], definition);
            isUpdated = 1;
        }
        return isUpdated;
    }

    // finds the passed word from the array , returns -1 if not found
    int findWord(const char *word)
    {
        int found = 0;
        int index = -1;
        for (int i = 0; i < MAX_NO_OF_WORDS && !found; i++)
        {
            if (strcmp(word, dictionary.words[i].word) == 0)
            {
                found = 1;
                index = i;
            }
        }
        return index;
    }

}

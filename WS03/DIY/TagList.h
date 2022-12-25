/*
====================================================================
workshop -3 part -2
====================================================================
Name: Harshil Dineshbhai Thakkar
Student Id: 160431219
E-mail : hthakkar8@myseneca.ca
Date :3-10-2022
OOP244 NEE

--------------------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
i only took inspiration for the bubbleSort algorithm from geekforgeeks
link is provided near function definition
====================================================================
*/
#ifndef SDDS_TAGLIST_H_
#define SDDS_TAGLIST_H_
#include "NameTag.h"

namespace sdds
{
    class TagList
    {
        NameTag *NameList;
        int longestName;
        int noOfRecs;

    public:
        // Sets the TagList to an empty state
        void set();

        // Calls CleanUp() and then dynamically creates an array of num NameTags.
        void set(int num);

        // Adds up to num (of the set method) NameTags to the TagList.
        void add(const NameTag &nt);

        // Prints all the tags with the same size that is the frame size of the longest name in the list.
        void print();

        // Deallocates the NameTags and put the TagList back to a safe empty state.
        void cleanup();
    };
}
#endif
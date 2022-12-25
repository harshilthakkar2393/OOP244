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

#include <iostream>
#include "Utils.h"
#include "TagList.h"
using namespace std;

namespace sdds
{
    int j = 0;

    // Sets the TagList to an empty state
    void sdds::TagList::set()
    {
        longestName = 0;
        noOfRecs = 0;
    }

    // Calls CleanUp() and then dynamically creates an array of num NameTags.
    void sdds::TagList::set(int num)
    {
        cleanup();
        noOfRecs = num;
        NameList = new NameTag[noOfRecs];
    }

    // Adds up to num (of the set method) NameTags to the TagList.
    void sdds::TagList::add(const NameTag &nt)
    {
        int len = strlen(nt.charName);
        NameList[j].set(nt.charName);
        if (len > longestName)
        {
            longestName = len;
        }
        j++;
    }

    // Prints all the tags with the same size that is the frame size of the longest name in the list.
    void sdds::TagList::print()
    {
        for (int i = 0; i < noOfRecs; i++)
        {
            for (int k = 0; k < longestName + 4; k++)
            {
                cout << "*";
            }
            cout << endl;
            cout.setf(ios::left);
            cout << "* ";
            cout.width(longestName);
            cout << NameList[i].charName;
            cout << " *" << endl;
            for (int k = 0; k < longestName + 4; k++)
            {
                cout << "*";
            }
            cout << endl;
        }
        cout.unsetf(ios::left);
    }

    // Deallocates the NameTags and put the TagList back to a safe empty state.
    void sdds::TagList::cleanup()
    {
        if (noOfRecs)
        {
            delete[] NameList;
            NameList = nullptr;
            set();
        }
    }
}
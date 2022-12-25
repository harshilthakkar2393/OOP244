/* Citation and Sources...
Final Project Milestone 1
Module: Menu
Filename: Menu.cpp
Version 1.0
Author Harshil Dineshbhai Thakkar
Revision History
-----------------------------------------------------------
Date Reason
2020/31/10 Preliminary release
2020/6/11 Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
*/

#include <iostream>
#include "Menu.h"
#include "Utils.h"

using namespace std;

namespace sdds
{
    //=================================================
    // Class: MenuItem
    //=================================================

    //---------------------------------------------
    // Member functions
    //---------------------------------------------

    // Display: prints the title/ MenuItem
    std::ostream &MenuItem::display(std::ostream &coutRef) const
    {
        coutRef << title << endl;
        return coutRef;
    }

    //---------------------------------------------
    // Constructors
    //---------------------------------------------

    // Zero arg constructor: initializes the title to an empty state.
    MenuItem::MenuItem()
    {
        title[0] = '\0';
    }

    //  1 arg constructor: validates the passed string and assigns to title only if valid else sets to empty state.
    //  if passed strings is longer than 50 chars , it truncates value to 50 chars .
    MenuItem::MenuItem(char *string)
    {
        if (string != nullptr && strlen(string) > 0)
        {
            strcpy(title, string, 50);
        }
        else
        {
            title[0] = '\0';
        }
    }

    //=================================================
    // Class: Menu
    //=================================================

    //---------------------------------------------
    // Constructors
    //---------------------------------------------

    // Zero arg constructor: initializes the object to empty state.
    Menu::Menu()
    {
        noOfItems = 0;
        indent = 0;
        title[0] = '\0';
    }

    // 2 args constructor : validates the passed arguments and assigns to data members only if valid ,
    // else sets to an invalid empty state
    Menu::Menu(const char *string, int idnt)
    {
        noOfItems = 0;
        if (string != nullptr) // checking if the string is not null
        {
            strcpy(title, string, 50);
            if (idnt > INVALID)
            {
                indent = idnt;
            }
            else
            {
                indent = 0;
            }
        }
        else
        {
            title[0] = '\0';
            indent = 0;
            noOfItems = INVALID; // setting to empty invalid state
        }
    }

    //---------------------------------------------
    // Operator overloading
    //---------------------------------------------

    // Bool casting operator: returns true if object is valid and false otherwise
    Menu::operator bool() const
    {
        return (noOfItems > 0);
    }

    // Bool casting operator: returns the user's selected option
    Menu::operator int() const
    {
        return run();
    }
    // = operator : assigns the righthand oprand to title.
    Menu &Menu::operator=(const char *rightHand)
    {
        strcpy(title, rightHand, 50);
        return *this;
    }

    // << (left shift) operator : adds a new Menu Item
    Menu &Menu::operator<<(const char *string)
    {
        add(string);
        return *this;
    }

    //---------------------------------------------
    // Member functions : private
    //---------------------------------------------

    bool Menu::isEmpty()
    {
        return !(*this);
    }
    std::ostream &Menu::printIndent(std::ostream &coutRef) const
    {
        for (int i = 0; i < (indent * SPACES_PER_VALUE); i++)
        {
            coutRef << " ";
        }
        return coutRef;
    }
    std::istream &Menu::read(int &selection, std::istream &cinRef) const
    {
        bool valid = false;
        do
        {
            cinRef >> selection;
            if (cinRef.fail()) // checking if entered data is not an integer
            {
                cout << "Invalid Integer, try again: ";
                cinRef.clear();
                cinRef.ignore(1000, '\n');
            }
            else if (selection > noOfItems || selection < 1) // checking if the entered data is an integer but in valid option
            {
                cout << "Invalid selection, try again: ";
            }
            else
            {
                valid = true;
            }
        } while (!valid);
        cinRef.ignore();
        return cinRef;
    }
    //---------------------------------------------
    // Member functions : public
    //---------------------------------------------

    // Display : the menu and its menu items if valid and not empty else shows respective error messages.
    std::ostream &Menu::display(std::ostream &coutRef) const
    {
        if (noOfItems == INVALID) // checking if menu is invalid
        {
            coutRef << "Invalid Menu!" << endl;
        }
        else if (!(*this)) // checking if menu is valid but empty
        {
            coutRef << title << endl;
            coutRef << "No Items to display!" << endl;
        }
        else // menu is valid and non empty
        {

            printIndent();
            coutRef << title << endl;
            for (int i = 0; i < noOfItems; i++)
            {
                printIndent();
                coutRef << i + 1 << "- ";
                items[i].display();
            }
            printIndent();
            coutRef << "> ";
        }
        return coutRef;
    }

    // Clear: resets the object to empty and valid state.
    Menu &Menu::clear()
    {
        for (int i = 0; i < MAX_NO_OF_ITEMS; i++) // resetting menu items to empty
        {
            items[i].title[0] = '\0';
        }
        noOfItems = 0;
        indent = 0;
        return *this;
    }

    // add: this function takes a char string as arguement and adds it to the object if valid else sets it to invalid state.
    void Menu::add(const char *string)
    {
        if (string && strlen(string) > 0 && noOfItems < MAX_NO_OF_ITEMS && noOfItems > INVALID)
        {
            strcpy(items[noOfItems].title, string, 50);
            noOfItems++;
        }
        else
        {
            noOfItems = INVALID;
        }
    }

    // run: this function runs the menu by first displaying the menu and the asking user for a valid selection and returns the selection.
    int Menu::run() const
    {
        int selection = 0;
        this->display(); // calling display function to display menu

        if (noOfItems > 0) // checking if menu is not empty or invalid
        {
            read(selection);
        }
        return selection;
    }
}
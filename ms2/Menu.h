/* Citation and Sources...
Final Project Milestone 1
Module: Menu
Filename: Menu.h
Version 1.1
Author Harshil Dineshbhai Thakkar
Revision History
-----------------------------------------------------------
Date Reason
2022/31/10 Preliminary release
2022/13/11 Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
*/

#ifndef SDDS_MENU_H__
#define SDDS_MENU_H__
#define MAX_CHAR_LENGTH 50
#define MAX_NO_OF_ITEMS 10
#define SPACES_PER_VALUE 4
#define INVALID -1
#include<iostream>

namespace sdds
{
    //=================================================
    // Class: MenuItem
    //=================================================
    class MenuItem
    {
        //---------------------------------------------
        // Data members
        //---------------------------------------------
        char title[MAX_CHAR_LENGTH + 1];

        //---------------------------------------------
        // Member functions
        //---------------------------------------------
        std::ostream &display(std::ostream &coutRef = std::cout) const;

        //---------------------------------------------
        // Constructors
        //---------------------------------------------
        MenuItem();
        MenuItem(char *string);

        //---------------------------------------------
        // Operator overloading
        //---------------------------------------------
        MenuItem &operator=(MenuItem &rightHand) = delete;

        //---------------------------------------------
        // Friend classes
        //---------------------------------------------
        friend class Menu;
    };

    //=================================================
    // Class: Menu
    //=================================================
    class Menu
    {
        //---------------------------------------------
        // Data members
        //---------------------------------------------
        char title[MAX_CHAR_LENGTH + 1];
        MenuItem items[MAX_NO_OF_ITEMS];
        int noOfItems;
        int indent;

        //---------------------------------------------
        // Member functions : private
        //---------------------------------------------
        std::ostream &printIndent(std::ostream &coutRef = std::cout) const;
        std::istream &read(int &selection, std::istream &cinRef = std::cin) const;
        bool isEmpty();

        //---------------------------------------------
        // Restricted operators
        //---------------------------------------------
        Menu &operator=(Menu &rightHand) = delete;
        Menu(Menu &rightHand) = delete;

    public:
        //---------------------------------------------
        // Constructors
        //---------------------------------------------
        Menu();
        Menu(const char *string, int idnt = 0);

        //---------------------------------------------
        // Member functions : public
        //---------------------------------------------
        std::ostream &display(std::ostream &coutRef = std::cout) const;
        Menu &clear();
        void add(const char *string);
        int run() const;
        void setIndent(int idnt);

        //---------------------------------------------
        // Operator overloading
        //---------------------------------------------
        Menu &operator<<(const char *string);
        Menu &operator=(const char *rightHand);
        operator bool() const;
        operator int() const;
    };

}
#endif // !
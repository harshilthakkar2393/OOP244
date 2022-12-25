/* ------------------------------------------------------
Final Project Milestone 1
Module: Menu
Filename: main.cpp
Version 1.0
Author	Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Date      Reason
-----------------------------------------------------------*/

#include <iostream>
#include "Utils.h"
#include "Menu.h"
using namespace std;
using namespace sdds;
int showSelection(int n);
void prompt(const char* message);
void pause();
void testMenus(const Menu& m, const Menu& sub1, const Menu& sub2);
void TT(const char* title);
int main() {
   TT("M1T1: constructors");
   Menu mainMenu("** Main Menu **");
   Menu subMenu1("** Sub Menu One **", 1);
   Menu subMenu2("** Sub Menu **", 2);
   Menu tempMenu("** Temp **");
   Menu invMenu("** To test Invalid Menu **");

   TT("M1T2: operator<< adding MenuItems");
   tempMenu << "One" << "Two" << "three";

 

   TT("M1T3: Menu::run()");
   prompt("Do the following: \nabc <ENTER>\n0 <ENTER>\n4 <ENTER>\n3 <ENTER>");
   cout << tempMenu.run() << " selected!" << endl;
   pause();


   TT("M1T4: Reseting Menu title and running an empty menu with no Items");
   tempMenu.clear();
   tempMenu = "** New Title **"; //<<---- Assignment
   cout << tempMenu.run() << " returned by the Menu with no Items." << endl;
   pause();

   TT("M1T5: Menu::add() and operator<<");
   mainMenu.add("Option one");
   mainMenu.add("Option Two");
   mainMenu.add("Sub Options");
   mainMenu.add("Option four");
   mainMenu.add("Exit");
   subMenu1 << "Selection one" << "Sub Selections two" << "Selection three" << "Selection four";
   subMenu2 << "The first" << "The second" << "The third";



   TT("M1T6: Submenu and indentation display");
   testMenus(mainMenu, subMenu1, subMenu2);

   TT("M1T7: operator bool()");
   if (mainMenu) {
      cout << "The mainMenu is valid and usable." << endl;
   }

   TT("M1T8: Invalid Menu and its usage");
   mainMenu.add(nullptr);
   if (!mainMenu) {
      cout << "The mainMenu is invalid(empty) and not usable." << endl;
   }
   mainMenu.run();
   mainMenu.display();
   
   TT("M1T9: Adding invalid string to render Menu invalid");
   invMenu << nullptr << "This should not be added" << "This shouldn't be added either";
   invMenu.run();
   invMenu.display();
   return 0;
}
int showSelection(int n) {
   cout << "You selected " << n << "." << endl;
   return n;
}

void prompt(const char* message) {
   cout << message << endl;
}
void pause() {
   cout << "Press enter to continue..." << endl;
   cin.ignore(1000, '\n');
}
void testMenus(const Menu& m, const Menu& sub1, const Menu& sub2) {
   int selection;
   prompt("Do the following:\n2 <ENTER>\n3 <ENTER>");
   while ((selection = m.run()) != 5) {
      showSelection(selection);
      if (selection == 3) {
         prompt("Do the following:\n2 <ENTER>");
         if (showSelection(sub1) == 2) {
            prompt("Do the following:\n3 <ENTER>\n5 <ENTER>");
            showSelection(sub2);
         }
      }
   }
}
void TT(const char* title) {
   cout << "******************************************************************" << endl;
   cout << title << endl;
   cout << "==================>" << endl;
}


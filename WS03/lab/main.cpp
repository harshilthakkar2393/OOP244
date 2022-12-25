/***********************************************************************
// OOP244 Workshop 3 p1: tester program
//
// File	main.cpp
// Version 1.0
// Date	2022/09/23
// Author	Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include <fstream> // works like istream (cin) but for files
#include <cstdio>
#include "CC.h"
using namespace std;
using namespace sdds;
void listCCs();
int main() {
   CC cc;
   cc.set();
   cc.set("Hubert Blaine", 4098765423457896, 123, 5, 25);
   cout << "Valid credit card record: " << endl;
   cc.display();
   cout << "------------------------------------------------------" << endl; 
   cout << "Valid credit card with very long name: " << endl;
   cc.set("Hubert Blaine Wolfeschlegelsteinhausenbergerdorff Sr.", 4098765423457896, 123, 5, 25);
   cc.display();
   cout << "------------------------------------------------------" << endl;
   cout << endl << "reading Tests: " << endl;
   cout << "Enter the following values:" << endl
      << "Fred<ENTER>\naaa<ENTER>" << endl;
   if(cc.read()) {
      cout << "This should have failed right after card entry!" << endl;
   }
   else {
      cout << "aaa is not a valid number!" << endl;
   }
   cout << "Enter the following values:" << endl
      << "Fred<ENTER>\n123<ENTER>\nbbb<ENTER>" << endl;
   if(cc.read()) {
      cout << "This should have failed right after card entry!" << endl;
   } else {
      cout << "bbb is not a valid number!" << endl;
   }
   cout << "Enter the following values:" << endl
      << "Fred<ENTER>\n123<ENTER>\n123<ENTER>\n11/11<ENTER>" << endl;
   if(cc.read()) {
      cout << "This should have failed right after card entry!" << endl;
   } else {
      cout << "Values are readable but not valid credit card information!" << endl;
   }
   cout << "Press Enter to start validation tests, all the following must fail." << endl;
   cin.ignore(1000, '\n');
   cout<<endl;
   cc.set("HB", 4098765423457896, 123, 5, 25);
   cc.display();
   cc.set(nullptr, 4098765423457896, 123, 5, 25);
   cc.display();
   cc.set("Hubert Blaine", 3999999999999999, 123, 5, 25);
   cc.display();
   cc.set("Hubert Blaine", 4100000000000000, 123, 5, 25);
   cc.display();
   cc.set("Hubert Blaine", 4098765423457896, 99, 5, 25);
   cc.display();
   cc.set("Hubert Blaine", 4098765423457896, 1000, 5, 25);
   cc.display();
   cc.set("Hubert Blaine", 4098765423457896, 123, 0, 25);
   cc.display();
   cc.set("Hubert Blaine", 4098765423457896, 123, 13, 25);
   cc.display();
   cc.set("Hubert Blaine", 4098765423457896, 123, 5, 21);
   cc.display();
   cc.set("Hubert Blaine", 4098765423457896, 123, 5, 33);
   cc.display();
   cc.cleanUp();
   cout << "Press Enter to test the row display. Formatting test..." << endl;
   cin.ignore(1000, '\n');
   listCCs();
   return 0;
}
void listCCs() {
   char name[71]{};
   unsigned long long no{};
   short cvv{};
   short expMon{};
   short expYear{};
   CC cc;
   cc.set();
   ifstream filein("cc.csv");
   int row = 1;
   cout << "|     |                                |                     |     | Expiry|" << endl;
   cout << "| Row | Card holder name               | Credit card number  | CVV | MM/YY |" << endl;
   cout << "+-----+--------------------------------+---------------------+-----+-------+" << endl;

   do {
      filein.getline(name, 71, ',');
      filein >> no;
      filein.ignore();
      filein >> cvv;
      filein.ignore();
      filein >> expMon;
      filein.ignore();
      filein >> expYear;
      filein.ignore();
      if(filein) {
         cc.set(name, no, cvv, expMon, expYear);
         cc.display(row++);
      }
   } while(filein);
   cout << "+----+--------------------------------+---------------------+-----+-------+" << endl;
   cc.cleanUp();
}
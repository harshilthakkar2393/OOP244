/***********************************************************************
// OOP244 Workshop 4 p2: tester program
//
// File	main.cpp
// Version 1.0
// Date	2022/09/27
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
#include "TourBus.h"
using namespace std;
using namespace sdds;
void depart(const TourBus& T) {
   if(T.validTour()) 
      T.startTheTour();
}
int main() {
   TourBus* t;
   bool done = false;
   int num;
   cout << "Enter the following data:" << endl
      << "100<ENTER>" << endl
      << "10<ENTER>" << endl
      << "22<ENTER>" << endl
      << "16<ENTER>" << endl
      << "4<ENTER>" << endl
      << "John Doe<ENTER>" << endl
      << "Jane Doe<ENTER>" << endl
      << "Jack Doe<ENTER>" << endl
      << "Jill Doe<ENTER>" << endl
      << "-------------------" << endl;
   while(!done){
      cout << "Please enter number of passengers: ";
      cin >> num;
      cin.ignore(1000, '\n');
      t = new TourBus(num);
      if(t->validTour()) {
         if(num == 4) {
            depart(t->board());
            done = true;
         }
         else {
            depart(*t);
         }
      }
      else {
         cout << "Invalid tour bus!" << endl;
      }
      delete t;
   }
   return 0;
}
/***********************************************************************
// OOP244 Workshop 4 p1: tester program
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
#include <fstream>
#include "Seat.h"
using namespace std;
using namespace sdds;
void testSeatClass();
void displayPassenger(const Seat& S, int row);
void listSeatBookings();
int main() {
   testSeatClass();
   listSeatBookings();
   return 0;
}
void testSeatClass() {
   cout << "Testing Seat class Functionalities..." << endl;
   Seat A;
   A.display(cout << "       Should be Invalid: ") << endl;
   Seat B = "Darth Vader";
   B.display(cout << "       Seat not assigned: ") << endl;
   Seat C("Luke Skywalker", 7, 'B');
   C.display(cout << "           Assigned Seat: ") << endl;
   B.set(7, 'A');
   B.display(cout << "Darth`s seat is assigned: ") << endl;
   Seat D(nullptr, 12, 'C');
   D.display(cout << "   nullptr name; Invalid: ") << endl;
   Seat E("", 12, 'C');
   E.display(cout << "     Empty name; Invalid: ") << endl;
   Seat F("Hubert Blaine Wolfeschlegelsteinhausenbergerdorff Sr.", 2, 'A');
   F.display(cout << "        A very long name: ") << endl;
   B.set(-1, 'A').display(cout << "          bad row number: ") << endl;
   B.set(5, 'A').display(cout << "          bad row number: ") << endl;
   B.set(6, 'A').display(cout << "          bad row number: ") << endl;
   B.set(16, 'A').display(cout << "          bad row number: ") << endl;
   B.set(19, 'A').display(cout << "          bad row number: ") << endl;
   B.set(39, 'A').display(cout << "          bad row number: ") << endl;
   B.set(1, 'C').display(cout << "         bad seat letter: ") << endl;
   B.set(1, 'D').display(cout << "         bad seat letter: ") << endl;
   B.set(12, 'G').display(cout << "         bad seat letter: ") << endl;
   C.display(cout << "  Luke's individual info: ") << endl;
   cout << "Name: " << C.passenger() << endl
      << "Row: " << C.row() << endl
      << "letter: " << C.letter() << endl;
   C.reset().display(cout << "       Seat gone (reset): ") << endl;
   cout << " Give the seat to luke's sister; enter following information:" << endl
      << "Leia Organa,12B<ENTER>" << endl;
   C.read();
   cout << "you entered: " << endl;
   C.display(cout << "             Leia's seat: ") << endl;
   cout << "========================================================================" << endl;
}
void displayPassenger(const Seat& S, int row) {
   cout.width(3);
   cout << row << "- ";
   if(!S.isEmpty()) {
      if(S.assigned()) {
         if(S.row() <= 4) cout << "Business Class ";
         else if(S.row() < 20) cout << "  Economy Plus ";
         else cout << "       Economy ";
         if(S.letter() == 'A' || S.letter() == 'F')
            cout << "Window: ";
         else if((S.row() < 4 && (S.letter() == 'B' || S.letter() == 'E'))
                 || (S.row() >= 7 && (S.letter() == 'C' || S.letter() == 'D')))
            cout << " Aisle: ";
         else cout << "Middle: ";
      } else {
         cout << "Invalid seat assigned: ";
      }
   }
   S.display() << endl;
}

void listSeatBookings() {
   cout << "Testing Read and constant methods" << endl;
   ifstream passengers("passengers.csv");  // works exactly like cin, but for a file.
   Seat S;
   int cnt = 1;
   while(S.read(passengers)) {
      displayPassenger(S, cnt++);
   }
}
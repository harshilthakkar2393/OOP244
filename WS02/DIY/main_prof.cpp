/***********************************************************************
// OOP244 Workshop 2 p2: tester program
//
// File	main.cpp
// Version 1.0
// Date	2022/09/17
// Author	Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include "Population.h"
using namespace sdds;
int main() {
   if (load("PCpopulationsComplete.csv")) {
      display();
   }
   deallocateMemory();
   return 0;
}

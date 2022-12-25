/* ------------------------------------------------------
Final Project Milestone 2
Module: Parking
Filename: main.cpp
Version 1.0
Author	Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Date      Reason
-----------------------------------------------------------*/
#include "Parking.h"
#include <iostream>
using namespace sdds;
int main() {
   Parking P("ParkingData.csv"), bad1(nullptr),bad2("");
   bad1.run();
   bad2.run();
   P.run();
   std::cout << std::endl << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << std::endl<<std::endl;
   P.run();
   return 0;
}


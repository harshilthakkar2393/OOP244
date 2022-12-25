/* ------------------------------------------------------
Final Project Milestone 4
Module: Car and Motorcycle
Filename: main.cpp
Version 1.0
Author	Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Date      Reason
-----------------------------------------------------------*/
#include <iostream>
#include "Car.h"
#include "Motorcycle.h"
using namespace std;
using namespace sdds;
void  MotorcycleTest(Vehicle*);
void  CarTest(Vehicle*);
void CarAfterTest(Car C, Car B);
void MotorcycleAfterTest(Motorcycle M, Motorcycle N);
void deallocate(Vehicle*);
int main() {
   Car* c = new Car;
   Motorcycle* m = new Motorcycle;
   cout << "Milestone 4, Car and Motorcycle: " << endl;
   CarTest(c);
   CarAfterTest(*c, *c);
   deallocate(c);
   MotorcycleTest(m);
   MotorcycleAfterTest(*m, *m);
   deallocate(m);
   return 0;
}
void CarAfterTest(Car C, Car B) {
   cout << "Copy of Car after test:" << endl << C << endl;
   B.setParkingSpot(200);
   B.setCsv(true);
   C = B;
   cout << "Assigned Car after test:" << endl << C << endl;
}
void MotorcycleAfterTest(Motorcycle M, Motorcycle N) {
   cout << "Copy of Motorcycle after test:" << endl << M << endl;
   N.setCsv(true);
   N.setParkingSpot(400);
   M = N;
   cout << "Assigned Motorcycle after test:" << endl << M << endl;
}
void deallocate(Vehicle* V) {
   cout << "Deallocating Vehicle!" << endl;
   delete V;
}
void  MotorcycleTest(Vehicle* V) {
   cout << "Motorcycle Test:" << endl << endl << "Invalid object printout: " <<endl;
   cout << *V << endl;
   cout << "Testing Console Entry, Enter the following: " << endl
      << "ab12 <ENTER>" << endl
      << "Harley Davidson <ENTER>" << endl
      << "yes <ENTER>" << endl
      << "y <ENTER>" << endl;
   cin >> *V;
   V->setCsv(true);
   cout << endl << "Comma Separated Values: " << endl << *V << endl;
   V->setCsv(false);
   cout << "Console Printout: " << endl << *V << endl;
   cout << "Testing CSV Entry, Enter the following: " << endl
      << "12,AA22,Honda CD80,0 <ENTER>" << endl;
   V->setCsv(true);
   cin >> *V;
   cout << endl << "Comma Separated Values: " << endl << *V << endl;
   V->setCsv(false);
   cout << endl << "Console Printout: " << endl << *V << endl;
}
void  CarTest(Vehicle* V) {
   cout << "Car Test:" << endl << endl << "Invalid object printout: " << endl;
   cout << *V << endl; 
   cout << "Testing Console Entry, Enter the following: " << endl
      << "abc123 <ENTER>" << endl
      << "Chevy Volt <ENTER>" << endl
      << "yes <ENTER>" << endl
      << "y <ENTER>" << endl;
   cin >> *V;
   V->setCsv(true);
   cout << endl << "Comma Separated Values: " << endl << *V << endl;
   V->setCsv(false);
   cout << "Console Printout: " << endl << *V << endl;
   cout << "Testing CSV Entry, Enter the following: " << endl
      << "12,GVAA123,Nissan Leaf,0 <ENTER>" << endl;
   V->setCsv(true);
   cin >> *V;
   cout << endl << "Comma Separated Values: " << endl << *V << endl;
   V->setCsv(false);
   cout << endl << "Console Printout: " << endl << *V << endl;
}

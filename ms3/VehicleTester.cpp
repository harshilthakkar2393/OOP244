/* ------------------------------------------------------
Final Project Milestone 3.2
Module: ReadWritable
Filename: VehicleTester.cpp
Version 1.1
Author	Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Date      Reason
22/11/17  Printed "T," in writeType of Truck (line 22)
-----------------------------------------------------------*/


#include <iostream>
#include "Vehicle.h"
using namespace std;
using namespace sdds;
class Truck : public Vehicle 
{
public:
   Truck() {};
   Truck(const char* lp, const char* mm) :Vehicle(lp, mm) {};
   ostream& writeType(ostream& ostr)const { return ostr << "T,"; };
};
void TestValidations();
void TestOperatorEqualEqual( Truck A, Truck B);
void TestIO(Vehicle& V);
int main() {
   Truck V;
   Truck C("abcd", "C car");
   // you can comment each test to develop your Vehicle step by step: 
   TestIO(V);
   TestOperatorEqualEqual(C, V);
   TestValidations();
   return 0;
}
void TestIO(Vehicle& V) {
   ReadWritable& rw = V;
   cout << "Invalid Vehicle Printing:" << endl;
   cout << rw << endl;
   cout << "Reading vehicle from console: " << endl;
   cout << "Enter:" << endl << "abc<ENTER>" << endl << "abc<ENTER>" << endl;
   rw.setCsv(false);
   cin >> rw;
   cout << "Printing a Vehicle that is not parked:" << endl;
   cout << rw << endl;
   V.setParkingSpot(12);
   cout << "Printing a Vehicle that is parked in the spot number 12:" << endl;
   cout << rw << endl;
   cout << "Reading and Writing Comma Separated values: " << endl;
   cout << "Enter: " << endl;
   cout << "123,abcd,abcd,<ENTER>" << endl;
   rw.setCsv(true);
   cin >> rw;
   cin.ignore(1000, '\n');
   cout << rw << endl;
}

void TestValidations() {
   Vehicle* V;
   cout << "Construction validations:" << endl;
   V = new Truck(nullptr, "abc");
   cout << *V;
   delete V;
   V = new Truck("123456789", "abc");
   cout << *V;
   delete V;
   V = new Truck("", "abc");
   cout << *V;
   delete V;
   V = new Truck("ABC", nullptr);
   cout << *V;
   delete V;
   V = new Truck("ABC", "");
   cout << *V;
   delete V;
   V = new Truck("ABC", "A");
   cout << *V;
   cout << "Input validations: " << endl;
   cout << "Enter: " << endl << "123456789<ENTER>" << endl << "abc<ENTER>" << endl << "abc<ENTER>" << endl;
   cin >> *V;
   cout << *V << endl;
   cout << "Enter: " << endl << "abc<ENTER>" << endl << "a<ENTER>" << endl << "ab<ENTER>" << endl;
   cin >> *V;
   cout << *V << endl;
   cout << "Testing setParkingSpot validation: " << endl <<  "Valid setting: " <<endl;
   V->setParkingSpot(20);
   cout << *V << endl;
   cout << "invalid setting: " << endl;
   V->setParkingSpot(-1);
   cout << *V << endl;
   delete V;
}
void TestOperatorEqualEqual(Truck A, Truck B) {
   cout << "opeator== (cstring):" << endl;
   if (A == "Abcd") {
      cout << "operator== with cstring works" << endl;
   }
   else {
      cout << "Bad Opertor==, fix your code" << endl;
   }
   cout << "opeator== (Vehicle):" << endl;
   if (A == B) {
      cout << "operator== with Vehicle works" << endl;
   }
   else {
      cout << "Bad Opertor==, fix your code" << endl;
   }
}


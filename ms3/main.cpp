/* ------------------------------------------------------
Final Project Milestone 3
Module: 
Filename: main.cpp
Version 1.1
Author	Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Date      Reason
22/11/17  1.1 printed T, in writeType and removed 
                                        space from box entry
-----------------------------------------------------------*/


#include <iostream>
#include <fstream>
#include "ReadWritable.h"
#include "Vehicle.h"
using namespace std;
using namespace sdds;
class Box :public ReadWritable {
   int m_width;
   int m_height;
public:
   Box(int width = 0, int height = 0) {
      m_width = width;
      m_height = height;
   }
   std::istream& read(std::istream& istr = std::cin) {
      if(isCsv()) {
         istr >> m_width;
         istr.ignore();
         istr >> m_height;
      } else {
         cout << "Width: ";
         istr >> m_width;
         cout << "Height: ";
         istr >> m_height;
      }
      return istr;
   }
   std::ostream& write(std::ostream& ostr = std::cout)const {
      if(isCsv()) {
         ostr << m_width << "," << m_height;
      } else {
         int i;
         int j;
         for(cout << "*", i = 0; i < m_width - 1; cout << " *", i++);
         ostr << endl;
         for(j = 0; j < m_height - 2; j++) {
            for(cout << "* ", i = 0; i < m_width - 2; i++, cout << "  ");
            cout << "*" << endl;
         }
         for(cout << "*", i = 0; i < m_width - 1; cout << " *", i++);
      }
      return ostr;
   }
};

class Truck : public Vehicle {
public:
   Truck() {};
   Truck(const char* lp, const char* mm) :Vehicle(lp, mm) {};
   ostream& writeType(ostream& ostr)const { return ostr << "T,"; };
};


// ReadWrite teste functions

void pause();
void test1();
void test2();
void test3();
void test4();
void RWmain();


// Vehicle tester functions
void TestValidations();
void TestOperatorEqualEqual( Truck A, Truck B);
void TestIO(Vehicle& V);
void Vehiclemain();


// you can comment each test to develop your code step by step: 

int main() {
   cout << "ReadWrite Test......................................." << endl;
   RWmain();
   cout << "....................................................." << endl;
   cout << endl
      << "Vehicle Test........................................." << endl;
   Vehiclemain();
   cout << "....................................................." << endl;
   return 0;
}


void RWmain() {
   test1();
   pause();
   test2();
   pause();
   test3();
   pause();
   test4();
}

void Vehiclemain() {
   Truck V;
   Truck C("abcd", "C car");
   TestIO(V);
   TestOperatorEqualEqual(C, V);
   TestValidations();
}

// ReadWrite Tester functions

void pause() {
   cout << "Press Enter to continue.";
   cin.ignore(1000, '\n');
}
void test1() {
   int i;
   Box B[2] = { {3,3},{30,3} };
   cout << "Testing operator<< overload (pass 1): " << endl;
   cout << "These two outputs should match" << endl;
   cout << "Output 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1" << endl;
   for(i = 0; i < 2; i++) {
      cout << B[i] << endl;
      B[i].setCsv(true);
      cout << B[i] << endl;
   }
   cout << "Output 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2" << endl;
   cout
      << "* * *" << endl
      << "*   *" << endl
      << "* * *" << endl
      << "3,3" << endl
      << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl
      << "*                                                         *" << endl
      << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl
      << "30,3" << endl;
   cout << "**************************************************************" << endl;
}
void test2() {
   int i;
   ofstream bxout("boxes.csv");
   Box B[2] = { {3,3},{30,3} };
   for(i = 0; i < 2; i++) {
      B[i].setCsv(true);
      bxout << B[i] << endl;
   }
   bxout.close();
   ifstream bxin("boxes.csv");
   cout << "Testing operator<< overload (pass 2): " << endl;
   cout << "These two outputs should match" << endl;
   cout << "Output 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1" << endl;
   while(bxin) {
      cout << char(bxin.get());
   }
   cout << "\rOutput 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2" << endl;
   cout << "3,3\n30,3\n";
   cout << "**************************************************************" << endl;
}
void test3() {
   Box B;
   cout << "Testing operator>> overload (pass 1): " << endl;
   cout << "Enter the following: " << endl;
   cout << "4<ENTER>" << endl;
   cout << "5<ENTER>" << endl;
   cin >> B;
   cout << B << endl;
}
void test4() {
   int i;
   ifstream bxin("boxes.csv");
   Box B[2];
   for(i = 0; i < 2; i++) {
      B[i].setCsv(true);
      bxin >> B[i];
   }
   cout << "Testing operator>> overload (pass 2): " << endl;
   cout << "These two outputs should match" << endl;
   cout << "Output 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1" << endl;
   for(i = 0; i < 2; i++) {
      cout << B[i] << endl;
   }
   cout << "\rOutput 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2" << endl;
   cout << "3,3\n30,3\n";
   cout << "**************************************************************" << endl;
}


// End ReadWrite Tester functions

// Vehicle Tester functions

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

// End Vehicle Tester functions

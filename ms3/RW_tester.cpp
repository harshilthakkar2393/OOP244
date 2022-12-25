/* ------------------------------------------------------
Final Project Milestone 3.1
Module: N/A
Filename: RW_Tester.cpp
Version 1.1
Author	Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Date      Reason
22/11/17  removed space from bos entry
-----------------------------------------------------------*/

#include <iostream>
#include <fstream>
using namespace std;
#include "ReadWritable.h"
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
      if (isCsv()) {
         istr >> m_width;
         istr.ignore();
         istr >> m_height;
      }
      else {
         cout << "Width: ";
         istr >> m_width;
         cout << "Height: ";
         istr >> m_height;
      }
      return istr;
   }
   std::ostream& write(std::ostream& ostr = std::cout)const {
      if (isCsv()) {
         ostr << m_width << "," << m_height;
      }
      else {
         int i;
         int j; 
         for (cout << "*", i = 0; i < m_width - 1; cout << " *", i++);
         ostr << endl;
         for (j = 0; j < m_height - 2; j++) {
            for (cout << "* ",i = 0; i < m_width - 2; i++, cout << "  ");
            cout << "*" << endl;
         }
         for (cout << "*", i = 0; i < m_width - 1; cout << " *", i++);
      }
      return ostr;
   }
};

void pause();
void test1();
void test2();
void test3();
void test4();
int main() {
   test1();
   pause();
   test2();
   pause();
   test3();
   pause();
   test4();
   return 0;
}

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
   for (i = 0; i < 2; i++) {
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
   for (i = 0; i < 2; i++) {
      B[i].setCsv(true);
      bxout << B[i] << endl;
   }
   bxout.close();
   ifstream bxin("boxes.csv");
   cout << "Testing operator<< overload (pass 2): " << endl;
   cout << "These two outputs should match" << endl;
   cout << "Output 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1" << endl;
   while (bxin) {
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
   for (i = 0; i < 2; i++) {
      B[i].setCsv(true);
      bxin >> B[i];
   }
   cout << "Testing operator>> overload (pass 2): " << endl;
   cout << "These two outputs should match" << endl;
   cout << "Output 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1" << endl;
   for (i = 0; i < 2; i++) {
      cout << B[i] << endl;
   }
   cout << "\rOutput 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2" << endl;
   cout << "3,3\n30,3\n";
   cout << "**************************************************************" << endl;
}

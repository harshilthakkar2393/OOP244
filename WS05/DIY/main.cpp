/***********************************************************************
// OOP244 Workshop 5 p2: tester program
//
// File  main.cpp
// Version 1.0
// Date  2022/10/10
// Author  Fardad Soleimanloo
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include <iostream>
#include <iomanip>
#include "Mark.h"
using namespace std;
using namespace sdds;

ostream& prn(const Mark& m, int mode = 0, ostream& ostr = cout);
ostream& operator<<(ostream& ostr, const Mark& M);
void testComparison(const Mark& L, const Mark& E, const Mark& H);
void unaryOpTest();
void constructorAndConversion();
void binaryTest(const Mark& I);
int main() {
   Mark L = 49, E = 50, H = 51, I = 20;
   constructorAndConversion();
   testComparison(L, E, H);
   unaryOpTest();
   binaryTest(I);
   return 0;
}

void testComparison(const Mark& L, const Mark& E, const Mark& H) {
   cout << "Testing Comparision!" << endl;

   cout << L << "  < " << E << ": " << (L < E ? "T" : "F") << endl;
   cout << L << "  > " << E << ": " << (L > E ? "T" : "F") << endl;
   cout << L << " <= " << E << ": " << (L <= E ? "T" : "F") << endl;
   cout << L << " >= " << E << ": " << (L >= E ? "T" : "F") << endl;
   cout << L << " == " << E << ": " << (L == E ? "T" : "F") << endl;
   cout << L << " != " << E << ": " << (L != E ? "T" : "F") << endl;
   cout << "----------------" << endl;

   cout << E << "  < " << E << ": " << (E < E ? "T" : "F") << endl;
   cout << E << "  > " << E << ": " << (E > E ? "T" : "F") << endl;
   cout << E << " <= " << E << ": " << (E <= E ? "T" : "F") << endl;
   cout << E << " >= " << E << ": " << (E >= E ? "T" : "F") << endl;
   cout << E << " == " << E << ": " << (E == E ? "T" : "F") << endl;
   cout << E << " != " << E << ": " << (E != E ? "T" : "F") << endl;
   cout << "----------------" << endl;

   cout << E << "  < " << H << ": " << (E < H ? "T" : "F") << endl;
   cout << E << "  > " << H << ": " << (E > H ? "T" : "F") << endl;
   cout << E << " <= " << H << ": " << (E <= H ? "T" : "F") << endl;
   cout << E << " >= " << H << ": " << (E >= H ? "T" : "F") << endl;
   cout << E << " == " << H << ": " << (E == H ? "T" : "F") << endl;
   cout << E << " != " << H << ": " << (E != H ? "T" : "F") << endl;
   cout << "----------------" << endl;
}
void unaryOpTest() {
   Mark m, n(51), p(100), R;
   cout << "Testing Unary operators!" << endl;
   cout << "m: " << m << endl;
   R = m--;
   cout << "R = m--, R: " << R << ", m: " << m << endl;
   R = --m;
   cout << "R = --m, R: " << R << ", m: " << m << endl;
   R = m++;
   cout << "R = m++, R: " << R << ", m: " << m << endl;
   R = ++m;
   cout << "R = ++m, R: " << R << ", m: " << m << endl;
   cout << "-----------------------------------------" << endl;
   cout << "n: " << n << endl;
   R = --n;
   cout << "R = --n, R: " << R << ", n: " << n << (~n ? " Passed!" : " Failed!") << endl;
   R = n--;
   cout << "R = n--, R: " << R << ", n: " << n << (~n ? " Passed!" : " Failed!") << endl;
   R = ++n;
   cout << "R = ++n, R: " << R << ", n: " << n << (~n ? " Passed!" : " Failed!") << endl;
   R = n++;
   cout << "R = n++, R: " << R << ", n: " << n << (~n ? " Passed!" : " Failed!") << endl;
   cout << "-----------------------------------------" << endl;
   cout << "p: " << p << endl;
   R = p++;
   cout << "R = p++, R: " << R << ", p: " << p << endl;
   R = ++p;
   cout << "R = ++p, R: " << R << ", p: " << p << endl;
   R = p--;
   cout << "R = p--, R: " << R << ", p: " << p << endl;
   R = --p;
   cout << "R = --p, R: " << R << ", p: " << p << endl;
}
void constructorAndConversion() {
   Mark m, n(30), k(75), p(300);
   cout << "Constructors and" << endl;
   cout << "and conversion" << endl;
   prn(m) << ", ";
   prn(n, 1) << ", ";
   prn(k, 2) << ", ";
   prn(p) << endl;

}
void binaryTest(const Mark& C) {
   Mark m, n = 90;
   cout << "Testing Member Binaries!" << endl;
   cout << "m: " << m << endl;
   cout << "m = 75, m: " << (m = 75) << endl;
   cout << "m = -1, m: " << (m = -1) << endl;
   cout << "m = 100, m: " << (m = 100) << endl;
   cout << "m = 101, m: " << (m = 101) << endl;
   cout << "-----------------------------------------" << endl;
   cout << "m += 65: " << (m += 65) << endl;
   cout << "m -= 10: " << (m -= 10) << endl;
   cout << "m = 10: " << (m = 10) << endl;
   cout << "m += 65: " << (m += 65) << endl;
   cout << "m -= 55: " << (m -= 10) << endl;
   cout << "-----------------------------------------" << endl;
   cout << "m = 5" << endl;
   m = 5;
   cout << "m: " << m << ", n: " << n << endl;
   cout << "m << n: " << (m << n) << endl;
   cout << "m: " << m << ", n: " << n << endl;
   cout << "m >> n: " << (m >> n) << endl;
   cout << "m: " << m << ", n: " << n << endl;
   cout << "-----------------------------------------" << endl;
   cout << "C: " << C << endl;
   cout << "C + 30: " << (C + 30) << endl;
   cout << "C + -90: " << (C + -90) << endl;
   cout << "C + 100: " << (C + 100) << endl;
   cout << "C + C: " << (C + C) << endl;
   cout << "n = 90" << endl;
   n = 90;
   cout << "n: " << n << endl;
   cout << "C + n: " << (C + n) << endl;
   cout << "-----------------------------------------" << endl;
   cout << "Testing Helper Binaries!" << endl;
   int v = 50;
   cout << "v: " << v << ", C: " << C << endl;
   cout << "v += C: " << (v += C) << endl;
   cout << "v: " << v << ", C: " << C << endl;
   cout << "v -= C: " << (v -= C) << endl;
   cout << "v: " << v << ", C: " << C << endl;
   cout << "v + C: " << (v + C) << endl;
   cout << "v: " << v << ", C: " << C << endl;
}
ostream& prn(const Mark& m, int mode, ostream& ostr) {
   ostr << "[";
   if(bool(m)) {
      if(mode == 1) {
         ostr << char(m);
      } else if(mode == 2) {
         ostr << fixed << setprecision(1) << setw(3) << double(m);
      } else {
         ostr << setw(3) << right << int(m);
      }
   } else {
      ostr << "Invalid!";
   }
   return ostr << "]";
}
ostream& operator<<(ostream& ostr, const Mark& M) {
   return prn(M, 0, ostr);
}

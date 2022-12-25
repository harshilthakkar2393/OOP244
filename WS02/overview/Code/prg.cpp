#include <iostream>
using namespace std;
struct Arr {
   int* m_data;
   int m_len;
};

int main() {
   
   Arr A;
   A.m_data = new int[10];
   A.m_len = 10;


   delete[] A.m_data;


   Arr* I = new Arr[3];

   for(int n = 0; n < 3; n++) {
      I[n].m_data = new int[100];
      I[n].m_len = 100;
   }


   for(int n = 0; n < 3; n++) {
      delete[] I[n].m_data;
   }
   delete[] I;


   return 0;
}
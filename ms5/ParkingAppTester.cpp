#include <fstream>
#include <iostream>
#include <ctype.h>
#include "Parking.h"
using namespace std;
using namespace sdds;
void runParking();
void Datafile(bool restore = false);
int main() {
   runParking();
   Datafile(true);
   return 0;
}
void runParking() {
   Parking P("ParkingData.csv", 10);
   P.run();
}
void Datafile(bool restore) {
   char ch;
   ifstream file("ParkingData.csv");
   cout << endl << "Content of ParkingData.csv after the program exits" << endl;
   cout << "-----------------------------------------------------------" << endl;
   while(file.get(ch)) {
      cout << char(tolower(ch));
   }
   cout << "-----------------------------------------------------------" << endl;
   if(restore) {
      cout << "Restore data file to original values? (y)es/(n)o: ";
      file.close();
      if(cin.get() == 'y') {
         char ch;
         file.open("ParkingData.csv.bak");
         ofstream fout("ParkingData.csv");
         while(file) {
            ch = file.get();
            if(file) fout.put(ch);
         }
         file.close();
         fout.close();
         cout << "Data file restored to orginal values." << endl;
      } else {
         cout << "Restoration aborted!" << endl;
      }
   }
}


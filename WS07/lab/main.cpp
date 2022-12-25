// Workshop 7: Inheritance
// Version: 1.0
// Date: 2022-07-21
// Author: Wail Mardini
/////////////////////////////////////////////

#include<iostream>
#include "Dumper.h"
#include "Dumper.h" // intentional
#include "VehicleBasic.h"
#include "VehicleBasic.h" // intentional

using namespace std;
using namespace sdds;

void printHeader(const char* title)
{
	char oldFill = cout.fill('-');
	cout.width(58);
	cout << "" << endl;

	cout << "|> " << title << endl;

	cout.fill('-');
	cout.width(58);
	cout << "" << endl;
	cout.fill(oldFill);
}

void moveAndLoad(Dumper& aDumper, const char* destination, double cargo)
{
	aDumper.NewAddress(destination);
	if (aDumper.loaddCargo(cargo))
		cout << "\nCargo loaded!\n";
	else
		cout << "\nLoading cargo failed!\n";
	cout << "Status " <<aDumper << endl << endl;
}

void moveAndUnload(Dumper& aDumper, const char* destination)
{
	aDumper.NewAddress(destination);
	if (aDumper.unloadCargo())
		cout << "\nCargo unloaded!\n";
	else
		cout << "\nUnloading cargo failed!\n";
	cout << "Status " << aDumper << endl << endl;
}

int main()
{
	
		printHeader("Vehicle 1: Basic Vehicle");

		VehicleBasic aVehicle("abc-123", 2010);
		cout << aVehicle << endl << endl;

		aVehicle.NewAddress("Downtown Toronto");
		aVehicle.NewAddress("Mississauga");
		aVehicle.NewAddress("North York");

		cout << endl << aVehicle << endl << endl;

		printHeader("Vehicle 2: Read/Write");
		cin >> aVehicle;
		cout << endl << aVehicle << endl << endl;
	
		printHeader("Vehicle 3: Dumper");

		Dumper aDumper("T-1111", 2015, 5432, "Toronto HQ");
		cout << endl;

		moveAndLoad(aDumper, "Toronto Deposit", 2345);

		moveAndLoad(aDumper, "Ottawa", 123); 

		moveAndLoad(aDumper, "Montreal", 3456); 

		moveAndLoad(aDumper, "New York", 4567);

		moveAndUnload(aDumper, "New Jersey");

		moveAndUnload(aDumper, "Toronto");


		printHeader("Vehicle 4: Read/Write");
		cin >> aDumper;
		cout << endl << (VehicleBasic)aDumper;
		cout << endl << aDumper << endl << endl;
	
}



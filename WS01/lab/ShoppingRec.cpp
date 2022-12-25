/*
====================================================================
workshop -1 part -1 
====================================================================
Name: Harshil Dineshbhai Thakkar
Student Id: 160431219
E-mail : hthakkar8@myseneca.ca
Date :16-09-2022
OOP244 NEE  

--------------------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
====================================================================
*/

#include <iostream>
#include "Utils.h"
#include "ShoppingRec.h"

using namespace std;
namespace sdds
{

   ShoppingRec getShoppingRec()
   {
      ShoppingRec R = {};
      cout << "Item name: ";
      readCstr(R.m_title, MAX_TITLE_LENGTH);
      cout << "Quantity: ";
      R.m_quantity = readInt(1, MAX_QUANTITY_VALUE);
      return R;
   }
   void displayShoppingRec(const ShoppingRec *shp)
   {
      cout << "[" << (shp->m_bought ? 'X' : ' ') << "]" << shp->m_title << " qty:(" << shp->m_quantity << ")" << endl;
   }
   void toggleBoughtFlag(ShoppingRec *rec)
   {
      rec->m_bought = !rec->m_bought;
   }
   bool isShoppingRecEmpty(const ShoppingRec *shp)
   {
      return shp->m_title[0] == 0;
   }
}

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

#ifndef SDDS_SHOPPINGREC_H
#define SDDS_SHOPPINGREC_H


namespace sdds
{
   const int MAX_QUANTITY_VALUE = 50;
   const int MAX_TITLE_LENGTH = 50;
   struct ShoppingRec
   {
      char m_title[MAX_TITLE_LENGTH + 1];
      int m_quantity;
      bool m_bought;
   };
   ShoppingRec getShoppingRec();
   void displayShoppingRec(const ShoppingRec *shp);
   void toggleBoughtFlag(ShoppingRec *rec);
   bool isShoppingRecEmpty(const ShoppingRec *shp);
}

#endif
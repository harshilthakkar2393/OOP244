/*
====================================================================
workshop -5 part -1
====================================================================
Name: Harshil Dineshbhai Thakkar
Student Id: 160431219
E-mail : hthakkar8@myseneca.ca
Date :14-10-2022
OOP244 NEE

--------------------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
====================================================================
*/
#pragma once
#ifndef SDDS_APARTMENT_H_
#define SDDS_APARTMENT_H_
#include <iostream>

namespace sdds
{
   class Apartment
   {
      int m_number = -1;
      double m_balance = 0.0;

   public:
      Apartment();
      Apartment(int number, double balance);
      std::ostream &display() const;
      int ApartmentNumber() const;
      double Balance() const;
      bool operator~()const;
      void setInvalid();
      operator bool() const;
      operator int() const;
      operator double() const;
      Apartment &operator=(int number);
      Apartment &operator=(Apartment &rightHand);
      Apartment &operator+=(double number);
      Apartment &operator-=(double number);
      Apartment &operator<<(Apartment &rightHand);
      Apartment &operator>>(Apartment &rightHand);
   };
   double operator+(const Apartment& leftHand, const Apartment& rightHand);
   double operator+=(double &leftHand, const Apartment& rightHand);
}

#endif // SDDS_APARTMENT_H_
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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Apartment.h"

using namespace std;
namespace sdds
{
   //-------------------------------------------
   // constructors
   //-------------------------------------------

   Apartment::Apartment()
   {
      m_number = -1;
      m_balance = 0;
   }

   Apartment::Apartment(int number, double balance)
   {

      if (number >= 1000 && number <= 9999 && balance >= 0)
      {
         m_number = number;
         m_balance = balance;
      }
   }

   //-------------------------------------------
   // queries and other functions
   //-------------------------------------------

   void sdds::Apartment::setInvalid()
   {
      this->m_number = -1;
      this->m_balance = 0;
   }

   std::ostream &Apartment::display() const
   {
      if (*this)
      {
         cout.width(4);
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else
      {
         cout << "Invld|  Apartment   ";
      }
      return cout;
   }

   int sdds::Apartment::ApartmentNumber() const
   {
      return this->m_number;
   }
   double sdds::Apartment::Balance() const
   {
      return this->m_balance;
   }

   //-------------------------------------------
   // type conversion operators
   //-------------------------------------------

   sdds::Apartment::operator bool() const
   {
      return ((this->m_number > 999 && this->m_number < 10000) && (this->m_balance >= 0));
   }

   sdds::Apartment::operator int() const
   {
      return this->m_number;
   }

   sdds::Apartment::operator double() const
   {
      return this->m_balance;
   }

   //-------------------------------------------
   // Unary member operator
   //-------------------------------------------

   bool sdds::Apartment::operator~() const
   {
      bool isZero = false;
      if (this->Balance() < 0.00001)
      {
         isZero = true;
      }
      return isZero;
   }

   //-------------------------------------------
   // Binary member operators:
   //-------------------------------------------
   //-------------------------------------------
   // assignment operators
   //-------------------------------------------

   Apartment &sdds::Apartment::operator=(int number)
   {
      if (number > 999 && number < 10000)
      {
         this->m_number = number;
      }
      else
      {
         this->setInvalid();
      }
      return *this;
   }

   Apartment &sdds::Apartment::operator=(Apartment &rightHand)
   {
      Apartment temp;
      temp.m_balance = this->m_balance;
      temp.m_number = this->m_number;
      this->m_number = rightHand.m_number;
      this->m_balance = rightHand.m_balance;
      rightHand.m_number = temp.m_number;
      rightHand.m_balance = temp.m_balance;
      return *this;
   }
   Apartment &sdds::Apartment::operator+=(double number)
   {
      if (*this && number >= 0)
      {
         this->m_balance += number;
      }
      return *this;
   }

   Apartment &sdds::Apartment::operator-=(double number)
   {
      if (*this && number >= 0 && this->m_balance >= number)
      {
         this->m_balance -= number;
      }
      return *this;
   }

   Apartment &sdds::Apartment::operator<<(Apartment &rightHand)
   {
      if (this != &rightHand && rightHand.m_balance > 0)
      {
         this->m_balance += rightHand.m_balance;
         rightHand.m_balance = 0;
      }
      return *this;
   }

   Apartment &sdds::Apartment::operator>>(Apartment &rightHand)
   {
      if (this != &rightHand && rightHand.m_balance > 0)
      {
         rightHand.m_balance += this->m_balance;
         this->m_balance = 0;
      }
      return *this;
   }

   //-------------------------------------------
   // Binary helper operators
   //-------------------------------------------
   double operator+(const Apartment &leftHand, const Apartment &rightHand)
   {
      double returnValue = 0;
      if (leftHand && rightHand)
      {
         returnValue = leftHand.Balance() + rightHand.Balance();
      }
      return returnValue;
   }

   double operator+=(double &leftHand, const Apartment &rightHand)
   {
      leftHand += rightHand.Balance();
      return leftHand;
   }
}
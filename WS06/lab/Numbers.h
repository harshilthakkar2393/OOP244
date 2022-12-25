/*
====================================================================
workshop -6 part 1
====================================================================
Name: Harshil Dineshbhai Thakkar
Student Id: 160431219
E-mail : hthakkar8@myseneca.ca
Date :26-10-2022
OOP244 NEE

--------------------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
====================================================================
*/
#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_
#include <iostream>
namespace sdds
{
   class Numbers
   {
      double *m_numbers{};
      char *m_filename{};
      bool m_isOriginal;
      int m_numCount;
      bool isEmpty() const;
      void setEmpty();
      void deallocate();
      void setFilename(const char *filename);

   public:
      Numbers();
      Numbers(const char *filename);
      Numbers(const Numbers &rightHand);
      ~Numbers();
      double average() const;
      double max() const;
      double min() const;
      Numbers &operator=(const Numbers &rightHand);
      bool operator==(const Numbers &rightHand) const;
      Numbers operator-();
      Numbers operator+();
      Numbers &operator+=(double rightHand);
      Numbers &sort(bool ascending);
      void save();
      bool load();
      int numberCount();
      std::ostream &display(std::ostream &ostr) const;
   };
   std::ostream &operator<<(std::ostream &os, const Numbers &N);
   std::istream &operator>>(std::istream &istr, Numbers &N);
}
#endif // !SDDS_NUMBERS_H_
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
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include "Numbers.h"
using namespace std;
namespace sdds
{
   //---------------------------------------------------------
   // Constructors, Destructor and Copy Assignment
   //---------------------------------------------------------

   Numbers::Numbers()
   {

      setEmpty();
      m_isOriginal = false;
   }

   Numbers::Numbers(const char *filename)
   {

      setEmpty();
      m_isOriginal = true;
      setFilename(filename);
      m_numCount = numberCount();
      if (m_numCount == 0 || !load())
      {
         deallocate();
         setEmpty();
         m_isOriginal = false;
      }
   }
   Numbers::Numbers(const Numbers &rightHand)
   {
      setEmpty();
      m_isOriginal = false;
      *this = rightHand;
   }
   Numbers::~Numbers()
   {

      save();
      deallocate();
   }

   //---------------------------------------------------------
   // Member Functions and Member operator overload
   //---------------------------------------------------------

   bool Numbers::isEmpty() const
   {

      return m_numbers == nullptr;
   }

   void Numbers::setEmpty()
   {
      m_numbers = nullptr;
      m_filename = nullptr;
      m_numCount = 0;
   }

   void Numbers::deallocate()
   {

      delete[] m_filename;
      delete[] m_numbers;
   }

   void Numbers::setFilename(const char *filename)
   {

      delete[] m_filename;
      m_filename = new char[strlen(filename) + 1];
      strcpy(m_filename, filename);
   }

   double Numbers::average() const
   {

      double aver = 0.0;
      if (!isEmpty())
      {
         for (int i = 0; i < m_numCount; i++)
            aver += m_numbers[i];
         aver = aver / m_numCount;
      }
      return aver;
   }

   double Numbers::min() const
   {

      double minVal = 0.0;
      if (!isEmpty())
      {
         minVal = m_numbers[0];
         for (int i = 1; i < m_numCount; i++)
            if (minVal > m_numbers[i])
               minVal = m_numbers[i];
      }
      return minVal;
   }

   double Numbers::max() const
   {

      double maxVal = 0.0;
      if (!isEmpty())
      {
         maxVal = m_numbers[0];
         for (int i = 1; i < m_numCount; i++)
            if (maxVal < m_numbers[i])
               maxVal = m_numbers[i];
      }
      return maxVal;
   }

   bool Numbers::operator==(const Numbers &rightHand) const
   {

      return ((this->m_numbers == rightHand.m_numbers) && (this->m_filename == rightHand.m_filename) && (this->m_numCount == rightHand.m_numCount));
   }

   Numbers &Numbers::operator=(const Numbers &rightHand)
   {

         delete[] this->m_numbers;
      if (*this == rightHand)
      {
         this->setEmpty();
         this->m_isOriginal = false;
      }
      else
      {
         this->m_numCount = rightHand.m_numCount;
         this->m_filename = rightHand.m_filename;
         this->m_numbers = new double[rightHand.m_numCount];
         for (int i = 0; i < rightHand.m_numCount; i++)
         {
            this->m_numbers[i] = rightHand.m_numbers[i];
         }
      }
      return *this;
   }

   Numbers Numbers::operator+()
   {
      Numbers proxy(*this);
      proxy.sort(true);
      return proxy;
   }

   Numbers Numbers::operator-()
   {

      Numbers proxy(*this);
      proxy.sort(false);
      return proxy;
   }

   Numbers &Numbers::sort(bool ascending)
   {
      bool isUnsorted = false;
      double proxyNumber = 0;
      do
      {
         isUnsorted = false;
         if (ascending)
         {
            for (int i = 0; i < (m_numCount - 1); i++)
            {
               if (m_numbers[i] > m_numbers[i + 1])
               {
                  isUnsorted = true;
                  for (; i < (m_numCount - 1); i++)
                  {
                     if (this->m_numbers[i] > this->m_numbers[i + 1])
                     {
                        proxyNumber = this->m_numbers[i];
                        this->m_numbers[i] = this->m_numbers[i + 1];
                        this->m_numbers[i + 1] = proxyNumber;
                     }
                  }
               }
            }
         }
         else
         {
            for (int i = m_numCount - 1; i >= 0; i--)
            {

               for (int j = m_numCount - 1; j > (m_numCount - 1) - i; j--)
               {
                  if (m_numbers[j] > m_numbers[j - 1])
                  {
                     isUnsorted = true;

                     if (m_numbers[j] > m_numbers[j - 1])
                     {
                        proxyNumber = this->m_numbers[j];
                        this->m_numbers[j] = this->m_numbers[j - 1];
                        this->m_numbers[j - 1] = proxyNumber;
                     }
                  }
               }
            }
         }
      } while (isUnsorted);

      return *this;
   }
   void Numbers::save()
   {
      if (!isEmpty() && m_isOriginal)
      {
         ofstream nums;
         nums.open(this->m_filename);
         nums.setf(ios::fixed);
         nums.precision(2);
         for (int i = 0; i < this->m_numCount; i++)
         {
            nums << this->m_numbers[i] << endl;
         }
         nums.close();
      }
   }
   bool Numbers::load()
   {
      int i = 0;
      ifstream nums;
      nums.open(this->m_filename);
      if (numberCount())
      {
         this->m_numCount = numberCount();
         this->m_numbers = new double[this->m_numCount];
         while (!(nums.fail()))
         {
            nums >> this->m_numbers[i];
            i++;
         }
         i--;
      }
      nums.close();
      return (i == this->m_numCount);
   }
   int Numbers::numberCount()
   {
      int count = 0;
      ifstream fstr;
      fstr.open(m_filename);
      while (fstr.is_open() && !fstr.eof())
      {
         count += fstr.get() == '\n';
      }
      fstr.close();
      return count;
   }
   Numbers &Numbers::operator+=(double rightHand)
   {
      double *proxy = nullptr;
      proxy = new double[m_numCount + 1];
      for (int i = 0; i < m_numCount; i++)
      {
         proxy[i] = this->m_numbers[i];
      }
      proxy[m_numCount] = rightHand;
      delete[] m_numbers;
      this->m_numbers = proxy;
      this->m_numCount++;
      return *this;
   }
   std::ostream &Numbers::display(std::ostream &ostr) const
   {
      if (isEmpty())
      {
         ostr << "Empty list" << endl;
      }
      else
      {
         ostr << "=========================" << endl;
         if (m_isOriginal)
         {
            ostr << this->m_filename << endl;
         }
         else
         {
            ostr << "*** COPY ***" << endl;
         }
         for (int i = 0; i < this->m_numCount - 1; i++)
         {
            ostr.setf(ios::fixed);
            ostr.precision(2);
            ostr << this->m_numbers[i] << ", ";
         }
         ostr.precision(2);
         ostr << this->m_numbers[m_numCount - 1];

         ostr << endl;
         ostr << "-------------------------" << endl;
         ostr << "Total of " << m_numCount << " number(s)" << endl;
         ostr << "Largest number:  " << this->max() << endl;
         ostr << "Smallest number: " << this->min() << endl;
         ostr << "Average:         " << this->average() << endl;
         ostr << "=========================";
         ostr.unsetf(ios::fixed);
      }
      return ostr;
   }
   std::ostream &operator<<(std::ostream &os, const Numbers &N)
   {
      return N.display(os);
   }
   std::istream &operator>>(std::istream &istr, Numbers &N)
   {
      double proxy=0;
      istr >> proxy;
      N += proxy;
      return istr;
   }
}

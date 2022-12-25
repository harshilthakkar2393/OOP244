/*
====================================================================
workshop -5 part -2
====================================================================
Name: Harshil Dineshbhai Thakkar
Student Id: 160431219
E-mail : hthakkar8@myseneca.ca
Date :19-10-2022
OOP244 NEE

--------------------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
====================================================================
*/

#include <iostream>
#include "Mark.h"

using namespace std;
namespace sdds
{

    //=============================================================
    // Construction
    //=============================================================

    sdds::Mark::Mark()
    {
        marks = 0;
    }
    sdds::Mark::Mark(int mark)
    {
        this->marks = mark;
    }

    //=============================================================
    // Type conversion Operators
    //=============================================================

    sdds::Mark::operator int() const
    {
        int mark = INVALID;
        if (*this)
        {
            mark = this->marks;
        }
        return mark;
    }
    sdds::Mark::operator double() const
    {
        double gpa = 0.0;

        if (MIN_MARKS <= this->marks && this->marks < MIN_PASS_MARKS) // F grade
        {
            gpa = 0.0;
        }
        else if (MIN_MARKS <= this->marks && this->marks < 60) // D grade
        {
            gpa = 1.0;
        }
        else if (60 <= this->marks && this->marks < 70) // C grade
        {
            gpa = 2.0;
        }
        else if (70 <= this->marks && this->marks < 80) // B grade
        {
            gpa = 3.0;
        }
        else if (80 <= this->marks && this->marks <= Max_MARKS) // A grade
        {
            gpa = 4.0;
        }
        else // invalid marks
        {
            gpa = 0.0;
        }
        return gpa;
    }
    sdds::Mark::operator char() const
    {
        char grade;
        if (*this)
        {
            switch (int(double(*this)))
            {
            case 0:
            {
                grade = 'F';
                break;
            }
            case 1:
            {
                grade = 'D';
                break;
            }
            case 2:
            {
                grade = 'C';
                break;
            }
            case 3:
            {
                grade = 'B';
                break;
            }
            case 4:
            {
                grade = 'A';
                break;
            }
            default:
            {

                break;
            }
            }
        }
        else
        {
            grade = 'X';
        }

        return grade;
    }
    sdds::Mark::operator bool() const
    {
        return (isMarkValid(this->marks));
    }

    //=============================================================
    // Comparison operator overloads
    //=============================================================

    bool sdds::Mark::operator==(const Mark &rightHand) const
    {
        return (this->marks == int(rightHand));
    }
    bool sdds::Mark::operator!=(const Mark &rightHand) const
    {
        return (this->marks != int(rightHand));
    }
    bool sdds::Mark::operator<(const Mark &rightHand) const
    {
        return (this->marks < int(rightHand));
    }
    bool sdds::Mark::operator>(const Mark &rightHand) const
    {
        return (this->marks > int(rightHand));
    }
    bool sdds::Mark::operator<=(const Mark &rightHand) const
    {
        return (this->marks <= int(rightHand));
    }
    bool sdds::Mark::operator>=(const Mark &rightHand) const
    {
        return (this->marks >= int(rightHand));
    }

    //=============================================================
    // Unary operators
    //=============================================================
    Mark &sdds::Mark::operator++()
    {
        if (isMarkValid(this->marks))
        {
            this->marks += 1;
        }
        return *this;
    }
    Mark sdds::Mark::operator++(int)
    {
        Mark temp(this->marks);
        if (isMarkValid(this->marks))
        {
            this->marks=this->marks+ 1;
        }
        return temp;
    }
    Mark &sdds::Mark::operator--()
    {
        if (isMarkValid(this->marks))
        {
            this->marks = this->marks - 1;
        }
        return *this;
    }
    Mark sdds::Mark::operator--(int)
    {
        Mark temp(this->marks);
        if (isMarkValid(this->marks))
        {
            this->marks = this->marks - 1;
        }
        return temp;
    }
    bool sdds::Mark::operator~() const
    {
        return (*this && this->marks >= MIN_PASS_MARKS);
    }

    //=============================================================
    // Binary Operators
    //=============================================================
    Mark &sdds::Mark::operator=(Mark &rightHand)
    {

        this->marks = rightHand.marks;
        return *this;
    }
    Mark &sdds::Mark::operator=(int rightHand)
    {

        this->marks = rightHand;
        return *this;
    }

    Mark &sdds::Mark::operator+=(int rightHand)
    {
        if (isMarkValid(rightHand))
        {
            this->marks += rightHand;
        }
        return *this;
    }

    Mark &sdds::Mark::operator-=(int rightHand)
    {
        if (isMarkValid(rightHand))
        {
            this->marks -= rightHand;
        }
        return *this;
    }

    Mark &sdds::Mark::operator<<(Mark &rightHand)
    {
        this->marks += rightHand.marks;
        rightHand.marks = 0;
        return *this;
    }

    Mark &sdds::Mark::operator>>(Mark &rightHand)
    {
        rightHand.marks += this->marks;
        this->marks = 0;
        return *this;
    }
    Mark sdds::Mark::operator+(const Mark &rightHand) const
    {
        Mark temp;
        temp.marks = (this->marks + int(rightHand));
        return temp;
    }
    Mark sdds::Mark::operator+(int rightHand) const
    {
        Mark temp;
        temp.marks = (this->marks + rightHand);
        return temp;
    }

    //=============================================================
    // Binary helper Operators
    //=============================================================
    bool isMarkValid(int mark)
    {
        return (mark >= MIN_MARKS && mark <= Max_MARKS);
    }
    int operator+=(int &leftHand, const Mark &rightHand)
    {
        if (rightHand)
        {
            leftHand += int(rightHand);
        }
        return leftHand;
    }
    int operator-=(int &leftHand, const Mark &rightHand)
    {
        if (rightHand)
        {
            leftHand -= int(rightHand);
        }
        return leftHand;
    }
    int operator+( int leftHand, const Mark &rightHand)
    {
        int temp=(leftHand + int(rightHand));
        return temp;
    }
}
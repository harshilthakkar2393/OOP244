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
#pragma once
#ifndef SDDS_MARK_H_
#define SDDS_MARK_H_
#define Max_MARKS 100
#define MIN_MARKS 0
#define MIN_PASS_MARKS 50
#define INVALID -1

namespace sdds
{
    class Mark
    {
        int marks;

    public:
        //=============================================================
        // Construction
        //=============================================================

        Mark();
        Mark(int mark);

        //=============================================================
        // Type conversion Operators
        //=============================================================

        operator int() const;
        operator double() const;
        operator char() const;
        operator bool() const;

        //=============================================================
        // Comparison operator overloads
        //=============================================================

        bool operator==(const Mark &rightHand) const;
        bool operator!=(const Mark &rightHand) const;
        bool operator<(const Mark &rightHand) const;
        bool operator>(const Mark &rightHand) const;
        bool operator<=(const Mark &rightHand) const;
        bool operator>=(const Mark &rightHand) const;

        //=============================================================
        // Unary operators
        //=============================================================
        Mark &operator++();
        Mark operator++(int);
        Mark &operator--();
        Mark operator--(int);
        bool operator~() const;

        //=============================================================
        // Binary Operators
        //=============================================================
        Mark &operator=(Mark &rightHand);
        Mark &operator=(int rightHand);
        Mark &operator+=(int rightHand);
        Mark &operator-=(int rightHand);
        Mark &operator<<(Mark &rightHand);
        Mark &operator>>(Mark &rightHand);
        Mark operator+(const Mark &rightHand) const;
        Mark operator+(int rightHand) const;
    };
    bool isMarkValid(int);
    int operator+=(int &leftHand, const Mark &rightHand);
    int operator-=(int &leftHand, const Mark &rightHand);
    int operator+(int leftHand, const Mark &rightHand);
}
#endif
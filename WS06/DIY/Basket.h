/*
====================================================================
workshop -6 part 2
====================================================================
Name: Harshil Dineshbhai Thakkar
Student Id: 160431219
E-mail : hthakkar8@myseneca.ca
Date :30-10-2022
OOP244 NEE

--------------------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
====================================================================
*/
#ifndef SDDS_BASKET_H_
#define SDDS_BASKET_H_
#include <iostream>
namespace sdds
{
    struct Fruit
    {
        char m_name[30 + 1]; // the name of the fruit
        double m_qty;        // quantity in kilograms
    };
    class Basket
    {
        Fruit *m_fruit;
        int arrSize;
        double basketPrice;

    public:
        Basket();
        Basket(Fruit *fruit, int size, double price);
        Basket(Basket &basket);
        ~Basket();
        Basket &operator=(Basket &rightHand);
        void setPrice(double price);
        operator bool();
        Basket &operator+=(Fruit rightHand);
        friend std::ostream &operator<<(std::ostream &os, const Basket &RightHand);
    };
}
#endif // !SDDS_BASKET_H_
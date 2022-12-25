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
#include <iostream>
#include "Basket.h"
using namespace std;
namespace sdds
{

    Basket::Basket()
    {
        m_fruit = nullptr;
        arrSize = 0;
        basketPrice = 0;
    }

    Basket::Basket(Fruit *fruit, int size, double price)
    {
        m_fruit = nullptr;
        if (fruit && size > 0 && price > 0)
        {
            arrSize = size;
            basketPrice = price;
            m_fruit = new Fruit[size];
            for (int i = 0; i < size; i++)
            {
                m_fruit[i] = fruit[i];
            }
        }
    }

    Basket::Basket(Basket &basket)
    {
        m_fruit = nullptr;
        *this = basket;
    }

    Basket::~Basket()
    {
        delete[] this->m_fruit;
    }

    Basket &Basket::operator=(Basket &rightHand)
    {
        if (rightHand)
        {

            m_fruit = new Fruit[rightHand.arrSize];
            for (int i = 0; i < rightHand.arrSize; i++)
            {
                m_fruit[i] = rightHand.m_fruit[i];
            }
            this->arrSize = rightHand.arrSize;
            this->basketPrice = rightHand.basketPrice;
        }
        else
        {
            delete[] m_fruit;
            m_fruit = nullptr;
            arrSize = 0;
        }
        return *this;
    }

    void Basket::setPrice(double price)
    {
        if (price > 0)
        {
            this->basketPrice = price;
        }
    }

    Basket::operator bool()
    {
        return (this->m_fruit != nullptr && this->arrSize > 0);
    }

    Basket &Basket::operator+=(Fruit rightHand)
    {
        Fruit *proxy = new Fruit[arrSize + 1];
        for (int i = 0; i < arrSize; i++)
        {
            proxy[i] = m_fruit[i];
        }
        arrSize++;
        proxy[arrSize - 1] = rightHand;
        delete[] m_fruit;
        m_fruit = proxy;
        return *this;
    }

    std::ostream &operator<<(std::ostream &os, const Basket &RightHand)
    {
        if (RightHand.m_fruit == nullptr && RightHand.arrSize <= 0)
        {
            os << "The basket is empty!" << endl;
        }
        else
        {
            os << "Basket Content:" << endl;
            for (int i = 0; i < RightHand.arrSize; i++)
            {
                os.setf(ios::right);
                os.width(10);
                os.setf(ios::fixed);
                os.precision(2);
                os << RightHand.m_fruit[i].m_name << ": " << RightHand.m_fruit[i].m_qty << "kg" << endl;
            }
            os << "Price: " << RightHand.basketPrice << endl;
        }
        return os;
    }
}
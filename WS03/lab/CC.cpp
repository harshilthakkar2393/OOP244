/*
====================================================================
workshop -3 part -1
====================================================================
Name: Harshil Dineshbhai Thakkar
Student Id: 160431219
E-mail : hthakkar8@myseneca.ca
Date :30-09-2022
OOP244 NEE

--------------------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
i only took inspiration for the bubbleSort algorithm from geekforgeeks
link is provided near function definition
====================================================================
*/
#include <iostream>
#include "Utils.h"
#include "CC.h"
#define MIN_CARD_NO 4000000000000000
#define MAX_CARD_NO 4099999999999999
#define MIN_MONTH 1
#define MAX_MONTH 12
#define MIN_YEAR 22
#define MAX_YEAR 32
using namespace std;
namespace sdds
{

    // This function validates the credit card information .
    // it will return true if all the conditions are met, otherwise it will return false
    bool sdds::CC::validate(const char *name, unsigned long long cardNo, short cvv, short expMon, short expYear) const
    {
        bool isValid = false;
        if (name != nullptr && strlen(name) > 2 && cardNo <= MAX_CARD_NO && cardNo >= MIN_CARD_NO && cvv > 99 && cvv < 1000 && expMon <= MAX_MONTH && expMon >= MIN_MONTH && MIN_YEAR <= expYear && expYear <= MAX_YEAR)
        {
            isValid = true;
        }
        return isValid;
    }

    // This function prints a 16-digit number in a set of 4-digit numbers separated by spaces
    void sdds::CC::prnNumber() const
    {
        int first4Digit = 0;
        int second4Digit = 0;
        int third4Digit = 0;
        int fourth4Digit = 0;
        unsigned long long int remainder = 0;

        first4Digit = creditCardNumber / 1000000000000;
        remainder = creditCardNumber % 1000000000000;
        second4Digit = remainder / 100000000;
        remainder = remainder % 100000000;
        third4Digit = remainder / 10000;
        fourth4Digit = remainder % 10000;
        cout.setf(ios::right);
        cout.fill('0');
        cout.width(4);
        cout << first4Digit << " ";
        cout.width(4);
        cout << second4Digit << " ";
        cout.width(4);
        cout << third4Digit << " ";
        cout.width(4);
        cout << fourth4Digit;
        cout.fill(' ');
        cout.unsetf(ios::right);
    }

    // Sets the object to a safe empty state by setting all the values to zero and nullptr.
    void sdds::CC::set()
    {
        cardHolderName = nullptr;
        CVV = 0;
        expMonth = 0;
        expYr = 0;
        creditCardNumber = 0;
    }

    // it deallocates the cardholder's name and then calls the set() to set the object to a safe empty state.
    void sdds::CC::cleanUp()
    {
        delete[] cardHolderName;
        set();
    }

    // Returns if the CC object is in a safe empty state or not; by returning true if the cardholder name pointer attribute
    // of the object is nullptr, otherwise, it will return false.
    bool sdds::CC::isEmpty() const
    {
        bool is_Empty = false;
        if (cardHolderName == nullptr)
        {
            is_Empty = true;
        }
        return is_Empty;
    }

    // it will dynamically keep a copy of the name in the name attribute and set the rest of the attributes to their corresponding values.
    void sdds::CC::set(const char *cc_name, unsigned long long cc_no, short cvv, short expMon, short expYear)
    {
        cleanUp();
        if (validate(cc_name, cc_no, cvv, expMon, expYear) == true)
        {
            int len = strlen(cc_name);
            cardHolderName = new char[len + 1];
            strcpy(cardHolderName, cc_name, len);
            creditCardNumber = cc_no;
            CVV = cvv;
            expMonth = expMon;
            expYr = expYear;
        }
        else
        {
            set();
        }
    }

    // this function will attempt to read all the values from the console
    // they will be validated and then stored in the object.
    // The function will return true if the values are stored in the object and false otherwise
    bool sdds::CC::read()
    {
        bool isSet = false;
        char proxyName[71];
        short int proxyCVV = 0;
        short int proxyExpMonth = 0;
        short int proxyExpYr = 0;
        unsigned long long proxyNumber = 0;
        cleanUp();
        cout << "Card holder name: ";
        cin.getline(proxyName, 71);
        if (cin.fail())//checking if entered name is valid
        {
            cin.clear();
            cin.ignore(10000, '\n');
        }
        else
        {
            cout << "Credit card number: ";
            cin >> proxyNumber;
            if (cin.fail())//checking if entered number is valid 
            {
                cin.clear();
                cin.ignore(10000, '\n');
            }
            else
            {
                cout << "Card Verification Value (CVV): ";
                cin >> proxyCVV;
                if (cin.fail())//checking if entered cvv is valid 
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
                else
                {
                    cout << "Expiry month and year (MM/YY): ";
                    cin >> proxyExpMonth;
                    cin.ignore();
                    cin >> proxyExpYr;
                    if (cin.fail())//checking if entered date is valid 
                    {
                        cin.clear();
                        cin.ignore(10000, '\n');
                    }
                    else
                    {
                        set(proxyName, proxyNumber, proxyCVV, proxyExpMonth, proxyExpYr);
                    }
                    if (!isEmpty())
                    {
                        isSet = true;
                    }
                }
            }
        }

        return isSet;
    }

    // displays data in a formatted from
    void sdds::CC::display(int row) const
    {
        if (!isEmpty())
        {

            if (row <= 0)
            {
                cout << "Name: " << cardHolderName << endl;
                cout << "Creditcard No: ";
                prnNumber();
                cout << endl;
                cout << "Card Verification Value: " << CVV << endl;
                cout << "Expiry Date: " << expMonth << "/" << expYr << endl;
            }
            else
            {
                char temp[31];
                strcpy(temp,cardHolderName,30);
                cout << "| ";
                cout.width(3);
                cout.setf(ios::right);
                cout << row;
                cout.unsetf(ios::right);
                cout << " | ";
                cout.width(30);
                cout.setf(ios::left);
                cout << temp;
                cout.unsetf(ios::left);
                cout << " | ";
                prnNumber();
                cout << " | ";
                cout << CVV;
                cout << " | ";
                cout.width(2);
                cout.setf(ios::right);
                cout << expMonth;
                cout.unsetf(ios::right);
                cout << "/" << expYr << " |" << endl;
            }
        }
        else
        {
            cout << "Invalid Credit Card Record" << endl;
        }
    }
}

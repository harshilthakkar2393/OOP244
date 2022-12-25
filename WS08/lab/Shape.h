/*
====================================================================
workshop -8 part 1
====================================================================
Name: Harshil Dineshbhai Thakkar
Student Id: 160431219
E-mail : hthakkar8@myseneca.ca
Date :16-11-2022
OOP244 NEE

--------------------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
====================================================================
*/
#ifndef SDDS_SHAPE_H
#define SDDS_SHAPE_H
namespace sdds
{
    class Shape
    {
    public:
        //--------------------------------------------------------
        // private virtual member functions
        //--------------------------------------------------------
        // distructor
        virtual ~Shape(){};
        
        // draw fucntion : returns nothing and takes ostream refrence as arguement 
        virtual void draw(std::ostream &os) const = 0;
        
        // getSpecs fucntion : returns nothing and takes istream refrence as arguement
        virtual void getSpecs(std::istream &is) = 0;
    };

    //--------------------------------------------------------
    // operator overloading 
    //--------------------------------------------------------
    std::ostream &operator<<(std::ostream& os,Shape &shape);
    std::istream &operator>>(std::istream& is ,Shape &shape);
}
#endif
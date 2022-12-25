#ifndef SDDS_LINE_H
#define SDDS_LINE_H

#include "./LblShape.h"

namespace sdds
{
    class Line : public LblShape
    {

        //--------------------------------------------------------
        // private data member
        //--------------------------------------------------------

        int m_length;

    public:
        //--------------------------------------------------------
        // constructors and distructors
        //--------------------------------------------------------

        // default constructor
        Line();

        // 2 args constructor
        Line(const char *label, int length);

        // distructor
        ~Line();

        //--------------------------------------------------------
        // inherited virtual functions
        //--------------------------------------------------------

        // draw fucntion : returns nothing and takes ostream refrence as arguement
        virtual void draw(std::ostream &os) const;

        // getSpecs fucntion : returns nothing and takes istream refrence as arguement
        virtual void getSpecs(std::istream &is);
    };
}
#endif
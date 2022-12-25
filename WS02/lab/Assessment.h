/*
====================================================================
workshop -2 part -1
====================================================================
Name: Harshil Dineshbhai Thakkar
Student Id: 160431219
E-mail : hthakkar8@myseneca.ca
Date :23-09-2022
OOP244 NEE

--------------------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
====================================================================
*/
#ifndef SDDS_ASSESSMENT_H
#define SDDS_ASSESSMENT_H

namespace sdds
{
    struct Assessment
    {
        double *m_mark;
        char *m_title;
    };

    // Reads one integer from the fptr file into the value reference and returns true if
    // it was successful, otherwise, it will return false
    bool read(int &value, FILE *fptr);

    // Reads one double from the fptr file into the value reference and returns true
    // if it was successful, otherwise, it will return false
    bool read(double &value, FILE *fptr);

    // Skips a comma and then reads a cstring no longer than 60 characters from the
    // fptr file into the address, `cstr`  and returns true if it was successful, otherwise, it will return false
    bool read(char *cstr, FILE *fptr);

    // First it will try to read a double value for the mark and a string for title into a temporary
    // local double variable and a 60 character lone cString (+1 for null).
    bool read(Assessment& asmnt, FILE *fptr);

    // This function will receive a reference of a dynamic Assessment array and its size.
    // The function then will delete the dynamic Assessment array
    void freeMem(Assessment *&aptr, int size);

    // This read function receives a reference of an Assessment pointer (to hold a dynamic array)
    //  and a file pointer from which it will read the assessment records into a newly allocated dynamic array.
    int read(Assessment *&aptr, FILE *fptr);
}
#endif

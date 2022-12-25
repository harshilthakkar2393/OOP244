/***********************************************************************
// OOP244 Workshop 2 p2: tester program
//
// File  File.h
// Version 1.0
// Date  2022/09/17
// Author   Fardad Soleimanloo
// Description
// This file is incomplete and to be completed by students
// Revision History
// -----------------------------------------------------------
// Name Harshil Thakkar  Date 26-09-2022      Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_

namespace sdds {
   // Opens a file and keeps the file pointer in the File.cpp (file scope)
   bool openFile(const char filename[]);
   // Closes the open file
   void closeFile();
   // Finds the records kept in the file to be used for the dynamic memory allocation 
   // of the records in the file
   int noOfRecords();

    bool load(Population *newPopulation ,const char filename[]);
}
#endif // !SDDS_FILE_H_

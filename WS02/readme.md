# Workshop #2: References, Overloading and Dynamic memory allocation
* Version 1.0<br /> 
- 0.8: submission is not open yet
- 0.9: Overview session scheduled
- 1.0: Submission are now open
- 1.1: changed "asm" name to asmnt, since asm is a reserved word in C.
## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- allocate and deallocate dynamic memory;
- overload functions
- create and use references

## Workshop Online Overview Session. (Tuesday Sep20th 16:15 to 17:05)
The overview session will go through the workshop, explaining the steps and answering questions you might have.

The session will be online on BigBlueButton. Click on the link below 5 minutes before the session begins to join the session. 
Make sure your microphone is set up and join with the microphone. This is an interactive session, avoid "Listen only" connections unless you REALLY have to.

[Click HERE to join the session](https://connect.rna2.blindsidenetworks.com/invite/to?c=fFm-opfEavRb6s57mbfsMyK0effDDUyRcDVEKYwW4kY&m=f5fee54f6c569f103d073e94fde7fee76fe07b17&t=1663704681614&u=senecacollege)

### Overview session recordings
- [Part 1](https://youtu.be/aa_Y8OvVnb8)
- [Part 2](https://youtu.be/NEItXpW4-r8)



## Submission Policy

This workshop is divided into two coding parts and one non-coding part:

- Part 1 (**LAB**): A step-by-step guided workshop, worth 50% of the workshop's total mark
> Please note that the part 1 section is **not to be started in your first session of the week**. You should start it on your own before the day of your class and join the first session of the week to ask for help and correct your mistakes (if there are any).
- Part 2 (**DIY**): A Do It Yourself type of workshop that is much more open-ended and is worth 50% of the workshop's total mark.  
- *reflection*: non-coding part, to be submitted together with *DIY* part. The reflection doesn't have marks associated with it but can incur a **penalty of max 40% of the whole workshop's mark** if your professor deems it insufficient (you make your marks from the code, but you can lose some on the reflection).
- Submissions of part 2 that do not contain the *reflection* (that is the **non-coding part**) are not considered valid submissions and are ignored.

## Due Dates

Depending on the section you are enrolled in, the submission due day of the week may shift a day or two. Please choose the "-due" option of the submitter program to see the exact due date of your section:

```bash
~profname.proflastname/submit 2??/wX/pY -due<ENTER>
```
- Replace **??** with your subject code (`00 or 44`)
- Replace **X** with Workshop number: [`1 to 10`]
- Replace **Y** with the part number: [`1 or 2`]

### Overall workshop due days
- day 1: Workshop open for preview<br/>
  (If you need to check your program with the submitter, you can use `-feedback` option to test the execution without submission)
- day 2: submission opens for both parts 1 and 2
- day 5: (end of day) Part 1 due
- day 8: (end of day) Part 2 due
- day 9: (end of day) submissions rejected

If at the deadline (end of day 8) the workshop is not complete, there is an extension of **one day** when you can submit the missing parts.  **The code parts that are submitted late receive 0%.**  After this extra day, the submission closes; if the workshop is incomplete when the submission closes (missing at least one of the coding or non-coding parts), **the mark for the entire workshop is 0%**.

## Citation

Every file that you submit must contain (as a comment) at the top:<br />
**your name**, **your Seneca email**, **Seneca Student ID** and the **date** when you completed the work.

### For work that is done entirely by you (ONLY YOU)

If the file contains only your work or the work provided to you by your professor, add the following message as a comment at the top of the file:

> I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

### For work that is done partially by you.

If the file contains work that is not yours (you found it online or somebody provided it to you), **write exactly which part of the assignment is given to you as help, who gave it to you, or which source you received it from.**  By doing this you will only lose the mark for the parts you got help for, and the person helping you will be clear of any wrongdoing.

> - Add the citation to the file in which you have the borrowed code
> - In the 'reflect.txt` submission of part 2 (DIY), add exactly what is added to which file and from where (or whom).

> :warning: This [Submission Policy](#submission-policy) only applies to the workshops. All other assessments in this subject have their own submission policies.

### If you have helped someone with your code

If you have helped someone with your code. Let them know of these regulations and in your 'reflect.txt' of part 2 (DIY), write exactly which part of your code was copied and who was the recipient of this code.<br />By doing this you will be clear of any wrongdoing if the recipient of the code does not honour these regulations.

## Compiling and Testing Your Program

All your code should be compiled using this command on `matrix`:

```bash
g++ -Wall -std=c++11 -g -o ws file1.cpp file2.cpp ...
```

- `-Wall`: the compiler will report all warnings
- `-std=c++11`: the code will be compiled using the C++11 standard
- `-g`: the executable file will contain debugging symbols, allowing *valgrind* to create better reports
- `-o ws`: the compiled application will be named `ws`

After compiling and testing your code, run your program as follows to check for possible memory leaks (assuming your executable name is `ws`):

```bash
valgrind --show-error-list=yes --leak-check=full --show-leak-kinds=all --track-origins=yes ws
```

- `--show-error-list=yes`: show the list of detected errors
- `--leak-check=full`: check for all types of memory problems
- `--show-leak-kinds=all`: show all types of memory leaks identified (enabled by the previous flag)
- `--track-origins=yes`: tracks the origin of uninitialized values (`g++` must use `-g` flag for compilation, so the information displayed here is meaningful).

To check the output, use a program that can compare text files.  Search online for such a program for your platform, or use *diff* available on `matrix`.

> Note: All the code written in workshops and the project must be implemented in the **sdds** namespace, unless instructed otherwise.

### Custom code submission

If you have any additional custom code, (i.e. functions and etc) that you want to reuse in the workshop add them to the module Utils (`Utils.cpp and Utils.h`) to submit them with your workshop 

# Part 1 - LAB (50%)

Your task is to create a module called **Assessments** (`Assessments.cpp and Assessments.h`) to implement multiple overloaded read functions to read a series of subject names and their average mark received by students. 

The file is in the following format:
- The first line is only an integer that is the number of upcoming records
- The rest of the file is the records of subject marks.<br />Each subject mark record consists of:
  - a double number (the mark)
  - comma
  - name of the subject
  - newline character
  
Example:
```text
5
70.9,Applied Problem Solving
55.5,Computer Principles for Programmers
63.8,Communicating Across Contexts 
88,Introduction to Programming Using C
78.9,Introduction to UNIX/Linux and the Internet

```

## implementation

Use the following structure to hold an assessment record.
For practice, both fields should be kept dynamically:

```cpp
struct Assessment {
   double* m_mark;
   char* m_title;
};
```

- m_mark will hold the address of a single double value that is kept dynamically in memory
- m_title will hold the address of a cstring that is kept dynamically in memory but will not be more than 60 + 1(null) characters. 
> Although the dynamic title of the assessment will not be 60 characters, but when allocating memory make sure the size of the dynamic cString is equal to the exact size of the data and not more.

## Functions to implement:

### `bool read(int& value, FILE* fptr);`
Reads one integer from the fptr file into the value reference and returns true if it was successful, otherwise, it will return false

### `bool read(double& value, FILE* fptr);`
Reads one double from the fptr file into the value reference and returns true if it was successful, otherwise, it will return false

### `bool read(char* cstr, FILE* fptr);`
Skips a comma and then reads a cstring no longer than 60 characters from the fptr file into the address, `cstr`  and returns true if it was successful, otherwise, it will return false

> Use the following format in the fscanf to accomplish this:<br/> `",%60[^\n]\n"`


### `bool read(Assessment& asmnt, FILE* fptr);`
First it will try to read a double value for the mark and a string for title into a temporary local double variable and a 60 character lone cString (+1 for null).

If the read is successful, it will then allocate a dynamic double and a dynamic cString to the exact size of the read cstring from the file into the fields of the asmnt structure (asmnt.m_mark and asmnt.m_title) and copies the values into them.<br />
In this case, the function will return true, otherwise, it will return false with no memory allocation.

### `void freeMem(Assessment*& aptr, int size);`
This function will receive a reference of a dynamic Assessment array and its size.
The function then will delete the dynamic Assessment array as follows:

The dynamic array will be deleted by first going through each element of the Assessment array in a loop, deleting the dynamic double and the dynamic cString of all Assessment elements and then it will delete the array itself.


### `int read(Assessment*& aptr, FILE* fptr);`

This read function receives a reference of an Assessment pointer (to hold a dynamic array) and a file pointer from which it will read the assessment records into a newly allocated dynamic array.

The function will first read one integer which is the number of upcoming records to read.

Then it will allocate a dynamic array of Assessments in the `aptr` pointer reference. After allocating the memory, in a loop, it will read each record of the file into the Assessment elements (use the proper read overload for this). 
This loop should stop either if the number of reads reaches the number of elements or if the read function fails.

When the loop is done compare the number of reads to the number of elements of the array. If the number is not a match, free the Memory of the dynamic array (`freeMem`) and return zero, otherwise, return the size of the array.


## Tester Program
```c++
/***********************************************************************
// OOP244 Workshop 2: tester program
//
// File	main.cpp
// Version 1.0
// Date	2022/09/17
// Author	Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include "Assessment.h"
#include "Utils.h"
using namespace sdds;
using namespace std;
void display(const Assessment& a);
bool readTesters();
int main() {
   if(readTesters()) {
      int cnt;
      Assessment* aptr = nullptr;
      FILE* fptr = fopen("baddata.txt", "r");
      cnt = read(aptr, fptr);
      if(cnt) {
         cout << "This should have failed, keep working on the workshop!" << endl;
      } else {
         cout << "File records and number of records do not match" << endl;
      }
      fclose(fptr);
      cout << "Listing Good Data:" << endl;
      fptr = fopen("gooddata.txt", "r");
      cnt = read(aptr, fptr);
      if(cnt) {
         for(int i = 0; i < cnt; i++) {
            cout << (i + 1) << ": ";
            display(aptr[i]);
         }
         freeMem(aptr, cnt);
      } else {
         cout << "This should not have failed, keep working on the workshop!" << endl;
      }
      fclose(fptr);
   }
   return 0;
}
void display(const Assessment& a) {
   cout.setf(ios::fixed);// setting the number of digits
   cout.precision(1);    // after the decimal point to 1
                         // this will be covered later
   cout << a.m_title << ": " << *a.m_mark << endl;
}

bool readTesters() {
   FILE* fptr = fopen("gooddata.txt", "r");
   bool passed = true;
   int i;
   double d;
   char str[61];
   if(read(i, fptr) && i == 13) {
      cout << "bool read(int& value, FILE* fptr) test passed" << endl;
   }
   else {
      cout << "bool read(int& value, FILE* fptr) test failed" << endl;
      passed = false;
   }
   if(passed && read(d, fptr) && (d - 70.9) < 0.0001 && (d - 70.9) > -0.0001) {
      cout << "bool read(double& value, FILE* fptr) test passed" << endl;
   } 
   else {
      cout << "bool read(double& value, FILE* fptr) test failed" << endl;
      passed = false;
   }
   if(passed && read(str, fptr) && strcmp(str, "Applied Problem Solving") == 0)  {
      cout << "bool read(double& value, FILE* fptr) test passed" << endl;
   } 
   else {
      cout << "bool read(double& value, FILE* fptr) test failed" << endl;
      passed = false;
   }
   fclose(fptr);
   return passed;
}
```
## Execution Sample
```text
bool read(int& value, FILE* fptr) test passed
bool read(double& value, FILE* fptr) test passed
bool read(double& value, FILE* fptr) test passed
File records and number of records do not match
Listing Good Data:
1: Applied Problem Solving: 70.9
2: Computer Principles for Programmers: 55.5
3: Communicating Across Contexts : 63.8
4: Introduction to Programming Using C: 88.0
5: Introduction to UNIX/Linux and the Internet: 78.9
6: Introduction to Database Systems: 98.0
7: Data Communications Fundamentals: 100.0
8: Introduction to Object Oriented Programming: 83.3
9: Web Programming Principles: 50.0
10: Advanced Database Services: 77.2
11: Object-Oriented Software Development Using C++: 85.5
12: Software Analysis and Design - I: 90.0
13: Web Programming Tools and Framework: 95.0
```
## PART 1 Submission (lab)

### Files to submit:  

```Text
Assessment.cpp
Assessment.h 
Utils.cpp  
Utils.h
main.cpp  
```


### Data Entry

No data entry needed

### Submission Process:

Upload the files listed above to your `matrix` account. Compile and run your code using the `g++` compiler as shown in [Compiling and Testing Your Program](#compiling-and-testing-your-program) and make sure that everything works properly.

Then, run the following command from your account
- replace `profname.proflastname` with your professor’s Seneca userid
- replace **??** with your subject code (2**00** or 2**44**)
- replace **#** with the workshop number
- replace **X** with the workshop part number (**1** or **2**) 
```text
~profname.proflastname/submit 2??/w#/pX
```
and follow the instructions.



> **⚠️Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.


# DIY (50%)

Write a **postal-code-based population report** program that reads series of records of postal codes and their population in Canada from a comma-separated-values file and prints a report of the postal code and their population sorted in an ascending order based on the population of the account. 

The data file is called `PCpopulations.csv` and is formatted like as follows:
  
```Text
Three First Characters of postal code
comma
population
newline
```

Example:

```Text
A0A,46587
A0B,19792
A0C,12587
A0E,22294
A0G,35266
A0H,17804
A0J,7880
A0K,26058
A0L,7643
A0M,6200
A0N,13815
A0P,13721
A0R,2543
A1A,30382
A1B,19867
```

## DIY Execution example (with the incomplete sample file)
```text
Postal Code: population
-------------------------
1- A0R:  2543
2- A0M:  6200
3- A0L:  7643
4- A0J:  7880
5- A0C:  12587
6- A0P:  13721
7- A0N:  13815
8- A0H:  17804
9- A0B:  19792
10- A1B:  19867
11- A0E:  22294
12- A0K:  26058
13- A1A:  30382
14- A0G:  35266
15- A0A:  46587
-------------------------
Population of Canada: 282439
```

Implement this program in 2 modules called `File` and `Population` that can accomplish the above task.  

***You may freely use/copy any logic or code needed from the LAB section!***

## `File` Module

The `File` module is partially implemented. 


## `Population` Module

The `Population` module is not implemented.

There are three mandatory functions in the `Population` module. Apart from these three functions you are free to choose any method to implement this system, however you must use function overloading, reference and dynamic memory allocation since the number of records in submission will be much more that what you have for development.

Mandatory functions in this module:

- `load`: Loads data from a file, and returns `true` if data was successfully loaded, `false` otherwise. This function receives as a parameter the name of the file
    - If the file cannot be found, print the following error message: 
    ```Text
    Could not open data file: FILENAME<ENDL>
    ```

    - If the file doesn't have a correct content, print:
    ```Text
    Error: incorrect number of records read; the data is possibly corrupted!<ENDL>
    ```

- `display`: a function with no parameters that return nothing and prints the report as shown in [DIY Execution example](#diy-execution-example).

- `deallocateMemory`: a function with no parameters that return nothing and deallocate **all** dynamic memory used by the program.



## Tester Program
```C++
/***********************************************************************
// OOP244 Workshop 2 p2: tester program
//
// File	main.cpp
// Version 1.0
// Date	2022/09/17
// Author	Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include "Population.h"
using namespace sdds;
int main() {
   if (load("PCpopulations.csv")) {
      display();
   }
   deallocateMemory();
   return 0;
}
```

## Reflection

Study your final solutions for each deliverable of the workshop, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop.  **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this workshop and mention any issues that caused you difficulty.

You may be asked to talk about your reflection (as a presentation) in class.

## Part 2 Submission (DIY)

### Files to submit:  

```reflect.txt``` and:
```Text
popReport.cpp <--- contains the main function, do not modify this.
File.cpp
File.h
Population.cpp
Population.h
main.cpp
```

#### Custom code submission

If you have any additional custom code, (i.e. functions, classes etc) that you want to reuse in this workshop save them under a module called Utils (`Utils.cpp and Utils.h`) and submit them with your workshop using the instructions in the "[Submitting Utils Module](#submitting-utils-module)" section.

### Data Entry

No data entry needed

### Submission Process:

Upload the files listed above to your `matrix` account. Compile and run your code using the `g++` compiler as shown in [Compiling and Testing Your Program](#compiling-and-testing-your-program) and make sure that everything works properly.

Then, run the following command from your account
- replace `profname.proflastname` with your professor’s Seneca userid
- replace **??** with your subject code (2**00** or 2**44**)
- replace **#** with the workshop number
- replace **X** with the workshop part number (**1** or **2**) 
```text
~profname.proflastname/submit 2??/w#/pX
```
and follow the instructions.

#### Submitting Utils Module
To have your custom Utils module compiled with your workshop and submitted, add a **u** to the part number of your workshop (i.e **u**p1 for part one and **u**p2 for part two) and issue the following submission command instead of the above:
```text
~profname.proflastname/submit 2??/w#/upX
```
See [Custom Code Submission](#custom-code-submission) section for more detail

> **⚠️Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.


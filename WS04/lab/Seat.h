/*
====================================================================
workshop -4 part -1
====================================================================
Name: Harshil Dineshbhai Thakkar
Student Id: 160431219
E-mail : hthakkar8@myseneca.ca
Date :04-10-2022
OOP244 NEE

--------------------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
====================================================================
*/

#ifndef SDDS_SEAT_H_
#define SDDS_SEAT_H_
namespace sdds
{
   class Seat
   {

      //------------------------------
      // Attributes & Private methods
      //------------------------------


      char* passengerName;
      int seatRow;
      char seatLetter;
      // returns true if the row number and the seating letter, together correctly address a seat in the airplane
      bool validate(int row, char letter) const;

      // allocates memory for passenger name and copies values into the allocated memory
      // returns the refrence of the current object
      Seat &alAndCp(const char *str);

   public:
      //------------------------------
      // Safe Empty state and Seating
      //------------------------------

      // This function resets the object into a safe empty state
      Seat &reset();

      // returns if the object is in an empty state (true =empty / false= !empty)
      bool isEmpty() const;

      // returns true if the seats are assigned and valid othervise false
      bool assigned() const;

      //-----------------------------
      // Constructors and destructor
      //-----------------------------

      // No argument constructor
      Seat();

      // One argument constructor
      Seat(const char *passengerName);

      // Three argument constructor
      Seat(const char *passengerName, int row, char letter);

      // Destructor
      ~Seat();

      //----------------------------
      // Modifier and Query Methods
      //----------------------------

      // this function first validates the row and letter & if valid then sets the values else sets to zero.
      Seat &set(int row, char letter);

      // Returns the row attribute value.
      int row() const;

      // Returns the letter attribute value.
      char letter() const;

      // Returns the value of the passenger name pointer attribute.
      const char *passenger() const;

      //--------------
      // Input/Output
      //--------------

      // prints the passenger and seat information
      std::ostream& display(std::ostream &coutRef = std::cout) const;

      // Extracts the passanger name, seat row letter and number in three local function scope variables
      std::istream& read(std::istream& cinRef = std::cin);

   };
}
#endif // !SDDS_SEAT_H_

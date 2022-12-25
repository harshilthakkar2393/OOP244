// Author: Cornel
#include <iostream>
#include "word.h"
#include "dictionary.h"

using namespace std;

int main()
{
	// USAGE CASE #1: load a dictionary from a file that doesn't exist
	cout << "------------------------------------------------------------\n";
	cout << "USAGE CASE #1: bad input file\n";
	cout << "------------------------------------------------------------\n";
    if (sdds::LoadDictionary("missing.txt") == 0)
    {
		cout << "ERROR: There is no file; the function 'LoadDictionary()' should return non-zero value.\n";
		cout << "       Keep working on your code.\n";
	}
	else
	{
		cout << "SUCCESS\n";
	}
	cout << "------------------------------------------------------------\n\n";



	// USAGE CASE #2: load a valid dictionary from the file and display it to the user
	cout << "------------------------------------------------------------\n";
	cout << "USAGE CASE #2: good dictionary\n";
	cout << "------------------------------------------------------------\n";
	if (sdds::LoadDictionary("dictionary.txt") == 0)
	{
		cout << "SUCCESS\n";

		std::cout << "\nSearch for the word 'fine'\n\n";
		sdds::DisplayWord("fine");

		std::cout << "\nAdding 2 more definitions to word 'fine' and display it.\n\n";
		sdds::AddWord("fine", "verb", "clarify (beer or wine) by causing the precipitation of sediment during production.");
		sdds::AddWord("fine", "verb", "make or become thinner.");
		sdds::DisplayWord("fine");

		// std::cout << "\nSeach for words containing 'very' in their definition.\n\n";
		// sdds::DisplayMatches("very");
		std::cout << "\nDisplay the word 'apple'.\n\n";
		sdds::DisplayWord("apple");

		std::cout << "\nOOOPS! The SECOND definition for apple is wrong. Let's update it.\n\n";
		sdds::UpdateDefinition("apple", "noun", "the tree which bears apples.");
		std::cout << "\n";
		sdds::DisplayWord("apple");

		// add a few more words
		std::cout << "\n\nAdding more words and display them.\n\n";

		sdds::AddWord("language", "noun", "a system of communication used by a particular country or community.");
		sdds::AddWord("computer", "noun", "an electronic device for storing and processing data, "
		                                  "typically in binary form, according to instructions "
		                                   "given to it in a variable program.");
		sdds::AddWord("computer", "noun", "a person who makes calculations, especially with a calculating machine.");
		sdds::DisplayWord("language");
		std::cout << "\n";
		sdds::DisplayWord("computer");

		sdds::SaveDictionary("dictionary_better.txt");
	}
	else
	{
		cout << "ERROR: There is no file; the function 'LoadDictionary()' should return non-zero value.\n";
		cout << "       Keep working on your code.\n";

	}
	cout << "------------------------------------------------------------\n\n";


	// USAGE CASE #3: load a dictionary from a file that doesn't exist
	cout << "------------------------------------------------------------\n";
	cout << "USAGE CASE #3: bad input file\n";
	cout << "------------------------------------------------------------\n";
	if (sdds::LoadDictionary("missing_better.txt") == 0)
	{
		cout << "ERROR: There is no file; the function 'LoadDictionary()' should return non-zero value.\n";
		cout << "       Keep working on your code.\n";
	}
	else
	{
		cout << "SUCCESS\n";

		// the loaded dictionary should be empty now
		// the following function should not find anything
		sdds::DisplayWord("apple");
	}
	cout << "------------------------------------------------------------\n\n";


	// USAGE CASE #4: load the previously saved distionary
	cout << "------------------------------------------------------------\n";
	cout << "USAGE CASE #4: loading the previously saved dictionary\n";
	cout << "------------------------------------------------------------\n";
	if (sdds::LoadDictionary("dictionary_better.txt") == 0)
	{
		cout << "SUCCESS\n";

		std::cout << "Search for the word 'apple'\n\n";
		sdds::DisplayWord("apple");

		std::cout << "\n\nSearch for the word 'language'\n\n";
		sdds::DisplayWord("language");

		std::cout << "\n\nSearch for the word 'computer'\n\n";
		sdds::DisplayWord("computer");

		std::cout << "\n\nSearch for the word 'oop'\n\n";
		sdds::DisplayWord("oop");
	}
	else
	{
		cout << "ERROR: The dictionary should be valid; the function 'LoadDictionary()' should return non-zero value.\n";
		cout << "       Keep working on your code.\n";
	}
	cout << "------------------------------------------------------------\n\n";




    return 0;
}

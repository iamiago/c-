//Header file containing declaration of functions
//pre-processor directives
#ifndef Person_HPP  // if not defined
#define Person_HPP	// define

#include "datasimdate.hpp" // dates and other stuff
#include <string>

using namespace std;

class Person{
public: // Everything is public for convinience in this example

	//data
	string name;			// name of person
	DatasimDate dob; 		// date of birthday
	DatasimDate createdD;	// when obj was created
public:

	Person(const string& Name, const DatasimDate& DateOfBirth);
	void print() const;
	int age() const;
};

#endif

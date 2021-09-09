//Code file containing bodies of functions 
#include "Person.hpp"

//constructor
Person::Person(const string& Name, const DatasimDate& DateOfBirth){
	
	name=Name;
	dob=DateOfBirth;
	createdD=DatasimDate();		// default today
}
// methods
void Person::print() const {
	cout << "\n ** Person Data ** \n";
	cout << "Name: " << name <<< ", Date of birth: " << dob << ", Age: " << age() << "\n";
}

int Person::age() const{
	return int(double(DatesimDate()-dob)/365.0);
}

#ifndef Conversions_CPP
#define Conversions_CPP

#include "Conversions.hpp"
#include <sstream>
#include <string>

using namespace std;

template<typename T> 
string toString(const T& value){
	stringstream s;
	s << value;
	return s.str();
}

#endif

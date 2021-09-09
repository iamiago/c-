#ifndef exception_lib_HPP
#define exception_lib_HPP

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class exception_lib
{// Base class for my current exceptions
	
private:
	string mess;
	string meth;
	string why;
	
	vector<string> result;

public:
	exception_lib();
	exception_lib(const string& message, const string& method, const string& extraInfo);
	string Message() const;
	string rationale() const;
	string Method() const;
	
	vector<string> MessageDump() const;
	
	virtual void print() const;
};
#endif

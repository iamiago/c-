#include "exception_lib.hpp"

exception_lib::exception_lib()
{
	mess=meth=why=string();
	result = vector<string>(3);
	result[0] = mess;
	result[1] = meth;
	result[2] = why;
}

exception_lib::exception_lib(const string& message, const string& method, const string& extraInfo)
{
	mess = message;
	meth = method;
	why = extraInfo;
	result = vector<string>(3);
	result[0] = mess;
	result[1] = meth;
	result[2] = why;
}

string exception_lib::Message() const
{
	return mess;
}

string exception_lib::rationale() const 
{
	return why;
}

string exception_lib::Method() const
{
	return meth;
}

vector<string> exception_lib::MessageDump() const
{
	return result;
}

void exception_lib::print() const
{
	//Variant part
	vector<string> r = MessageDump();
	
	cout << "\n" << r[0] << "\n";
	//Invariant part
	for(int i=1; i<(int)r.size(); ++i){
		cout <<"\t   - "<< r[i] << "\n";
	}
	cout <<"\n";
}

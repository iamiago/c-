#include <iostream>
#include "exception_lib.hpp"
#include <string>
using namespace std;

double Divide(double x, double y){
	if (y == 0)
	{
		throw exception_lib(string("[Exception]: Divide by zero"),string("In function Divide"),string("Try with non-zero value"));
	}
	return x/y;
}
int main () 
{
LIB1:	try
	{
		cout << "Give a number to dividee by: \n";
		double y; cin >> y;
		
		cout << Divide(2.0, y);
	}
	catch (exception_lib& e)
	{
		e.print();
		goto LIB1;
	}
	return 0;
}

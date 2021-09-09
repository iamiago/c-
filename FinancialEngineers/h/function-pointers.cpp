#include <iostream>

using namespace std;

//function with an embedded function pointer
void genericFunction(double a, double b, double (*f) (double x, double y))
{ // call the function f with arguments a and b
	double result=(*f)(a,b);
	cout << "Result is: " << result << endl;
}
double add(double x, double y)
{
	cout << "** Adding two numbers: " << x << ", " << y << endl;
	return x+y;
}

double multiply(double x, double y)
{
	cout << "** Multiplying two numbers: "<< x<< ", "<< y << endl;
	return x*y;
	
}
double substract(double x, double y)
{
	cout << "** Substracting two numbers: "<< x << ", "<< y << endl;
	return x-y;
}

int main (){
	
	double x = 3.0;
	double y = 2.0;
	
	genericFunction(x,y,add);
	genericFunction(x,y,multiply);
	genericFunction(x,y,substract);
	
	return 0;
}

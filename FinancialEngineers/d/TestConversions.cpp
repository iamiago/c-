#include <iostream>
#include "Conversions.cpp"
using namespace std;

int main (){
	int i=0;
	long j=1234567890;
	float f=3.14f;
	double d =2.71222222222223;
	string myString = toString<int>(i);
	cout << myString << "\n";
	
	myString = toString<long>(j);
	cout << myString << endl;
	
	myString = toString<float>(f);
	cout << myString << endl;
	
	myString =toString<double>(d);
	cout << myString << endl;
	return 0;
}

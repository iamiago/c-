//Main program (console-based) to test functions
#include <iostream>

#include "Inequalities.hpp"

using namespace std;

int main(){
	double d1, d2;
	cout << "First number : ";
	cin >> d1;
	cout << "Second number : ";
	cin >> d2;
	
	char c;
	cout << "Which function a) Max() or b) Min()? ";
	cin >> c;
	if (c=='a') cout << "Max value is : " << Max(d1,d2) << "\n";
	else cout <<"Min value is : " << Min(d1,d2) << "\n";
	
	double dA =1.0, dB=2.0, dC=3.5;
	cout<<"_\n \nMax and min of three numbers : \n";
	cout<<"Max value is: " << Max(dA,dB,dC) << "\n";
	cout<<"Min value is: "<< Min(dA,dB,dC) << "\n";
	return 0;
}

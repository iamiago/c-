#include <iostream>
#include "GenericInequalities.cpp"

using namespace std;

int main (){
	int d1,d2;
	cout << "Give the first numer: ";
	cin >> d1;
	cout << "Gibe the second number: ";
	cin >> d2;
	
	char c;
	cout << "Which function a-Max() or b-Min()? ";
	cin >> c;
	if(c=='a') cout << "Max value is: " << Max<int>(d1,d2) << "\n";
	else cout << "Min value is : " << Min<int>(d1,d2) << "\n";
	
	long dA = 1234, dB =2, dC=-4;
	cout << "\n\nMax and min of three numbers: \n";
	cout << "Max: "<< Max<long>(dA,dB,dC) << "\n";
	cout << "Min: "<< Min<long>(dA,dB,dC)<< "\n";
	
	return 0;
}

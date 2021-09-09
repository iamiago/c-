#include <iostream>

using namespace std;

class SimpleOption
{
public:
	double T;
	double K;
	
	//Constructor
	SimpleOption() { T = 1.0; K= 100.0;}
	
	void print() const
	//the const at the end of a function makes the (this) pointer const (which means you cannot modifiy parameters
	{
		cout << "Expiry: " << T << ", " << "Strike: " << K << endl;
	}
};

int main (){
	
	//Defining a scope
	{
		int j=90;
		cout << j << endl;
	}
	//~ cout << j ; //Compiler error j was not declared in this scope
	
	//static array, size is known at compile time and its impossible to extend its size in run-time
	int array[10];
	for(int i=0; i <10; i++){
		array[i] = i+1;
		cout << array[i] << ", ";
	}
	cout << endl;
	//~ cout << endl << array[-1];  // error below bounds of array indexation
	//~ cout << endl << array[100]; // error above bound of array indexation
	
	
	{//Defines a scope
		SimpleOption opt1;
		opt1.print();
	}
	SimpleOption myPortfolio[10]; 
	for(int i=0; i<10; ++i){
			myPortfolio[i].print();
	}
	return 0;
}

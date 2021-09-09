#include <iostream>

using namespace std;

class SimpleOption
{
public:
	double T;
	double K;
	
	//Constructor
	SimpleOption() { T = 1.0; K= 100.0;}
	SimpleOption(double t, double k)
	{
		T=t;
		K=k;
	}
	
	void print() const
	//the const at the end of a function makes the (this) pointer const (which means you cannot modifiy parameters
	{
		cout << "Expiry: " << T << ", " << "Strike: " << K << endl;
	}
};

int main (){
	
	//Declaring a pointer data type(no definition, no memory allocated)
	SimpleOption* opt;
	SimpleOption* opt2;
	
	//~ opt->print();  // variable is used uninitialized -> segmentation fault
	//~ opt2->print(); // variable is used uninitialized -> segmentation fault
	
	//Allocating memory for that data type
	opt = new SimpleOption;
	opt2 = new SimpleOption(0.25, 90.0);
	
	opt->print();
	(*opt2).print(); // dereferencing the pointer to get the object itself
	
	{	// Creating another scope , since it has been allocated to the heap section of the memory, its accesible to any scope
	
		cout << endl <<"In another scope : " << endl;
		opt->print();
		(*opt2).print();
		cout << endl;
		
	}
	delete opt;
	delete opt2;
	
	//~ opt->print(); 	 // Completely arbitraty values are printed
	//~ (*opt2).print(); // Completely arbitraty values are printed
	
	opt = new SimpleOption;
	(*opt).print();
	delete opt;
	
	//Array of options
	SimpleOption* optArray;
	
	const int n = 10;
	optArray = new SimpleOption[n]; // default constructor called (memory leak with sanitizers(if not deleted in the end)
	
	for(int i=0; i<n; ++i)
	{
		optArray[i].T = i;
		optArray[i].K = 100*i;
		optArray[i].print();
	}
	delete [] optArray;
	
	return 0;
}

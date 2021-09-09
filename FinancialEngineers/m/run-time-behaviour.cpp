#include <iostream>
#include <vector>
using namespace std;

class Base
{
public:
	Base() {}
	virtual ~Base() {}
	
	virtual void print() const { cout << "I'm base class \n";}
	virtual double calculate(double d) const = 0;
};

class D1 : public Base
{
public:
	D1() {}
	virtual ~D1() {}
	
	virtual void print() const { cout << "I'm D1 class \n";}
	virtual double calculate(double d) const { return 1.0*d; }
	
};

class D2 : public Base
{
public:
	D2(){}
	virtual ~D2() {}
	
	virtual void print() const { cout << "I'm D2 class \n";}
	virtual double calculate(double d) const { return 2.0*d;}
};

int main ()
{
	D1 d1, d11;
	D2 d2;
	
	//Define a reference to typeid
	const type_info& myRef = typeid(d1);
	
	cout << "Human-readable name: " << myRef.name() << endl;
	
	//Test if two objects have same type
	if(typeid(d1) == typeid(d11)) cout << "Types are the same \n";
	if(typeid(d2)!=typeid(d1)) cout <<"Types are different \n";
	
	Base* b = &d1;
	const type_info& myRef2 = typeid(*b);
	cout << "Human-readable name: " << myRef2.name() << endl;
	
	//useful to know the type of derived class object from base
	
	//Array of base class pointers
	const int size = 10;
	Base* myArr[size];
	
	for(int i=0; i<6; ++i){
		myArr[i] = &d1;
	}
	for(int i=6; i<size; ++i){
		myArr[i] = &d2;
	}
	
	//now filter the real types
	int cptD1 = 0;
	int cptD2 = 0;
	
	for(int i = 0; i  < size ; ++i){
		
		if(typeid(*myArr[i]) == typeid(D1)){
			cout << "We have a member of D1\n";
			cptD1++;
		}
		if(typeid(*myArr[i]) ==  typeid(D2)){
			cout << "We have a member of D2\n";
			cptD2++;
		}
	}
	cout << "Number of D1s: " << cptD1 << endl;
	cout << "Number of D2s: " << cptD2 << endl;
	
	//Casting between types
	//process of converting an object pointer of one class to an object pointer of another class
	//static casting for non polymorphic classes
	//dynamic casting for polymorphic class (class with atleast one virtaul function)
	
	//Down casting example, base class pointer to a derived class pointer
	D1 d1A;
	Base* base2 = &d1A;
	
	//attempt to cast the pointer base2 to a pointer of class D1 (here its possible because its the same class)
	D1* d1Cast = dynamic_cast<D1*> (base2);
	
	if(d1Cast == 0) cout << "Cast not possible\n"; //Should throw an exception here
	else{
		cout << "Cast is possible: ";
		d1Cast->print();
	}

	//Attempt to cast the pointer base2 to a pointer of class D2 (here its impossible bacause base2 points to D1 a different class)
	D2* d2Cast = dynamic_cast<D2*> (base2);
	
	if(d2Cast == 0) cout << "Cast not possible\n";
	else{
		cout << "Cast is possible: ";
		d2Cast->print();
	}	
	
	//Up casting example, devired class pointer to a base class pointer
	D1* dd = new D1;
	//attempt to cast the pointer dd to a pointer of class Base (here its possible because D1 is derived from Base)
	Base* b3 = dynamic_cast<Base*> (dd);
	if(b3 == 0) cout << "Cast not possible \n";
	else{
		cout << "Cast is possible: ";
		b3->print(); // should print Base class
	}
	delete dd;
	
	//Static casting
	
	Base* bA = &d1;
	//~ Base* bB = &d2;
	
	D1* dA = static_cast<D1*> (bA);
	dA->print();
	cout << "Unsafe cast...\n";
	//~ D1* dB = static_cast<D1*>(bB);
	//~ dB->print();
	return 0;
}	

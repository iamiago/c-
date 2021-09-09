#include <iostream>
using namespace std;
// Example of a canonical head file

//Abstract class
class Payoff
{
public:
	//Constructor and destructor
	Payoff();						//Default constructor
	Payoff(const Payoff& source);	//Copy constructor
	virtual ~Payoff(){}
	
	//Operator overloading
	Payoff& operator = (const Payoff& source);
	
	//Pure virtual payoff function
	virtual double payoff(double S) const = 0; 	//Spot price S
};

//class inheriting from abstract class (preferably in another header file)
class CallPayoff: public Payoff
{
private:
	double K; 						//Strike price
public:
	//Constructor and destructor
	CallPayoff();
	CallPayoff(double strike);
	CallPayoff(const CallPayoff& source);
	virtual ~CallPayoff(){}
	
	//Selectors
	double Strike() const; 			//Return strike price
	
	//Modifiers
	void Strike(double NewStrike); 	//Set strike price
	
	//Operator overloading
	CallPayoff& operator = (const CallPayoff& source);
	
	//Implement the pure virtual payoff function from base class
	double payoff(double S) const;
};

CallPayoff::CallPayoff()
{
	K=0.0;
}
CallPayoff::CallPayoff(double strike)
{
	K=strike;
}

CallPayoff::CallPayoff(const CallPayoff& source) : Payoff(source)
{ // Copy constructor
	K = source.K;
}

CallPayoff& CallPayoff::operator = (const CallPayoff& source)
{// Assignment operator
	//Exit if its the same object
	if(this==&source) return *this;
	
	//Call base class assignment
	Payoff::operator = (source);
	
	//Copy state
	K=source.K;
	
	return *this;
}

double CallPayoff::Strike() const
{
	return K;
}

void CallPayoff::Strike(double NewStrike)
{
	K = NewStrike;
}

double CallPayoff::payoff(double S) const
{
	if(S>K) return (S-K);
	return 0.0;
}



int main ()
{
	
	return 0;
}

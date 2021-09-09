#include <iostream>
using namespace std;
//Options that depend on two or more underlying assets		Exchnage , Rainbow, Basket, Best/worst, Quotient, Foreign exchange, Spread, Dual-strike, Out-performance options
//implementation for the payoff functions for these types 
//class hierarchy
//Base class and derived classes, with one derived class for each payoff function


//The abstract base class
class MultiAssetPayoffStrategy
{//Interface specification
public:
	virtual double payoff(double S1, double S2) const = 0;
	//No default structure behaviour defined here
	//Only pure virtual function specification describing the pricing function based on two underlyings
	//Each derived class must implement this function
};

class BasketStrategy: public MultiAssetPayoffStrategy
{// 2-asset basket option payoff
private:
	double K; 				//Strike price
	double w; 				//+1 call, -1 put
	double w1, w2; 			// w1 + w2 = 1
	
public:
	//All classes need default constructor
	// we use the colon syntax ':' to call the constructor of the base class from derived class
	// this ensures that the member data in the base class will be initialised
	BasketStrategy():MultiAssetPayoffStrategy()
	{
		K=95.0; w = +1; w1 = 0.5; w2 = 0.5;	
	}
	BasketStrategy(double strike, double cp, double weight1, double weight2):MultiAssetPayoffStrategy()
	{
		K=strike; w=cp; w1=weight1; w2=weight2;
	}
	double payoff(double S1, double S2) const
	{
		double sum = w1*S1+w2*S2;
		return max(w*(sum-K),0.0);
	}
};

//We can now use it for two-factor payoff
class TwoFactorInstrument
{//Empty class
public:
};

class TwoFactorOptionData: public TwoFactorInstrument
{
public:
	//An option uses a polymorphic payoff object
	BasketStrategy pay;
public:
	//Public for convinience, 13 parameters
	double r; 				// Interest rate (taux d'interet)
	double D1, D2;			// Dividends
	double sig1, sig2;		// Volatility
	double rho;				// Cross correlation
	double K;				// Strike price, now place in IC
	double T; 				// Expiry date
	double SMax1, SMax2;	// Far field condition
	double w1,w2;
	int type;				// call +1 or put -1
	
	//Constructors
	TwoFactorOptionData()
	{//initialise all data and the payoff, use topper's data as the default
		r=0.01;
		D1=D2=0.0;
		sig1=0.1;sig2=0.2;
		rho=0.5;
		K=40.0;
		T=0.5;
		w1=1.0;
		w2=20.0;
		type = -1;
		//Create the payoff Strategy object
		//~ BasketStrategy(double strike, double cp, double weight1, double weight2)
		//~ {
			//~ K=strike; w=cp; w1=weight1; w2=weight2;
		//~ }
		
		pay = BasketStrategy(K,type,w1,w2);
		//1) we need a Factory object as we have done in the one-dimensional case
		//2) work with pointer to base classes
	}
	
	double payoff(double x, double y) const
	{
		return pay.payoff(x,y);
	}
		
	
};

int main (){
	BasketStrategy b = BasketStrategy();
	cout << b.payoff(204,100) << endl;
	return 0;	
}

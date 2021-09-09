#include <iostream>
using namespace std;

//Initial Boundary Value Problem Implementation
class IBVPImp
{
public:
	
	virtual double diffusion(double x, double t) const = 0;
	virtual double convection(double x, double t) const = 0;
	virtual double zeroterm(double x, double t) const = 0;
	virtual double RHS(double x, double t) const = 0;
	virtual double BCL(double t) const = 0;
	virtual double BCR(double t) const = 0;
	virtual double IC(double x) const = 0;
	
};

class Instrument{
public:
};

class Option: public Instrument{
public:
	//Data public for convenience only
	double r; double sig; double K; double T; double b;
	Option(){}
	//An option uses a polymorphic payoff object
	
	//~ OneFactorPayoff OptionPayoff;
};

//Black and Scholes Initial Boundary Value Problem Implementation
class BSIBVPImp : public IBVPImp
{
public:
	Option* opt;
	BSIBVPImp(Option& option){ opt = &option;};
		
	double diffusion(double x, double t) const
	{
		double v = (opt -> sig);
		return 0.5 * v * v * x * x;
	}
	
	double convection(double x, double t) const
	{
		return (opt->r) * x;
	}
	
	double zeroterm(double x, double t) const
	{
		return -(opt->r);
	}	
	
	double RHS(double x, double t) const
	{
		return 0.0;
	}
	
	double BCL(double t) const
	{
		return 0.0;
	}
	
	double BCR(double t) const
	{
		return 3.0*(opt->K);
	}
	
	double IC(double x) const
	{
		//~ return (*opt).OptionPayoff.payoff(x);
	}
	//Define the other coefficients here
};

int main (){

	return 0;
}

#ifndef EuropeanOption_HPP
#define EuropeanOption_HPP
#include <string>

class EuropeanOption
{
private:
	void init(); 		// initialize with default values
	void copy(const EuropeanOption& o2);
	// private functions for options calculations "Kernel function" or "functions noyaux"
	double CallPrice() const;
	double PutPrice() const;
	double CallDelta() const;
	double PutDelta() const;
	
	
public:
	//public member data for convenience only of the example
	double r;		// interest rate ou taux d'interet
	double sig;		// volatility ou volatilité
	double K;		// Strike price ou prix d'exercice
	double T; 		// Expiry date ou date de maturité
	double U; 		// Current underlying price prix actuel de l'actif sous-jacent
	double b;		// Cost of carry
	
	string optType; // Option name (call, put)

public:
	//Constructors
	EuropeanOption();	//default call option
	EuropeanOption(const EuropeanOption& option2); //Copy constructor
	EuropeanOption(const string& optionType);	//Create option type
	
	//Destructor
	virtual ~EuropeanOption();
	
	//Assignment operator
	EuropeanOption& operator = (const EuropeanOption& option2);
	
	//Functions that calculate option price and (some) sensitivities
	double Price() const;
	double Delta() const;
	
	//Modifier functions
	void toggle(); 	//change option type (Call to Put, Put to Call)
	
	
};
#endif

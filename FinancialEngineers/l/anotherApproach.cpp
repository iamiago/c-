#include <iostream>
using namespace std;

class OneFactorPayoff
{
private:
	double K;
	double (*payoffFN)(double K, double S);				//Pointer to a payoff function to be defined
	
public:
	//Constructors and destructor
	OneFactorPayoff(double strike, double(*payoff)(double K, double S));
	
	
	
	double payoff(double S) const; 						// for a given spot price
};

OneFactorPayoff::OneFactorPayoff(double strike, double(*pay)(double K, double S))
{
	K=strike;
	payoffFN = pay;
}

double OneFactorPayoff::payoff(double S) const
{	// for a given spot price
	return payoffFN(K,S);
}

//1. write the apyoff functions we would like to use
//2. Create a instance of OneFactorPayoff with the payoff function of our choice
//3. Test and use the payoff class

double CallPayoffFN(double K, double S)
{	// Max(S-K,0)
	if(S>K) return (S-K);
	return 0.0;
}

double PutPayoffFN(double K, double S)
{	// Max(S-K,0)
	if(K>S) return (K-S);
	return 0.0;
}

int main ()
{
	OneFactorPayoff pay1(20.0, CallPayoffFN);
	cout << "Give a stock price (plain Call): ";
	double S;
	cin >> S;
	cout << "Call Payoff is: " << pay1.payoff(S) << endl;
	
	OneFactorPayoff pay2(20.0, PutPayoffFN);
	cout << "Give a stock price (plain Put): ";
	cin >> S;
	cout << "Put Payoff is: " << pay2.payoff(S) << endl;
	
	
	return  0;
}

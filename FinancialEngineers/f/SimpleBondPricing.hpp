#ifndef SimpleBondPricing_HPP
#define SimpleBondPricing_HPP

#include <vector>
using namespace std;

namespace Chapter3CPPBook
{
	//handy shorthand synonyms
	typedef vector<double> Vector;
	
	//Recursive function to calculate power of a number
	double power(double d, long n);
	
	//Future value of a sum of money invested today
	double FutureValue(double P0, long nPeriods, double r);
	
	//Future value of sum of money invested today, m periods per year
	// r is the annual interest rate
	double FutureValue(double P0, long nPeriods, double r, long m);
	
	//Continuous compouding, ie limi as m -> Infinity
	double FutureValueContinuous(double P0, long nPeriods, double r);
	
	//Future value of ordinary annuity
	double OrdinaryAnnuity(double A, long nPeriods, double r);
	
	//Present value
	double PresentValue(double Pn, long nPeriods, double r);
	
	//Present value of a series of future values
	double PresentValue(const Vector& prices, long nPeriods, double r);
}
#endif

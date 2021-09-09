#include <iostream>
//~ #include <math.h>
#include <cmath>

using namespace std;



double N(double x){ // phi(-infinity,x) normal cumulative distribution function
	return erfc(-x/sqrt(2))/2.0;
}


class NonlinearSolver
{
public:
	double (*myF)(double x); // the function we want to use
	double tol; 			 // the desired accuracy

public:
	//~ NonlinearSolver(double (*function)(double a), double TOL);
	virtual double solve() = 0;
};

class SteffensensSolver : public NonlinearSolver
{// One-step nonlinear solver
private:
	double x0; 					// Initial guess
	double xPrevious, xCurrent;
	long n;						// Number of iterations taken
	
public:
	SteffensensSolver(double guess, double (*myFunc) (double x))
	{
		x0=guess;
		xPrevious =0;
		myF = myFunc;
	}
	double solve()
	{
		double tmp, hn;
		n=1;
		xPrevious=x0;
L1:
		tmp=myF(xPrevious);
		hn = (myF(xPrevious + tmp) - tmp) /tmp;
		xCurrent = xPrevious - hn;
		xPrevious = xCurrent;
		
		n++;
		if(fabs(hn) <= tol)
		{
			return xCurrent;
		}
		goto L1;
	}
	void printStatistics() const
	{
		cout <<"** Data pertaining to Steffensen's method \n";
		cout <<"Value: " << xCurrent << "\nNumber of iterations(actual): " <<n << "\n";
		cout <<"**\n";
	}	
	
};

double SquareRoot(double x)
{
	return sqrt(2) -x;
}


double CallPrice(double sig)
{
	double S = 59.0;			// current price of underlying
	double K = 60.0;			//Strike price
	double r = 0.067; 			// 6.7% interest rate
	double marketPrice = 2.82;  // call price
	double b = r;				// cost of carry
	double T = 0.25; 			// Expiry date, three months
	
	double tmp = sig*sqrt(T);
	
	double d1 = ( log(S/K) + (b + (sig * sig) * 0.5) * T) / tmp;
	double d2 = d1 - tmp;
	
	double calculatedValue = (S * exp((b-r) * T) * N(d1)) - (K * exp(-r * T) * N(d2));
	
	//function in the form f(x) = 0
	return marketPrice - calculatedValue;
}	


class RegulaFalsi : public NonlinearSolver
{
public:
	double x0, xPrevious, xCurrent;
	long n;
public:
	RegulaFalsi(double guess, double (*myFunc)(double x)){
		x0=guess;
		xPrevious =0;
		myF=myFunc;
	}
	double solve(){
		double tmp, tmpp;
		double d=0;
		n=1;
		xPrevious=x0;
		double xxPrevious =100;
L1:
		
		tmp=myF(xPrevious);
		tmpp=myF(xxPrevious);
		d= ((xPrevious - xxPrevious)*tmp)/(tmp-tmpp);
		xCurrent = xPrevious - d;
		//~ cout << "[ ";
		//~ cout << "xPrevious: " << xPrevious<<", ";
		//~ cout << "tmp: " << tmp<<", ";
		//~ cout << "xxPrevious: " << xxPrevious<<", ";
		//~ cout << "tmpp: " << tmpp<<", ";
		//~ cout << "d: " << d<<", ";
		//~ cout << "xCurrent: " << xCurrent<<"]\n";
		xxPrevious = xPrevious;
		xPrevious = xCurrent;
		n++;
		
		if(fabs(tmp) <= tol || tmp==tmpp)
		{
			return xCurrent;
		}
		goto L1;
		
	}
	void printStatistics() const
	{
		cout <<"** Data pertaining to RegulaFalsi's method \n";
		cout <<"Value: " << xCurrent << "\nNumber of iterations(actual): " <<n << "\n";
		cout <<"**\n";
	}
};

class test
{
private: 
	double (*f)(double x);
	double tol;
public : 
	test( double (*function)(double a), double b)
	{
		f=function;
		tol =b;
	}
	double getTol() const  {
		return this->tol;
	}
	double solve() const{
		cout << "tolerance: " << tol <<", "<<getTol()<< endl;
		return f(2) - f(1);
		
	}

};


int main (){
	//Steffensen's method
	
	double guess = 0.2;
	SteffensensSolver steff(guess, CallPrice);
	steff.tol = 0.0001;
	
	double resultST = steff.solve();
	
	cout << "Steffensen's Method for callPrice function: " << resultST << endl;
	steff.printStatistics();
	
	
	//~ cout << SquareRoot(sqrt(2.0)) << endl;
	cout << endl;
	//~ double g=1;
	//~ SteffensensSolver s(g, SquareRoot);
	//~ s.tol = 1;
	//~ double r = s.solve();
	//~ cout << "Steffensen's Method for SquareRoot function: "<< r << endl;
	//~ s.printStatistics();
	
	//~ double gues = 0.5;
	RegulaFalsi model(50,SquareRoot);
	model.tol = 0.00000001;
	
	double result = model.solve();
	cout << "RegulaFalsi method for SquareRoot function: " << result << endl;
	model.printStatistics();
	//~ test t(N,5.0);
	//~ cout << t.solve() << endl;
	return 0;
}

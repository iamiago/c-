#include <iostream>
#include <math.h>
#include <array>
using namespace std;

#define DEBUG(x) cout << "["<<(#x) << " : " << (x) <<"]\n" 

class Complex
{
private:
	double x;
	double y;
public:
	//constructor
	Complex();
	Complex(const double& a, const double& b);
	Complex(const Complex& c);
	
	//destructor
	virtual ~Complex();
	
	//Functions
	Complex add (const Complex& c2) const;
		//Operators
	Complex operator + (const Complex& c2) const;
	Complex operator - (const Complex& c2) const;
	Complex operator * (const Complex& c2) const;
	friend Complex operator * (const Complex& c, double d);
	friend Complex operator * (double d, const Complex& c);
	Complex operator / (const Complex& c2) const;
		//Only the left hand side is modified by those operators
	Complex& operator = (const Complex& c);
	Complex& operator += (const Complex& c);
	Complex& operator *= (const Complex& c);
	Complex& operator -= (const Complex& c);
	Complex& operator /= (const Complex& c);
		//for printing with << operator
	friend ostream& operator << (ostream& os, const Complex& cmp);
	
	//trigonometric and hyperbolic functions
	friend Complex exp(const Complex& c);			//Exponential
	friend Complex cos(const Complex& c);			//Cosine function
	friend Complex sin(const Complex& c);
	friend Complex cosh(const Complex& c);
	friend Complex cotanh(const Complex& c);
	
};

Complex::Complex()
{
	x=0;
	y=0;
}
Complex::Complex(const double& a, const double& b)
{
	x=a;
	y=b;
}
Complex::Complex(const Complex& c)
{
	x=c.x;
	y=c.y;
}
Complex::~Complex()
{
	
}

Complex Complex::add(const Complex& c2) const
{// Add two complex numbers
	Complex result;
	result.x = x + c2.x;
	result.y = y + c2.y;
	
	return result;
}

Complex Complex::operator + (const Complex& c2) const 
{
	return Complex(x+c2.x, y+c2.y);
}

Complex Complex::operator - (const Complex& c2) const
{
	return Complex(x-c2.x, y-c2.y);
}

Complex Complex::operator * (const Complex& c2) const
{
	return Complex(x*c2.x-y*c2.y,x*c2.y+y*c2.x);
}

Complex operator * (const Complex& c, double d)
{	//Scalling by a double
	return Complex(c.x*d, c.y*d);
}

Complex operator * (double d, const Complex& c)
{
	return c*d;
}

Complex Complex::operator / (const Complex& c2) const
{
	if(c2.x*c2.x+c2.y*c2.y==0) return Complex(0,0);
	else return Complex((x*c2.x+y*c2.y)/(c2.x*c2.x+c2.y*c2.y),(y*c2.x-x*c2.y)/(c2.x*c2.x+c2.y*c2.y));
}

Complex& Complex::operator = (const Complex& c)
{
	//avoid doing assign to myself
	if(this == &c)
		return *this;
		
	x=c.x;
	y=c.y;
	
	return *this;
}
Complex& Complex::operator += (const Complex& c)
{
	x += c.x;
	y += c.y;
	return *this;
}

ostream& operator << (ostream& os, const Complex& cmp)
{	// print the complex number
	
	os <<"(" << cmp.x << ", i"<< cmp.y<< ")";
	return os;
}

Complex exp(const Complex& c)
{	//Exponential function
	// e^z = e^(x+iy) = e^x*e^iy= e^x(cos(y) + i sin(y))
		double ex= exp(c.x);
		return Complex(ex*cos(c.y), ex*sin(c.y));
}
Complex cosh(const Complex& c)
{	//Hyperbolic cosine function
	return(exp(c)+exp(-(c)))*0.5;
	
}


int main (){
	//~ Complex a(1,1),b(2,2);
	
	//~ Complex c = a+b;
	//~ Complex d = a-b;
	//~ Complex e = a/b;
	//~ Complex f = a*5;
	//~ Complex g = a*b;
	//~ cout << c.x << " " << c.y << endl;
	//~ cout << d.x << " " << d.y << endl;
	//~ cout << e.x << " " << e.y << endl;
	//~ cout << f.x << " " << f.y << endl;
	//~ cout << g.x << " " << g.y << endl;
	
	double real, imaginary;
	cout << "Creating a complex number" << endl;
	cout << "Give the real part: ";
	cin >> real;
	cout << "Give the imaginary part: ";
	cin >> imaginary;
	
	Complex c(real,imaginary);
	cout << c << endl;
	DEBUG(c);
	cout << exp(c) << endl;
	

	return 0;
}

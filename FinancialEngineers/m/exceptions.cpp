
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <exception>
#include <typeinfo>
#include <stdexcept>
using namespace std;
class MathErr
{ // Base class for my currenct exceptions
	
private:
	string mess;				// the error message
	string meth; 				// the methode that threw the exception
	
public:
	MathErr()
	{
		mess = meth = string();
	}	
	MathErr(const string& message, const string& method)
	{
		mess = message;
		meth = method;
	}
	string Message() const { return mess;}
	string Method() const { return meth;}
	
	virtual vector<string> MessageDump() const = 0;
	
	virtual void print() const
	{
		//This uses a template methode pattern
		
		//Variant part
		vector<string> r = MessageDump();
		
		//Invariant part
		const int len = r.size();
		cout <<"\n\n**Exception: \n";
		for(int i=0; i<len ; ++i)
		{
			cout << r[i] << "\n";
		}
		
	}
};


class ZeroDivide : public MathErr
{
private:
	string mess; 			//Extra information
	
public:
	ZeroDivide() : MathErr()
	{
		mess = string();
	}
	ZeroDivide(const string& message, const string& method, const string& annotation) : MathErr(message,method)
	{
		mess = annotation;
	}
	
	vector<string> MessageDump() const
	{
		vector<string> result(3);
		result[0] = Message();
		result[1] = Method();
		result[2] = mess;
		return result;
	}
};

template<class T>
T sumReciprocals(const vector<T>& array)
{//Somme des inverses (si un element vaut 0 on aura RUN TIME ERROR)
	T ans = T(0.0);
	const int len = array.size();
	for(int i=0; i<len; ++i)
	{
		if(fabs(array[i] < 0.001))
		{
			throw ZeroDivide("divide by zero", "sumReciprocals", string());
		}
		cout << 1.0/array[i] ;
		if(i!=len-1) cout << " + " ;
		ans += 1.0/array[i];
	}
	cout << endl;
	return ans;
}

int main()
{
	const int size = 10;
	double elementsValue = 3.1415;
	vector<double> myArray(size,elementsValue);
	myArray[5] = 0.0;
	try
	{
		double answer = sumReciprocals(myArray);
		cout << answer << endl;
	}
	catch(ZeroDivide& exception)
	{
		exception.print();
	}	
Lab1: try
	{
		cout << "\nGive a new value for index number 5: ";
		double val; cin >> val;
		myArray[5] = val;
		if(val == 999.0) return 1;
		
		double a = sumReciprocals(myArray);
		cout<< "Sym of reciprocals; " << a << endl;
		
	}
	catch (ZeroDivide& exception)
	{
		exception.print();
		goto Lab1;
	}
	return 0;
}



#include <iostream>
using namespace std;

//This class models one dimensional intervals
template<class Type= double> class Range
//if we instantiate the template class without parameter, the default type is double
{
private: 
	Type lo;
	Type hi;
	Range();	//Default constructor

public:
	//Constructors and destructor
	Range(const Type& low, const Type& high);
	Range(const Range<Type>& ran2);
	virtual ~Range();
	
	//Modifiers
	void low(const Type& t1);
	void high(const Type& t1);
	
	//Accessing functions
	Type low() const;
	Type high() const;
	
	Type length() const;		//High - Low
	
	//Boolean functions
	bool left(const Type& value) const;
	bool right(const Type& value) const;
	bool contains(const Type& value) const;
	
	//Operator overloading
	Range<Type>& operator = (const Range<Type>& ran2){
		if(this !=  &ran2)
		{
			this=&ran2;
		}
		return *this;
		
	}
	
	void print() const;
	
	//print
	template<class T>
	friend ostream& operator << (ostream& os, const Range<Type>& ran);
	
};


template<class Type>
ostream& operator << (ostream& os, const Range<Type>& ran)
{
	os << "(" << ran.low() << ", " << ran.high() << ")\n";
	return os;
}
template<class Type> Type Range<Type>::low() const
{
	return lo;
}
template<class Type> Type Range<Type>::high() const
{
	return hi;
}
template<class Type> Range<Type>::Range()
{//Default constructor
	
}
template<class Type> Range<Type>::~Range()
{
	
}

template<class Type> 
Range<Type>::Range(const Type& l, const Type& h)
{
	if(l<h){
		lo=l;
		hi=h;
	}else{
		hi=l;
		lo=h;
	}
}

template<class Type> 
bool Range<Type>::contains(const Type& t) const
{
	if((lo<=t) && (hi>=t)){
		return true;
	}
	return false;
}
template<class Type> 
bool Range<Type>::left(const Type& value) const
{
	if(value<lo) return true;
	return false;
}

template<class Type> 
bool Range<Type>::right(const Type& value) const
{
	if(value>hi) return true;
	return false;
}

template<class Type> 
void Range<Type>::print() const
{
	cout << "Range:\t";
	cout << "[" << lo << ", " << hi << "]\n";
}

template<class V> void mySwap(V& v1, V& v2)
{
	V tmp = v2;
	v2 = v1;
	v1=tmp;
}
int main ()
{
	Range<int> range(5,7);
	
	if (range.contains(6)) cout << "Range contains number 6\n";
	
	Range<int> range1(0,10);
	
	int valL=-1;
	int valM =5;
	int valR=20;
	
	if(range1.left(valL)) cout << valL << " to left, OK\n";
	
	if(range1.contains(valM)) cout << valM << " in interval, OK\n";
	
	if(range1.right(valR)) cout << valR << " to right, OK\n";
	
	Range a(5.5, 11.1);
	a.print();
	
	cout << a << endl;
	
	int j=10, k=20;
	mySwap(j,k); 
	cout << j << " " << k << endl;
	
	Range<int> ex1(0,20);
	Range<int> ex2(20,50);
	//~ mySwap(ex1,ex2); 
	cout << ex1 << ex2 << endl;
	
	return 0;
}

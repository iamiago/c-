#include <iostream>
#include <math.h>
#include <array>
#include <vector>
using namespace std;

//pré-requis
template<class V, class I =int, class S=vector<V>>
class Array
{
private:
	S m_structure; // The array structure
	I m_start; // The start index
	
public:
	//Constructors & destructors
	Array();										//Default constructor						
	Array(size_t size);								//Give length, start index ==1
	Array(size_t size, I start);					//Length and start index
	Array(const Array<V,I,S>& source);				//Copy constructor
	
	//Selectors
	I MinIndex() const;								//Return the minimum index
	I MaxIndex() const;								//Return the maximum index
	size_t Size() const;							//The size of the array
	const V& Element(I index) const;				//Element at position
	
	//Modifiers
	void Element(I index, const V& val);			//Change element at position
	void StartIndex(I index);						//Change the start index
	
	//Operators
	virtual V& operator [] (I index);				//Subscripting operator
	virtual const V& operator [] (I index) const;	
};

template <class V, class I =int, class S = vector<V>>
class Vector : public Array<V,I,S>
{
private:


public:
	//Selector
	Vector<V,I> Row(I row) const;
	Vector<V,I> Column(I column) const;
	
	//Modifiers
	void Row(I row, const Array<V,I>& val);
	void Column(I column, const Array<V,I>& val);

	//Operator overloading
	Vector<V,I,S> operator - () const;
	Vector<V,I,S> operator + (const Vector<V,I,S>& v) const;
	Vector<V,I,S> operator - (const Vector<V,I,S>& v) const;
	
	//~ Vector<V,I,S> operator - (const V& v) const;
	//~ Vector<V,I,S> operator - (const V& v) const;
	//~ Vector<V,I,S> operator * (const V& v) const;
	
};




//Structure de réseau
template<class V, class I, int NumberNodes> 
class Lattice
{//Generice lattice class
private:
	Array<Vector<V,I>,I> tree;
	
	I nrows;
	int typ;

public:
	//Constructors & destructor
	
	Lattice();									//Default constructor
	Lattice(const I& Nrows); 					//Number of rows and branch factor
	Lattice(const I& Nrows, const V& val);		//+ value at nodes
	Lattice(const Lattice<V,I,NumberNodes>& source);
	virtual ~Lattice();							//Destructor
	
	//Iterating in a lattice, forward and backward versions
	I MinIndex() const;
	I MaxIndex() const;
	I Depth() const;
	
	//Operators
	Lattice<V,I, NumberNodes>& operator = (const Lattice<V,I,NumberNodes>& source);
	
	//Indexing the "outer" array of lattice
	Vector<V,I>& operator [] (const I& nLevel);
	const Vector<V,I>& operator [] (const I& nLevel) const;
	
	//We need the form of the lattice at the "base" of the pyramid
	//This will be needed when we use backward induction
	
	Vector<V,I> BasePyramidVector() const;
	I BasePyramidSize() const;
	I numberNodes() const;
	
	
};

template<class V,class I, int NumberNodes>
Lattice<V,I, NumberNodes>::Lattice(const I& Nrows, const V& val)
{//Number of rows and branch factor

	nrows = Nrows;
	typ = NumberNodes;
	
	tree = Array<Vector<V,I>,I>(nrows+1,1); // Start index == 1
	
	I currentBranch = 1;
	
	//Initialise tree vectors (give sizes of vectors)
	for(int n=tree.MinIndex(); n<= tree.MaxIndex(); ++n){
		
		//Create the appropriate vector(in vertical direction)
		tree[n] = Vector<V,I>(currentBranch, 1, val);
		
		//Calculate the next number of columns
		currentBranch += (typ -1);
	}
}	



//Stratégie de réseau binomial
class BinomialLatticeStrategy  
{// base on Clewlow and Strickland 1998
protected:
	double u; double d; double p;
	double s; double r; double k;
	int bType; //-1 multiplicative , +1 arithmetical
	
public:
	//Public inline functions for normal clients
	double downValue() const { return d;}
	double upValue() const { return u;}
	double probValue() const {return p;}
	int binomialType() const { return bType;}
	
	//~ virtual void updateLattice(Lattice<double, int, 2>& source, double rootValue) const;
	
	
};
//Each specific strategy for calculating u, d and p is mapped to a class


//Simple class with constructor and params :volatility, interest rate and step size in the time direction
class CRRStrategy: public BinomialLatticeStrategy
{
public:
	CRRStrategy(double vol, double interest, double delta);
};

CRRStrategy::CRRStrategy(double vol, double interest, double delta):BinomialLatticeStrategy()
{
	double R1 = (r - 0.5 * s * s) * k;
	double R2 = s * sqrt(k);
	 
	u = exp(R1 + R2);
	d = exp(R1 - R2);
	
	//~ double discounting = exp(-r * k);
	p = 0.5;
}

class JRStrategy : public BinomialLatticeStrategy
{
public:
	JRStrategy(double vol, double interest, double delta);
};

JRStrategy::JRStrategy(double vol, double interest, double delta):BinomialLatticeStrategy()
{
	double k2 =  sqrt(k);
	u = exp(s * k2);
	d = 1.0/u;
	p = 0.5 + ((r - 0.5 * s * s) * k2 * 0.5) / s;
}

class EQPStrategy : public BinomialLatticeStrategy
{
public:
	EQPStrategy(double vol, double interest, double delta);
};

EQPStrategy::EQPStrategy(double vol, double interest, double delta): BinomialLatticeStrategy()
{
	bType = 1;	
	double nu = r - 0.5 * s * s;
	
	double a = nu * k;
	double b = 0.5 *  sqrt((4.0 * s * s * k) - (3.0 * nu * nu * k * k));
	
	u = 0.5 * a + b;
	d = 0.5 * a - b;
	p = 0.5;
	
}

class TRGStrategy :  public BinomialLatticeStrategy
{
public:
	TRGStrategy(double vol, double interest, double delta);
	
};

TRGStrategy::TRGStrategy(double vol, double interest, double delta): BinomialLatticeStrategy()
{
	bType = 1;
	double nu = r - 0.5 * s * s;
	
	double nudt = nu * k;
	
	u = sqrt(s * s * k + nudt * nudt);
	d = -u;
	p = 0.5 * (1.0 + (nudt/u));
}

class ModCRRStrategy : public BinomialLatticeStrategy
{
public:
	ModCRRStrategy(double vol, double interest, double delta, double S, double K, int N);
};

ModCRRStrategy::ModCRRStrategy(double vol, double interest, double delta, double S, double K, int N): BinomialLatticeStrategy()
{
	double KN = log(K/S) / double(N);
	double VN = s * sqrt(k);
	
	u = exp(KN + VN);
	d = exp(KN - VN);
	p = (exp(r * k) - d) / (u - d);
}
/*
void BinomialLatticeStrategy::updateLattice(Lattice<double,int,2>& source, double rootValue) const
{
	int si = source.MinIndex();
	source[si][source[si].MinIndex()] = rootValue;
	
	for(int n= source.MinIndex() +1; n <= source.MaxIndex(); ++n){
		for(int i=source[n].MinIndex(); i<source[n].MaxIndex(); ++i){
			source[n][i] = d * source[n-1]*[i];
			source[n][i+1] = u * source[n-1][i];
		}
	}
}
* */

class BinomialMethod
{
private:
	//Underlying data structure
	//~ Lattice<double, int, 2> lattice; Number == 2 binomial
	BinomialLatticeStrategy* str; // pointer to an algorithm
	
	double disc;
	
public:
	//Default constructor
	BinomialMethod();
	
	//Constructor taking discount factor, strategt and the number of time steps
	BinomialMethod(double discounting, BinomialLatticeStrategy& strategy, int N);
	
	//Initialise lattice data structure
	void buildLattice(int N);
	
	//Initialise lattice node values (forward induction)
	void modifyLattice(double U);
	
	//Calculate derivate price (backward induction)
	double getPrice(const Vector<double, int>& RHS);
	
	//Handy function to give us the size at expiry date
	Vector<double, int> BasePyramidVector() const;
	
	//Uderlying lattice
	const Lattice<double, int, 2>& getLattice() const;
	
};

double BinomialMethod::getPrice(const Vector<double, int>& RHS)
{
	double pr = str->probValue();
	int ei = lattice.MaxIndex();
	lattice[ei] = RHS;
	
	//loop from max index to the start index
	for(int n= lattice.MaxIndex()-1; n>=lattice.MinIndex(); n--)
	{
		for(int i=lattice[n].MinIndex(); i<= lattice[n].MaxIndex(); ++i)
		{
			lattice[n][i] = disc*(pr*lattice[n+1][i+1] + (1.0-pr)*lattice[n+1][i]);
		}
	}
	int si = lattice.MinIndex();
	return lattice[si][lattice[si].MinIndex()];
}
int main (){
	
	/*
	//TEST
	const int typeB = 2;		//BinomialLatticeType
	const int typeT = 3;		//Trinomial type
	const int typeP = 5;		//Pentagonal type
	
	int depth = 4;
	
	//Create object of various
	Lattice<double, int, typeB> lat1(depth,3.14);
	Lattice<double, long, typeT> lat2(depth,4.6);
	Lattice<double, long, typeP> lat2(depth,2.0);
	
	print(lat1);
	cout << endl<< endl;
	print(lat2);
	cout << endl << endl;
	print(lat3);
	cout << endl;
	* */
	
	
	return 0;
}

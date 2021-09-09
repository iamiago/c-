#include <iostream>

using namespace std;

// the namespace represent mutually exclusive functionality.
namespace MyFunctions
{
	double diffusion(double x)
	{
		return x;
	}
	double convection(double x)
	{
		return x*x;
	}
}

namespace YourFunctions
{
	double diffusion(double x){ return 2.0;}
	double convection(double x){ return 1.0;}
}

namespace MF= MyFunctions;
namespace YF= YourFunctions;

//combining function pointers and namespaces

namespace StandardInterface
{
	//Namespace consisting of function pointers
	double (*func1) (double x);
	double (*func2) (double x, double y);
}

namespace Implementation1
{
	double F1 (double x) { return x;}
	double F2 (double x, double y) { return x*y; }
}

namespace Implementation2
{
	double G1 (double x) { return -x;}
	double G2 (double x, double y) {  return -x*y;}
}

// we assign the function pointer of StandardInterface that we desire to use




int main (){
	
	cout << YourFunctions::convection(10.0) << endl;
	cout << MyFunctions::convection(10.0) << endl;
	
	cout << MF::diffusion(10.0) << endl;
	cout << YF::diffusion(10.0) << endl;
	
	StandardInterface::func1 =  Implementation1::F1;
	StandardInterface::func2 =  Implementation1::F2;
	using namespace StandardInterface;
	
	cout << func1(2.0) << ", " << func2(3.0, 4.0) << endl;
	
	//If we want to change the functions that are being pointed to
	func1 =  Implementation2::G1;
	func2 =  Implementation2::G2;
	
	cout << func1(2.0) << ", " << func2(3.0, 4.0) << endl;
	return 0;
}

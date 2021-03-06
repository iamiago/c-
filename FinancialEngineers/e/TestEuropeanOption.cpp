#include "EuropeanOption.hpp"
#include <iostream>

using namespace std;

int main (){
	//All options are european
	
	//Call option on a stock
	EuropeanOption callOption;
	cout <<"Call option on a stock: "<< callOptions.Price() << endl;
	
	//Put option on a stock index
	EuropeanOption indexOption;
	indexOption.optType = "P";
	indexOption.U = 100.0;
	indexOption.K = 95.0;
	indexOption.T = 0.5;
	indexOption.r = 0.10;
	indexOption.sig = 0.20;
	double q = 0.05; // Dividend yield ou rendement du dividende
	indexOption.b = indexOption.r - q;
	
	cout << "Put option on index: " << indexOption.Price() << endl;
	
	//Call and put options on a future
	EuropeanOption futureOption;
	futureOption.optType = "P";
	futureOption.U = 19.0;
	futureOption.K = 19.0;
	futureOption.T = 0.75;
	futureOption.r = 0.10;
	futureOption.sig = 0.28;
	futureOption.b = 0.0;
	
	cout <<"Put option on future: "<< futureOption.Price() << endl;
	
	
	// Change over to a call on the option
	futureOption.toggle();
	
	cout << "Call on future: "<< futureOption.Price() << endl;
	
		
	return 0;
}

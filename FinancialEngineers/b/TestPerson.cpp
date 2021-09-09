//Main program (console-based) to test functions
#include "datasimdate.hpp"
#include "Person.hpp"
#include <string>

using namespace std;

int main (){
	
	DatasimDate myBirthDay(14,10,1999);
	string myName("Iago Gama De Souza");
	Person me(myName,myBirthday);
	me.print();
	
	DatasimDate bBirthDay(01,01,1900);
	string bName ("Test");
	Person b(bName,bBirthDay);
	b.print();
	return 0;
}

#include <iostream>
#include <string>
using namespace std;

class Person
{
public: //(Attributes) Everything public, for convenience only
	//data
	string name;
	int yearOfBirthday;

public: //(Functions)
	
	//Constructor
	Person(const string& Name, const int YearOfBirthday);
	
	//Destructor
	virtual ~Person();
	
	void print() const;
	virtual void DeepPrint() const
	{
			print();
	}
	
	int age() const;
	
};

Person::Person(const string& Name, const int YearOfBirthday)
{
	name = Name;
	yearOfBirthday = YearOfBirthday;
}
int Person::age() const 
{
	return 2021-yearOfBirthday;
}
void Person::print() const
{
	cout << "** Person Data **\n";
	cout << "Name: " << name << "\nYear of Birthday: " << yearOfBirthday << "\nAge: " << age() << endl;
}
Person::~Person(){
	
}

class Employee : public Person
{
public: // for convinience only
	string fun;
	double sal;
	int rAge;
	
	Employee(const string& Name, const int YearOfBirthday, const string& Function, const double& Salary, const int& RAge):Person(Name,YearOfBirthday)
	{
		fun=Function;
		sal = Salary;
		rAge = RAge;
	}
	
	void print() const 
	{
		cout << "** Employee Data **\n";
		Person::print();
		cout << "\nFunction: " << fun << "\nSalary: " << sal << "$\nRetires at: " << rAge <<"\n" << YearsToRetirement() << " years to retirement.\n";
	}
	void DeepPrint() const
	{
		print();
	}
	int YearsToRetirement() const 
	{
		return rAge - age();
	}

};


int main (){
	
	string name("Iago Gama De Souza");
	int year = 1999;
	Person me(name,year);
	me.print();
	
	string namme("Test employee");
	int y = 2000;
	Employee emp(namme,y,"Trader",200'000.0,65);
	emp.print();
	cout << endl;
	 
	Employee teacher(string("Alber Einstein"), 1979, string("Teacher"), 100'000, 65);
	Person* p =&teacher;
	
	p->print();
	p->DeepPrint();
	
	Person* parr[3]; // Array of pointers
	parr[0] = new Employee("test1", 2000, "tester", 100, 65);
	parr[1] = new Person("test2",2001);
	parr[2] = new Employee("test3", 2002, "tester3", 100, 65);
	cout << endl;
	for(int i=0; i<3; ++i){
		cout<< i+1 << endl;
		parr[i] -> DeepPrint();
		cout << endl;
	}
	
	//~ for(auto x : parr) delete x;
	for(int i=0; i<3; ++i)
	 {
		 delete parr[i];
	 }
	
	return 0;
}

#ifndef Point_HPP
#define Point_HPP

#include <iostream>
using namespace std;

template<class TFirst, class TSecond>
class Point
{
private:
	//The two coordinates
	TFirst m_first;
	TSecond m_second;
	
public:
	//Constructor & destructor
	Point();
	Point(TFirst first, TSecond second);
	Point(const Point<TFirst, TSecond>& source);
	virtual ~ Point();
	
	//Accessing functions
	TFirst First() const;
	TSecond Second() const;
	
	//Modifiers
	void First(const TFirst& val);
	void Second(const TSecond& val);
	
	//Functions
	double Distance(const Point<TFirst, TSecond>& p) const;
	
	
	//Assignment operator
	Point<TFirst, TSecond>& operator = (const Point<TFirst, TSecond>& source);
	
	//Print
	template<class Tf,class Ts>
	friend ostream& operator << (ostream& os, const Point<TFirst, TSecond>& p);
};
#endif

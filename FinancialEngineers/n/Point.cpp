#ifndef Point_cpp
#define Point_cpp

#include "Point.hpp"
#include <math.h>

//Default constructor
template<class TFirst, class TSecond>
Point<TFirst, TSecond>::Point()
{
	m_first=TFirst();
	m_second=TSecond();
}

//Constructor with coordinates
template <class TFirst, class TSecond>
Point<TFirst, TSecond>::Point(TFirst first, TSecond second)
{
	m_first=first;
	m_second=second;
}

//Copy constructor
template<class TFirst, class TSecond>
Point<TFirst, TSecond>::Point(const Point<TFirst, TSecond>& source)
{
	m_first = source.m_first;
	m_second = source.m_second;
	
}

//Destructor
template<class TFirst, class TSecond>
Point<TFirst, TSecond>::~Point()
{
	
}

//Get first coordinates
template<class TFirst, class TSecond>
TFirst Point<TFirst, TSecond>::First() const
{
	return m_first;
}

//Get second coordinate
template<class TFirst, class TSecond>
TSecond Point<TFirst, TSecond>::Second() const 
{
	return m_second;
}

//Set first coodinate
template<class TFirst, class TSecond>
void Point<TFirst, TSecond>::First(const TFirst& val)
{
	m_first=val;
}

//Set second coordinate
template<class TFirst, class TSecond>
void Point<TFirst,TSecond>::Second(const TSecond& val)
{
	m_second=val;
}

//Calculate distance
template<class TFirst, class TSecond>
double Point<TFirst, TSecond>::Distance(const Point<TFirst, TSecond>& p) const
{
	//Get the length of the sides
	TFirst a =p.m_first - m_first;
	TSecond b=p.m_second  - m_second;
	
	//Pythagoras to calculate distance
	return sqrt(a*a + b*b);
}

//Assignment operator
template<class TFirst,class TSecond>
Point<TFirst, TSecond>& Point<TFirst, TSecond>::operator = (const Point<TFirst, TSecond>& source)
{
	if(this == &source) return *this;
	
	m_first =source.m_first;
	m_second = source.m_second;
	
	return *this;
}

//Print
template<class TFirst, class TSecond>
ostream& operator << (ostream& os, const Point<TFirst, TSecond>& p)
{
	os << "(" << p.First() << ", "<< p.Second()<< ")\n";
	return os;
}
#endif

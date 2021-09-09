#include <iostream>
struct Point
{
	double x;
	double y;
};
class Rectangle 
{
protected: //Derived classes can acces this data directly
	Point bp;		//Base point, Point class given
	double h; 		//height
	double w; 		//width
	
public:
	//Constructors and Destructor
	Rectangle()
	{
		bp = Point();
		h=1.0;
		w=2.0;
	}
	Rectangle(const Point& basePoint, double height, double width)
	{
		bp = basePoint;
		h = height;
		w = width;
	}
	
	//Modifiers
	void setHeight(double newHeight)
	{
		h = newHeight;
	}
	void setWidth(double newWidth)
	{
		w = newWidth;
	}
	
	//Other functions
	void print() const
	{
		std::cout << "** Rectangle Data \n";
		std::cout << "Base point (x, y): ("<< bp.x <<", "<<bp.y<<")\n";
		std::cout << "Dimensions (H, W): ("<< h  << ", " << w << ")\n";
		std::cout << "**\n";
	}
};
//We can create rectangle and change its dimensions

//Now we derive a square class from it
class BadSquare : public Rectangle
{// Version 1, a Square is a rectangle
private:
	//This function has no member data because it is derived from Rectangle
	//In this case we defined the data in Rectangle as being protected
	//This mean it is directly available to derived classes
public:
	//A default constructor will be generated if you do not provide one
	// The default constructor in the derived class will automatically call the default constructor in the base class
	//In general we prefet to write default constructors in all classes because we control what default behaviour will be
	
	BadSquare() : Rectangle(Point(), 1.0, 1.0)
	{
		//We must implement this, otherwise this default constructor inherits a default rectangle
	}
	BadSquare(const Point& basePoint, double size)
	{
		bp =basePoint;
		h=w=size;
	}
	void print() const
	{
		std::cout << "** Square Data \n";
		std::cout << "Base point (x, y): ("<< bp.x <<", "<<bp.y<<")\n";
		std::cout << "Dimensions (H, W): ("<< h  << ", " << w << ")\n";
		std::cout << "**\n";
	}

};

//we implement a new class that uses a rectangle as private member data 
//We develop the member functions in the new square while we suppress those functions that are not relevant
class GoodSquare 
{	//Version 2, adapts a Rectangle's interface
private:
	Rectangle r;

public:
	GoodSquare()
	{
		double size=1.0;
		r = Rectangle( Point(), size, size); //Unit square
	}
	
	void setSize(double newSize)
	{//this ensures that constraints on the square are always satisfied
		r.setHeight(newSize);
		r.setWidth(newSize);
	}
	
	void print() const
	{	//Delegate to the embedde rectangle's output
		std::cout << "Good Square Data\n";
		r.print();
	}	
	
	
};
int main ()
{
	Point Origin;
	Origin.x=0.0;Origin.y=0.0;
	Rectangle rec(Origin, 2, 4);
	rec.print();
	
	BadSquare bs;
	bs.print();
	bs.setHeight(2.0);
	bs.print(); // now height and width are different (not a square anymore)
	
	GoodSquare gs;
	gs.print();
	gs.setSize(2.0);
	gs.print();
	//~ Point a = Point();
	//~ std::cout << a.x << ", " << a.y << std::endl;
	
	
	return 0;
}

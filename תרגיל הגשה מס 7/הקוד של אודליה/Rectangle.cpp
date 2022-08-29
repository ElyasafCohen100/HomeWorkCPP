/*Odelya Yaakowich 207346784
Workshop in c++
Exercise 7 Question 1*/

#include "Rectangle.h"


Rectangle::Rectangle() :Shape(4)
{}


float Rectangle::area() const
{
	float a = distance(Points[0], Points[1]);
	float b = distance(Points[1], Points[2]);
	return (a * b);
}


bool Rectangle::isSpecial() const
{
	float a = distance(Points[0], Points[1]);
	float b = distance(Points[1], Points[2]);
	float c = distance(Points[2], Points[3]);
	float d = distance(Points[0], Points[3]);
	if (a == b && c == d && b == c)
		return true;
	return false;
}


void Rectangle::printSpecial() const
{
	float a = distance(Points[0], Points[1]);
	if (isSpecial())
		cout << "Square with side length " << a << endl;
}

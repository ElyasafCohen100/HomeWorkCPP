/*Odelya Yaakowich 207346784
Workshop in c++
Exercise 7 Question 1*/


#include "Triangle.h"
#include <cmath>



Triangle::Triangle():Shape(3)
{}


float Triangle::area() const
{
	float a = distance(Points[0], Points[1]);
	float b = distance(Points[1], Points[2]);
	float c = distance(Points[0], Points[2]);
	float y = acos((pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2 * a * b));
	return (a * b * sin(y) * 0.5);
}


bool Triangle::isSpecial() const
{
	float a = distance(Points[0], Points[1]);
	float b = distance(Points[1], Points[2]);
	float c = distance(Points[0], Points[2]);
	if (a == b == c)
		return true;
	return false;
}


void Triangle::printSpecial() const
{
	float a = distance(Points[0], Points[1]);
	if (isSpecial())
		cout << "An isosceles triangle with a side length " << a << endl;
}

/*Odelya Yaakowich 207346784
Workshop in c++
Exercise 7 Question 1*/

#include "Circle.h"
#include<cmath>
const float PI = 3.14;  //const value for pi

Circle::Circle(){}


void Circle::setRadius(float myRadius)
{
	if (myRadius > 0)
		radius = myRadius;
	else
		throw "invalid input";
}


Circle::Circle(float myRadius):Shape(1)
{
	setRadius(myRadius);
}


float Circle::getRadius() const
{
	return radius;
}


float Circle::area() const
{
	return PI * pow(radius, 2);
}


bool Circle::isSpecial() const
{
	if (Points[0].getX() == 0 && Points[0].getY() == 0)
		return true;
	else
		return false;
}


void Circle::printSpecial() const
{
	if (isSpecial())
		cout << "A canonical circle with a radius " << radius << endl;
}
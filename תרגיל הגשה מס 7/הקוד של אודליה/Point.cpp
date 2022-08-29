/*Odelya Yaakowich 207346784
Workshop in c++
Exercise 7 Question 1*/

#include "Point.h"
#include<iostream>
using namespace std;

void Point::setX(int myX) {
	x = myX;
}

void Point::setY(int myY) {
	y = myY;
}

int Point::getX() {
	return x;
}

int Point::getY() {
	return y;
}


istream& operator>>(istream& in, Point& s)
{
	char tav;
	in >> tav >> s.x >> tav >> s.y >> tav;
	return in;
}

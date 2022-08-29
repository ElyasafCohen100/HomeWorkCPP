/*Odelya Yaakowich 207346784
Workshop in c++
Exercise 7 Question 1*/

#include "Point.h"
#include <iostream>
using namespace std;
#pragma once

class Shape
{
protected:
	int numOfPoints;
	Point* Points;
public:
	Shape(); //defult ctor
	Shape(int numOfPoints);//ctor
	Shape(const Shape& s); //copy-ctor
	Shape(Shape&& s); //move-ctor
	virtual ~Shape(); // virtual method
	friend ostream& operator<<(ostream& os, const Shape& s);
	virtual float distance(Point p1, Point p2) const; //pure virtual method
	virtual float area() const = 0;//pure virtual method
	virtual bool isSpecial() const = 0;//pure virtual method
	virtual void printSpecial() const = 0;//pure virtual method
};


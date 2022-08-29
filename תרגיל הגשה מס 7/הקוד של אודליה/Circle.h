/*Odelya Yaakowich 207346784
Workshop in c++
Exercise 7 Question 1*/


#include "Shape.h"
#pragma once

class Circle: public Shape
{
	float radius;
public:
	Circle();
	Circle(float myRadius);
	void setRadius(float myRadius);
	float getRadius() const;
	float area() const override;
	bool isSpecial() const override;
	void printSpecial() const override;
	
};


/*Odelya Yaakowich 207346784
Workshop in c++
Exercise 7 Question 1*/

#include "Shape.h"
#pragma once

class Triangle : public Shape
{
public:
	Triangle();
	float area() const override;
	bool isSpecial() const override;
	void printSpecial() const override;
};


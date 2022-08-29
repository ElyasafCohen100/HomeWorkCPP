/*Odelya Yaakowich 207346784
Workshop in c++
Exercise 7 Question 1*/

#include<iostream>
using namespace std;
#pragma once

class Point
{
private:
	int x;
	int y;
public:
	void setX(int myX);
	void setY(int myY);
	int getX();
	int getY();
	friend istream& operator>>(istream& in, Point& s);
};
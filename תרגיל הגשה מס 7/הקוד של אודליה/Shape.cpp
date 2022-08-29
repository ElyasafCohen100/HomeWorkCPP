/*Odelya Yaakowich 207346784
Workshop in c++
Exercise 7 Question 1*/


#include "Shape.h"
#include <cmath>


Shape::Shape() {}

Shape::Shape(int myNumOfPoints)//ctor
{
	numOfPoints = myNumOfPoints;
	Points = new Point[numOfPoints];              //a new arr for all the points
	cout << "Enter values of  " << numOfPoints << " points:" << endl;
	Point p1;
	for (int i = 0; i < numOfPoints; i++)
	{
		cin >> p1;
		Points[i] = p1;
	}
}


Shape::Shape(const Shape& s) //copy-ctor
{
	numOfPoints = s.numOfPoints;
	Points = new Point[numOfPoints];
	for (int i = 0; i < numOfPoints; i++)
		Points[i] = s.Points[i];
}


Shape::Shape(Shape&& s) //move-ctor
{
	numOfPoints = s.numOfPoints;
	Points = s.Points;
	s.Points = NULL;
}


Shape::~Shape() //dctor
{
	if (Points)
		delete[] Points;
}



ostream& operator<<(ostream& os, const Shape& s)
{
	cout << "points: ";
	for (int i = 0; i < s.numOfPoints; i++)  //print all data in arr 
	{
		os << "(" << s.Points[i].getX() << "," << s.Points[i].getY() << ")" << " ";
	}
	return os;
}


float Shape::distance(Point p1, Point p2) const
{
	int subX = p1.getX() - p2.getX();
	int subY = p1.getY() - p2.getY();
	float dst = sqrt(pow(subX, 2) + pow(subY, 2));
	return dst;
}

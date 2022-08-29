/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 7          *
*                            *
******************************/
#include "Point.h"
#include <cmath>
#include<iostream>
using namespace std;

///---------------------------------------- Point �� cpp - ����� ����� � ------------------------------------------///


//------------------ ����� ����� ������ -------------------//

//------ x �� -------//
int Point::getX()const {
	return this->x;
}


//------ y �� -------//
int Point::getY()const {
	return this->y;
}

//------ x �� -------//
void  Point::setX(int myX) {
	this->x = myX;
}


//------ y �� -------//
void Point::setY(int myY) {
	this->y = myY;
}

//-------------- >> ������� ���� - ������� ��� -----------------//
istream& operator>>(istream& is, Point& my_point) {
	char tav;
	is >> tav >> my_point.x >> tav >> my_point.y >> tav;

	return is;
}


//-------------- ����� ������ ���� ��� ��� ������ -----------//
float Point::distance(Point p2) {

	//---- ����� ���� ��"� ������ �� ����� ������� ----//
	int deltaX = this->getX() - p2.getX();
	int deltaY = this->getY() - p2.getY();
	float distance = (float)sqrt(pow(deltaX, 2) + pow(deltaY, 2));

	return  distance;
}

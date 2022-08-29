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

///---------------------------------------- Point של cpp - אנחנו בקובץ ה ------------------------------------------///


//------------------ הגדרת הגטים והסטים -------------------//

//------ x גט -------//
int Point::getX()const {
	return this->x;
}


//------ y גט -------//
int Point::getY()const {
	return this->y;
}

//------ x סט -------//
void  Point::setX(int myX) {
	this->x = myX;
}


//------ y סט -------//
void Point::setY(int myY) {
	this->y = myY;
}

//-------------- >> פונקציה חברה - אופרטור קלט -----------------//
istream& operator>>(istream& is, Point& my_point) {
	char tav;
	is >> tav >> my_point.x >> tav >> my_point.y >> tav;

	return is;
}


//-------------- מתודה המחשבת מרחק בין שתי נקודות -----------//
float Point::distance(Point p2) {

	//---- חישוב מרחק עפ"י הנוסחא של הנדסה אנליטית ----//
	int deltaX = this->getX() - p2.getX();
	int deltaY = this->getY() - p2.getY();
	float distance = (float)sqrt(pow(deltaX, 2) + pow(deltaY, 2));

	return  distance;
}

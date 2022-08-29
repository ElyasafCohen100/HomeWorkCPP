/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 7          *
*                            *
******************************/
#pragma once
#include<iostream>
using namespace std;

///--------------------------------------------- Point אנחנו בקובץ ההדר של -----------------------------------------------///

//---------- Point פתיחת המחלקה ------------//

class Point {

private:

	int x;
	int y;

public:

	//------------------ הגדרת הגטים והסטים -------------------//

	//------ x גט -------//
	int getX()const;
	//------ y גט -------//
	int getY()const;
	//------ x סט -------//
	void setX(int myX);
	//------ y סט -------//
	void setY(int myY);

	//-------------- >> פונקציה חברה - אופרטור קלט -----------------//
	friend istream& operator>>(istream& is, Point& my_point);
	//-------------- מתודה המחשבת מרחק בין שתי נקודות -----------//
	float distance(Point p2);
};
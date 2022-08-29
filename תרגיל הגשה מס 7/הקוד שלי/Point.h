/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 7          *
*                            *
******************************/
#pragma once
#include<iostream>
using namespace std;

///--------------------------------------------- Point ����� ����� ���� �� -----------------------------------------------///

//---------- Point ����� ������ ------------//

class Point {

private:

	int x;
	int y;

public:

	//------------------ ����� ����� ������ -------------------//

	//------ x �� -------//
	int getX()const;
	//------ y �� -------//
	int getY()const;
	//------ x �� -------//
	void setX(int myX);
	//------ y �� -------//
	void setY(int myY);

	//-------------- >> ������� ���� - ������� ��� -----------------//
	friend istream& operator>>(istream& is, Point& my_point);
	//-------------- ����� ������ ���� ��� ��� ������ -----------//
	float distance(Point p2);
};
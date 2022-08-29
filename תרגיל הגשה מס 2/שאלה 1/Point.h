/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 2 seif 1   *
*                            *
******************************/
#pragma once
#include <cmath>
using namespace std;

///---------------------------------------- Point ����� ���� ����� ���� �� ------------------------------------------///

//---------- Point ����� ������ ------------//

class Point {

private:

	int x;
	int y;

public:

	//------------------ ����� ����� ������ -------------------//

	//------ x �� -------//
	int getX() {
		return this->x;
	}

	//------ x �� -------//
	void setX(int myX) {
		this->x = myX;
	}

	//------ y �� -------//
	int getY() {
		return this->y;
	}


	//------ y �� -------//
	void setY(int myY) {
		this->y = myY;
	}


	//-------------- ����� ������ ���� ��� ��� ������ -----------//
	float distance(Point p2) {

		//---- ����� ���� ��"� ������ �� ����� ������� ----//
		int deltaX =  this->getX() - p2.getX();
		int deltaY =  this->getY() - p2.getY();
		float distance =(float)sqrt(pow(deltaX, 2) + pow(deltaY, 2));

		return  distance;
	}
};

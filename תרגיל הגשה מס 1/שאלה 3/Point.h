/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 1 seif 3   *
*                            *
******************************/
#pragma once
#include<iostream>
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

};

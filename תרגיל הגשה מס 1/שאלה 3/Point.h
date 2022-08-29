/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 1 seif 3   *
*                            *
******************************/
#pragma once
#include<iostream>
using namespace std;

///---------------------------------------- Point אנחנו כרגע בקובץ ההדר של ------------------------------------------///

//---------- Point פתיחת המחלקה ------------//

class Point {

private:

	int x;
	int y;

public:

	//------------------ הגדרת הגטים והסטים -------------------//

	//------ x גט -------//
	int getX() {
		return this->x;
	}

	//------ x סט -------//
	void setX(int myX) {
		this->x = myX;
	}

	//------ y גט -------//
	int getY() {
		return this->y;
	}


	//------ y סט -------//
	void setY(int myY) {
		this->y = myY;
	}

};

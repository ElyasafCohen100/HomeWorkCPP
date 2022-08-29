/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 2 seif 1   *
*                            *
******************************/
#pragma once
#include <cmath>
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


	//-------------- מתודה המחשבת מרחק בין שתי נקודות -----------//
	float distance(Point p2) {

		//---- חישוב מרחק עפ"י הנוסחא של הנדסה אנליטית ----//
		int deltaX =  this->getX() - p2.getX();
		int deltaY =  this->getY() - p2.getY();
		float distance =(float)sqrt(pow(deltaX, 2) + pow(deltaY, 2));

		return  distance;
	}
};

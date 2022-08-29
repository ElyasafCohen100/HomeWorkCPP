/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 1 seif 3   *
*                            *
******************************/
#pragma once
#include "Point.h"
#include<iostream>
#include <cmath>
using namespace std;

///---------------------------------------- Circle אנחנו כרגע בקובץ ההדר של ------------------------------------------///

//---------- Circle פתיחת המחלקה ------------//

class Circle {

private:

	Point center;
	int radius;

public:


	//---------------------- הגדרת הגטים, הסטים והמתודות  -----------------------//

	//------ Radius גט -------//
	int getRadius() {
		return this->radius;
	}


	//------ Radius סט -------//
	void setRadius(int myRadius) {
		this->radius = myRadius;
	}


	//------ Center גט -------//
	Point getCenter() {
		return this->center;
	}


	//--------- Center סט ----------//
	void setCenter(int x, int y) {
		this->center.setX(x);
		this->center.setY(y);
	}


	//-------מתודת חישוב שטח המעגל -------//
	float area() {
		const float PAI = 3.14;
		float area = (float) (radius * radius * PAI);
		return area;
	}


	//----מתודת חישוב היקף המעגל -------//
	float perimeter() {
		const float PAI = 3.14;
		float perimeter = (float)((radius + radius) * PAI);
		return perimeter;
	}


	//-------------- מתודת בדיקת מיקום נקודה ---------------//
	int onInOut(Point p) {

		//---- חישוב מרחק עפ"י הנוסחא של הנדסה אנליטית ----//
		int deltaX = center.getX() - p.getX();
		int deltaY = center.getY() - p.getY();
		float distance = sqrt(pow(deltaX, 2) + pow(deltaY, 2));

		if (distance > radius) {
			return 1;
		}

		else if (distance < radius) {
			return -1;
		}

		else {
			return 0;
		}
	}
};

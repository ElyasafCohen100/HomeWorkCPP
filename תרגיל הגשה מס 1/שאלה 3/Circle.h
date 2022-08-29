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

///---------------------------------------- Circle ����� ���� ����� ���� �� ------------------------------------------///

//---------- Circle ����� ������ ------------//

class Circle {

private:

	Point center;
	int radius;

public:


	//---------------------- ����� �����, ����� ��������  -----------------------//

	//------ Radius �� -------//
	int getRadius() {
		return this->radius;
	}


	//------ Radius �� -------//
	void setRadius(int myRadius) {
		this->radius = myRadius;
	}


	//------ Center �� -------//
	Point getCenter() {
		return this->center;
	}


	//--------- Center �� ----------//
	void setCenter(int x, int y) {
		this->center.setX(x);
		this->center.setY(y);
	}


	//-------����� ����� ��� ����� -------//
	float area() {
		const float PAI = 3.14;
		float area = (float) (radius * radius * PAI);
		return area;
	}


	//----����� ����� ���� ����� -------//
	float perimeter() {
		const float PAI = 3.14;
		float perimeter = (float)((radius + radius) * PAI);
		return perimeter;
	}


	//-------------- ����� ����� ����� ����� ---------------//
	int onInOut(Point p) {

		//---- ����� ���� ��"� ������ �� ����� ������� ----//
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

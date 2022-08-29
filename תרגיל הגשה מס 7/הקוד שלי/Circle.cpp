/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 7          *
*                            *
******************************/
#include "Circle.h"
#include <iostream>
using namespace std;
///---------------------------------------- Circle �� cpp - ����� ����� � ------------------------------------------///


//------------------- constructor ----------------------//
//-- ����������� ���� �� ���� ��� ���� --//    //--- father's ctor ---//
Circle::Circle(float my_radius) : Shape(1) {

	//--- ���� ��� ����� ��� ����� -----//
	this->setRadius(my_radius);
}



//-------------- �� ����� -----------------//
float Circle::getRadius() {
	return  this->radius;
}


//-------------- �� ����� ----------------//
void Circle:: setRadius(float my_radius){

	if (my_radius < 0) {
		throw "invalid input\n";
	}
	else {
		this->radius = my_radius;
	}
}




//----------------- ����� ��� ���� ------------------//
float Circle::area()const {
	const float PAI = 3.14;
	float circle_area = (this->radius * this->radius) * PAI;

	return circle_area;
}




//-------------------- ����� ����� ������ --------------------//
bool Circle::isSpecial()const {

	//------ (����� �� ����� ���� ����� ��� (0,0 --------//
	if (this->p->getX() == 0 && this->p->getY() == 0) {
		return true;
	}

	else {
		return false;
	}
}



//-------------- ����� ������ ������� ���� ����� ---------------//
void Circle::printSpecial()const {

	if (isSpecial() == true) {
		cout << "A canonical circle with a radius " << this->radius << endl;
	}
}
/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 7          *
*                            *
******************************/
#include "Circle.h"
#include <iostream>
using namespace std;
///---------------------------------------- Circle של cpp - אנחנו בקובץ ה ------------------------------------------///


//------------------- constructor ----------------------//
//-- הקונסטרקטור מקבל את ערכי הבן והאב --//    //--- father's ctor ---//
Circle::Circle(float my_radius) : Shape(1) {

	//--- ערכי הבן שאותם הוא מאתחל -----//
	this->setRadius(my_radius);
}



//-------------- גט רדיוס -----------------//
float Circle::getRadius() {
	return  this->radius;
}


//-------------- סט רדיוס ----------------//
void Circle:: setRadius(float my_radius){

	if (my_radius < 0) {
		throw "invalid input\n";
	}
	else {
		this->radius = my_radius;
	}
}




//----------------- חישוב שטח מעגל ------------------//
float Circle::area()const {
	const float PAI = 3.14;
	float circle_area = (this->radius * this->radius) * PAI;

	return circle_area;
}




//-------------------- בדיקת תכונה מיוחדת --------------------//
bool Circle::isSpecial()const {

	//------ (בדיקה אם נקודת מרכז המעגל היא (0,0 --------//
	if (this->p->getX() == 0 && this->p->getY() == 0) {
		return true;
	}

	else {
		return false;
	}
}



//-------------- הדפסת התכונה המיוחדת מעגל קנוני ---------------//
void Circle::printSpecial()const {

	if (isSpecial() == true) {
		cout << "A canonical circle with a radius " << this->radius << endl;
	}
}
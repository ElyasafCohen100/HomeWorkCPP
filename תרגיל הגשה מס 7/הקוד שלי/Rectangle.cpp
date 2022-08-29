/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 7          *
*                            *
******************************/
#include "Rectangle.h"
#include <iostream>
using namespace std;
///---------------------------------------------------- Rectangle של cpp - אנחנו בקובץ ה -------------------------------------------------------///


//---------------- default-constructor -----------------//
Rectangle::Rectangle() :Shape(4) {
	/*
	Once the constructor has received that his "number of points" is 4
	it's opens an array of size 4 and puts the point in it
	*/
}


//------------------- חישוב שטח --------------------//
float Rectangle::area()const {
	float s = (this->p[0].distance(this->p[1])) * (this->p[1].distance(this->p[2]));

	return s;
}


//---------------- פונקציה ורטואלית בדיקת תכונה מיוחדת ---------------//
bool Rectangle::isSpecial()const {

	/*
	Once the constructor has received that his "number of points" is 4
	it's opens an array of size 4 and enters the point in it
	our test is done on this array
	*/

	//------------------ הגדרת הצלעות ----------------//
	float side1 = this->p[0].distance(this->p[1]);
	float side2 = this->p[1].distance(this->p[2]);
	float side3 = this->p[2].distance(this->p[3]);
	float side4 = this->p[3].distance(this->p[0]);


	//---- בדיקה שהמרובע הוא ריבוע ----//
	if (side1 == side2 && side1 == side3 && side1 == side4) {
		return true;
	}
	else {
		return false;
	}

}



//------------------- הדפסת התכונה מיוחדת --------------------//
void Rectangle::printSpecial()const {
	
	if (this->isSpecial() == true) {
		cout << "Square with side length " << this->p[0].distance(this->p[1]) << endl;
	}
}

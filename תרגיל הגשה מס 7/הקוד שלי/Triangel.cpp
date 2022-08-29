/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 7          *
*                            *
******************************/
#include "Triangle.h"
#include <iostream>
#include <cmath>
using namespace std;
///---------------------------------------------------- Triangel של cpp - אנחנו בקובץ ה -------------------------------------------------------///


//---------------- default-constructor -----------------//
Triangel::Triangel() :Shape(3) { // מגדירים לקונסטרקטור האב 3 נקודות 
/*
Once the constructor has received that his "number of points" is 3
it's opens an array of size 3 and puts the point in it
*/
}



//-------------------- פונקציה ורטואלית חישוב שטח ------------------//
float Triangel::area()const {

	//----- הגדרת צלעות המשולש -----//
	float a = this->p[0].distance(this->p[1]);
	float b = this->p[1].distance(this->p[2]);
	float c = this->p[2].distance(this->p[0]);

	//------ משפט הקוסינוסים -----//
	float cos_gama = (pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2 * a * b);
	float gama_angel = acos(cos_gama); // gama = arc-cos(gama);


	//--- חישוב שטח משולש עפ"י משפט הסינוסים ---//
	float s = (a * b * sin(gama_angel)) / 2;

	return s;
}




//---------------- פונקציה ורטואלית בדיקת תכונה מיוחדת ---------------//
bool Triangel::isSpecial()const {

	/*
	Once the constructor has received that his "number of points" is 3
	it's opens an array of size 3 and enters the point in it
	our test is done on this array
	*/

	//------ בדיקה שהמשולש הוא שווה צלעות ------//

	float side1 = this->p[0].distance(this->p[1]);
	float side2 = this->p[1].distance(this->p[2]);
	float side3 = this->p[2].distance(this->p[0]);

	if (side1 == side2 && side1 == side3 && side2 == side3) {
		return true;
	}
	else {
		return false;
	}
}



//------------- פונקציה ורטואלית הדפסת התכונה מיוחדת --------------//
void Triangel::printSpecial()const {

	if (isSpecial() == true) {
		cout << "An isosceles triangle with a side length " << this->p[0].distance(this->p[1]) << endl;
	}
}
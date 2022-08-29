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
///---------------------------------------------------- Triangel �� cpp - ����� ����� � -------------------------------------------------------///


//---------------- default-constructor -----------------//
Triangel::Triangel() :Shape(3) { // ������� ����������� ��� 3 ������ 
/*
Once the constructor has received that his "number of points" is 3
it's opens an array of size 3 and puts the point in it
*/
}



//-------------------- ������� �������� ����� ��� ------------------//
float Triangel::area()const {

	//----- ����� ����� ������ -----//
	float a = this->p[0].distance(this->p[1]);
	float b = this->p[1].distance(this->p[2]);
	float c = this->p[2].distance(this->p[0]);

	//------ ���� ���������� -----//
	float cos_gama = (pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2 * a * b);
	float gama_angel = acos(cos_gama); // gama = arc-cos(gama);


	//--- ����� ��� ����� ��"� ���� �������� ---//
	float s = (a * b * sin(gama_angel)) / 2;

	return s;
}




//---------------- ������� �������� ����� ����� ������ ---------------//
bool Triangel::isSpecial()const {

	/*
	Once the constructor has received that his "number of points" is 3
	it's opens an array of size 3 and enters the point in it
	our test is done on this array
	*/

	//------ ����� ������� ��� ���� ����� ------//

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



//------------- ������� �������� ����� ������ ������ --------------//
void Triangel::printSpecial()const {

	if (isSpecial() == true) {
		cout << "An isosceles triangle with a side length " << this->p[0].distance(this->p[1]) << endl;
	}
}
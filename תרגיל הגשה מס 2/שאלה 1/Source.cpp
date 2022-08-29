/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 2 seif 1   *
*                            *
******************************/
#include "Polygon.h"
#include<iostream>
#include <cmath>
using namespace std;

int main() {

	//--------------------- מצולע ראשון --------------------//
	cout << "enter number of sides: " << endl;
	int Number_of_sides;
	cin >> Number_of_sides;

	//--- בדיקת תקינות קלט ---//
	while (Number_of_sides < 0) {
		cout << "ERROR\a" << endl;
		cin >> Number_of_sides;
	}

	Polygon poly1(Number_of_sides);

	//--------------------- מצולע שני ---------------------//
	cout << "enter number of sides: " << endl;
	cin >> Number_of_sides;

	while (Number_of_sides < 0) {
		cout << "ERROR\a" << endl;
		cin >> Number_of_sides;
	}

	Polygon poly2(Number_of_sides);

	//------------ בדיקה אם שני מצולעים זהים --------------//
	if (poly1.equality_between_polygons(poly2) == true) {
		cout << "equal.perimeter: " << poly1.perimeter() << endl;
	}
	else {
		cout << "perimeter: " << poly1.perimeter() << endl;
		cout << "perimeter: " << poly2.perimeter() << endl;
	}

	return 0;
}
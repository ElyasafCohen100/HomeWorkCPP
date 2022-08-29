 #pragma once
/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 2 seif 1   *
*                            *
******************************/
#pragma once
#include<iostream>
#include "Point.h"
#include <cmath>
using namespace std;

///---------------------------------------- Polygon אנחנו כרגע בקובץ ההדר של ------------------------------------------///

//---------- Polygon פתיחת המחלקה ------------//

class Polygon {

private:

	Point* p; // מצביע למערך של קודקודים
	int number_of_vertices; // מספר הקודקודים במצולע

public:

	//---------------------------- הגדרת הגטים והסטים והמתודות  ----------------------------//

	//---------- number_of_vertices גט -----------//
	int get_number_of_vertices() {
		return this->number_of_vertices;
	}

	//---------- number_of_vertices סט -----------//
	void set_number_of_vertices(int my_number_of_vertices) {
		this->number_of_vertices = my_number_of_vertices;
	}


	//--------------------- constructor -----------------------//
	Polygon(int Number_of_sides) {

		cout << "in constructor" << endl;
		cout << "enter the point values:" << endl;

		//--- גודל המערך הוא כמס הצלעות במצולע ---//
		p = new	Point[Number_of_sides];

		int x, y;
		char tav;

		//------ הכנסת הקודקודים למערך -----//
		for (int i = 0; i < Number_of_sides; i++) {
			cin >> tav >> x >> tav >> y >> tav;
			(p + i)->setX(x);
			(p + i)->setY(y);
		}
		number_of_vertices = Number_of_sides;
	}



	//------------------- copy-constructor ------------------//
	Polygon(const Polygon& poly) {

		cout << "in copy-constructor " << endl;
		this->number_of_vertices = poly.number_of_vertices; // העתקה רדודה

		//--- העתקה עמוקה ----//
		p = new	Point[number_of_vertices];

		for (int i = 0; i < number_of_vertices; i++) {
			*(p + i) = *(poly.p + i);
		}

	}


	//--------------------- destructor ---------------------//
	~Polygon() {

		cout << "in destructor" << endl;

		if (p) {
			delete p;
		}
		p = NULL;
	}


	//----------------- addPoint מתודת הוספת קודקוד למערך הקדוקודים --------------------//
	void addPoint(int index, Point new_point) {

		//----- הגדרת מערך עם גודל חדש -----//
		Point* arr = new Point[number_of_vertices + 1];

		//-- הזרמת המערך הקיים למערך עם הגודל החדש --//
		for (int i = 0; i < number_of_vertices; i++) {
			*(arr + i) = *(p + i);
		}

		//----------- הוספת הנקודה --------//
		*(arr + number_of_vertices) = new_point;

		delete[]p;
		p = arr;
	}


	//----------------------------- מתודת חישוב היקף מצולע ----------------------------------//
	double perimeter() {

		double perimeter = 0;
		//-------- חיבור כל הצלעות לפי דלתא ---------//
		for (int i = 0; i < number_of_vertices - 1; i++) {
			perimeter += p[i].distance(p[i + 1]);
		}

		//---- חבור דלתת הקודקוד הראשון ואחרון ----//
		perimeter += p[0].distance(p[number_of_vertices-1]);
		return round(perimeter); // מעוגל למס הקרוב ביותר 
	}


	//-------------------- מתודה בולאינית הבודקת אם שני מצולעים שווים ---------------------------//
	bool equality_between_polygons(Polygon poly) {

		if (this->number_of_vertices != poly.number_of_vertices) {
			return false;
		}

		//--- בדיקה האם הקודקודים שווים נשים לב שהם לאו דווקא מסודרים לפי הסדר ----//
		int count = 0;
		for (int i = 0; i < number_of_vertices; i++) {
			for (int j = 0; j < number_of_vertices; j++) {
				if ((p[i].getX() == p[j].getX() && p[i].getY() == p[j].getY())) {
					count++;
				}
			}
		}

		//----- צריך להיות שווה לכמות הקודקודים count אם ערך הנקודות שווה ------//
		if (count == number_of_vertices) {
			return true;
		}
		else {
			return false;
		}
	}
};

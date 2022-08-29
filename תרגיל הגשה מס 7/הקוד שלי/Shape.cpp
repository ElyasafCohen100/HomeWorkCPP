/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 7          *
*                            *
******************************/
#include "Shape.h"
#include <iostream>
using namespace std;
///---------------------------------------- Shape של cpp - אנחנו בקובץ ה ------------------------------------------///


//---------------- default-constructor -----------------//
Shape::Shape() {
	//	this->num_of_points = 0;
	//	this->p = NULL;
}



//------------------- constructor ----------------------//
Shape::Shape(int my_num_of_points) {
	
	this->num_of_points = my_num_of_points;
		 
	if (my_num_of_points < 0) {
		return;
	}

	//---- פתיחת מערך שיכיל את מס הקודקודים ----//
	this->p = new Point[my_num_of_points];
	cout << "Enter values of " << my_num_of_points <<" "<< "points: " << endl;

	Point my_point;

	//---- קליטת הנקודות והכנסתן למערך ----//
	for (int i = 0; i < my_num_of_points; i++) {
		cin >> my_point;
		this->p[i] = my_point;
	}
}



//----------------- copy constructor -------------------//
Shape::Shape(const Shape& my_shape) {

	//----- העתקה רדודה -----//
	this->num_of_points = my_shape.num_of_points;

	//----- העתקה עמוקה -----//
	this->p = new Point[my_shape.num_of_points];

	for (int i = 0; i < this->num_of_points; i++) {
		*(this->p + i) = *(my_shape.p + i);
	}
}



//----------------- move-constructor -------------------//
Shape::Shape(Shape&& my_shape) {
	//---- העתקה רדודה ----//
	this->num_of_points = my_shape.num_of_points;
	this->p = my_shape.p; // גנבת המערך

	my_shape.p = NULL; // ניתוק הקשר של המערך
}



//---------------- virtual destructor ------------------//
Shape::~Shape() { // virtual - במימוש לא כותבים
	if (this->p) {
		delete[]p;
	}

	this->p = NULL;
}



//-------------- << פונקציה חברה - אופרטור פלט -----------------//
ostream& operator<<(ostream& os, const Shape& my_shape) {
	cout << endl;
	cout << "points: ";

	//----- ריצה על המערך והדפסת הנקודות -----//
	for (int i = 0; i < my_shape.num_of_points; i++) {
		os << "(" << my_shape.p[i].getX() << "," << my_shape.p[i].getY() << ")" << " ";
	}

	return os;
}


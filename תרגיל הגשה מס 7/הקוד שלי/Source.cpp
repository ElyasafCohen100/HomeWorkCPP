/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 7          *
*                            *
******************************/
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
#include <string>


int main() {

	cout << " How many shapes you would like to define? " << endl;
	int length;
	cin >> length;

	//---- הגדרת מערך של מצביעים מסוג אבא כוכבית ----//
	Shape** shape_arr = new Shape * [length];

	int choice;
	float my_radius;

	for (int i = 0; i < length; i++) {

		cout << "Which shape will you choose? Circle - 1, Triangular - 3, Rectangle - 4 " << endl;
		cin >> choice;

		switch (choice) {

		case 1:

			//------- קליטת הרדיוס --------//
			try {
				cout << "Enter radius: " << endl;
				cin >> my_radius;
				shape_arr[i] = new Circle(my_radius); // יצביע על מעגל עם רדיוס מהמשתמש i התא ה
			}
			catch (const string str) {
				cout << "invalid input " << endl;
			}

			break;


		case 3:
			shape_arr[i] = new Triangel;
			break;

		case 4:
			shape_arr[i] = new Rectangle;
			break;


		default: // במקרה שלא נבחר 1 3 או 4

			cout << "invalid input " << endl;
			i--; // איזון האיטרציה
			break;
		};
	}


	//---- ריצה על המערך המכיל בכל תא מצביע לצורה מסויימת והדפסת תכונה מיוחדת בהתאמה -----//
	for (int i = 0; i < length; i++) {

		cout << *shape_arr[i];
		cout << " area is: " << shape_arr[i]->area() << endl;
		if (shape_arr[i]->isSpecial() == true) {
			shape_arr[i]->printSpecial();
		}

	}

	return 0;
}

/*
 How many shapes you would like to define?
3
Which shape will you choose? Circle - 1, Triangular - 3, Rectangle - 4
3
Enter values of 3 points:
(0,0) (1,0) (1,1)
Which shape will you choose? Circle - 1, Triangular - 3, Rectangle - 4
1
Enter radius:
4
Enter values of 1 points:
(0,0)
Which shape will you choose? Circle - 1, Triangular - 3, Rectangle - 4
2
invalid input
Which shape will you choose? Circle - 1, Triangular - 3, Rectangle - 4
4
Enter values of 4 points:
(0,0) (1,0) (1,1) (0,1)

points: (0,0) (1,0) (1,1)  area is: 0.5

points: (0,0)  area is: 50.24
A canonical circle with a radius 4

points: (0,0) (1,0) (1,1) (0,1)  area is: 1
Square with side length 1
Press any key to continue . . .
*/
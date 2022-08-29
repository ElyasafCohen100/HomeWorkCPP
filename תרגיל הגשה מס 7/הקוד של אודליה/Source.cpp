/*Odelya Yaakowich 207346784
Workshop in c++
Exercise 7 Question 1*/

#include<iostream>
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
using namespace std;


int main()
{

	cout << "How many shapes you would like to define?" << endl;
	int size = 0, choice;
	cin >> size;
	Shape** arrShape = new Shape * [size];
	for (int i = 0; i < size; i++)
	{
		cout << "Which shape will you choose? Circle - 1, Triangular - 3, Rectangle – 4" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter radius:" << endl;
			int r;
			cin >> r;
			try
			{
				arrShape[i] = new Circle(r);   //circle
			}
			catch (const char* msg)
			{
				cout << msg;
			}
			break;
		case 3:
			arrShape[i] = new Triangle;
			break;
		case 4:
			arrShape[i] = new Rectangle;
			break;
		default:
			cout << "invalid input" << endl;
			i--;
		};
	}

	for (int i = 0; i < size; i++)
	{
		cout << *arrShape[i] << "area is: " << arrShape[i]->area() << endl;
		if (arrShape[i]->isSpecial())
			arrShape[i]->printSpecial();
	}


	return 0;
}



/*
How many shapes you would like to define?
3
Which shape will you choose? Circle - 1, Triangular - 3, Rectangle – 4
3
Enter values of  3 points:
(0,0) (1,0) (1,1)
Which shape will you choose? Circle - 1, Triangular - 3, Rectangle – 4
1
Enter radius:
4
Enter values of  1 points:
(0,0)
Which shape will you choose? Circle - 1, Triangular - 3, Rectangle – 4
2
invalid input
Which shape will you choose? Circle - 1, Triangular - 3, Rectangle – 4
4
Enter values of  4 points:
(0,0) (1,0) (1,1) (0,1)

points: (0,0) (1,0) (1,1)  area is: 0.5

points: (0,0) area is: 50.24
A canonical circle with a radius 4

points: (0,0) (1,0) (1,1) (0,1)  area is: 1
Square with side length 1

*/
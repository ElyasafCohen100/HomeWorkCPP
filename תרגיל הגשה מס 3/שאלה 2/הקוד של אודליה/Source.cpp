/*Odelya Yaakowich 207346784
Workshop in c++
Exercise 3 Question 2*/

#include "Date.h"
#include <iostream>
using namespace std; 


enum {stop = -1, setDate = 1, addPre, addPost, add, bigger, smaller, bothEqual};

int main() {
	
	int day, mounth, year;
	char tav;

	cout << "Enter a date" << endl;
	cin >> day >> tav >> mounth >> tav >> year;

	Date d1(day, mounth, year), d2, d3, d4;
	d1.print();

	int choice;
	cout << "Enter an action code:" << endl;
	cin >> choice;

	while (choice != -1)
	{
		switch (choice)
		{
		case setDate:
			cout << "Enter a date" << endl;
			cin >> day >> tav >> mounth >> tav >> year;
			d1.setDate(day, mounth, year);
			d1.print();
			break;

		case addPre:
			(++d1).print();
			break;

		case addPost:
			(d1++).print();
			break;

		case add:
			cout << "Enter # days" << endl;
			int days;
			cin >> days;
			d1 += days;
			d1.print();
			break;

		case bigger:
			cout << "Enter a date" << endl;
			cin >> day >> tav >> mounth >> tav >> year;
			d2.setDate(day, mounth, year);
			(d1 > d2) ? cout << ">: true" : cout << ">: false"; cout << endl;
			break;

		case smaller:
			cout << "Enter a date" << endl;
			cin >> day >> tav >> mounth >> tav >> year;
			d3.setDate(day, mounth, year);
			(d1 < d3) ? cout << "<: true" : cout << "<: false"; cout << endl;
			break;

		case bothEqual:
			cout << "Enter a date" << endl;
			cin >> day >> tav >> mounth >> tav >> year;
			d4.setDate(day, mounth, year);
			(d1 == d4) ? cout << "==: true" : cout << "==: false"; cout << endl;
			break;
		}
		cout << "Enter an action code:" << endl;
		cin >> choice;
	}


	return 0;
}





/*
Enter a date
-5/1/2012
Error day
1/1/2012
What do you want to do
1
Enter a date
5/7/2010
5/7/2010
What do you want to do
2
6/7/2010
What do you want to do
3
6/7/2010
What do you want to do
4
Enter # days
7
14/7/2010
What do you want to do
5
Enter a date
14/7/2010
>: false
What do you want to do
7
Enter a date
14/7/2010
==: true
What do you want to do
-1
*/
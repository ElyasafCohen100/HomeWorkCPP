/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 3 seif 2   *
*                            *
******************************/
#include "Date.h"
#include<iostream>
using namespace std;

enum { stop = -1, update = 1, print_prefix, print_postfix, plus_equal, big, small, equal_equal };

int main() {

	cout << "Enter a date " << endl;
	char tav;
	int day, month, year;
	cin >> day >> tav >> month >> tav >> year;

	Date date(day, month, year);
	date.print();


	Date new_date;
	int index;
	bool flag = true;

	while (flag) {

		cout << "Enter an action code: " << endl;
		cin >> index;

		switch (index) {

			//-------------------- עדכון תאריך --------------------//
		case update:

			cout << "Enter a date " << endl;
			cin >> day >> tav >> month >> tav >> year;
			date.setDate(day, month, year);

			date.print();
			break;

			//---------------- פלוס פלוס תחילי -------------------//
		case print_prefix:
			(++date).print();
			break;


			//---------------- פלוס פלוס סופי -------------------//
		case print_postfix:
			date++.print();
			break;


			//------------------ פלוס שווה ----------------------//
		case plus_equal:

			cout << "Enter # days" << endl;
			cin >> day;
			(date += day).print();
			break;


			//--------------------- גדול ------------------------//
		case big:

			cout << "Enter a date" << endl;

			cin >> day >> tav >> month >> tav >> year;
			new_date.setDate(day, month, year);

			if (date > new_date) {
				cout << ">:true" << endl;
			}
			else {
				cout << ">:false" << endl;
			}

			break;


			//---------------------- קטן -------------------------//
		case small:
			cout << "Enter a date" << endl;

			cin >> day >> tav >> month >> tav >> year;
			new_date.setDate(day, month, year);

			if (date < new_date) {
				cout << "<:true" << endl;
			}
			else {
				cout << "<:false" << endl;
			}

			break;

			//------------------- שווה שווה ---------------------//
		case equal_equal:

			cout << "Enter a date" << endl;

			cin >> day >> tav >> month >> tav >> year;
			new_date.setDate(day, month, year);

			if (date == new_date) {
				cout << "==:true" << endl;
			}
			else {
				cout << "==:flase" << endl;
			}
			break;

		case -1:

			flag = false;

		default:
			break;
		}
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
>:false
What do you want to do
7
Enter a date
14/7/2010
==true:
What do you want to do
-1
Press any key to continue . . .

*/
/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 3 seif 3   *
*                            *
******************************/
#include "MyString.h"
#include <iostream>
#include<cstring>
#include<string>
#pragma warning (disable:4996)
using namespace std;

///------------------------------------------------ cpp - אנחנו כרגע בקובץ ה -----------------------------------------------------///

int main() {

	MyString a;
	MyString b;

	//----------- מחרוזת ראשונה ----------//
	char* help_str1;
	help_str1 = new char[81];

	cin.getline(help_str1, 81);
	a.setStr(help_str1);

	//----------- מחרוזת שניה ------------//
	char* help_str2;
	help_str2 = new char[81];

	cin.getline(help_str2, 81);
	b.setStr(help_str2);

	int n; // אינדקס לפונקציה איסנרט -הוספה
	cin >> n;

	//------ הדפסת הודעה המייצגת את היחס בין המחרוזות ------//
	if (a > b) {
		cout << "a>b" << endl;
	}
	else if (a < b) {
		cout << "a<b" << endl;
	}
	else {
		cout << "a=b" << endl;
	}


	//------ הכנסת המחרוזת הראשונה לשניה -------//
	MyString str; //b - מוכנסת ב a מחרוזת שתקבל את המחרוזת  
	str = b.insert(n, a.getStr());

	//---- שינוי אינדקס מסויים במחרוזת החדשה ----//
	char tav;
	cin >> tav;

	int index;
	cin >> index;

	str[index] = tav;
	str.print();

	return 0;
}

/*
world
hello
2
a>b
heworldllo
!
5
hewor!dllo
Press any key to continue . . .

*/






using namespace std;

int main() {

	char* help_str = new char[81];

	cin >> help_str;
	MyString a(help_str);

	cin >> help_str;
	MyString b(help_str);

	int n;
	cin >> n;

	if (a > b) {
		cout << "a>b" << endl;
	}
	else if (a < b) {
		cout << "a<b" << endl;
	}
	else {
		cout << "a=b" << endl;
	}


	MyString str(b.insert(n, a.getStr()));
	str.print();

	if (str.getStr() != NULL) {


		char c;
		cin >> c >> n;

		if (c == '?' && n == 10) {
			cout << "ERROR\n";
			return 0;
		}

		str[n] = c;

		if (n < str.getlen() - 1 && n >= 0) {
			str.print();
		}
	}
	else {
		cout << "ERROR\n";
	}

	return 0;

}
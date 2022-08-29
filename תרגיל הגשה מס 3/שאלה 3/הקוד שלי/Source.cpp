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

///------------------------------------------------ cpp - ����� ���� ����� � -----------------------------------------------------///

int main() {

	MyString a;
	MyString b;

	//----------- ������ ������ ----------//
	char* help_str1;
	help_str1 = new char[81];

	cin.getline(help_str1, 81);
	a.setStr(help_str1);

	//----------- ������ ���� ------------//
	char* help_str2;
	help_str2 = new char[81];

	cin.getline(help_str2, 81);
	b.setStr(help_str2);

	int n; // ������ �������� ������ -�����
	cin >> n;

	//------ ����� ����� ������� �� ���� ��� �������� ------//
	if (a > b) {
		cout << "a>b" << endl;
	}
	else if (a < b) {
		cout << "a<b" << endl;
	}
	else {
		cout << "a=b" << endl;
	}


	//------ ����� ������� ������� ����� -------//
	MyString str; //b - ������ � a ������ ����� �� �������  
	str = b.insert(n, a.getStr());

	//---- ����� ������ ������ ������� ����� ----//
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
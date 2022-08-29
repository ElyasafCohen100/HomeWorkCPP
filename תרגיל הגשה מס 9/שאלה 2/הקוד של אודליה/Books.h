/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 9          *
* seif:    II                *
******************************/
#pragma once
#include<string>
#include <iostream>
using namespace std;
///------------------------------------------------ Books ���� ���� �� -----------------------------------------------------///


//------------------ Books ����� ������ --------------------//
class Books {

private:

	int code_book; // ��� ����
	string author_name; // �� �����
	string book_name; // �� ����

public:


	//-------------- ���������� -----------------//
	Books();
	//------------- < ������� ��� ---------------//
	const bool operator<(Books&);
	//------------- > ������� ���� --------------//
	const bool operator>(const Books&);
	//----------- <= ������� ��� ���� -----------//
	const bool operator<=(const Books&);


	//---------- >= ������� ���� ���� -----------//
	const bool operator>=(const Books&);
	//---------- == ������� ���� ���� -----------//
	const bool operator==(const Books&);
	//----------- != ������� �� ���� ------------//
	const bool operator!=(const Books&);


	//----------------- << ������� ���� - ������� ��� --------------------//
	friend ostream& operator<<(ostream& os, const Books& in);
	//----------------- >> ������� ���� - ������� ��� --------------------//
	friend istream& operator>>(istream& is, Books& in);
};


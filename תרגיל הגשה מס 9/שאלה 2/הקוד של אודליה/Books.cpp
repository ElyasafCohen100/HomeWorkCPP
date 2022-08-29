/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 9          *
* seif:    II                *
******************************/
#include "Books.h"
#include<string>
#include<string.h>
#include<iostream>
using namespace std;
///------------------------------------------------ Books �� cpp - ����� ����� � -----------------------------------------------------///


//-------------------- ���������� -----------------------//
Books::Books() {
	this->code_book = 0;
	this->author_name = " ";
	this->book_name = " ";
}



//------------------- < ������� ��� ---------------------//
const bool Books::operator<(Books& in) {

	//------ ����� �� �� ����� -------//
	if (this->author_name.compare(in.author_name) < 0) {
		return true;
	}
	else if (this->author_name.compare(in.author_name) > 0) {
		return false;
	}

	//------ ����� �� ��� ���� ------//
	if (this->book_name.compare(in.book_name) < 0) {
		return true;
	}
	else if (this->book_name.compare(in.book_name) > 0) {
		return false;
	}

	//------ ����� �� ��� ���� -----//
	if (this->code_book < in.code_book) {
		return true;
	}

	return false;
}



//------------------- > ������� ���� --------------------//
const bool Books::operator>(const Books& in) {

	//------ ����� �� �� ����� -------//
	if (this->author_name.compare(in.author_name) > 0) {
		return true;
	}
	else if (this->author_name.compare(in.author_name) < 0) {
		return false;
	}

	//------ ����� �� ��� ���� ------//
	if (this->book_name.compare(in.book_name) > 0) {
		return true;
	}
	else if (this->book_name.compare(in.book_name) > 0) {
		return false;
	}

	//------ ����� �� ��� ���� -----//
	if (this->code_book > in.code_book) {
		return true;
	}

	return false;
}



//----------------- <= ������� ��� ���� ----------------//
const bool Books::operator<=(const Books& in) {

	if (this->author_name.compare(in.author_name) <= 0) {
		return true;
	}

	return false;
}



//---------------- >= ������� ���� ���� -----------------//
const bool Books::operator>=(const Books& in) {

	if (this->author_name.compare(in.author_name) >= 0) {
		return true;
	}

	return false;
}



//---------------- == ������� ���� ���� -----------------//
const bool Books::operator==(const Books& in) {

	//------- ����� �� ������ ����� ------//
	if (this->author_name.compare(in.author_name) || this->book_name.compare(in.book_name) || this->code_book != in.code_book) {
		return false;
	}

	return true; // �� �� �� ����� (���� �����) ����� ���
}



//----------------- != ������� �� ���� ------------------//
const bool Books::operator!=(const Books& in) {
	return !(*this == in);
}



//----------------- << ������� ���� - ������� ��� --------------------//
ostream& operator<<(ostream& os, const Books& in) {
	os << in.code_book << " " << in.author_name << " " << in.book_name;
	return os;
}



//----------------- >> ������� ���� - ������� ��� --------------------//
istream& operator>>(istream& is, Books& in) {
	is >> in.code_book >> in.author_name >> in.book_name;
	return is;
}
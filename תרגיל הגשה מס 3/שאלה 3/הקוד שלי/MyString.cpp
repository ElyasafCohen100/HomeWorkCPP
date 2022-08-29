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

//------------------------------------------------ �� ���� cpp - ����� ���� ����� � -----------------------------------------------------///

//------------------ ����� ����� ������ --------------------//

//------ str �� ------//
char* MyString::getStr() {
	return this->str;
}


//------ len �� ------//
int MyString::getlen() {
	return this->len;
}



//------ str �� ------//
void MyString::setStr(char*& my_str) {
	if (this->str) {
		delete[]this->str;
	}
	this->str = my_str;
	this->len = strlen(my_str); // ����� ����� �����
}


//------ len �� ------//
void MyString::setlen(int my_len) {
	this->len = my_len;
}



//------------------  ������ ���������� --------------------//
MyString::MyString() {
	this->str = nullptr;
	this->len = 0;
}

//**--------------------- ���������� ----------------------**//
MyString::MyString(const char* s) {

	if (s) {

		this->len = strlen(s);
		this->str = new char[this->len + 1];
		strncpy(this->str, s, this->len + 1);
	}
	else {
		this->str = nullptr;
	}
	cout << "ctor: " << this->str << endl;
}


//**----------------- ���� ���������� --------------------**//
MyString::MyString(const MyString& ms) {

	len = strlen(ms.str);

	if (ms.str) {
		this->str = new char[this->len + 1];
		strncpy(this->str, ms.str, this->len + 1);
	}
	else {
		this->str = nullptr;
	}
}

//**------------------ ������� ����� ---------------------**//
MyString& MyString:: operator=(const MyString& ms) {

	if (this->str != ms.str) { // ����� ��� ������ �� ������ �� ��� ����� �����

		this->len = ms.len;

		if (this->str) { //   ����� �� ����� ��� �� ����� ������
			delete[] this->str; // ��� ���� ���� 
		}

		//-----����� �� ����� ���� ----//
		if (ms.str) {

			this->len = strlen(ms.str);
			this->str = new char[this->len + 1];
			strncpy(this->str, ms.str, this->len + 1);
		}
		else {
			this->str = nullptr;
		}

		cout << this->str << endl;
	}

	return *this;
}


//------------------------ ��������� --------------------------//
MyString::~MyString() {

	if (this->str) { //very important!!!
		delete[] this->str;
	}

	this->str = nullptr;
}



//----------------------- == ���� ���� -------------------------//
bool MyString::operator==(const MyString& ms) const {

	cout << "operator== : " << this->str << endl;
	return !strcmp(this->str, ms.str);
}


//------------------------- + ���� ------------------------------//
MyString MyString::operator+(const MyString& ms) const {

	int sizeI = this->len;
	int sizeII = ms.len;

	char* temp = new char[sizeI + sizeII + 1];

	strncpy(temp, this->str, sizeI + 1);
	strncpy(temp + sizeI, ms.str, sizeII + 1);

	MyString x(temp);
	cout << "operator+ : " << this->str << endl;

	return x;
}



//------------------------- * ��� ------------------------------//
MyString MyString::operator*(const int num) const {

	char* temp;
	temp = new char[this->len * num + 1];

	for (int i = 0; i < num; i++) {
		strncpy(temp + i * this->len, str, this->len + 1);
	}

	MyString s(temp);
	cout << "operator* : " << this->str << endl;

	return s;
}




//------------------------ << ��� ��� --------------------------//
ostream& operator<<(ostream& os, const MyString& ms) {

	if (ms.str) {
		os << ms.str << endl;
	}

	//cout << "operator<< : " << ms.str << endl;
	cout << ms.str << endl;
	return os;
}


//---------------------- >> ���� ���� --------------------------//
istream& operator>>(istream& is, MyString& ms) {

	is >> ms.len;
	ms.str = new char[ms.len + 1];
	is >> ms.str;

	return is;
}

//--------------------------- > ���� -----------------------------//
bool MyString:: operator>(const MyString st) const {

	//---- st - ������ 1 ���� ��� ����� � strcmp �� -----//
	if (strcmp(this->str, st.str) > 0) {
		return true;
	}

	else {
		return false;
	}

	// ���� �� ��� //
	//return (strcmp(this->str, st.str) > 0);

}


//--------------------------- < ��� -----------------------------//
bool MyString:: operator<(const MyString st)const {

	//---- st - ������ 1- ���� ��� ���� � strcmp �� -----//
	if (strcmp(this->str, st.str) < 0) {
		return true;
	}

	else {
		return false;
	}

	// ���� �� ��� //
	//return (strcmp(this->str, st.str) < 0);
}



//----------------------- >= ���� ���� -------------------------//
bool MyString:: operator>=(const MyString st)const {

	if (strcmp(this->str, st.str) < 0) { // ����� ���� ���� ����
		return false;
	}
	else {
		return true;
	}

	// ���� �� ��� //
//return (strcmp(this->str, st.str) >= 0);
}



//----------------------- <= ��� ���� -------------------------//
bool MyString ::operator<=(const MyString st)const {

	if (strcmp(this->str, st.str) > 0) { // ����� ���� ����� ����
		return false;
	}
	else {
		return true;
	}

	// ���� �� ��� //
//return (strcmp(this->str, st.str) <= 0);
}



//----------------------- != �� ���� -------------------------//
bool MyString ::operator!=(const MyString st)const {

	if (strcmp(this->str, st.str) != 0) {
		return true;
	}
	else {
		return false;
	}

	// ���� �� ��� //
//return (strcmp(this->str, st.str) != 0);
}


//----------------------- [] ������� --------------------------//
char& MyString:: operator[] (int index) {

	if (this->len <= index || index < 0) {
		cout << "ERROR" << endl;
		this->str = nullptr;
		return *(this->str);
	}
	else {
		return this->str[index]; // ����� ���� �� ������ ���� �������
	}
}


//--------------------- insert ����� ------------------------//
MyString MyString::insert(int index, const char* my_str) {

	MyString the_new_str;

	//---- ����� ������ ���� ����� �� ��� �������� ----//
	the_new_str.len = strlen(this->str) + strlen(my_str) + 1; // ���� ������� ����� ����� ��� ������� ������� ���� 1 � /0
	the_new_str.str = new char[the_new_str.len];

	//----- index ����� ������ -----//
	if (index < 0 || index >= the_new_str.len) {

		cout << "ERROR" << endl;

		delete[] the_new_str.str;
		the_new_str.str = nullptr;
		
		return the_new_str;
	}

	//------ ����� �������� ������� ����� ------//
	strncpy(the_new_str.str, this->str, index); // ����� �� ����� �� ������ ���� ����� ����
	the_new_str.str[index] = '\0';// ������ ������ ��� ����� ������
	strcat(the_new_str.str, my_str); //  ����� ������� ����� ������� �����
	

	//--------- ����� ��� ������� ����� -------//
	for (int i = index; i < this->len; i++) {
		the_new_str.str[i + strlen(my_str)] = this->str[i];
	}
	the_new_str.str[the_new_str.len - 1] = '\0'; // ������ ������ ��� ����� ������

	return the_new_str;
}

//---------------- ����� ����� -----------------//
void MyString::print() {
	cout << str << endl;
}

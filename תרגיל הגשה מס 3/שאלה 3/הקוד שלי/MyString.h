/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 3 seif 3   *
*                            *
******************************/
#pragma once
#include<cstring>
#include<string>
#pragma warning (disable:4996)
using namespace std;
///------------------------------------------------ ����� ���� ����� ���� -----------------------------------------------------///

//---------- MyString ����� ������ ------------//
class MyString {

private:

	int len = 0; // ���� �������
	char* str; // ����� �������

public:

	//------------------ ������ ���������� --------------------//
	MyString();
	//**--------------------- ���������� ----------------------**//
	MyString(const char* s);
	//**----------------- ���� ���������� --------------------**//
	MyString(const MyString& ms);
	//**------------------ ������� ����� ---------------------**//
	MyString& operator=(const MyString& ms);
	//------------------------- ��������� ---------------------------//
	~MyString();


	//------ str �� ------//
	char* getStr();
	//------ str �� ------//
	void setStr(char*& my_str);
	//------ len �� ------//
	int getlen();
	//------ len �� ------//
	void setlen(int my_len);


	//----------------------- == ���� ���� --------------------------//
	bool operator==(const MyString& ms) const;

	//------------------------- + ���� ------------------------------//
	MyString operator+(const MyString& ms) const;

	//--------------------------- * ��� -----------------------------//
	MyString operator*(const int num) const;

	//------------------------ << ��� ��� ---------------------------//
	friend ostream& operator<<(ostream& os, const MyString& ms);

	//---------------------- >> ���� ���� --------------------------//
	friend istream& operator>>(istream& is, MyString& ms);

	//-------------------------- > ���� ----------------------------//
	bool operator>(const MyString str)const;

	//--------------------------- < ��� ----------------------------//
	bool operator<(const MyString str)const;

	//----------------------- >= ���� ���� ------------------------//
	bool operator>=(const MyString str)const;

	//----------------------- <= ��� ���� -------------------------//
	bool operator<=(const MyString str)const;

	//----------------------- != �� ���� --------------------------//
	bool operator!=(const MyString str)const;

	//----------------------- [] ������� --------------------------//
	char& operator[] (int index);

	//---------------------- insert ����� -------------------------//
	MyString insert(int index, const char* str);

	//----------------------- ����� ����� ------------------------//
	void print();
};

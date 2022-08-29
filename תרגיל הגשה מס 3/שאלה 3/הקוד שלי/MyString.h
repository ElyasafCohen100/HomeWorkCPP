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
///------------------------------------------------ אנחנו כרגע בקובץ ההדר -----------------------------------------------------///

//---------- MyString פתיחת המחלקה ------------//
class MyString {

private:

	int len = 0; // אורך המחרוזת
	char* str; // מצביע למחרוזת

public:

	//------------------ דיפולט קונסטרקטור --------------------//
	MyString();
	//**--------------------- קונסטרקטור ----------------------**//
	MyString(const char* s);
	//**----------------- קופי קונסטרקטור --------------------**//
	MyString(const MyString& ms);
	//**------------------ אופרטור ההשמה ---------------------**//
	MyString& operator=(const MyString& ms);
	//------------------------- דיסטרקטור ---------------------------//
	~MyString();


	//------ str גט ------//
	char* getStr();
	//------ str סט ------//
	void setStr(char*& my_str);
	//------ len גט ------//
	int getlen();
	//------ len סט ------//
	void setlen(int my_len);


	//----------------------- == שווה שווה --------------------------//
	bool operator==(const MyString& ms) const;

	//------------------------- + פלוס ------------------------------//
	MyString operator+(const MyString& ms) const;

	//--------------------------- * כפל -----------------------------//
	MyString operator*(const int num) const;

	//------------------------ << קטן קטן ---------------------------//
	friend ostream& operator<<(ostream& os, const MyString& ms);

	//---------------------- >> גדול גדול --------------------------//
	friend istream& operator>>(istream& is, MyString& ms);

	//-------------------------- > גדול ----------------------------//
	bool operator>(const MyString str)const;

	//--------------------------- < קטן ----------------------------//
	bool operator<(const MyString str)const;

	//----------------------- >= גדול שווה ------------------------//
	bool operator>=(const MyString str)const;

	//----------------------- <= קטן שווה -------------------------//
	bool operator<=(const MyString str)const;

	//----------------------- != לא שווה --------------------------//
	bool operator!=(const MyString str)const;

	//----------------------- [] אופרטור --------------------------//
	char& operator[] (int index);

	//---------------------- insert מתודת -------------------------//
	MyString insert(int index, const char* str);

	//----------------------- מתודת הדפסה ------------------------//
	void print();
};

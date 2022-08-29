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

//------------------------------------------------ של ההדר cpp - אנחנו כרגע בקובץ ה -----------------------------------------------------///

//------------------ הגדרת הגטים והסטים --------------------//

//------ str גט ------//
char* MyString::getStr() {
	return this->str;
}


//------ len גט ------//
int MyString::getlen() {
	return this->len;
}



//------ str סט ------//
void MyString::setStr(char*& my_str) {
	if (this->str) {
		delete[]this->str;
	}
	this->str = my_str;
	this->len = strlen(my_str); // עדכון הגודל החחדש
}


//------ len סט ------//
void MyString::setlen(int my_len) {
	this->len = my_len;
}



//------------------  דיפולט קונסטרקטור --------------------//
MyString::MyString() {
	this->str = nullptr;
	this->len = 0;
}

//**--------------------- קונסטרקטור ----------------------**//
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


//**----------------- קופי קונסטרקטור --------------------**//
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

//**------------------ אופרטור ההשמה ---------------------**//
MyString& MyString:: operator=(const MyString& ms) {

	if (this->str != ms.str) { // בדיקה שלא קיבלתי את הכתובת של דיס בעצמו בטעות

		this->len = ms.len;

		if (this->str) { //   בדיקה אם למופע שלי יש הקצאה דינמית
			delete[] this->str; // אני דורס אותה 
		}

		//-----בדיקה על המופע השני ----//
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


//------------------------ דיסטרקטור --------------------------//
MyString::~MyString() {

	if (this->str) { //very important!!!
		delete[] this->str;
	}

	this->str = nullptr;
}



//----------------------- == שווה שווה -------------------------//
bool MyString::operator==(const MyString& ms) const {

	cout << "operator== : " << this->str << endl;
	return !strcmp(this->str, ms.str);
}


//------------------------- + פלוס ------------------------------//
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



//------------------------- * כפל ------------------------------//
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




//------------------------ << קטן קטן --------------------------//
ostream& operator<<(ostream& os, const MyString& ms) {

	if (ms.str) {
		os << ms.str << endl;
	}

	//cout << "operator<< : " << ms.str << endl;
	cout << ms.str << endl;
	return os;
}


//---------------------- >> גדול גדול --------------------------//
istream& operator>>(istream& is, MyString& ms) {

	is >> ms.len;
	ms.str = new char[ms.len + 1];
	is >> ms.str;

	return is;
}

//--------------------------- > גדול -----------------------------//
bool MyString:: operator>(const MyString st) const {

	//---- st - מחזירה 1 משמע דיס גדולה מ strcmp אם -----//
	if (strcmp(this->str, st.str) > 0) {
		return true;
	}

	else {
		return false;
	}

	// אפשר גם ככה //
	//return (strcmp(this->str, st.str) > 0);

}


//--------------------------- < קטן -----------------------------//
bool MyString:: operator<(const MyString st)const {

	//---- st - מחזירה 1- משמע דיס קטנה מ strcmp אם -----//
	if (strcmp(this->str, st.str) < 0) {
		return true;
	}

	else {
		return false;
	}

	// אפשר גם ככה //
	//return (strcmp(this->str, st.str) < 0);
}



//----------------------- >= גדול שווה -------------------------//
bool MyString:: operator>=(const MyString st)const {

	if (strcmp(this->str, st.str) < 0) { // במידה ודיס קטנה יותר
		return false;
	}
	else {
		return true;
	}

	// אפשר גם ככה //
//return (strcmp(this->str, st.str) >= 0);
}



//----------------------- <= קטן שווה -------------------------//
bool MyString ::operator<=(const MyString st)const {

	if (strcmp(this->str, st.str) > 0) { // במדיה ודיס גדולה יותר
		return false;
	}
	else {
		return true;
	}

	// אפשר גם ככה //
//return (strcmp(this->str, st.str) <= 0);
}



//----------------------- != לא שווה -------------------------//
bool MyString ::operator!=(const MyString st)const {

	if (strcmp(this->str, st.str) != 0) {
		return true;
	}
	else {
		return false;
	}

	// אפשר גם ככה //
//return (strcmp(this->str, st.str) != 0);
}


//----------------------- [] אופרטור --------------------------//
char& MyString:: operator[] (int index) {

	if (this->len <= index || index < 0) {
		cout << "ERROR" << endl;
		this->str = nullptr;
		return *(this->str);
	}
	else {
		return this->str[index]; // החזרת הערך של המצביע פלוס האינדקס
	}
}


//--------------------- insert מתודת ------------------------//
MyString MyString::insert(int index, const char* my_str) {

	MyString the_new_str;

	//---- פתיחת מחרוזת חדשה שתכיל את שתי המחרוזות ----//
	the_new_str.len = strlen(this->str) + strlen(my_str) + 1; // אורך המחרוזת החדשה כגודל שתי מחרוזות הנכנסות פלוס 1 ל /0
	the_new_str.str = new char[the_new_str.len];

	//----- index בדיקת תקינות -----//
	if (index < 0 || index >= the_new_str.len) {

		cout << "ERROR" << endl;

		delete[] the_new_str.str;
		the_new_str.str = nullptr;
		
		return the_new_str;
	}

	//------ הכנסת המחרוזות למחרוזת החדשה ------//
	strncpy(the_new_str.str, this->str, index); // מכניס מס כלשהו של איברים מדיס למערך החדש
	the_new_str.str[index] = '\0';// הכניסת באקסלש אפס במקום האחרון
	strcat(the_new_str.str, my_str); //  הזרמת המחרוזת השניה למחרוזת החדשה
	

	//--------- הזרמת שאר האותיות למערך -------//
	for (int i = index; i < this->len; i++) {
		the_new_str.str[i + strlen(my_str)] = this->str[i];
	}
	the_new_str.str[the_new_str.len - 1] = '\0'; // הכניסת באקסלש אפס במקום האחרון

	return the_new_str;
}

//---------------- מתודת הדפסה -----------------//
void MyString::print() {
	cout << str << endl;
}

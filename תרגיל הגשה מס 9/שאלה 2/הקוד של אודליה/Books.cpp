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
///------------------------------------------------ Books של cpp - אנחנו בקובץ ה -----------------------------------------------------///


//-------------------- קונסטרקטור -----------------------//
Books::Books() {
	this->code_book = 0;
	this->author_name = " ";
	this->book_name = " ";
}



//------------------- < אופרטור קטן ---------------------//
const bool Books::operator<(Books& in) {

	//------ בדיקה על שם הסופר -------//
	if (this->author_name.compare(in.author_name) < 0) {
		return true;
	}
	else if (this->author_name.compare(in.author_name) > 0) {
		return false;
	}

	//------ בדיקה על השם הספר ------//
	if (this->book_name.compare(in.book_name) < 0) {
		return true;
	}
	else if (this->book_name.compare(in.book_name) > 0) {
		return false;
	}

	//------ בדיקה על קוד הספר -----//
	if (this->code_book < in.code_book) {
		return true;
	}

	return false;
}



//------------------- > אופרטור גדול --------------------//
const bool Books::operator>(const Books& in) {

	//------ בדיקה על שם הסופר -------//
	if (this->author_name.compare(in.author_name) > 0) {
		return true;
	}
	else if (this->author_name.compare(in.author_name) < 0) {
		return false;
	}

	//------ בדיקה על השם הספר ------//
	if (this->book_name.compare(in.book_name) > 0) {
		return true;
	}
	else if (this->book_name.compare(in.book_name) > 0) {
		return false;
	}

	//------ בדיקה על קוד הספר -----//
	if (this->code_book > in.code_book) {
		return true;
	}

	return false;
}



//----------------- <= אופרטור קטן שווה ----------------//
const bool Books::operator<=(const Books& in) {

	if (this->author_name.compare(in.author_name) <= 0) {
		return true;
	}

	return false;
}



//---------------- >= אופרטור גדול שווה -----------------//
const bool Books::operator>=(const Books& in) {

	if (this->author_name.compare(in.author_name) >= 0) {
		return true;
	}

	return false;
}



//---------------- == אופרטור שווה שווה -----------------//
const bool Books::operator==(const Books& in) {

	//------- בדיקה אם הספרים שונים ------//
	if (this->author_name.compare(in.author_name) || this->book_name.compare(in.book_name) || this->code_book != in.code_book) {
		return false;
	}

	return true; // אם הם לא שונים (משמע שווים) יוחזר טרו
}



//----------------- != אופרטור לא שווה ------------------//
const bool Books::operator!=(const Books& in) {
	return !(*this == in);
}



//----------------- << פונקציה חברה - אופרטור פלט --------------------//
ostream& operator<<(ostream& os, const Books& in) {
	os << in.code_book << " " << in.author_name << " " << in.book_name;
	return os;
}



//----------------- >> פונקציה חברה - אופרטור קלט --------------------//
istream& operator>>(istream& is, Books& in) {
	is >> in.code_book >> in.author_name >> in.book_name;
	return is;
}
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
///------------------------------------------------ Books קובץ ההדר של -----------------------------------------------------///


//------------------ Books פתיחת המחלקה --------------------//
class Books {

private:

	int code_book; // קוד הספר
	string author_name; // שם הסופר
	string book_name; // שם הספר

public:


	//-------------- קונסטרקטור -----------------//
	Books();
	//------------- < אופרטור קטן ---------------//
	const bool operator<(Books&);
	//------------- > אופרטור גדול --------------//
	const bool operator>(const Books&);
	//----------- <= אופרטור קטן שווה -----------//
	const bool operator<=(const Books&);


	//---------- >= אופרטור גדול שווה -----------//
	const bool operator>=(const Books&);
	//---------- == אופרטור שווה שווה -----------//
	const bool operator==(const Books&);
	//----------- != אופרטור לא שווה ------------//
	const bool operator!=(const Books&);


	//----------------- << פונקציה חברה - אופרטור פלט --------------------//
	friend ostream& operator<<(ostream& os, const Books& in);
	//----------------- >> פונקציה חברה - אופרטור קלט --------------------//
	friend istream& operator>>(istream& is, Books& in);
};


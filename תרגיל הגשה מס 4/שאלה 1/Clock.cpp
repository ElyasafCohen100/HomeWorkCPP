/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 4          *
*                            *
******************************/
#include "Clock.h"
#include <iostream>
#pragma warning (disable:4996)
using namespace std;
///------------------------------------------------ Clock של cpp - אנחנו כרגע בקובץ ה -----------------------------------------------------///

//------------------------ קונסטרקטור --------------------------//
Clock::Clock(int my_hour, int my_minute, int my_second) {

	//--- בגלל שהבדיקה נעשית בסטרים נכניס לקונסטרקטור את הסטרים ---//
	setHour(my_hour);
	setMinute(my_minute);
	setSecond(my_second);

}


//-------------------- קופי קונסטרקטור -------------------------//
Clock::Clock(const Clock& my_time) {
	this->hour = my_time.hour;
	this->minute = my_time.minute;
	this->second = my_time.second;
}


//------------------- הגדרת הגטרים והסטרים ---------------------//

//----------- hour גט -----------//
int Clock::getHour() const {
	return this->hour;
}

//---------- minute גט -----------//
int Clock::getMinute()const {
	return this->minute;
}

//--------- seconde גט ---------//
int Clock::getSecond()const {
	return this->second;
}


//----------- hour סט -----------//
void Clock::setHour(int my_hour) {
	if (my_hour > 23) {
		this->hour = 0;
		throw "Invalid time - more than 24 hours.\n";
	}

	else if (my_hour < 0) {
		this->hour = 0;
		throw "Invalid time - negative number of hours.\n";
	}

	else {
		this->hour = my_hour;
	}
}



//---------- minute סט ----------//
void Clock::setMinute(int my_minute) {

	if (my_minute > 59) {
		this->minute = 0;
		throw "Invalid time - more than 60 minutes.\n";
	}

	else if (my_minute < 0) {
		this->minute = 0;
		throw "Invalid time - negative number of minutes.\n";
	}

	else {
		this->minute = my_minute;
	}

}


//--------- seconde סט ---------//
void Clock::setSecond(int my_second) {

	if (my_second > 59) {
		this->second = 0;
		throw "Invalid time - more than 60 seconds.\n";
	}

	else if (my_second < 0) {
		this->second = 0;
		throw "Invalid time - negative number of seconds.\n";
	}

	else {
		this->second = my_second;
	}
}



//---------------------- += אופרטור פלוס שווה -------------------------//
Clock Clock:: operator+=(int num_of_seconds) {

	this->second += num_of_seconds;// הוספת השניות
	this->minute += this->second / 60; // כדי לקבל את מס השניות כפונקציה של דקות ושניות שארית
	this->second %= 60; // כדי לקבל את השניות תכלס
	this->hour += this->minute / 60;
	this->minute %= 60;
	this->hour %= 24;

	return *this;

}



//-------------------- << פונקציה חברה - אופרטור פלט -----------------------//
ostream& operator <<(ostream& tout, const Clock time) { // Clock ואובייקט מסוג ostream& הפונ מקבלת משתנה מסוג 

//----- return -וכנל ל ostream& אז אנחנו מגדירים ostream בגלל שאין לנו גישה להגדיר אובייקט חדש מסוג -----//

//--------- Clock נדפיס את האובייקט ostream& באמצעות ה -------//													
	if (time.hour < 10) { // בשביל לשמור על פורמט של שתי ספרות
		tout << "0" << time.hour;
	}

	else {
		tout << time.hour;
	}

	tout << ":";

	if (time.minute < 10) {
		tout << "0" << time.minute;
	}

	else {
		tout << time.minute;
	}
	tout << ":";

	if (time.second < 10) {
		tout << "0" << time.second;
	}

	else {
		tout << time.second;
	}

	//------- באופן כללי ניתן לעשות גם ככה --------//
	//tout << time.hour << ":" << time.minute << ":" << time.second << endl;

	return tout; //רגיל cout כדי שנוכל לעשות המשך שירשור כמו ב - ostream& מחזירים משתנה מסוג
}


//----------------- >> פונקציה חברה - אופרטור קלט --------------------//
istream& operator>>(istream& tin, Clock& time) { // "const Clock" כמו הפונקציה הקודמת רק שפה לא יהיה 

	tin >> time.hour; // time.hour קלט "סיאיני" לתוך 
	time.setHour(time.hour); //set בדיקת הקלט באמצעות 

	tin >> time.minute;
	time.setMinute(time.minute);

	tin >> time.second;
	time.setSecond(time.second);

	return tin;
}
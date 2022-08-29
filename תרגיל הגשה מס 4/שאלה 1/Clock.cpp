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
///------------------------------------------------ Clock �� cpp - ����� ���� ����� � -----------------------------------------------------///

//------------------------ ���������� --------------------------//
Clock::Clock(int my_hour, int my_minute, int my_second) {

	//--- ���� ������� ����� ������ ����� ����������� �� ������ ---//
	setHour(my_hour);
	setMinute(my_minute);
	setSecond(my_second);

}


//-------------------- ���� ���������� -------------------------//
Clock::Clock(const Clock& my_time) {
	this->hour = my_time.hour;
	this->minute = my_time.minute;
	this->second = my_time.second;
}


//------------------- ����� ������ ������� ---------------------//

//----------- hour �� -----------//
int Clock::getHour() const {
	return this->hour;
}

//---------- minute �� -----------//
int Clock::getMinute()const {
	return this->minute;
}

//--------- seconde �� ---------//
int Clock::getSecond()const {
	return this->second;
}


//----------- hour �� -----------//
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



//---------- minute �� ----------//
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


//--------- seconde �� ---------//
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



//---------------------- += ������� ���� ���� -------------------------//
Clock Clock:: operator+=(int num_of_seconds) {

	this->second += num_of_seconds;// ����� ������
	this->minute += this->second / 60; // ��� ���� �� �� ������ �������� �� ���� ������ �����
	this->second %= 60; // ��� ���� �� ������ ����
	this->hour += this->minute / 60;
	this->minute %= 60;
	this->hour %= 24;

	return *this;

}



//-------------------- << ������� ���� - ������� ��� -----------------------//
ostream& operator <<(ostream& tout, const Clock time) { // Clock �������� ���� ostream& ���� ����� ����� ���� 

//----- return -���� � ostream& �� ����� ������� ostream ���� ���� ��� ���� ������ ������� ��� ���� -----//

//--------- Clock ����� �� �������� ostream& ������� � -------//													
	if (time.hour < 10) { // ����� ����� �� ����� �� ��� �����
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

	//------- ����� ���� ���� ����� �� ��� --------//
	//tout << time.hour << ":" << time.minute << ":" << time.second << endl;

	return tout; //���� cout ��� ����� ����� ���� ������ ��� � - ostream& ������� ����� ����
}


//----------------- >> ������� ���� - ������� ��� --------------------//
istream& operator>>(istream& tin, Clock& time) { // "const Clock" ��� �������� ������ �� ��� �� ���� 

	tin >> time.hour; // time.hour ��� "������" ���� 
	time.setHour(time.hour); //set ����� ���� ������� 

	tin >> time.minute;
	time.setMinute(time.minute);

	tin >> time.second;
	time.setSecond(time.second);

	return tin;
}
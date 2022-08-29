/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 4          *
*                            *
******************************/
#pragma once
#pragma warning (disable:4996)
#include <iostream>
using namespace std;
///------------------------------------------------ Clock ����� ���� ����� ���� �� -----------------------------------------------------///

//---------- Clock ����� ������ ------------//
class Clock {

private:

	int hour = 0;
	int minute = 0;
	int second = 0;

public:
	//------------------------ ���������� --------------------------//
	Clock(int my_hour = 0, int my_minute = 0, int my_second = 0);

	//-------------------- ���� ���������� -------------------------//
	Clock(const Clock& my_time);

	//------------------- ����� ������ ������� ---------------------//
	int getHour()const;
	void setHour(int my_hour);

	int getMinute()const;
	void setMinute(int my_minute);

	int getSecond()const;
	void setSecond(int my_second);

	//---------------------- += ������� ���� ���� -------------------------//
	Clock operator+=(int second);

	//----------------- << ������� ���� - ������� ��� --------------------//
	friend ostream& operator<<(ostream& tout, const Clock time);

	//----------------- >> ������� ���� - ������� ��� --------------------//
	friend istream& operator>> (istream& tin, Clock& time);
};

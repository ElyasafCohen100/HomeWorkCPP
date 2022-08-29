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
///------------------------------------------------ Clock אנחנו כרגע בקובץ ההדר של -----------------------------------------------------///

//---------- Clock פתיחת המחלקה ------------//
class Clock {

private:

	int hour = 0;
	int minute = 0;
	int second = 0;

public:
	//------------------------ קונסטרקטור --------------------------//
	Clock(int my_hour = 0, int my_minute = 0, int my_second = 0);

	//-------------------- קופי קונסטרקטור -------------------------//
	Clock(const Clock& my_time);

	//------------------- הגדרת הגטרים והסטרים ---------------------//
	int getHour()const;
	void setHour(int my_hour);

	int getMinute()const;
	void setMinute(int my_minute);

	int getSecond()const;
	void setSecond(int my_second);

	//---------------------- += אופרטור פלוס שווה -------------------------//
	Clock operator+=(int second);

	//----------------- << פונקציה חברה - אופרטור פלט --------------------//
	friend ostream& operator<<(ostream& tout, const Clock time);

	//----------------- >> פונקציה חברה - אופרטור קלט --------------------//
	friend istream& operator>> (istream& tin, Clock& time);
};

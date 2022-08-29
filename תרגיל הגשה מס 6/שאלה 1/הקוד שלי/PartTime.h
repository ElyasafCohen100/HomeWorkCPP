/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 6          *
* Seif: I                    *
******************************/
#pragma once
#include "FullTime.h"
#include <iostream>
#include <string>
using namespace std;
///------------------------------------------------ PartTime אנחנו בקובץ ההדר של  -----------------------------------------------------///


//------------------------- PartTime פתיחת מחלקת הבן --------------------------//
class PartTime : public Employee { // Employee - יורשת מ PartTime המחלקה 

private:
	float business_hours; // שעות עבודה
	float pay_per_hour; // תשלום לשעה


public:

	//---- default constructor -----//
	PartTime();
	//------------------- קונסטרקטור מקבל את הערכים של הבן והאב--------------------//
	PartTime(float my_business_hours, float my_Pay_per_hour, string my_name, int my_taz, int my_seniority, float my_pay);


	//------------ הגדרת הגטים והסטים בהתאמה -------------//
	float get_business_hours()const;
	float get_pay_per_hour()const;

	void set_business_hours(float my_business_hours);
	void set_pay_per_hour(float my_pay_per_hour);



	//--------------- חישוב משכורת חודשית ----------------//
	float salary();



	//-------------- >> פונקציה חברה - אופרטור קלט -----------------//
	friend istream& operator>>(istream& is, PartTime& pt);
	//-------------- << פונקציה חברה - אופרטור פלט -----------------//
	friend ostream& operator<<(ostream& os, const PartTime& pt);

};
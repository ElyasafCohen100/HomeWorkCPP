/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 6          *
* Seif: I                    *
******************************/
#pragma once
#include "Employee.h"
#include <iostream>
#include <string>
using namespace std;
///------------------------------------------------ FullTime אנחנו בקובץ ההדר של  -----------------------------------------------------///


//------------------------- FullTime פתיחת מחלקת הבן --------------------------//
class FullTime : public Employee { // Employee - יורשת מ FullTime המחלקה 

private:
	float annual_salary; // משכורת שנתית

public:

	//---- default constructor -----//
	FullTime();
	//------------------- קונסטרקטור מקבל את הערכים של הבן והאב--------------------//
	FullTime(float my_annual_salary, string my_name, int my_taz, int my_seniority, float my_pay);



	//------------ הגדרת הגטים והסטים בהתאמה -------------//
	float getAnnualSalary() const;
	void setAnnualSalary(float my_annual_salary);



	//--------------- חישוב משכורת חודשית ----------------//
	float salary();



	//-------------- >> פונקציה חברה - אופרטור קלט -----------------//
	friend istream& operator>>(istream& is, FullTime& ft);
	//-------------- << פונקציה חברה - אופרטור פלט -----------------//
	friend ostream& operator<<(ostream& os, const FullTime& ft);

};


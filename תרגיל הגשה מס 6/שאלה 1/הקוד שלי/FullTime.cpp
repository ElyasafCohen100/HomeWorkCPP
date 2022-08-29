/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 6          *
* Seif: I                    *
******************************/
#include "FullTime.h"
#include <iostream>
#include <string>
using namespace std;
///------------------------------------------------ FullTime של cpp - אנחנו בקובץ ה -----------------------------------------------------///



//------------------- קונסטרקטור מקבל את הערכים של הבן והאב--------------------//                //--- father's ctor without "int"/"float" etc ----//
FullTime::FullTime(float my_annual_salary, string my_name, int my_taz, int my_seniority, float my_pay) :Employee(my_name, my_taz, my_seniority, my_pay) {
	this->annual_salary = my_annual_salary;
	/*
	//----- כל השדות שקונסטרקטור האבא מאתחל ולכן לא נכתוב אותם ------//
	this->name = my_name;
	this->taz = my_taz;
	this->seniority = my_seniority;
	this->pay = 0;
	*/
}


//--------------- default constructor -------------------//
FullTime::FullTime() :Employee(" ", 0, 0, 0) { // הדיפולט קוסנטרקטור קורא לקונסטרקטור של שהאבא ומציב בו ערכים ממשיים
	this->annual_salary = 0;
}

//----------------- annual_salary גט -------------------//
float FullTime::getAnnualSalary() const {
	return this->annual_salary;
}


//----------------- annual_salary סט -------------------//
void FullTime::setAnnualSalary(float my_annual_salary) {
	if (my_annual_salary > 0) {
		this->annual_salary = my_annual_salary;
		setPay(salary());
	}
	else {
		throw "ERROR\n";
	}
}

//--------------- חישוב משכורת חודשית ----------------//
float FullTime::salary() {
	return annual_salary / 12;
}





//-------------- >> פונקציה חברה - אופרטור קלט -----------------//
istream& operator>>(istream& is, FullTime& ft) {
	bool wasError = false;
	try
	{
		is >> (Employee&)ft;
	}
	catch (const char* msg)
	{
		wasError = true;
	}

	//------ השדה החדש של הבן -------//
	int annualSalary;
	is >> annualSalary;
	ft.setAnnualSalary(annualSalary);
	if (wasError)
	{
		throw "ERROR";
	}

	return is;
}


//-------------- << פונקציה חברה - אופרטור פלט -----------------//
ostream& operator<<(ostream& os, const FullTime& ft) {

	os << (Employee&)ft;
	os << "Salary per Month: " << ft.pay << endl;

	return os;
}

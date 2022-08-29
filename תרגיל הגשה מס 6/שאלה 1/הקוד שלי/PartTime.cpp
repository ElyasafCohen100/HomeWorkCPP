/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 6          *
* Seif: I                    *
******************************/
#include "PartTime.h"
#include <iostream>
#include <string>
using namespace std;


///------------------------------------------------ PartTime של cpp - אנחנו בקובץ ה -----------------------------------------------------///


//------------------- קונסטרקטור מקבל את הערכים של הבן והאב--------------------//                                          //--- father's ctor without "int"/"float" etc ----//
PartTime::PartTime(float my_business_hours, float my_Pay_per_hour, string my_name, int my_taz, int my_seniority, float my_pay) :Employee(my_name, my_taz, my_seniority, my_pay) {

	//---- השדות החדשים שהבן מאתחל ----//
	this->business_hours = my_business_hours;
	this->pay_per_hour = my_Pay_per_hour;

}

//---------------------- default constructor ---------------------//

				  //father's ctor's getting values//
PartTime::PartTime() :Employee(" ", 0, 0, 0) {
	this->business_hours = 0;
	this->pay_per_hour = 0;
}




//----------------- business_hours גט -------------------//
float PartTime::get_business_hours()const {
	return this->business_hours;
}


//----------------- pay_per_hour גט -------------------//
float PartTime::get_pay_per_hour()const {
	return this->pay_per_hour;
}



//----------------- business_hours סט -------------------//
void PartTime::set_business_hours(float my_business_hours) {

	if (my_business_hours >= 0) {
		this->business_hours = my_business_hours;
		setPay(salary());
	}
	else {
		throw "ERROR\n";
	}
}

//----------------- pay_per_hour סט -------------------//
void PartTime::set_pay_per_hour(float my_pay_per_hour) {

	if (my_pay_per_hour >= 0) {
		this->pay_per_hour = my_pay_per_hour;
		setPay(salary());
	}
	else {
		throw "ERROR\n";
	}
}


//--------------- חישוב משכורת חודשית ----------------//
float PartTime::salary() {
	float pay = this->business_hours * this->pay_per_hour;
	return pay;
}




//-------------- >> פונקציה חברה - אופרטור קלט -----------------//
istream& operator>>(istream& is, PartTime& pt) {

	bool wasError = false;
	try {
		is >> (Employee&)pt;
	}
	catch (const char* msg){
		wasError = true;
	}

	//-------- השדות החדשים של הבן ---------//
	int set_business_hours;
	is >> set_business_hours;

	int pay_per_hour;
	is >> pay_per_hour;
	pt.set_business_hours(set_business_hours);
	pt.set_pay_per_hour(pay_per_hour);

	if (wasError) {
		throw "ERROR";
	}

	return is;
}



//-------------- << פונקציה חברה - אופרטור פלט -----------------//
ostream& operator<<(ostream& os, const PartTime& pt) {

	os << (Employee&)pt;

	os << "Hours:" << pt.business_hours << endl;
	os << "Salary per Month: " << pt.pay << endl;

	return os;
}
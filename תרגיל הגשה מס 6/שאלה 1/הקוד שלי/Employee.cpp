/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 6          *
* Seif: I                    *
******************************/
#include "Employee.h"
#include <iostream>
#include <string>
using namespace std;
///------------------------------------------------ Employee של cpp - אנחנו בקובץ ה -----------------------------------------------------///



//------------------------- קונסטרקטור ---------------------------//
Employee::Employee(string my_name, int my_taz, int my_seniority) {
	this->name = my_name;
	this->taz = my_taz;
	this->seniority = my_seniority;
	this->pay = 0;
}



//------------------------ מתודות הגטים ------------------------//

//--------- name גט -------------//
string Employee::getName()const {
	return this->name;
}

//---------- taz גט --------------//
int Employee::getTaz()const {
	return this->taz;
}

//------- seniority גט -----------//
int Employee::getSeniority()const {
	return this->seniority;
}

//---------- pay גט --------------//
double Employee::getPay()const {
	return this->pay;
}



//------------------------ מתודות הסטים -------------------------//
void Employee::setName(string my_name) {
	this->name = my_name;
}

//-------------- taz סט -------------------//
void Employee::setTaz(int my_taz) {

	if (my_taz > 99999999 || my_taz < 1000000000) {
		this->taz = my_taz;
	}
	else {
		throw "ERROR\n";
	}
}


//------------ seniority סט -----------------//
void Employee::setSeniority(int my_seniority) {
	if (my_seniority >= 0) {
		this->seniority = my_seniority;
	}
	else {
		throw "ERROR\n";
	}
}


//-------------- pay סט -------------------//
void Employee::setPay(float my_Pay) {

	if (my_Pay >= 0) {
		this->pay = my_Pay;
	}
	else {
		throw "ERROR\n";
	}
}



//-------------- עדכון המשכורת אחר בונוס תשרי ------------------//
float Employee::salaryAfterBonus() {
	float salary = pay;
	if (this->seniority <= 5) {
		salary += 500;
	}
	else {
		
		salary = salary * 1.25;
	}
	return salary;
}



//-------------- >> פונקציה חברה - אופרטור קלט -----------------//
istream& operator>>(istream& is, Employee& emp) {

	cout << "Enter employee details: " << endl;
	string name;
	int taz;
	int seniority;
	is >> name;
	
	//-- set כל מה שעלול לזרוק חריגה נעשה באמצעות ----//
	is >> taz;

	is >> seniority;

	emp.setName(name);
	emp.setTaz(taz);
	emp.setSeniority(seniority);

	return is;
}


//-------------- << פונקציה חברה - אופרטור פלט -----------------//
ostream& operator<<(ostream& os, const Employee& emp) {

	os << "Employee: "<< emp.name << endl;
	os << "Employee ID: " << emp.taz << endl;
	os << "Years Seniority: " << emp.seniority << endl;

	return os;
}
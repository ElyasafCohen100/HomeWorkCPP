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
///------------------------------------------------ Employee �� cpp - ����� ����� � -----------------------------------------------------///



//------------------------- ���������� ---------------------------//
Employee::Employee(string my_name, int my_taz, int my_seniority) {
	this->name = my_name;
	this->taz = my_taz;
	this->seniority = my_seniority;
	this->pay = 0;
}



//------------------------ ������ ����� ------------------------//

//--------- name �� -------------//
string Employee::getName()const {
	return this->name;
}

//---------- taz �� --------------//
int Employee::getTaz()const {
	return this->taz;
}

//------- seniority �� -----------//
int Employee::getSeniority()const {
	return this->seniority;
}

//---------- pay �� --------------//
double Employee::getPay()const {
	return this->pay;
}



//------------------------ ������ ����� -------------------------//
void Employee::setName(string my_name) {
	this->name = my_name;
}

//-------------- taz �� -------------------//
void Employee::setTaz(int my_taz) {

	if (my_taz > 99999999 || my_taz < 1000000000) {
		this->taz = my_taz;
	}
	else {
		throw "ERROR\n";
	}
}


//------------ seniority �� -----------------//
void Employee::setSeniority(int my_seniority) {
	if (my_seniority >= 0) {
		this->seniority = my_seniority;
	}
	else {
		throw "ERROR\n";
	}
}


//-------------- pay �� -------------------//
void Employee::setPay(float my_Pay) {

	if (my_Pay >= 0) {
		this->pay = my_Pay;
	}
	else {
		throw "ERROR\n";
	}
}



//-------------- ����� ������� ��� ����� ���� ------------------//
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



//-------------- >> ������� ���� - ������� ��� -----------------//
istream& operator>>(istream& is, Employee& emp) {

	cout << "Enter employee details: " << endl;
	string name;
	int taz;
	int seniority;
	is >> name;
	
	//-- set �� �� ����� ����� ����� ���� ������� ----//
	is >> taz;

	is >> seniority;

	emp.setName(name);
	emp.setTaz(taz);
	emp.setSeniority(seniority);

	return is;
}


//-------------- << ������� ���� - ������� ��� -----------------//
ostream& operator<<(ostream& os, const Employee& emp) {

	os << "Employee: "<< emp.name << endl;
	os << "Employee ID: " << emp.taz << endl;
	os << "Years Seniority: " << emp.seniority << endl;

	return os;
}
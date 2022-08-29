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
///------------------------------------------------ FullTime �� cpp - ����� ����� � -----------------------------------------------------///



//------------------- ���������� ���� �� ������ �� ��� ����--------------------//                //--- father's ctor without "int"/"float" etc ----//
FullTime::FullTime(float my_annual_salary, string my_name, int my_taz, int my_seniority, float my_pay) :Employee(my_name, my_taz, my_seniority, my_pay) {
	this->annual_salary = my_annual_salary;
	/*
	//----- �� ����� ����������� ���� ����� ���� �� ����� ���� ------//
	this->name = my_name;
	this->taz = my_taz;
	this->seniority = my_seniority;
	this->pay = 0;
	*/
}


//--------------- default constructor -------------------//
FullTime::FullTime() :Employee(" ", 0, 0, 0) { // ������� ���������� ���� ����������� �� ����� ����� �� ����� ������
	this->annual_salary = 0;
}

//----------------- annual_salary �� -------------------//
float FullTime::getAnnualSalary() const {
	return this->annual_salary;
}


//----------------- annual_salary �� -------------------//
void FullTime::setAnnualSalary(float my_annual_salary) {
	if (my_annual_salary > 0) {
		this->annual_salary = my_annual_salary;
		setPay(salary());
	}
	else {
		throw "ERROR\n";
	}
}

//--------------- ����� ������ ������ ----------------//
float FullTime::salary() {
	return annual_salary / 12;
}





//-------------- >> ������� ���� - ������� ��� -----------------//
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

	//------ ���� ���� �� ��� -------//
	int annualSalary;
	is >> annualSalary;
	ft.setAnnualSalary(annualSalary);
	if (wasError)
	{
		throw "ERROR";
	}

	return is;
}


//-------------- << ������� ���� - ������� ��� -----------------//
ostream& operator<<(ostream& os, const FullTime& ft) {

	os << (Employee&)ft;
	os << "Salary per Month: " << ft.pay << endl;

	return os;
}

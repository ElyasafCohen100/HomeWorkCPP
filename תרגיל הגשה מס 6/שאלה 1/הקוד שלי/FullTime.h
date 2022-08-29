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
///------------------------------------------------ FullTime ����� ����� ���� ��  -----------------------------------------------------///


//------------------------- FullTime ����� ����� ��� --------------------------//
class FullTime : public Employee { // Employee - ����� � FullTime ������ 

private:
	float annual_salary; // ������ �����

public:

	//---- default constructor -----//
	FullTime();
	//------------------- ���������� ���� �� ������ �� ��� ����--------------------//
	FullTime(float my_annual_salary, string my_name, int my_taz, int my_seniority, float my_pay);



	//------------ ����� ����� ������ ������ -------------//
	float getAnnualSalary() const;
	void setAnnualSalary(float my_annual_salary);



	//--------------- ����� ������ ������ ----------------//
	float salary();



	//-------------- >> ������� ���� - ������� ��� -----------------//
	friend istream& operator>>(istream& is, FullTime& ft);
	//-------------- << ������� ���� - ������� ��� -----------------//
	friend ostream& operator<<(ostream& os, const FullTime& ft);

};


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
///------------------------------------------------ PartTime ����� ����� ���� ��  -----------------------------------------------------///


//------------------------- PartTime ����� ����� ��� --------------------------//
class PartTime : public Employee { // Employee - ����� � PartTime ������ 

private:
	float business_hours; // ���� �����
	float pay_per_hour; // ����� ����


public:

	//---- default constructor -----//
	PartTime();
	//------------------- ���������� ���� �� ������ �� ��� ����--------------------//
	PartTime(float my_business_hours, float my_Pay_per_hour, string my_name, int my_taz, int my_seniority, float my_pay);


	//------------ ����� ����� ������ ������ -------------//
	float get_business_hours()const;
	float get_pay_per_hour()const;

	void set_business_hours(float my_business_hours);
	void set_pay_per_hour(float my_pay_per_hour);



	//--------------- ����� ������ ������ ----------------//
	float salary();



	//-------------- >> ������� ���� - ������� ��� -----------------//
	friend istream& operator>>(istream& is, PartTime& pt);
	//-------------- << ������� ���� - ������� ��� -----------------//
	friend ostream& operator<<(ostream& os, const PartTime& pt);

};
/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 6          *
* Seif: I                    *
******************************/
#pragma once
#include <iostream>
#include <string>
using namespace std;
///------------------------------------------------ Employee ����� ����� ���� ��  -----------------------------------------------------///


//------------------------- Employee ����� ����� ��� --------------------------//
class Employee {

protected:
	string name; // �� ����
	int taz; // ��
	int seniority; // �� ���� ����
	float pay; // ��� �����

public:

	//------------------- ���������� --------------------//
	Employee(string my_name, int my_taz, int my_seniority);



	//------------ ����� ����� ������ ������ -------------//
	string getName()const;
	int getTaz()const;
	int getSeniority()const;
	double getPay()const;

	void setName(string my_name);
	void setTaz(int my_taz);
	void setSeniority(int my_seniority);
	void setPay(float my_Pay);



	//-------------- ����� ������� ��� ����� ���� ------------------//
	float salaryAfterBonus();
	//-------------- >> ������� ���� - ������� ��� -----------------//
	friend istream& operator>>(istream& is, Employee& emp);
	//-------------- << ������� ���� - ������� ��� -----------------//
	friend ostream& operator <<(ostream& os, const Employee& emp);

};
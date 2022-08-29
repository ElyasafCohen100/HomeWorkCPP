/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 10         *
*                            *
******************************/
#pragma once
#include<iostream>
#include <string>
using namespace std;
///------------------------------------------------ Soldier ����� ���� ���� �� -----------------------------------------------------///


//------------------------- Soldier ����� ������ ���������� --------------------------//
class Soldier {

protected:

	int taz; // ��
	string first_name; // �� ����
	string last_name; // �� �����
	int num_operation; // �� ������� ������ ��� ��� ���

public:


	//----------- ������ ���������� ----------------//
	Soldier() {
		this->taz = 0;
		this->first_name = ' ';
		this->last_name = ' ';
		this->num_operation = 0;
	}

	//------------ ���������� ����� ������ -----------//
	Soldier(int my_taz, string my_first_name, string my_last_name, int my_num_operation) {
		this->setTaz(my_taz);
		this->first_name = my_first_name;
		this->last_name = my_last_name;
		this->set_num_operation(my_num_operation);
	}

	//------------ virtual distractor ----------------//
	virtual ~Soldier() {}
	//--------- ��������� ����� ����� ���� ---------//
	virtual bool medal() const = 0;



	//---------------------------- ������ ����� ������ ---------------------------------//

	//------- first name �� -------//
	string getFname() const {
		return this->first_name;
	}

	//------- last name �� -------//
	string getName() const {
		return this->last_name;
	}

	//----- num_operation �� -----//
	int get_num_operation() {
		return this->num_operation;
	}



	//----------- taz �� ----------//
	void setTaz(int my_taz) {
		if (my_taz >= 0) {
			this->taz = my_taz;
		}
	}

	//------ num_operation �� ------//
	void set_num_operation(int my_num_operation) {
		if (my_num_operation > 0) {
			this->num_operation = my_num_operation;
		}
	}


	//--------- ������� ��������� ����� ------------//
	virtual void print()const {
		cout << "ID: " << this->taz << endl;
		cout << "first name: " << this->first_name << endl;
		cout << "last name: " << this->last_name << endl;
		cout << "num operations: " << this->num_operation << endl;
	}



	//---------------- ������� �� ��� ������� ����������� ���� ��� ������ �� ���� ����� ������� ����� -------------//

	//------------ ��������� ��� ����� ------------//
	virtual string string_soldierType() const {
		throw "ERROR: this function is just for officer soldier\n";
	}

	//------ Sociometric_score ��������� �� ------//
	virtual int get_Sociometric_score() {
		throw "ERROR: this function is just for officer soldier\n";
	}

	//----------- fighter ��������� �� -----------//
	virtual bool get_fighter() {
		throw "ERROR: this function is just for officer soldier\n";
	}

	/*

	//---------------------- ���� ����� ��� ��� ���� �� ������ �� ���� ��������� ��������� ------------------------//

	We have defined these two functions because we need the ability to access of "Soldier"
	because at the main we're define an " soldier* " type array and we want it to have access to the field
	that only exists in the "Officer" son.

	So in order for our abstract class to have access to it we have implemented here
	In order for there to be an orderly hierarchy a virtual function is done
	and so that only the son "Officer" has an orderly attitude, we've done the father "Soldier" will throw an exception
	and the son "Officer" will really operate the function.

	*/
};
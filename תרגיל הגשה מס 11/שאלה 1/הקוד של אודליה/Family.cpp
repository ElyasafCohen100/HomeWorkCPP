/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 11         *
*                            *
******************************/
#include "Family.h"
#include <iostream>
using namespace std;
///------------------------------------------------ Family של cpp - אנחנו בקובץ ה -----------------------------------------------------///

Family::Family() {

	this->family_number = 0;
	this->set_last_name(" ");

	this->num_of_people = 0;
	this->phone_number = 0;

	for (int i = 0; i < 6; i++) {
		this->classes[i] = false;
	}

}

//---------------------------- קונסטרקטור -----------------------------//
Family::Family(int myNumFamily, char* myLastName, int myNumOfPeople, int myNumPhone, string myBool) //ctor
{
	this->family_number = my_family_number;
	this->set_last_name(my_last_name);

	this->num_of_people = my_num_of_people;
	this->phone_number = my_phone_number;

	for (int i = 0; i < 6; i++) {
		this->classes[i] = myBool[i];
	}
}


//------------------------------- מתודות הגטים ---------------------------//
int Family::get_family_number() const {
	return this->family_number;
}

string Family::get_last_name() const {
	return this->last_name;
}

int Family::get_num_of_people() const {
	return this->num_of_people;
}

int Family::get_phone_number() const {
	return this->phone_number;
}

bool Family::get_classes(int myIndex)const {
	return this->classes[myIndex];
}



//------------------------------ מתודות הסטים ------------------------------//
void Family::set_family_number(int myNumFamily) {
	this->family_number = myNumFamily;
}

void Family::set_last_name(string myLastName) {
	strcpy_s(this->last_name, 20, myLastName.c_str());
}

void Family::set_num_of_people(int myNumOfPeople) {
	this->num_of_people = myNumOfPeople;
}

void Family::set_phone_number(int myNumPhone) {
	this->phone_number = myNumPhone;
}

void Family::set_classes(bool myBool, int myIndex) {
	this->classes[myIndex] = myBool;
}

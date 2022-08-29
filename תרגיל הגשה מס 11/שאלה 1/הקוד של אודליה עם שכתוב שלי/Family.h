/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 11         *
*                            *
******************************/
#pragma once
#include <string>
using namespace std;
///------------------------------------------------ Family אנחנו בקובץ ההדר של  -----------------------------------------------------///

//---------- Family פתיחת המחלקה ------------//
class Family {

private:

	int family_number; // מס משפחה
	char last_name[21]; // שם משפחה
	int num_of_people; // מס הנפשות במשפחה
	int phone_number; //מס טלפון
	bool classes[6]; // מערך החוגים

public:
	//--------------------- דיפולט קונסטרקטור -----------------------//
	Family();
	//------------------------ קונסטרקטור --------------------------//
	Family(int n, char*, int amount, int phone, string); //ctor

	//------------------- הגדרת הגטרים והסטרים ---------------------//
	int get_family_number() const;
	string get_last_name() const;
	int get_num_of_people() const;
	int get_phone_number() const;
	bool get_classes(int myIndex) const;


	void set_family_number(int my_family_number);
	void set_last_name(string my_last_name);
	void set_num_of_people(int my_num_of_people);
	void set_phone_number(int my_phone_number);
	void set_classes(bool my_bool, int my_index);

};
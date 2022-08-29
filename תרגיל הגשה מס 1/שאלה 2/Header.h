/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 1 seif 2   *
*                            *
******************************/
#pragma once
#include <iostream>	
#include <cstring>
using namespace std;

///------------------------------------------------ אנחנו כרגע בקובץ ההדר -----------------------------------------------------///

//---------- Latet_Mahalev פתיחת המחלקה ------------//
class Latet_Mahalev {

private:

	int id; // .ת.ז 
	char name[21]; // שם
	float pay_per_hour; // שכר לשעה
	int number_of_working_hours; //מס השעות שעבד 
	float sum_get_success; // סכום שהצליח להכניס לעמותה 


public:

	// ------------- הגדרת הגטים, הסטים והמתודות  -----------------//

	//---- גט תז ----//
	int getId() {
		return this->id;
	}

	//---- סט תז ----//
	void setId(int my_id) {
		this->id = my_id;
	}

	//---------------------------------------------------//

	//---- name גט ----//
	char* get_name() {
		return this->name;
	}

	//---- name סט ----//
	void set_name(char my_name[21]) {
		strcpy_s(this->name, my_name);
	}

	//---------------------------------------------------//

	//---- pay_per_hour גט ----//
	float get_pay_per_hour() {
		return this->pay_per_hour;
	}

	//---- pay_per_hour סט ----//
	void set_pay_per_hour(float my_pay_per_hour) {
		this->pay_per_hour = my_pay_per_hour;
	}

	//---------------------------------------------------//

	//---- number_of_working_hours גט ----//
	int get_number_of_working_hours() {
		return this->number_of_working_hours;
	}

	//---- number_of_working_hours סט ----//
	void set_number_of_working_hours(int my_number_of_working_hours) {
		this->number_of_working_hours = my_number_of_working_hours;
	}

	//---------------------------------------------------//

	//---- sum_get_success גט -----//
	float get_sum_get_success() {
		return this->sum_get_success;
	}
	//---- sum_get_success סט -----//
	void set_sum_get_success(float my_sum_get_success) {
		this->sum_get_success = my_sum_get_success;
	}

	//---------------------------------------------------//

	//---------------- מתודת חישוב המשכורת -------------------//
	float calc_salary() {

		int x = (number_of_working_hours * pay_per_hour); // מס שעות כפול שכר לשעה 
		int calculate = 0; // חישוב התוספת


		//-------- הכניס עד אלף --------//
		if (this->get_sum_get_success() <= 1000) {
			calculate = x + ((this->get_sum_get_success()) * 0.1);
		}


		//----------- בין אלף לאלפיים ------------//
		else if ((this->get_sum_get_success() > 1000) && (this->get_sum_get_success() <= 2000)) {
			calculate = x + ((1000 * 0.1) + ((this->get_sum_get_success() - 1000)) * 0.15);
		}

		//------------ בין אלפיים לארבע ------------//
		else if ((this->get_sum_get_success() > 2000) && (this->get_sum_get_success() <= 4000)) {
			calculate = x + ((1000 * 0.1) + (1000 * 0.15) + ((this->get_sum_get_success() - 2000) * 0.2));
		}


		//-------------- הכניס בין ארבע לחמש -----------//
		else if ((this->get_sum_get_success() > 4000) && (this->get_sum_get_success() <= 5000)) {
			calculate = x + ((1000 * 0.1) + (1000 * 0.15) + (2000 * 0.2) + ((this->get_sum_get_success() - 4000) * 0.3));
		}


		//----------- הכניס מעל חמש ------------//
		else if (this->get_sum_get_success() > 5000) {
			calculate = x + (((1000 * 0.1) + (1000 * 0.15) + (2000 * 0.2) + (1000 * 0.3) + (this->get_sum_get_success() - 5000) * 0.4));
		}

		return calculate;
	}
};





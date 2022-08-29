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
///------------------------------------------------ Employee אנחנו בקובץ ההדר של  -----------------------------------------------------///


//------------------------- Employee פתיחת מחלקת האב --------------------------//
class Employee {

protected:
	string name; // שם פרטי
	int taz; // תז
	int seniority; // מס שנות וותק
	float pay; // שכר לחודש

public:

	//------------------- קונסטרקטור --------------------//
	Employee(string my_name, int my_taz, int my_seniority);



	//------------ הגדרת הגטים והסטים בהתאמה -------------//
	string getName()const;
	int getTaz()const;
	int getSeniority()const;
	double getPay()const;

	void setName(string my_name);
	void setTaz(int my_taz);
	void setSeniority(int my_seniority);
	void setPay(float my_Pay);



	//-------------- עדכון המשכורת אחר בונוס תשרי ------------------//
	float salaryAfterBonus();
	//-------------- >> פונקציה חברה - אופרטור קלט -----------------//
	friend istream& operator>>(istream& is, Employee& emp);
	//-------------- << פונקציה חברה - אופרטור פלט -----------------//
	friend ostream& operator <<(ostream& os, const Employee& emp);

};
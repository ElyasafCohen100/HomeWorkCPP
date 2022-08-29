/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 4          *
*                            *
******************************/
#pragma once
#include<string>
#include <iostream>
#pragma warning (disable:4996)
using namespace std;
///------------------------------------------------ אנחנו כרגע בקובץ ההדר -----------------------------------------------------///

//---------- Account פתיחת המחלקה ------------//
class Account {

private:

	int accountNumber; // מס חשבון
	int code; // קוד סודי
	float balance; // היתרה בחשבון
	string mail; // מייל

public:

	//--------------------- דיפולט קונסטרקטור -----------------------//
	Account();

	//------------------------ קונסטרקטור --------------------------//
	Account(int my_accountNumber, int my_code, float my_balance, string my_mail);

	//------------------- הגדרת הגטרים והסטרים ---------------------//
	int getAccountNumber()const;
	int getCode()const;
	float getBalance()const;
	void setMail(string& my_mail);

	//----------------- >> פונקציה חברה - אופרטור קלט --------------------//
	friend istream& operator>> (istream& is, Account& my_account);

	//--------- מתודה למשיכת מזומנים --------//
	void withdraw(float nis);

	//--------- מתודה להפקדת מזומנים --------//
	void deposit(float nis);


	//------- תכונות ומתודות סטטיים -------// 
	static float sumWithdraw;
	static float sumDeposit;

	static float getSumWithdraw();
	static float getSumDeposit();
};

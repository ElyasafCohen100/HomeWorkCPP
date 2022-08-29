/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 4          *
*                            *
******************************/
#include "Account.h"
#include<string>
#pragma warning (disable:4996)	
using namespace std;
///------------------------------------------------ Account של cpp - אנחנו כרגע בקובץ ה -----------------------------------------------------///

//------- תכונות ומתודות סטטיים -------// 
float Account::sumWithdraw = 0; // סכום המשיכות
float Account::sumDeposit = 0; // סכום ההפקדות

float Account::getSumWithdraw() {
	return sumWithdraw;
}

float Account::getSumDeposit() {
	return  sumDeposit;
}


//--------------------- דיפולט קונסטרקטור -----------------------//
Account::Account() {

	this->accountNumber = 0;
	this->balance = 0;
	this->code = 0;
	this->mail.clear(); // החזרת מחרוזת ריקה
}

//------------------------ קונסטרקטור --------------------------//
Account::Account(int my_accountNumber, int my_code, float my_balance, string my_mail) {
	this->accountNumber = my_accountNumber;
	this->code = my_code;
	this->balance = my_balance;
	this->mail = my_mail;
}

//------------------- הגדרת הגטרים והסטרים ---------------------//
int Account::getAccountNumber()const {
	return this->accountNumber;
}

int Account::getCode()const {
	return this->code;
}


float Account::getBalance()const {
	return this->balance;
}


/*
	מחפשת את התו החל ממיקום מסויים. אפס זה ברירת המחדל find() הפונקציה
	find() - רצה על מחרוזת מסויימת *מההתחלה*, מחפשת את המחרוזת שבסוגריים ומחזירה את האינדקס בו היא מוצאת אותו
	rFind() - רק שהיא רצה על המחרוזת *מהסוף find() כמו
*/

void Account::setMail(string& my_mail) {

	if (my_mail.find("@", 0) == my_mail.rfind("@")) { // בדיקה אם @ מופיע פעם אחת

		//---- בדיקה שאין רווחים -----//
		if (my_mail.find(" ") == -1) { // שווה מינוס 1 משמע לא מצאנו את התו שחיפשנו

			//------ בדיקה שהסיומת של המייל היא אכן נכונה -----//
			if (my_mail.rfind(".com") == my_mail.length() - 4 || my_mail.rfind(".co.il") == my_mail.length() - 6) {
				this->mail.assign(my_mail); // העתקה עמוקה
			}
			else {
				throw "ERROR: email must end at .com or .co.il!\n"; // שגיאה בסיומת
			}
		}
		else {
			throw "ERROR: wrong email!\n"; // מייל שגוי
		}
	}
	else {
		throw "ERROR: email must contain @!\n"; // חוסר @ במייל
	}
}


//----------------- >> פונקציה חברה - אופרטור קלט --------------------//
istream& operator>> (istream& is, Account& my_account) {

	//--- קליטת מס חשבון ----//
	int accountNumber;
	is >> accountNumber;
	my_account.accountNumber = accountNumber;

	//---- קליטת קוד ----//
	int myCode;
	is >> myCode;


	//----- קליטת מייל ----//
	string myMail;
	is >> myMail;
	my_account.setMail(myMail);

	//--- לקוד אין סט ולכן נבדוק  אותו פה ---//
	if (myCode > 999 && myCode < 10000) {
		my_account.code = myCode;
	}

	else if (myCode >= 0 || myCode < 1000) {
		throw "ERROR: code must be of 4 digits!\n";
	}

	else {
		throw "ERROR: wrong code\n";
	}

	return is;
}


//---------------- מתודה למשיכת מזומנים -----------------//
void Account::withdraw(float nis) {

	//---- במדיה ולא נכנסים למינוס----//
	if ((this->balance - nis) > -6000) {

		if (nis <= 2500) { // אםלא עברנו את סכום משיכת המקסמימום

			this->balance -= nis; // הורדת המשיכה מהעו"ש
			sumWithdraw += nis; // הגדלת סכום המשיכה 
		}
		else
			throw "ERROR: cannot withdraw more than 2500 NIS!";
	}
	else {
		throw "ERROR: cannot have less than - 6000 NIS!";
	}
}



//--------- מתודה להפקדת מזומנים --------//
void Account::deposit(float nis) {

	if (nis > 10000) {
		throw "ERROR: cannot deposit more than 10000 NIS!\n"; // אסור להפקיד יותר מ -10000 ש"ח
	}

	else {
		this->balance += nis;
		sumDeposit += nis;
	}
}




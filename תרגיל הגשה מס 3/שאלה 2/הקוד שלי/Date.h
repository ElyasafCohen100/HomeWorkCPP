/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 3 seif 2   *
*                            *
******************************/
#pragma once
#include<iostream>
using namespace std;

///------------------------------------------------ אנחנו כרגע בקובץ ההדר -----------------------------------------------------///

//---------- Date פתיחת המחלקה ------------//
class Date {

private:

	int day;
	int month;
	int year;

public:

	//------------------------ קונסטרקטור --------------------------//
	Date(int my_day, int my_month, int my_year) {

		//----- בדיקת טווח הימים -----//
		if (my_day > 0 && my_day < 31) {
			this->day = my_day;
		}
		else {
			cout << "Error day " << endl;
			this->day = 1;
		}

		//----- בדיקת טווח החודשים -----//
		if (my_month > 0 && my_month < 13) {
			this->month = my_month;
		}

		else {
			cout << "Error month " << endl;
			this->month = 1;
		}

		//----- בדיקת טווח השנים -----//
		if (my_year > 1920 && my_year < 2099) {
			this->year = my_year;
		}

		else {
			cout << "Error year " << endl;
			this->year = 1920;
		}
	}

	//------------------ קונסטרקטור ללא ערכים --------------------//

	Date() {
		this->day = 1;
		this->month = 1;
		this->year = 1920;
	}

	//------------------- קופי קונסטרקטור -----------------------//
	Date(const Date& date) {
		this->day = date.day;
		this->month = date.month;
		this->year = date.year;
	}

	//------------------- מוב קונסטרקטור ------------------------//
	Date(Date&& date) {
		this->day = date.day;
		this->month = date.month;
		this->year = date.year;
	}


	//--------------------- setDate מתודת ------------------------//
	void setDate(int my_day, int  my_month, int my_year) {

		//------ אם כל התנאים של השדות מתקיימים יחדיו -------//
		if ((my_day > 0 || my_day < 31) && (my_month > 0 || my_month < 13) && (my_month > 1920 || my_month < 2099)) {
			this->day = my_day;
			this->month = my_month;
			this->year = my_year;
		}
	}

	//------------------- פלוס פלוס תחילי ----------------------//
	Date& operator ++() { // הפונקציה משנה את הערך לכן אין קונסט

		this->day++;

		if (this->day == 31) {
			this->month++;

			if (this->month == 13) {
				this->year++;
				this->month = 1;
			}

			this->day = 1;

			if (this->year > 2099) {

				this->day = 1;
				this->month = 1;
				this->year = 1920;
			}
			return *this;
		}
		return *this;
	}


	//------------------- פלוס פלוס סופי ----------------------//
	Date operator++(int postfix_not_used) { // ערך הפרמטר דיס משתנה ולכן  אין קונסט

		Date date = *this; //מגדירים אובייקט ששווה לדיס

		//----- מקדמים את דיס -----//
		this->day++;

		if (this->day == 31) {
			this->month++;

			if (this->month == 13) {
				this->year++;
				this->month = 1;
			}

			this->day = 1;

			if (this->year > 2099) {

				this->day = 1;
				this->month = 1;
				this->year = 1920;
			}
		}

		return date; // מחזירים את האובייקט אחרי שדיס התקדם
	}

	//------------------- += פלוס שווה ----------------------//
	Date operator+=(int num_of_days) { // המתודה משנה את הערכים ולכן אין קונסט

		this->day += num_of_days;

		//------ ספירת החודשים ------//
		while (this->day > 30) {
			this->month++;
			this->day = this->day - 30;
		}

		//------ ספירת השנים ------//
		while (this->month > 12) {
			this->year++;
			this->month = this->month - 12;
		}

		if (this->year > 2099) {
			//this->year = this->year - 180;
			this->day = 1;
			this->month = 1;
			this->year = 1920;
		}

		return *this;
	}


	//----------------------- > גדול -------------------------//
	bool operator>(const Date& date)const { // ערכי הפרמטים לא משתנים ולכן יש קונסט

		//-------- בדיקה אם שני התאריכים שווים -------//
		if (this->day == date.day && this->month == date.month && this->year == date.year) {
			return false;
		}

		else {
			//---------- השנה הגדולה מנצחת ----------//
			if (this->year > date.year) {
				return true;
			}
			else if (this->year < date.year) {
				return false;
			}


			//------------ אם השנים שוות ----------//
			else if (this->year == date.year) {

				//---- החודש הגדול מנצח ----//
				if (this->month > date.month) {
					return true;
				}
				else if (this->month < date.month) {
					return false;
				}
			}

			//----- אם השנים שוות וגם החודשים שווים -----//
			else if (this->month == date.month && this->year == date.year) {

				//----- היום הגדול מנצח -----//
				if (this->day > date.day) {
					return true;
				}

				else {
					return false;
				}
			}
		}
	}


	//----------------------- < קטן -------------------------//
	bool operator<(const Date& date)const { // ערכי הפרמטים לא משתנים ולכן יש קונסט

	//-------- בדיקה אם שני התאריכים שווים -------//
		if (this->day == date.day && this->month == date.month && this->year == date.year) {
			return false;
		}

		else {
			//---------- השנה הקטנה מנצחת ----------//
			if (this->year < date.year) {
				return true;
			}
			else if (this->year > date.year) {
				return false;
			}


			//------------ אם השנים שוות ----------//
			else if (this->year == date.year) {

				//---- החודש הקטן מנצח ----//
				if (this->month < date.month) {
					return true;
				}
				else if (this->month > date.month) {
					return false;
				}
			}

			//----- אם השנים שוות וגם החודשים שווים -----//
			else if (this->month == date.month && this->year == date.year) {

				//----- היום הקטן מנצח -----//
				if (this->day < date.day) {
					return true;
				}

				else {
					return false;
				}
			}
		}
	}

	//----------------------- == שווה שווה -------------------------//
	bool operator==(const Date& date)const {

		if (this->day == date.day && this->month == date.month && this->year == date.year) {
			return true;
		}
		return false;
	}

	//----------------------- מתודת הדפסה -------------------------//
	void print() const {
		cout << this->day << "/" << this->month << "/" << this->year << endl;
	}
};


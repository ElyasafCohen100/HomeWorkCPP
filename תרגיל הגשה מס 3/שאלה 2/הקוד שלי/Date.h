/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 3 seif 2   *
*                            *
******************************/
#pragma once
#include<iostream>
using namespace std;

///------------------------------------------------ ����� ���� ����� ���� -----------------------------------------------------///

//---------- Date ����� ������ ------------//
class Date {

private:

	int day;
	int month;
	int year;

public:

	//------------------------ ���������� --------------------------//
	Date(int my_day, int my_month, int my_year) {

		//----- ����� ���� ����� -----//
		if (my_day > 0 && my_day < 31) {
			this->day = my_day;
		}
		else {
			cout << "Error day " << endl;
			this->day = 1;
		}

		//----- ����� ���� ������� -----//
		if (my_month > 0 && my_month < 13) {
			this->month = my_month;
		}

		else {
			cout << "Error month " << endl;
			this->month = 1;
		}

		//----- ����� ���� ����� -----//
		if (my_year > 1920 && my_year < 2099) {
			this->year = my_year;
		}

		else {
			cout << "Error year " << endl;
			this->year = 1920;
		}
	}

	//------------------ ���������� ��� ����� --------------------//

	Date() {
		this->day = 1;
		this->month = 1;
		this->year = 1920;
	}

	//------------------- ���� ���������� -----------------------//
	Date(const Date& date) {
		this->day = date.day;
		this->month = date.month;
		this->year = date.year;
	}

	//------------------- ��� ���������� ------------------------//
	Date(Date&& date) {
		this->day = date.day;
		this->month = date.month;
		this->year = date.year;
	}


	//--------------------- setDate ����� ------------------------//
	void setDate(int my_day, int  my_month, int my_year) {

		//------ �� �� ������ �� ����� �������� ����� -------//
		if ((my_day > 0 || my_day < 31) && (my_month > 0 || my_month < 13) && (my_month > 1920 || my_month < 2099)) {
			this->day = my_day;
			this->month = my_month;
			this->year = my_year;
		}
	}

	//------------------- ���� ���� ����� ----------------------//
	Date& operator ++() { // �������� ���� �� ���� ��� ��� �����

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


	//------------------- ���� ���� ���� ----------------------//
	Date operator++(int postfix_not_used) { // ��� ������ ��� ����� ����  ��� �����

		Date date = *this; //������� ������� ����� ����

		//----- ������ �� ��� -----//
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

		return date; // ������� �� �������� ���� ���� �����
	}

	//------------------- += ���� ���� ----------------------//
	Date operator+=(int num_of_days) { // ������ ���� �� ������ ���� ��� �����

		this->day += num_of_days;

		//------ ����� ������� ------//
		while (this->day > 30) {
			this->month++;
			this->day = this->day - 30;
		}

		//------ ����� ����� ------//
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


	//----------------------- > ���� -------------------------//
	bool operator>(const Date& date)const { // ���� ������� �� ������ ���� �� �����

		//-------- ����� �� ��� �������� ����� -------//
		if (this->day == date.day && this->month == date.month && this->year == date.year) {
			return false;
		}

		else {
			//---------- ���� ������ ����� ----------//
			if (this->year > date.year) {
				return true;
			}
			else if (this->year < date.year) {
				return false;
			}


			//------------ �� ����� ���� ----------//
			else if (this->year == date.year) {

				//---- ����� ����� ���� ----//
				if (this->month > date.month) {
					return true;
				}
				else if (this->month < date.month) {
					return false;
				}
			}

			//----- �� ����� ���� ��� ������� ����� -----//
			else if (this->month == date.month && this->year == date.year) {

				//----- ���� ����� ���� -----//
				if (this->day > date.day) {
					return true;
				}

				else {
					return false;
				}
			}
		}
	}


	//----------------------- < ��� -------------------------//
	bool operator<(const Date& date)const { // ���� ������� �� ������ ���� �� �����

	//-------- ����� �� ��� �������� ����� -------//
		if (this->day == date.day && this->month == date.month && this->year == date.year) {
			return false;
		}

		else {
			//---------- ���� ����� ����� ----------//
			if (this->year < date.year) {
				return true;
			}
			else if (this->year > date.year) {
				return false;
			}


			//------------ �� ����� ���� ----------//
			else if (this->year == date.year) {

				//---- ����� ���� ���� ----//
				if (this->month < date.month) {
					return true;
				}
				else if (this->month > date.month) {
					return false;
				}
			}

			//----- �� ����� ���� ��� ������� ����� -----//
			else if (this->month == date.month && this->year == date.year) {

				//----- ���� ���� ���� -----//
				if (this->day < date.day) {
					return true;
				}

				else {
					return false;
				}
			}
		}
	}

	//----------------------- == ���� ���� -------------------------//
	bool operator==(const Date& date)const {

		if (this->day == date.day && this->month == date.month && this->year == date.year) {
			return true;
		}
		return false;
	}

	//----------------------- ����� ����� -------------------------//
	void print() const {
		cout << this->day << "/" << this->month << "/" << this->year << endl;
	}
};


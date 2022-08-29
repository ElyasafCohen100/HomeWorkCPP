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
///------------------------------------------------ Account �� cpp - ����� ���� ����� � -----------------------------------------------------///

//------- ������ ������� ������ -------// 
float Account::sumWithdraw = 0; // ���� �������
float Account::sumDeposit = 0; // ���� �������

float Account::getSumWithdraw() {
	return sumWithdraw;
}

float Account::getSumDeposit() {
	return  sumDeposit;
}


//--------------------- ������ ���������� -----------------------//
Account::Account() {

	this->accountNumber = 0;
	this->balance = 0;
	this->code = 0;
	this->mail.clear(); // ����� ������ ����
}

//------------------------ ���������� --------------------------//
Account::Account(int my_accountNumber, int my_code, float my_balance, string my_mail) {
	this->accountNumber = my_accountNumber;
	this->code = my_code;
	this->balance = my_balance;
	this->mail = my_mail;
}

//------------------- ����� ������ ������� ---------------------//
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
	����� �� ��� ��� ������ ������. ��� �� ����� ����� find() ��������
	find() - ��� �� ������ ������� *�������*, ����� �� ������� ��������� ������� �� ������� �� ��� ����� ����
	rFind() - �� ���� ��� �� ������� *����� find() ���
*/

void Account::setMail(string& my_mail) {

	if (my_mail.find("@", 0) == my_mail.rfind("@")) { // ����� �� @ ����� ��� ���

		//---- ����� ���� ������ -----//
		if (my_mail.find(" ") == -1) { // ���� ����� 1 ���� �� ����� �� ��� �������

			//------ ����� ������� �� ����� ��� ��� ����� -----//
			if (my_mail.rfind(".com") == my_mail.length() - 4 || my_mail.rfind(".co.il") == my_mail.length() - 6) {
				this->mail.assign(my_mail); // ����� �����
			}
			else {
				throw "ERROR: email must end at .com or .co.il!\n"; // ����� ������
			}
		}
		else {
			throw "ERROR: wrong email!\n"; // ���� ����
		}
	}
	else {
		throw "ERROR: email must contain @!\n"; // ���� @ �����
	}
}


//----------------- >> ������� ���� - ������� ��� --------------------//
istream& operator>> (istream& is, Account& my_account) {

	//--- ����� �� ����� ----//
	int accountNumber;
	is >> accountNumber;
	my_account.accountNumber = accountNumber;

	//---- ����� ��� ----//
	int myCode;
	is >> myCode;


	//----- ����� ���� ----//
	string myMail;
	is >> myMail;
	my_account.setMail(myMail);

	//--- ���� ��� �� ���� �����  ���� �� ---//
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


//---------------- ����� ������ ������� -----------------//
void Account::withdraw(float nis) {

	//---- ����� ��� ������ ������----//
	if ((this->balance - nis) > -6000) {

		if (nis <= 2500) { // ���� ����� �� ���� ����� ���������

			this->balance -= nis; // ����� ������ ����"�
			sumWithdraw += nis; // ����� ���� ������ 
		}
		else
			throw "ERROR: cannot withdraw more than 2500 NIS!";
	}
	else {
		throw "ERROR: cannot have less than - 6000 NIS!";
	}
}



//--------- ����� ������ ������� --------//
void Account::deposit(float nis) {

	if (nis > 10000) {
		throw "ERROR: cannot deposit more than 10000 NIS!\n"; // ���� ������ ���� � -10000 �"�
	}

	else {
		this->balance += nis;
		sumDeposit += nis;
	}
}




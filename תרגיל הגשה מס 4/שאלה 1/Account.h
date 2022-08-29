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
///------------------------------------------------ ����� ���� ����� ���� -----------------------------------------------------///

//---------- Account ����� ������ ------------//
class Account {

private:

	int accountNumber; // �� �����
	int code; // ��� ����
	float balance; // ����� ������
	string mail; // ����

public:

	//--------------------- ������ ���������� -----------------------//
	Account();

	//------------------------ ���������� --------------------------//
	Account(int my_accountNumber, int my_code, float my_balance, string my_mail);

	//------------------- ����� ������ ������� ---------------------//
	int getAccountNumber()const;
	int getCode()const;
	float getBalance()const;
	void setMail(string& my_mail);

	//----------------- >> ������� ���� - ������� ��� --------------------//
	friend istream& operator>> (istream& is, Account& my_account);

	//--------- ����� ������ ������� --------//
	void withdraw(float nis);

	//--------- ����� ������ ������� --------//
	void deposit(float nis);


	//------- ������ ������� ������ -------// 
	static float sumWithdraw;
	static float sumDeposit;

	static float getSumWithdraw();
	static float getSumDeposit();
};

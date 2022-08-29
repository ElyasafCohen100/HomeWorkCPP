/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 4          *
*                            *
******************************/
#include <iostream>
#include "Clock.h"
#include "Account.h"
using namespace std;

enum action {

	stop,
	balance,
	deposit,
	withdraw,
	sumDeposit,
	sumWithdraw
};

action menu() {

	cout << "enter 1 to get account balance" << endl;
	cout << "enter 2 to deposit money" << endl;
	cout << "enter 3 to withdraw money" << endl;
	cout << "enter 4 to see the sum of all withdraws" << endl;
	cout << "enter 5 to see the sum of all Deposits" << endl;
	cout << "enter 0 to stop" << endl;
	int x;
	cin >> x;
	return (action)x;
}


int findAccount(Account* bank, int size) {

	int number, code;
	bool flag = false;
	cout << "please enter account number:\n";
	cin >> number; // finding the balance of wich Account

	for (int j = 0; j < 10; j++) {
		if (bank[j].getAccountNumber() == number)
			flag = true;
	}

	if (!flag) {
		throw "ERROR: no such account number!";
	}

	int i = 0;
	while (i < size && bank[i].getAccountNumber() != number) {
		i++;
	}

	cout << "please enter the code:\n";
	cin >> code; //cin your code to see the balance
	if (bank[i].getCode() == code) {
		return i;
	}

	else {
		throw "ERROR: wrong code!";
	}

}

void printTransaction(Account a, action ac, Clock& c) {

	cout << c << "\t";

	switch (ac) {

	case balance: cout << "account #: " << a.getAccountNumber() << "\t";
		cout << "balance: " << a.getBalance() << endl;
		break;

	case deposit:
	case withdraw: cout << "account #: " << a.getAccountNumber() << "\t";
		cout << "new balance: " << a.getBalance() << endl;
		break;

	case sumDeposit:
		cout << "sum of all deposits: " << Account::getSumDeposit() << endl;
		break;

	case sumWithdraw:
		cout << "sum of all withdraws: " << Account::getSumWithdraw() << endl;
		break;
	}
}

void getBalance(Account* bank, int size, Clock& c) {
	int i = findAccount(bank, size);
	c += 20;
	printTransaction(bank[i], balance, c);
}

void cashDeposit(Account* bank, int size, Clock& c) {


	int i = findAccount(bank, size);
	float amount;
	cout << "enter the amount of the check: " << endl;
	cin >> amount;
	bank[i].deposit(amount);
	c += 30;
	printTransaction(bank[i], deposit, c);
}


void cashWithdraw(Account* bank, int size, Clock& c) {
	int i = findAccount(bank, size);
	float amount;
	cout << "enter the amount of money to withdraw: " << endl;
	cin >> amount;
	bank[i].withdraw(amount);
	c += 50;
	printTransaction(bank[i], withdraw, c);
}


int main() {

	Clock c;
	try {
		c.setHour(8);
		c.setMinute(0);
		c.setSecond(0);
	}

	catch (const char* msg) {

		cout << c << '\t' << msg << endl;
	}

	Account bank[10]; // each el in the array is an object of Account
	cout << "enter account number, code and email for 10 accounts:\n";

	for (int i = 0; i < 10; i++) {

		try {

			cin >> bank[i];
			for (int j = 0; j < i; j++)
				if (bank[i].getAccountNumber() == bank[j].getAccountNumber())
					throw "ERROR: account number must be unique!\n";
		}

		catch (const char* msg) {
			cout << c << '\t' << msg << endl;
			i--; // the account isnwt correct because his accountNumber
		}
	}

	action ac = menu();
	while (ac) {

		switch (ac) {

		case balance:
			try {
				getBalance(bank, 10, c);
			}

			catch (const char* msg) {
				cout << c << '\t' << msg;
			}
			break;

		case withdraw:

			try {
				cashWithdraw(bank, 10, c);
			}

			catch (const char* msg) {
				cout << c << '\t' << msg;
			}

			break;


		case deposit:
			try {
				cashDeposit(bank, 10, c);
			}

			catch (const char* msg) {
				cout << c << '\t' << msg;
			}

			break;

		case sumDeposit:c += 60;
			printTransaction(bank[0], sumDeposit, c);
			break;

		case sumWithdraw:c += 60;
			printTransaction(bank[0], sumWithdraw, c);

		}

		ac = menu();
	}


	return 0;
}



/*enter account number, codeand email for 10 accounts:
1 1111 aaa@gmail.com
2 2222 aaa@gmail.il
08:00 : 00        ERROR : email must end at.com or .co.il!
2 2222 aaa@gmail.com
3 3333 bbb@gmail.com
4 4444 ccc@gmail.com
5 5555 ddd@gmail.com
6 6666 eee@gmail.com
7 7777 fff@gmail.com
8 8888 ggg@gmail.com
9 9999 hhh@gmail.com
10 1010 iii@gmail.com
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all withdraws
enter 5 to see the sum of all Deposits
enter 0 to stop

2
please enter account number :
4
please enter the code :
1234
08 : 00 : 00        ERROR : wrong code!
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all withdraws
enter 5 to see the sum of all Deposits
enter 0 to stop

0
*/
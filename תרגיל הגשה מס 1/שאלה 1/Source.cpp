/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 1 seif 1   *
*                            *
******************************/
#include"Header.h"
#include <iostream>
using namespace std;

///------------------------------------------- cpp - אנחנו כרגע בקובץ ה  -------------------------------------------------///

int main()
{
	int numerator, denominator;
	char tav;

	cout << "enter two rational numbers:" << endl;
	cin >> numerator >> tav >> denominator;

	Rational r1;
	r1.setNumerator(numerator);
	r1.setDenominator(denominator);
	cin >> numerator >> tav >> denominator;


	Rational r2;
	r2.setNumerator(numerator);
	r2.setDenominator(denominator);


	Rational ans = r1.add(r2);
	r1.print();
	cout << "+ ";

	r2.print();
	cout << "= ";

	ans.print();
	cout << endl;

	if (r1.equal(r2)) {
		cout << "The two numbers are equal" << endl;
	}

	else {
		cout << "The two numbers are different" << endl;
		r1.print();
		r2.print();
		cout << endl;
	}
	return 0;
}


/*enter two rational numbers:
1/2 3/6
1/2+ 3/6= 1/1
The two numbers are equal
Press any key to continue . . .
*/
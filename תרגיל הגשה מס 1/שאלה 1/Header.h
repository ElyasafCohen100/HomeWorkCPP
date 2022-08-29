/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 1 seif 1   *
*                            *
******************************/
#pragma once
#include<iostream>
using namespace std;

///------------------------------------------------ ����� ���� ����� ���� -----------------------------------------------------///

//---------- Rational ����� ������ ------------//
class Rational {

private:

	int mone;
	int mechane;

	//-------------------------- ����� ��� ������ -------------------------///
	Rational reduction(Rational r) {
		Rational num = r;

		if (this->getNumerator() == 0) {
			num.setNumerator(0);
			num.setDenominator(1);
			return num;
		}

		//---- ���� ����� ����� ----//
		else if (this->getNumerator() == this->getDenominator()) {
			num.setNumerator(1);
			num.setDenominator(1);
			return num;
		}

		//---- ���� ���� 1 ----//
		else if (this->getDenominator() == 1) {
			num.setNumerator(this->getNumerator());
			num.setDenominator(1);
			return num;
		}

		int i;
		for ( i = 9; i > 1; i--)
		{
			if (getDenominator() % i == 0 && getNumerator() % i == 0)
			{
				num.setNumerator(getNumerator() / i);
				num.setDenominator(getDenominator() / i);
				break;
			}
		}
		if (i != 1)
			return num.reduction(num);
		return num;

	}



public:

	// ------------- ����� �����, ����� ��������  -----------------//

	//------ �� ���� -------//
	int getNumerator() {
		return this->mone;
	}

	//------- �� ���� ------//
	void setNumerator(int my_mone) {
		this->mone = my_mone;
	}

	//------ �� ����-------//
	int getDenominator() {
		return this->mechane;
	}

	//------ �� ���� -------//
	void setDenominator(int my_mechane) {
		if (my_mechane == 0) {
			this->mechane = 1;
		}
		else {
			this->mechane = my_mechane;
		}
	}


	//---------------------- ����� ������ ���� ��������� ----------------------- //
	void print() {
		cout << this->mone << "/" << this->mechane << " ";
	}


	//-------------------- ����� ������ ��� ��� ������ ���������� ������ ��� �� ����� -----------------//
	bool equal(Rational r2) {

		//----- ��� ��� �����/����� �� ���� -----//
		 if ((float) r2.getNumerator() / r2.getDenominator() == (float)this->getNumerator() / this->getDenominator()) {
			return true;
		}
		 return false;
	}



	//--------------- ������ ����� �� ��� ������ �������� add �������� ---------------//

	Rational add(Rational r2) {

		Rational num3;

		 num3.setDenominator(r2.getDenominator() * this->getDenominator());
		 num3.setNumerator(r2.getDenominator() * this->getNumerator() + r2.getNumerator() * this->getDenominator());

		return num3.reduction(num3);

	}
};


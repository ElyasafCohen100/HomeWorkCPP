/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 3 seif 1   *
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

	//-------------------------- ����� ��� ������ -------------------------//
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
		for (i = 9; i > 1; i--)
		{
			if (getDenominator() % i == 0 && getNumerator() % i == 0)
			{
				num.setNumerator(getNumerator() / i);
				num.setDenominator(getDenominator() / i);
				break;
			}
		}
		if (i != 1) {
			return num.reduction(num);
		}
		return num;
	}



public:

	//---------------- ���������� --------------------//

	Rational(int numerator, int denominator) {
	
		this->mone = numerator;
	
		if (this->mone == 0) {
			this->mechane = 1;
			return;
		}
		
		if (denominator == 0) {
			cout << "ERROR\a" << endl;
			this->mechane = 1;
		}

		else {
			this->mechane = denominator;
		}

		*this = this->reduction(*this);
	}

	Rational() {
	}

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
			cout << "ERROR\a" << endl;
			this->mechane = 1;
		}
		else {
			this->mechane = my_mechane;
		}
	}


	//---------------------- ����� ������ ���� ��������� ----------------------- //
	void print() {
		if (this->mone == 0 || this->mechane == 1) {
			cout << this->mone;
		}
		else {
			cout << this->mone << "/" << this->mechane << " ";
		}
	}


	//-------------------- ����� ������ ��� ��� ������ ���������� ������ ��� �� ����� -----------------//
	bool equal(Rational r2) {

		//----- ��� ��� �����/����� �� ���� -----//
		if ((float)r2.getNumerator() / r2.getDenominator() == (float)this->getNumerator() / this->getDenominator()) {
			return true;
		}
		return false;
	}


	//-------------------------------------------------------------- ����� ��������� ------------------------------------------------------------------------//

	//------------------------------- ����� ------------------------------//
	Rational operator +(const Rational& rational_number)const { //����� �� ���� �� ���� �������� ��� �� ������ �����

		Rational result;

		//----- ����� ����� ����� ������� ����� ----//
		if (this->mechane == rational_number.mechane) {

			result.setNumerator(this->mone + rational_number.mone);
			result.setDenominator(this->mechane);

			return result.reduction(result);
		}

		else {
			//------ ����� ���� ����� -----// 
			result.setDenominator(rational_number.mechane * this->mechane);
			result.setNumerator(rational_number.mechane * this->mone + rational_number.mone * this->mechane);

			return result.reduction(result);
		}
	}



	//------------------------------- ����� ------------------------------//
	Rational operator -(const Rational& rational_number)const { // ����� �� ���� �� ���� �������� ��� �� ������ ����� 

		Rational result;

		//----- ����� ����� ����� ������� ����� ----//
		if (this->mechane == rational_number.mechane) {

			result.setNumerator(this->mone - rational_number.mone);
			result.setDenominator(this->mechane);

			return result.reduction(result);
		}

		else {
			//------ ����� ���� ����� -----// 
			result.setDenominator(rational_number.mechane * this->mechane);
			result.setNumerator(rational_number.mechane * this->mone - rational_number.mone * this->mechane);

			return result.reduction(result);
		}

	}


	//------------------------------- ��� ------------------------------//
	Rational operator *(const Rational& rational_number)const {

		Rational result;

		result.setNumerator(this->mone * rational_number.mone);
		result.setDenominator(this->mechane * rational_number.mechane);

		return result.reduction(result);
	}

	//------------------------------- ����� ------------------------------//
	Rational operator /(const Rational& rational_number)const { // ����� �� ���� �� ���� �������� ��� �� ������ �����

		Rational result;

		//------- ��� ������ --------//
		result.setNumerator(this->mone * rational_number.mechane);
		result.setDenominator(this->mechane * rational_number.mone);

		return result.reduction(result);
	}

	//-------------------------------  ���� ���� ����� ------------------------------//

	Rational operator++() { // �������� ���� �� ���� ���� ��� �����
		this->mone = this->mone + this->mechane; // ���� ������ ������ ���� �� ��� ���� ���
		return this->reduction(*this); // ����� ���� (����) �� ��� ����
	}



	//------------------------------- ���� ���� ���� ------------------------------//
	Rational operator++(int posfix_not_used) {

		Rational ratio = *this; // ������� ���� ����� ���� �� ���
		this->mone = this->mone + this->mechane; // ������� �� ��� �- 1
		return ratio.reduction(ratio); // ������� �� ���� ������ ��� ����� ��� ���� ��� �-1
	}

	//------------------------------- ����� ����� ����� ------------------------------//
	Rational operator--() { // �������� ���� �� ���� ���� ��� �����
		this->mone = this->mone - this->mechane; // ���� ���� ������ �� �� �����
		return this->reduction(*this); // ����� ���� (����) �� ��� ����
	}


	//-------------------------------����� ����� ���� ------------------------------//
	Rational operator --(int posfix_not_used) {
		Rational ratio = *this;
		this->mone = this->mone - this->mechane;
		return ratio.reduction(ratio);
	}


	//----------------------------- >= ���� ���� ----------------------------//
	bool operator >=(const Rational rational_number)const {

		if (((float)this->mone / this->mechane) >= ((float)rational_number.mone / rational_number.mechane)) {
			return true;
		}
		return false;
	}

	//----------------------------- <= ��� ���� ----------------------------//
	bool operator <=(const Rational& rational_number)const {

		if (((float)this->mone / this->mechane) <= ((float)rational_number.mone / rational_number.mechane)) {
			return true;
		}
		return false;

	}

	//----------------------------- > ���� ----------------------------//
	bool operator > (const Rational& rational_number)const {

		if (((float)this->mone / this->mechane) > ((float)rational_number.mone / rational_number.mechane)) {
			return true;
		}
		return false;

	}

	//----------------------------- < ��� ----------------------------//
	bool operator < (const Rational& rational_number)const {

		if (((float)this->mone / this->mechane) < ((float)rational_number.mone / rational_number.mechane)) {
			return true;
		}
		return false;
	}

	//----------------------------- == ���� ���� ----------------------------//

	bool operator ==(const Rational& rational_number)const {

		if (((float)this->mone / this->mechane) == ((float)rational_number.mone / rational_number.mechane)) {
			return true;
		}
		return false;

	}


	//------------------------------ != �� ����  ----------------------------//

	bool operator !=(const Rational& rational_number)const {

		if (((float)this->mone / this->mechane) != ((float)rational_number.mone / rational_number.mechane)) {
			return true;
		}
		return false;
	}
};


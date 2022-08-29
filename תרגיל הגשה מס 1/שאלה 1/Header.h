/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 1 seif 1   *
*                            *
******************************/
#pragma once
#include<iostream>
using namespace std;

///------------------------------------------------ אנחנו כרגע בקובץ ההדר -----------------------------------------------------///

//---------- Rational פתיחת המחלקה ------------//
class Rational {

private:

	int mone;
	int mechane;

	//-------------------------- מתודת עזר לצמצום -------------------------///
	Rational reduction(Rational r) {
		Rational num = r;

		if (this->getNumerator() == 0) {
			num.setNumerator(0);
			num.setDenominator(1);
			return num;
		}

		//---- מונה ומכנה שווים ----//
		else if (this->getNumerator() == this->getDenominator()) {
			num.setNumerator(1);
			num.setDenominator(1);
			return num;
		}

		//---- מכנה שווה 1 ----//
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

	// ------------- הגדרת הגטים, הסטים והמתודות  -----------------//

	//------ גט מונה -------//
	int getNumerator() {
		return this->mone;
	}

	//------- סט מונה ------//
	void setNumerator(int my_mone) {
		this->mone = my_mone;
	}

	//------ גט מכנה-------//
	int getDenominator() {
		return this->mechane;
	}

	//------ סט מכנה -------//
	void setDenominator(int my_mechane) {
		if (my_mechane == 0) {
			this->mechane = 1;
		}
		else {
			this->mechane = my_mechane;
		}
	}


	//---------------------- מתודה להדפסת השבר הרציונאלי ----------------------- //
	void print() {
		cout << this->mone << "/" << this->mechane << " ";
	}


	//-------------------- מתודת השוואה בין שני מספרים רציונאליים ובודקת האם הם שווים -----------------//
	bool equal(Rational r2) {

		//----- אחד הוא הרחבה/צמצום של השני -----//
		 if ((float) r2.getNumerator() / r2.getDenominator() == (float)this->getNumerator() / this->getDenominator()) {
			return true;
		}
		 return false;
	}



	//--------------- לחישוב חיבור של שני מספרים רציונלים add הפונקציה ---------------//

	Rational add(Rational r2) {

		Rational num3;

		 num3.setDenominator(r2.getDenominator() * this->getDenominator());
		 num3.setNumerator(r2.getDenominator() * this->getNumerator() + r2.getNumerator() * this->getDenominator());

		return num3.reduction(num3);

	}
};


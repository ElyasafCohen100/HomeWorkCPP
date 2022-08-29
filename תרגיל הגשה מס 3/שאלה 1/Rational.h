/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 3 seif 1   *
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

	//-------------------------- מתודת עזר לצמצום -------------------------//
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

	//---------------- קונסטרקטור --------------------//

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
			cout << "ERROR\a" << endl;
			this->mechane = 1;
		}
		else {
			this->mechane = my_mechane;
		}
	}


	//---------------------- מתודה להדפסת השבר הרציונאלי ----------------------- //
	void print() {
		if (this->mone == 0 || this->mechane == 1) {
			cout << this->mone;
		}
		else {
			cout << this->mone << "/" << this->mechane << " ";
		}
	}


	//-------------------- מתודת השוואה בין שני מספרים רציונאליים ובודקת האם הם שווים -----------------//
	bool equal(Rational r2) {

		//----- אחד הוא הרחבה/צמצום של השני -----//
		if ((float)r2.getNumerator() / r2.getDenominator() == (float)this->getNumerator() / this->getDenominator()) {
			return true;
		}
		return false;
	}


	//-------------------------------------------------------------- העמסת אופרטורים ------------------------------------------------------------------------//

	//------------------------------- חיבור ------------------------------//
	Rational operator +(const Rational& rational_number)const { //חיבור לא משנה את ערכי הפרמרטים לכן יש פעמיים קונסט

		Rational result;

		//----- חיבור שברים במידה והמכנים שווים ----//
		if (this->mechane == rational_number.mechane) {

			result.setNumerator(this->mone + rational_number.mone);
			result.setDenominator(this->mechane);

			return result.reduction(result);
		}

		else {
			//------ חישוב מכנה משותף -----// 
			result.setDenominator(rational_number.mechane * this->mechane);
			result.setNumerator(rational_number.mechane * this->mone + rational_number.mone * this->mechane);

			return result.reduction(result);
		}
	}



	//------------------------------- חיסור ------------------------------//
	Rational operator -(const Rational& rational_number)const { // חיסור לא משנה את ערכי הפרמטרים לכן יש פעמיים קונסט 

		Rational result;

		//----- חיסור שברים במידה והמכנים שווים ----//
		if (this->mechane == rational_number.mechane) {

			result.setNumerator(this->mone - rational_number.mone);
			result.setDenominator(this->mechane);

			return result.reduction(result);
		}

		else {
			//------ חישוב מכנה משותף -----// 
			result.setDenominator(rational_number.mechane * this->mechane);
			result.setNumerator(rational_number.mechane * this->mone - rational_number.mone * this->mechane);

			return result.reduction(result);
		}

	}


	//------------------------------- כפל ------------------------------//
	Rational operator *(const Rational& rational_number)const {

		Rational result;

		result.setNumerator(this->mone * rational_number.mone);
		result.setDenominator(this->mechane * rational_number.mechane);

		return result.reduction(result);
	}

	//------------------------------- חילוק ------------------------------//
	Rational operator /(const Rational& rational_number)const { // חילוק לא משנה את ערכי הפרמטרים לכן יש פעמיים קונסט

		Rational result;

		//------- כפל בהופכי --------//
		result.setNumerator(this->mone * rational_number.mechane);
		result.setDenominator(this->mechane * rational_number.mone);

		return result.reduction(result);
	}

	//-------------------------------  פלוס פלוס תחילי ------------------------------//

	Rational operator++() { // הפונקציה משנה את הערך ולכן אין קונסט
		this->mone = this->mone + this->mechane; // שיטה מתמטית לחישוב מהיר של אחד ועוד שבר
		return this->reduction(*this); // החזרת הערך (השבר) של דיס עצמו
	}



	//------------------------------- פלוס פלוס סופי ------------------------------//
	Rational operator++(int posfix_not_used) {

		Rational ratio = *this; // מגדירים רטיו ששווה לערך של דיס
		this->mone = this->mone + this->mechane; // מגדילים את דיס ב- 1
		return ratio.reduction(ratio); // מחזירים את רטיו המקומי שלא השתנה אבל הדיס עלה ב-1
	}

	//------------------------------- מינוס מינוס תחילי ------------------------------//
	Rational operator--() { // הפונקציה משנה את הערך ולכן אין קונסט
		this->mone = this->mone - this->mechane; // אותה שיטה מתמטית רק עם מינוס
		return this->reduction(*this); // החזרת הערך (השבר) של דיס עצמו
	}


	//-------------------------------מינוס מינוס סופי ------------------------------//
	Rational operator --(int posfix_not_used) {
		Rational ratio = *this;
		this->mone = this->mone - this->mechane;
		return ratio.reduction(ratio);
	}


	//----------------------------- >= גדול שווה ----------------------------//
	bool operator >=(const Rational rational_number)const {

		if (((float)this->mone / this->mechane) >= ((float)rational_number.mone / rational_number.mechane)) {
			return true;
		}
		return false;
	}

	//----------------------------- <= קטן שווה ----------------------------//
	bool operator <=(const Rational& rational_number)const {

		if (((float)this->mone / this->mechane) <= ((float)rational_number.mone / rational_number.mechane)) {
			return true;
		}
		return false;

	}

	//----------------------------- > גדול ----------------------------//
	bool operator > (const Rational& rational_number)const {

		if (((float)this->mone / this->mechane) > ((float)rational_number.mone / rational_number.mechane)) {
			return true;
		}
		return false;

	}

	//----------------------------- < קטן ----------------------------//
	bool operator < (const Rational& rational_number)const {

		if (((float)this->mone / this->mechane) < ((float)rational_number.mone / rational_number.mechane)) {
			return true;
		}
		return false;
	}

	//----------------------------- == שווה שווה ----------------------------//

	bool operator ==(const Rational& rational_number)const {

		if (((float)this->mone / this->mechane) == ((float)rational_number.mone / rational_number.mechane)) {
			return true;
		}
		return false;

	}


	//------------------------------ != לא שווה  ----------------------------//

	bool operator !=(const Rational& rational_number)const {

		if (((float)this->mone / this->mechane) != ((float)rational_number.mone / rational_number.mechane)) {
			return true;
		}
		return false;
	}
};


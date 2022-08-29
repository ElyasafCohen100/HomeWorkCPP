/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 10         *
*                            *
******************************/
#include"Officer.h"
using namespace std;
///------------------------------------------------ Officer של cpp - אנחנו בקובץ ה ------------------------------------------------------///

/*
מימוש מחלקת קצין
*/


//----------- דיפולט קונסטורקטור --------------//
Officer::Officer() : Soldier() {
	this->Sociometric_score = 0;
}


//--------------------- קונסטרקטור מקבל את הערכים של הבן והאב ---------------------//              //------------- father's conctructor -------------//
Officer::Officer(int my_taz, string my_first_name, string my_last_name, int my_num_operation) : Soldier(my_taz, my_first_name, my_last_name, my_num_operation) {

	cout << "enter number of sociometric score" << endl;
	cin >> this->Sociometric_score;
	if (this->Sociometric_score < 0) {
		this->Sociometric_score = 0;
	}
}



//--------------- זכאות לצלש -----------------//
bool Officer::medal() const {
	if (this->num_operation > 2 && this->Sociometric_score >= 92) {
		return true;
	}
	return false;
}


//------------ סוג החייל ---------------//
string Officer::string_soldierType() const {
	return "officer";
}



//------- מתודת הדפסה ---------//
void Officer::print()const {
	cout << this->string_soldierType() << endl;
	Soldier::print(); // קריאה למתודת ההדפסה של האבא

	//----- הדפסת החלקים של הבן -----//
	cout << "sociometric score: " << this->Sociometric_score << endl;
}



//------ Sociometric_score ויראטולית גט ------//
int Officer::get_Sociometric_score() {
	return this->Sociometric_score;
}
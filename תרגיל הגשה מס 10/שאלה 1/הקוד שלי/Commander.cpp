/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 10         *
*                            *
******************************/
#include"Commander.h"
using namespace std;
///---------------------------------------------------------- Commander של cpp - אנחנו בקובץ ה ----------------------------------------------------------------///

/*
 מימוש מחלקת מפקד
*/

//----------- דיפולט קונסטורקטור --------------//
Commander::Commander() :Private() {
	this->fighter = 0;
}


//--------------------- קונסטרקטור מקבל את הערכים של הבן והאב ---------------------//                //------------- father's conctructor -------------//
Commander::Commander(int my_taz, string my_first_name, string my_last_name, int my_num_operation) : Private(my_taz, my_first_name, my_last_name, my_num_operation) {
	cout << "enter 1 if the soldier is combat and 0 if not\n";
	cin >> this->fighter; // המשתמש קובע אם המפקד קרבי או לא
}


//----------------- דיסטרקטור -----------------//
Commander::~Commander() {
	this->ptr_grade.clear();
}



//---------------- זכאות לצלש -----------------//
bool Commander::medal()const {

	//-- בדיקה כמות המבצעים שהמפקד השתתף בהם וממוצע הערכות שלו ואם הוא קרבי --//
	if (this->num_operation >= 7 && this->average() > 90 && this->fighter == true) {
		return true;
	}

	return false;
}


//------------ סוג החייל ---------------//
string Commander::string_soldierType() const {
	return "commander";
}


//-------------- הדפסה -----------------//
void Commander::print()const {

	Private::print(); // קריאה למתודת ההדפסה של האבא

	//--- הדפסת החלקים של הבן -----//
	if (this->fighter) {
		cout << "combat: yes" << endl;
	}
	else if (this->fighter == false) {
		cout << "combat: no " << endl;
	}
}

//----------- fighter ויראטולית גט -----------//
bool Commander::get_fighter() {
	return this->fighter;
}

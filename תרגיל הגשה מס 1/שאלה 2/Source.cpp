/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 1 seif 2   *
*                            *
******************************/
#include <iostream>	
#include <cstring>
#include "Header.h"
using namespace std;



//--------------- תוכנית המייצגת נתונים של עובד בעמותת "לתת מהלב" לצורך חישוב משכורתו -------------------//
 //--------------- התוכנית מדפיסה את מספר הזהות של העובד שהכניס הכי פחות כסף לעמותה  ------------------//
  //-------------------- ואת מס הזהות של העובד שקיבל את המשכורת הגבוהה ביותר -------------------------//



///------------------------------------------------ cpp - אנחנו כרגע בקובץ ה -----------------------------------------------------///

int main() {

	cout << "enter details, to end enter 0: " << endl;

	Latet_Mahalev highter_salary, lower_success;
	Latet_Mahalev person3;

	int taz; // תז
	char name[21]; // שם


	float pay_per_hour; // שכר לשעה
	int number_of_working_hours; //מס השעות שעבד 
	float sum_get_success; // סכום שהצליח להכניס לעמותה 

	highter_salary.set_pay_per_hour(0);
	lower_success.set_sum_get_success(1000000);

	//------ קליטת התז  ------//

	cin >> taz; 

	while (taz != 0) {

		//----- קליטת השם -----//
		cin >> name;

		//----- קליטת שאר פרטי העובד ----//
		cin >> pay_per_hour >> number_of_working_hours >> sum_get_success;

		//------ בדיקת תקינות ------ //
		if ((taz < 0) || (pay_per_hour < 0) || (number_of_working_hours < 0) || sum_get_success < 0) {
			cout << "ERROR" << endl;
		}

		else {

			person3.setId(taz);
			person3.set_name(name);
			person3.set_number_of_working_hours(number_of_working_hours);
			person3.set_pay_per_hour(pay_per_hour);
			person3.set_sum_get_success(sum_get_success);

			//---------- בדיקה מי הכניס הכי פחות כסף לעמותה ----------//
			if (lower_success.get_sum_get_success() > person3.get_sum_get_success()) {
				lower_success.setId(person3.getId());
				lower_success.set_name(person3.get_name());
				lower_success.set_number_of_working_hours(person3.get_number_of_working_hours());
				lower_success.set_pay_per_hour(person3.get_pay_per_hour());
				lower_success.set_sum_get_success(person3.get_sum_get_success());
			}


			//---------- בדיקה מי העובד שקיבל את המשכורת הכי גבוהה -----------//
			if (highter_salary.calc_salary() < person3.calc_salary()) {
				highter_salary.setId(person3.getId());
				highter_salary.set_name(person3.get_name());
				highter_salary.set_number_of_working_hours(person3.get_number_of_working_hours());
				highter_salary.set_pay_per_hour(person3.get_pay_per_hour());
				highter_salary.set_sum_get_success(person3.get_sum_get_success());
			}
		}

		cin >> taz;
	}

	//------------ ההדפסות לפי דרישות השאלה -------------//
		cout << "minimum sum: " << lower_success.get_sum_get_success() << " " << lower_success.get_name() << " " << lower_success.getId() << endl;
		cout << "highest salary: " << highter_salary.calc_salary() << " " << highter_salary.get_name() << " " << highter_salary.getId() << endl;


	return 0;
}


/*
enter details, to end enter 0:
123456789 moshe 50 40 2000
135792468 rivka 120 55 3450
97531246 sara 35 100 5632
0
minimum sum: 2000       moshe   123456789
highest salary: 7140    rivka   135792468
Press any key to continue . . .
*/
/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 10         *
*                            *
******************************/
#include <list>
#include <vector>
#include <algorithm>
#include <string>
#include "Private.h"
#include"Commander.h"
#include"Officer.h"
#include <iostream>
using namespace std;
///------------------------------------------------------------- vector נעבוד עם הקונטנר ------------------------------------------------------------------///


enum option {
	stop,	//	סיום התוכנית
	addNewSoldier,	//	הוספת חייל חדש
	medalList,	//הדפסת פרטי כל החיילים הזכאים לצל"ש
	mostSociometric,	//	הדפסת שם (משפחה ופרטי) של  החייל בעל ציון סוציומטרי מקסימלי 
	countMedalPrivate,	//	הדפסת מספר החיילים הטירוניים הזכאים לצל"ש
	noCombatCommander,	//	הדפסת שמות (משפחה ופרטי) של המפקדים שאינם בקרבי
	overSoldier,	//	הדפסת הודעה מתאימה, האם קיים חייל שהשתתף ביותר מ- 15  מבצעים צבאיים
	removeOfficer,	//	מחיקת כל החיילים הקצינים שלא השתתפו כלל במבצע צבאי
};


//------------ STL פונקצית הוספת חייל למערך -----------//
void add(vector<Soldier*>& my_stl_vec) { // Soldier* שכל תא שלו מצביע מכיל מצביע מסוג STL הפונקציה מקבלת מערך של 
	cout << "enter 1 to add a private soldier\n";
	cout << "enter 2 to add a commander soldier\n";
	cout << "enter 3 to add a officer soldier\n";

	int num;
	cin >> num;

	cout << "enter id, first name, last name and number Of operations\n";
	int taz; // תז
	string first_name; // שם פרטי
	string last_name; // שם משפחה
	int num_operation; // מס המבצעים שהחייל לקח בהם חלק

	cin >> taz >> first_name >> last_name >> num_operation;


	//----- בדיקה מה המשתמש הכניס ------//
	if (num == 1) {
		//---- STL פתיחת אובייקט מסוג טירון והכנסתו לווקטור ה ----//
		Soldier* ptr = new Private(taz, first_name, last_name, num_operation);
		my_stl_vec.push_back(ptr);
	}

	else if (num == 2) {
		//---- STL פתיחת אובייקט מסוג מפקד והכנסתו לווקטור ה ----//
		Soldier* ptr = new Commander(taz, first_name, last_name, num_operation);
		my_stl_vec.push_back(ptr);
	}

	else if (num == 3) {
		//---- STL פתיחת אובייקט מסוג קצין והכנסתו לווקטור ה ----//
		Soldier* ptr = new Officer(taz, first_name, last_name, num_operation);
		my_stl_vec.push_back(ptr);
	}
}



//--------- פונקציית הבודקת מי זכאי לצלש ---------// 
void medal(vector<Soldier*> my_stl_vec) { // Soldier* שכל תא שלו מצביע מכיל מצביע מסוג STL הפונקציה מקבלת מערך של 

	//---- הגדרת איטרטור שמצביע על הווקטור שלנו -----//
	vector<Soldier*>::iterator it = my_stl_vec.begin();

	// עוד אפשרות להגדרת איטרטור //
	//auto it = my_stl_vec.begin();

	for (it = my_stl_vec.begin(); it != my_stl_vec.end(); it++) {
		if ((*it)->medal()) {
			(*it)->print();
		}
	}
}



//----- פונקציה הבודקת מי הקצין בעל הציון הגבוה הסוציומטרי הגבוה ביותר ------//
Soldier* mostSociometricScore(vector<Soldier*> my_stl_vec) { // Soldier* שכל תא שלו מצביע מכיל מצביע מסוג STL הפונקציה מקבלת מערך של 

	int max = -1; // יעזור לי למצא את המקסימום במערך
	Soldier* ptr_sol = NULL; // פויינטר שיקבל את הערך המקסימאלי ויוחזר

	//----- הגדרת האיטרטור ----//
	vector<Soldier*>::iterator it = my_stl_vec.begin();

	for (it = my_stl_vec.begin(); it != my_stl_vec.end(); it++) {

		//--- בדיקה אם מדובר על קצין ----//
		if ((*it)->string_soldierType() == "officer") {

			//--- מציאת המקסימום ----//
			if ((*it)->get_Sociometric_score() > max) {
				max = (*it)->get_Sociometric_score(); // מציאת המקסימום
				ptr_sol = *it; // הפויינטר מקבל את ערך המקסימלי של המערך
			}
		}
	}

	return ptr_sol;
}



int main() {

	vector<Soldier*> my_vec;   // הצהרה על ווקטור או רשימה של חיילים
	int op; // בחירת אופציה

	cout << "enter 0-7\n";
	cin >> op;

	Soldier* sol;
	int count = 0;

	while (op != stop) {

		try {

			switch (op) {


			case addNewSoldier:add(my_vec);  //הוספת חייל חדש					
				break;


			case medalList:medal(my_vec);  //הדפסת פרטי הזכאים לצל"ש
				break;




			case mostSociometric: // הדפסת שם הקצין בעל ציון סוציומטרי גבוה ביותר //
				sol = mostSociometricScore(my_vec); // השלם\י פרמטר-וקטור או רשימה
				cout << "Officer soldier with most sociometric score: ";
				cout << sol->getFname() << ' ' << sol->getName() << endl;
				break;




				//-------- הדפסת מס הטירונים הזכאים לצלש -------//
			case countMedalPrivate:  cout << "# private soldier for medal: ";

				// ---- ביטוי למבדא ----//
				for_each(my_vec.begin(), my_vec.end(), [&count](Soldier* sol) {

					//----- בדיקה אם מדובר בטירון ובנוסף הוא זכאי לצלש ----//
					if (sol->string_soldierType() == "private" && sol->medal()) {
						count++;
					}
					} // סגירת הסוגריים של האיזור מימוש של ביטוי הלמבדא
				); // for_each סגירת הסוגריים של 

				cout << count << endl; //הדפסת מספר הזכאים לצל"ש בטירונים
				count = 0;
				break;





			case noCombatCommander: // הדפסת רשימת (שם משפחה ופרטי) החיילים המפקדים שאינם בקרבי //	

				cout << "list of no combat commander soldier :";
				for_each(my_vec.begin(), my_vec.end(), [](Soldier* sol) {
					//--- אם מדובר במפקד והוא אינו קרבי ----//
					if (sol->string_soldierType() == "commander" && !sol->get_fighter()) {
						cout << sol->getFname() << " " << sol->getName() << endl;
					}
					}
				);
				cout << endl;
				break;



			case overSoldier: // קיים חייל שהשתתף יותר מ- 15 מבצעים צבאיים //

				if (any_of(my_vec.begin(), my_vec.end(), [](Soldier* sol) {

					if (sol->get_num_operation() > 15) {
						return true;
					}
					return false;
					} // הסוגריים של גוף ביטוי הלמדא
				) //any_of הסוגריים של 
					) // if - הסוגריים של ה
					cout << "there is a soldier that takes more than 15 operations\n";

				else {
					cout << "no soldier takes more than 15 operations\n";
				}

				break;




			case removeOfficer:
				//מחיקה מהווקטור/רשימה של כל החיילם קצינים שאינם השתתפו כלל במבצעים צבאיים //
				vector<Soldier*>::iterator it1;

				it1 = remove_if(my_vec.begin(), my_vec.end(), [](Soldier* sol) {
					if (sol->string_soldierType() == "officer" && sol->get_num_operation() <= 0) {
						return true;
					}
					return false;
					}
				);


				//-------- הדפסת כל הרשימה לאחר מחיקת האיברים -----//
				vector<Soldier*>::iterator it2 = my_vec.begin();
				for (it2 = my_vec.begin(); it2 != it1; it2++) {
					(*it2)->print();
				}
				break;

			};
		}
		catch (const char* msg) {
			cout << msg << endl;;
		}

		cout << "enter 0-7\n";
		cin >> op;
	}

	return 0;
}


/*

enter 0-7
1
enter 1 to add a private soldier
enter 2 to add a commander soldier
enter 3 to add a officer soldier
1
enter id, first name, last name and number Of operations
111 aaa aaa 0
enter 0-7
1
enter 1 to add a private soldier
enter 2 to add a commander soldier
enter 3 to add a officer soldier
1
enter id, first name, last name and number Of operations
222 bbb bbb 14
enter 14 grades
98 98 98 98 98 98 98 98 98 98 98 98 98 98
enter 0-7
90
enter 0-7
1
enter 1 to add a private soldier
enter 2 to add a commander soldier
enter 3 to add a officer soldier
3
enter id, first name, last name and number Of operations
333 ccc ccc 2
enter number of sociometric score
10
enter 0-7
1
enter 1 to add a private soldier
enter 2 to add a commander soldier
enter 3 to add a officer soldier
3
enter id, first name, last name and number Of operations
444 ddd ddd 4
enter number of sociometric score
95
enter 0-7
1
enter 1 to add a private soldier
enter 2 to add a commander soldier
enter 3 to add a officer soldier
3
enter id, first name, last name and number Of operations
555 eee eee 4
enter number of sociometric score
99
enter 0-7
1
enter 1 to add a private soldier
enter 2 to add a commander soldier
enter 3 to add a officer soldier
3
enter id, first name, last name and number Of operations
666 fff fff 0
enter number of sociometric score
100
enter 0-7
1
enter 1 to add a private soldier
enter 2 to add a commander soldier
enter 3 to add a officer soldier
2
enter id, first name, last name and number Of operations
777 ggg ggg 8
enter 8 grades
98 98 98 98 98 98 98 98
enter 1 if the soldier is combat and 0 if not
1
enter 0-7
1
enter 1 to add a private soldier
enter 2 to add a commander soldier
enter 3 to add a officer soldier
2
enter id, first name, last name and number Of operations
888 hhh hhh 0
enter 1 if the soldier is combat and 0 if not
0
enter 0-7
1
enter 1 to add a private soldier
enter 2 to add a commander soldier
enter 3 to add a officer soldier
2
enter id, first name, last name and number Of operations
34 poi iop 0
enter 1 if the soldier is combat and 0 if not
0

*/




/*

|for_each| => הפונקציה מקבלת טווח (שני איטרטורים) ופונקציה (במקרה שלנו ביטוי למדא) ומחזירה את ביצוע הפונקציה על הטווח


|all_of| => הפונקציה מקבלת טווח (שני איטרטורים) ופונקציה (במקרה שלנו ביטוי למדא) היא מחזירה טרו רק אם ביטוי
				הלמדא החזיר טרו על *כל אחד* מאברי הטוווח, אם ביטוי הלמדא החזיר פולס עבור *אחד* מהערכים אולוף
																										תחזיר פולס

|any_of| =>  הפונקציה מקבלת טווח (שני איטרטורים) ופונקציה בולנאית (במקרה שלנו ביטוי למדא) אניאוף מחזירה טרו
			אם ביטוי הלמדא החזיר טרו על *אחד* מאברי הטווח, אם ביטוי הלמדא החזיר פולס עבור *כל* הערכים אניאוף
																										תחזיר פולס

|renove_if| => הפונקציה מקבלת טווח (שני איטרטורים) ופונקציה בולנאית (במקרה שלנו ביטוי למדא) רמובאוף מוחקת מהטווח
		  את האיבר שביטוי הלמדא החזיר עליו טרו, רמובאוף מחזירה איטרטור ל*סוף* הרשימה המעודכנת (אחרי המחיקות) ואז
				  אם נרצה להדפיס את הרשימה המעודכנת נגדיר איטרטור מתחילת הרשימה ועד לאיטרטור שרמובאוף החזירה לנו

 */
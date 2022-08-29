/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 11         *
*                            *
******************************/
#include "Family.h"
#include<fstream>
#include<queue>
#include <iostream>
using namespace std;


//----- כתיבת 100 שורות ריקות כשכל שורה בגודל האוביקט שלי --------//
void setFile(fstream& myFile) {
	Family f;
	for (int i = 0; i < 100; i++) {
		myFile.write((char*)&f, sizeof(Family));
	}
}


//------------------- הוספת משפחה החדשה לקובץ ----------------//
void add(fstream& file1) {
	int num, amount, phone;
	char arr[21];
	Family f;

	cout << "please enter the family number, thier name, amount of people and the phone number\n";
	cin >> num >> arr >> amount >> phone;

	if (num < 1 || num>100) {
		throw "ERROR: Invalid family number";
	}

	file1.seekg((num - 1) * sizeof(Family));
	file1.read((char*)&f, sizeof(Family));

	//------- בדיקה אם המשפחה קיימת כבר בקובץ -------//
	if (f.get_family_number() != 0) {
		throw "ERROR: Family is already in the file";
	}

	f.set_last_name(arr);
	f.set_family_number(num);
	f.set_num_of_people(amount);
	f.set_phone_number(phone);

	file1.seekp((num - 1) * sizeof(Family));
	file1.write((char*)&f, sizeof(Family)); //כתיבת המשפחה החדשה בקובץ 
}


//----------- מחיקת משפחה מהרשימה -----------//
void del(fstream& file1, int num) {
	if (num < 1 || num>100) {
		throw "ERROR: Invalid family number";
	}

	Family f;
	file1.seekp((num - 1) * sizeof(Family));
	file1.write((char*)&f, sizeof(Family));
}


//--------- עדכון הרגיסטר עבור כל משפחה ----------//
void update(fstream& file1, int num, queue<Family>& q) {

	Family f1, help;
	if (num < 1 || num>100) {
		throw "ERROR: Invalid family number";
	}

	file1.seekg((num - 1) * sizeof(Family));
	file1.read((char*)&f1, sizeof(Family));

	//------- בדיקה אם המשפחה קיימת כבר -------//
	if (f1.get_family_number() == 0) {
		throw "ERROR: Family is not in the file";
	}

	help.set_family_number(f1.get_family_number());
	help.set_num_of_people(f1.get_num_of_people());

	help.set_last_name(f1.get_last_name());
	help.set_phone_number(f1.get_phone_number());

	bool temp[6];
	Family f2;


	cout << "please enter for the 6 class: 1 if you want and 0 if don't\n";
	for (int i = 0; i < 6; i++) {
		cin >> temp[i];
	}

	file1.read((char*)&f2, sizeof(Family));
	for (int i = 0; i < 6; i++) {

		//--- ע"מ שיתחיל מההתחלה -----//
		file1.seekg(0);
		int counter = 0;

		if (temp[i] == true) {

			while (!file1.eof()) {

				if (f2.get_family_number() != 0) {
					//---- בדיקה כמה מקומות נשארו -----//
					if (f2.get_classes(i) == true) {
						counter++;
					}
				}
				file1.read((char*)&f2, sizeof(Family));
			}

			if (counter < 10) {
				(f1.set_classes(true, i));
			}
			else { // אם אין מקום בחוג
				help.set_classes(true, i);
				cout << "the place at the " << i + 1 << " class is full, you are entering to waiting list\n";
				q.push(help);
				help.set_classes(false, i);
			}

			file1.clear();//clear for the next iteration 
		}
	}

	file1.seekp((num - 1) * sizeof(Family));
	file1.write((char*)&f1, sizeof(Family));
}


//----------- בדיקה אם המשפחה בחוג -----------//
bool rishum(fstream& file1, int num, int type) {

	Family f;

	if (num < 1 || num > 100) {
		throw "ERROR: Invalid family number";
	}

	file1.seekg((num - 1) * sizeof(Family));
	file1.read((char*)&f, sizeof(Family));

	if (f.get_family_number() == 0) {
		throw "ERROR: Family is not in the file";
	}

	if ((f.get_classes(type - 1)) == true) {
		return true;
	}

	return false;
}



//----------- עדכון רשימת המתנה --------------//
void waiting(fstream& file1, queue<Family>& q) {
	int counter[6] = { 0,0,0,0,0,0 };
	Family t;

	for (int i = 0; i < 6; i++) {
		file1.seekg(0);

		//-------הדפסת מס המשפחות שבחוג ------//
		while (!file1.eof()) {

			if (t.get_family_number() != 0) {
				if (rishum(file1, t.get_family_number(), i + 1)) {
					counter[i]++;
				}
			}
			file1.read((char*)&t, sizeof(Family));
		}
		file1.clear();
	}
	Family temp;
	q.push(temp);

	t = q.front();
	char tav;
	int i;

	while (t.get_family_number() != 0) {
		q.pop();

		for (i = 0; i < 6; i++) {
			if ((t.get_classes(i))) {
				break;
			}
		}

		if (counter[i] >= 10) {
			q.push(t);
		}

		else {
			cout << "family name:" << t.get_last_name() << " with phone number:" << t.get_num_of_people() << endl;
			cout << "if you want to join class number " << i + 1 << " enter Y, else enter N\n";

			cin >> tav;
			switch (tav) {

			case 'y':
			case 'Y':

				//------- שינוי וכתיבה לתוך הקובץ -------//
				file1.seekg((t.get_family_number() - 1) * sizeof(Family));
				file1.read((char*)&t, sizeof(Family));
				(t.set_classes(true, i));

				file1.seekp((t.get_family_number() - 1) * sizeof(Family));
				file1.write((char*)&t, sizeof(Family));
				counter[i]++;
				break;

			case 'n':
			case 'N':
				break;

			default:
				break;
			}

			t = q.front();
		}
	}

	q.pop();
}



//------- הדפסת פרטי המשפחה שאנחנו צריכים -------// 
void print(fstream& file1, int num) {
	if (num < 1 || num>100) {
		throw "ERROR: Invalid family number";
	}

	Family f;
	file1.seekg((num - 1) * sizeof(Family));
	file1.read((char*)&f, sizeof(Family));

	if (f.get_family_number() == 0) {
		throw "ERROR: Family is not in the file";
	}

	cout << f.get_last_name() << ' ' << f.get_num_of_people() << ' ' << f.get_phone_number() << " ";

	for (int i = 0; i < 6; i++) {
		if ((f.get_classes(i)) == true) {
			cout << "Y" << " ";
		}
		else {
			cout << "N" << " ";
		}
	}
}

//------ הדפסת שמות המשפחה שנמצאים בכיתה ספציפית ---------//
void inClass(fstream& file1, int type) {
	if (type < 1 || type>6) {
		throw "ERROR: Invalid class number";
	}

	Family f;
	file1.seekg(0); // מתחילים מההתחלה
	file1.read((char*)&f, sizeof(Family));

	while (!file1.eof()) {
		if (f.get_family_number() != 0) {
			if (f.get_classes(type - 1)) { // בדיקה אם השפחה בחוג
				cout << f.get_family_number() << " ";
			}
		}
		file1.read((char*)&f, sizeof(Family));//read the next family
	}

	file1.clear();
}


enum option {
	ADD = 1,
	DEL,
	UPDATE,
	WAITING,
	RISHUM,
	PRINT,
	CLASS
};


int main()
{
	queue<Family> q;
	fstream file;

	file.open("families.txt", ios::binary | ios::in | ios::out);
	if (!file) {
		cout << "ERROR: couldn't open file\n";
		return 0;
	}

	setFile(file);
	int choice;
	int snum;
	int cnum;

	cout << "Choices are:\n0 to exit\n1 to add a family\n2 to delete a family\n3 to update rishum to classes\n4 to update waiting to classes \n5 to check rishum for a classas\n6 to print a family\n7 to print all the families that participate in a specific class\n";
	cout << "enter 0-7:\n";

	cin >> choice;
	while (choice) {

		switch (choice) {
		case ADD://add to the file

			try { add(file); }
			catch (const char* msg) { cout << msg; }

			break;

		case DEL://delete from file

			cout << "enter number of family to delete:\n";
			cin >> snum;

			try { del(file, snum); }
			catch (const char* msg) { cout << msg; }

			break;


		case UPDATE://update the list of classes of a family
			cout << "enter number of family to update:\n";
			cin >> snum;

			try { update(file, snum, q); }
			catch (const char* msg) { cout << msg; }

			break;


		case WAITING://update the list of classes of a waiting family

			waiting(file, q);
			break;


		case RISHUM://check rishum to a specific class
			cout << "enter number of family to check rishum:\n";
			cin >> snum;

			cout << "enter number of class to check rishum:\n";
			cin >> cnum;
			try {
				cout << "The family is" << (rishum(file, snum, cnum) ? " " : " not ") << "taking the class\n";
			}
			catch (const char* msg) { cout << msg; }

			break;


		case PRINT://print the details of a specific family

			cout << "enter number of family to print:\n";
			cin >> snum;

			try { print(file, snum); }
			catch (const char* msg) { cout << msg; }

			break;


		case CLASS://print the details of all the families that are taking a specific class

			cout << "enter number of class to check rishum:\n";
			cin >> cnum;

			try { inClass(file, cnum); }
			catch (const char* msg) { cout << msg; }

			break;

		default:

			cout << "ERROR: invalid choice\n";
		}

		cout << "\nenter 0-7:\n";
		cin >> choice;
	}

	file.close();
	return 0;
}

/*Choices are:
0 to exit
1 to add a family
2 to delete a family
3 to update rishum to classes
4 to update waiting to classes
5 to check rishum for a classas
6 to print a family
7 to print all the families that participate in a specific class
enter 0-7:
1
please enter the family number, thier name, amount of people and the phone number
1 chani 1 1

enter 0-7:
1
please enter the family number, thier name, amount of people and the phone number
2 shai 2 2

enter 0-7:
1
please enter the family number, thier name, amount of people and the phone number
3 ben 3 3

enter 0-7:
1
please enter the family number, thier name, amount of people and the phone number
4 barak 4 4

enter 0-7:
1
please enter the family number, thier name, amount of people and the phone number
5 shem 5 5

enter 0-7:
1
please enter the family number, thier name, amount of people and the phone number
6 bat 6 6

enter 0-7:
1
please enter the family number, thier name, amount of people and the phone number
7 ari 7 7

enter 0-7:
1
please enter the family number, thier name, amount of people and the phone number
8 raz 8 8

enter 0-7:
1
please enter the family number, thier name, amount of people and the phone number
9 ram 9 9

enter 0-7:
1
please enter the family number, thier name, amount of people and the phone number
10 bath 10 10

enter 0-7:
1
please enter the family number, thier name, amount of people and the phone number
11 shir 11 11

enter 0-7:
1
please enter the family number, thier name, amount of people and the phone number
12 shira 12 12

enter 0-7:
1
please enter the family number, thier name, amount of people and the phone number
200 gil 4 4
ERROR: Invalid family number
enter 0-7:
1
please enter the family number, thier name, amount of people and the phone number
8 pil 4 4
ERROR: Family is already in the file
enter 0-7:
3
enter number of family to update:
1
please enter for the 6 class: 1 if you want and 0 if don't
1 1 0 0 1 0

enter 0-7:
3
enter number of family to update:
2
please enter for the 6 class: 1 if you want and 0 if don't
1 1 1 1 1 0

enter 0-7:
3
enter number of family to update:
3
please enter for the 6 class: 1 if you want and 0 if don't
0 0 1 0 1 0

enter 0-7:
3
enter number of family to update:
4
please enter for the 6 class: 1 if you want and 0 if don't
1 0 0 1 1 1

enter 0-7:
3
enter number of family to update:
5
please enter for the 6 class: 1 if you want and 0 if don't
1 1 1 0 1 1

enter 0-7:
3
enter number of family to update:
6
please enter for the 6 class: 1 if you want and 0 if don't
1 0 0 1 1 1

enter 0-7:
3
enter number of family to update:
7
please enter for the 6 class: 1 if you want and 0 if don't
1 0 1 1 1 0

enter 0-7:
3
enter number of family to update:
8
please enter for the 6 class: 1 if you want and 0 if don't
1 1 1 1 1 1

enter 0-7:
3
enter number of family to update:
9
please enter for the 6 class: 1 if you want and 0 if don't
0 0 1 1 1 1

enter 0-7:
3
enter number of family to update:
10
please enter for the 6 class: 1 if you want and 0 if don't
1 1 0 1 1 0

enter 0-7:
3
enter number of family to update:
11
please enter for the 6 class: 1 if you want and 0 if don't
1 1 0 0 1 1
the place at the 5 class is full, you are entering to waiting list

enter 0-7:
3
enter number of family to update:
12
please enter for the 6 class: 1 if you want and 0 if don't
1 1 1 0 1 1
the place at the 5 class is full, you are entering to waiting list

enter 0-7:
1
please enter the family number, thier name, amount of people and the phone number
13 gil 1 13

enter 0-7:
3
enter number of family to update:
13
please enter for the 6 class: 1 if you want and 0 if don't
1 1 0 0 0 0
the place at the 1 class is full, you are entering to waiting list

enter 0-7:
2
enter number of family to delete:
200
ERROR: Invalid family number


enter 0-7:
5
enter number of family to check rishum:
13
enter number of class to check rishum:
1
The family is not taking the class

enter 0-7:
7
enter number of class to check rishum:
5
chani shai ben barak shem bat ari raz ram bath
enter 0-7:
2
enter number of family to delete:
8

enter 0-7:
2
enter number of family to delete:
4

enter 0-7:
4
family name:shir with phone number:11
if you want to join class number 5 enter Y, else enter N
Y
family name:shira with phone number:12
if you want to join class number 5 enter Y, else enter N
N
family name:gil with phone number:13
if you want to join class number 1 enter Y, else enter N
Y

enter 0-7:
6
enter number of family to print:
12
shira 12 12 Y Y Y N N Y

enter 0-7:
0*/
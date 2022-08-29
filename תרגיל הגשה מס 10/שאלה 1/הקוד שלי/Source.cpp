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
///------------------------------------------------------------- vector ����� �� ������� ------------------------------------------------------------------///


enum option {
	stop,	//	���� �������
	addNewSoldier,	//	����� ���� ���
	medalList,	//����� ���� �� ������� ������ ���"�
	mostSociometric,	//	����� �� (����� �����) ��  ����� ��� ���� ��������� ������� 
	countMedalPrivate,	//	����� ���� ������� ��������� ������ ���"�
	noCombatCommander,	//	����� ���� (����� �����) �� ������� ����� �����
	overSoldier,	//	����� ����� ������, ��� ���� ���� ������ ����� �- 15  ������ ������
	removeOfficer,	//	����� �� ������� ������� ��� ������ ��� ����� ����
};


//------------ STL ������� ����� ���� ����� -----------//
void add(vector<Soldier*>& my_stl_vec) { // Soldier* ��� �� ��� ����� ���� ����� ���� STL �������� ����� ���� �� 
	cout << "enter 1 to add a private soldier\n";
	cout << "enter 2 to add a commander soldier\n";
	cout << "enter 3 to add a officer soldier\n";

	int num;
	cin >> num;

	cout << "enter id, first name, last name and number Of operations\n";
	int taz; // ��
	string first_name; // �� ����
	string last_name; // �� �����
	int num_operation; // �� ������� ������ ��� ��� ���

	cin >> taz >> first_name >> last_name >> num_operation;


	//----- ����� �� ������ ����� ------//
	if (num == 1) {
		//---- STL ����� ������� ���� ����� ������� ������� � ----//
		Soldier* ptr = new Private(taz, first_name, last_name, num_operation);
		my_stl_vec.push_back(ptr);
	}

	else if (num == 2) {
		//---- STL ����� ������� ���� ���� ������� ������� � ----//
		Soldier* ptr = new Commander(taz, first_name, last_name, num_operation);
		my_stl_vec.push_back(ptr);
	}

	else if (num == 3) {
		//---- STL ����� ������� ���� ���� ������� ������� � ----//
		Soldier* ptr = new Officer(taz, first_name, last_name, num_operation);
		my_stl_vec.push_back(ptr);
	}
}



//--------- �������� ������ �� ���� ���� ---------// 
void medal(vector<Soldier*> my_stl_vec) { // Soldier* ��� �� ��� ����� ���� ����� ���� STL �������� ����� ���� �� 

	//---- ����� ������� ������ �� ������� ���� -----//
	vector<Soldier*>::iterator it = my_stl_vec.begin();

	// ��� ������ ������ ������� //
	//auto it = my_stl_vec.begin();

	for (it = my_stl_vec.begin(); it != my_stl_vec.end(); it++) {
		if ((*it)->medal()) {
			(*it)->print();
		}
	}
}



//----- ������� ������ �� ����� ��� ����� ����� ���������� ����� ����� ------//
Soldier* mostSociometricScore(vector<Soldier*> my_stl_vec) { // Soldier* ��� �� ��� ����� ���� ����� ���� STL �������� ����� ���� �� 

	int max = -1; // ����� �� ���� �� �������� �����
	Soldier* ptr_sol = NULL; // ������� ����� �� ���� ��������� ������

	//----- ����� �������� ----//
	vector<Soldier*>::iterator it = my_stl_vec.begin();

	for (it = my_stl_vec.begin(); it != my_stl_vec.end(); it++) {

		//--- ����� �� ����� �� ���� ----//
		if ((*it)->string_soldierType() == "officer") {

			//--- ����� �������� ----//
			if ((*it)->get_Sociometric_score() > max) {
				max = (*it)->get_Sociometric_score(); // ����� ��������
				ptr_sol = *it; // �������� ���� �� ��� �������� �� �����
			}
		}
	}

	return ptr_sol;
}



int main() {

	vector<Soldier*> my_vec;   // ����� �� ������ �� ����� �� ������
	int op; // ����� ������

	cout << "enter 0-7\n";
	cin >> op;

	Soldier* sol;
	int count = 0;

	while (op != stop) {

		try {

			switch (op) {


			case addNewSoldier:add(my_vec);  //����� ���� ���					
				break;


			case medalList:medal(my_vec);  //����� ���� ������ ���"�
				break;




			case mostSociometric: // ����� �� ����� ��� ���� ��������� ���� ����� //
				sol = mostSociometricScore(my_vec); // ����\� �����-����� �� �����
				cout << "Officer soldier with most sociometric score: ";
				cout << sol->getFname() << ' ' << sol->getName() << endl;
				break;




				//-------- ����� �� �������� ������ ���� -------//
			case countMedalPrivate:  cout << "# private soldier for medal: ";

				// ---- ����� ����� ----//
				for_each(my_vec.begin(), my_vec.end(), [&count](Soldier* sol) {

					//----- ����� �� ����� ������ ������ ��� ���� ���� ----//
					if (sol->string_soldierType() == "private" && sol->medal()) {
						count++;
					}
					} // ����� �������� �� ������ ����� �� ����� ������
				); // for_each ����� �������� �� 

				cout << count << endl; //����� ���� ������ ���"� ��������
				count = 0;
				break;





			case noCombatCommander: // ����� ����� (�� ����� �����) ������� ������� ����� ����� //	

				cout << "list of no combat commander soldier :";
				for_each(my_vec.begin(), my_vec.end(), [](Soldier* sol) {
					//--- �� ����� ����� ���� ���� ���� ----//
					if (sol->string_soldierType() == "commander" && !sol->get_fighter()) {
						cout << sol->getFname() << " " << sol->getName() << endl;
					}
					}
				);
				cout << endl;
				break;



			case overSoldier: // ���� ���� ������ ���� �- 15 ������ ������ //

				if (any_of(my_vec.begin(), my_vec.end(), [](Soldier* sol) {

					if (sol->get_num_operation() > 15) {
						return true;
					}
					return false;
					} // �������� �� ��� ����� �����
				) //any_of �������� �� 
					) // if - �������� �� �
					cout << "there is a soldier that takes more than 15 operations\n";

				else {
					cout << "no soldier takes more than 15 operations\n";
				}

				break;




			case removeOfficer:
				//����� ��������/����� �� �� ������ ������ ����� ������ ��� ������� ������ //
				vector<Soldier*>::iterator it1;

				it1 = remove_if(my_vec.begin(), my_vec.end(), [](Soldier* sol) {
					if (sol->string_soldierType() == "officer" && sol->get_num_operation() <= 0) {
						return true;
					}
					return false;
					}
				);


				//-------- ����� �� ������ ���� ����� ������� -----//
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

|for_each| => �������� ����� ���� (��� ���������) �������� (����� ���� ����� ����) ������� �� ����� �������� �� �����


|all_of| => �������� ����� ���� (��� ���������) �������� (����� ���� ����� ����) ��� ������ ��� �� �� �����
				����� ����� ��� �� *�� ���* ����� ������, �� ����� ����� ����� ���� ���� *���* ������� �����
																										����� ����

|any_of| =>  �������� ����� ���� (��� ���������) �������� ������� (����� ���� ����� ����) ������ ������ ���
			�� ����� ����� ����� ��� �� *���* ����� �����, �� ����� ����� ����� ���� ���� *��* ������ ������
																										����� ����

|renove_if| => �������� ����� ���� (��� ���������) �������� ������� (����� ���� ����� ����) ������� ����� ������
		  �� ����� ������ ����� ����� ���� ���, ������� ������ ������� �*���* ������ �������� (���� �������) ���
				  �� ���� ������ �� ������ �������� ����� ������� ������ ������ ��� �������� �������� ������ ���

 */
/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 1 seif 3   *
*                            *
******************************/
#include "Circle.h"
#include <iostream>
#include <cmath>
using namespace std;


//--------------- ������ ������ ����� �� ����� ������ ������� ��� ��� ��� �� ����� ��� ���� -------------------//
 //----------- ���� ��� �������� ����� �� �� ���� �� ������ ������ �� ������� �� ������ ��� ��� -------------//
  //------------------ ������� ����� ������� �� ���� ������� ������� �� �� ���� ����� -----------------------//


///----------------------------------------- cpp - ����� ���� ����� �  -----------------------------------------///

int main() {

	Circle A, B, C;

	//------- ����� ����� �� ����� ������ -------//
	cout << "enter the center point and radius of 3 circles: " << endl;

	char c; // ���� ������ ������� - �������� ������ 
	int x, y, r;

	//------- ���� ����� -------//
	cin >> c >> x >> c >> y >> c >> r; // (x,y) r;
	A.setCenter(x, y);
	A.setRadius(r);


	//------- ���� ��� -------//
	cin >> c >> x >> c >> y >> c >> r;
	B.setCenter(x, y);
	B.setRadius(r);


	//------ ���� ����� -------//
	cin >> c >> x >> c >> y >> c >> r;
	C.setCenter(x, y);
	C.setRadius(r);


	cout << "perimeter: " << "\t" << "A:" << " " << A.perimeter() << "\t" << "B:" << " " << B.perimeter() << "\t" << "C:" << " " << C.perimeter() << endl;

	cout << "area: " << "\t" << "A:" << " " << A.area() << "\t" << "B:" << " " << B.area() << "\t" << "C:" << " " << C.area() << endl;



	//--------------------------- ����� �� ������� ������� �� �� ���� ���� ������ ---------------------------//

	cout << "enter points until (0,0):" << endl;

	Circle point;
	int count1 = 0;
	int count2 = 0;
	int count3 = 0;

	cin >> c >> x >> c >> y >> c;
	point.setCenter(x, y);

	while (point.getCenter().getX() || point.getCenter().getY()) { // while (x != 0 && y != 0);

		//------------------- ���� ����� --------------------//

		if (A.onInOut(point.getCenter()) == -1 || A.onInOut(point.getCenter()) == 0) {
			count1++;
		}


		//-------------------- ���� ��� ---------------------//

		if (B.onInOut(point.getCenter()) == -1 || B.onInOut(point.getCenter()) == 0) {
			count2++;
		}


		//------------------- ���� ����� ------------------//

		if (C.onInOut(point.getCenter()) == -1 || C.onInOut(point.getCenter()) == 0) {
			count3++;
		}


		//------ ����� ������ ���� ������ --------//
		cin >> c >> x >> c >> y >> c;
		point.setCenter(x, y);

	}

	cout << "num of points in circle: " << "A: " << count1 << "\t" << "B: " << count2 << "\t" << "C: " << count3 << "\t" << endl;


	return 0;

}


/*enter the center point and radius of 3 circles:
(0,0) 3
(1,1) 2
(5,5) 2
perimeter:      A: 18.84        B: 12.56        C: 12.56
area:   A: 28.26        B: 12.56        C: 12.56
enter points until (0,0):
(0,1)
(1,0)
(0,4)
(0,0)
num of points in circle: A: 2   B: 2    C: 0
Press any key to continue . . .*/
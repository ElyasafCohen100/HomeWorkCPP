/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 8          *
* Seif: I                    *
******************************/
#include"StackList.h"
#include <string>
#include <cstring>

//------------------- postfix - ל infix פונקציית הפיכת --------------------//
string infixToPostfix(string infix) {

	string str; // מחרוזת ריקה

	//----- מחסנית תווים ריקה -----//
	StackList stk; // המחסנית שלנו תחזיק *תווים* באופן זמני //


	char spacing = ' ';
	char ch = 0;

	int i = 0;
	while (i != infix.length()) {

		char ch = infix[i];	

		/*4.1*/
		if (ch == '(') {
			stk.push(ch);
		}


		/*4.2*/
		else if (ch == ')') {

			//--- "(" כל זמן שראש המחסנית לא ---//
			while (stk.top() != '(') { // שליפה מהמחסנית עד לסוגר השמאלי
				str += stk.pop(); // הכנסת הערכים הנשלפים מהמחסנית למחרוזת
				str += ' ';
			}
			stk.pop(); // הוצאת הסוגר השמאלי
		}



		/*4.3*/
		//----- אם מדובר בפעולה חשבונית ----//
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {

			//--- השליפה מהמחסנית תתבצע עד שמגיעים לסוגריים ---//
			while ((!stk.isEmpty() && stk.top() != '(')) {				
				str += stk.pop(); // הכנסת הערכים הנשלפים מהמחסנית למחרוזת
				str += ' ';
			}
			stk.push(ch);
		}


		/*4.4*/
		//---- אם מדובר במספר ----//
		else if (ch >= '0' && ch <= '9') {
			str += ch; // שירשור הערך למחרוזת

			//--- בדיקה אם התו הבא במחרוזת הוא ספרה ----//
			while (i + 1 != infix.length() && infix[i + 1] >= '0' && infix[i + 1] <= '9') {
				str += infix[++i];
			}
			str += ' ';
		}

		/*4.5*/
		i++;
	}


	/*5*/
	while (!stk.isEmpty()) {
		str += stk.pop();
		str += ' ';

	}

	return str;
}

//------------------- postfix - ל infix פונקציית הפיכת --------------------//
int calcPostfix(string postfix) {

	//----- מחסנית תווים ריקה -----//
	StackList stk; // המחסנית שלנו תחזיק *אינטים* באופן זמני //

	int i = 0;
	while (i < postfix.length()) {

		char ch = postfix[i];

		if (ch >= '0' && ch <= '9') {
			string st; // מחרוזת עזר
			st += ch;

			//-- בדיקה אם יש לנו ספרה ולא מספר אם יש לנו מספר אנחנו מכניסים אותו למחרוזת עזר --//
			while (i + 1 != postfix.length() && postfix[i + 1] >= '0' && postfix[i + 1] <= '9') {
				st += postfix[i + 1];
				i++;
			}

			//--- יכניס לי למחסנית מספר בעל מס ספרות ---//
			stk.push(stoi(st)/* int הופך ל st */);
		}

		else if (ch != ' ') {

			//---- לשמור על הסדר של החילוק והחיסור ----//
			int operand1 = stk.pop();
			int operand2 = stk.pop();

			if (ch == '+') {
				stk.push(operand1 + operand2);
			}

			else if (ch == '-') {
				stk.push(operand2 - operand1);
			}

			else if (ch == '*') {
				stk.push(operand1 * operand2);
			}

			else if (ch == '/') {
				stk.push(operand2 / operand1);
			}
		}
		i++;
	}

	//--- התוצאה מחכה בראש המחסנית ---//
	return stk.pop();
}



int main() {
	try {
		string exp;
		cout << "enter an infix expression as a string" << endl;

		cin >> exp;
		string postfix = infixToPostfix(exp);

		cout << postfix << endl;
		cout << calcPostfix(postfix) << endl;
	}
	catch (const char* msg) {
		cout << msg << endl;
	}
	return 0;
}

/*
enter an infix expression as a string
(5+3)*((20/10)+(8-6))
5 3 + 20 10 / 8 6 - + *
32
Press any key to continue . . .
*/
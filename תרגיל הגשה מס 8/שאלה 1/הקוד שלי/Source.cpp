/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 8          *
* Seif: I                    *
******************************/
#include"StackList.h"
#include <string>
#include <cstring>

//------------------- postfix - � infix �������� ����� --------------------//
string infixToPostfix(string infix) {

	string str; // ������ ����

	//----- ������ ����� ���� -----//
	StackList stk; // ������� ���� ����� *�����* ����� ���� //


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

			//--- "(" �� ��� ���� ������� �� ---//
			while (stk.top() != '(') { // ����� �������� �� ����� ������
				str += stk.pop(); // ����� ������ ������� �������� �������
				str += ' ';
			}
			stk.pop(); // ����� ����� ������
		}



		/*4.3*/
		//----- �� ����� ������ ������� ----//
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {

			//--- ������ �������� ����� �� ������� �������� ---//
			while ((!stk.isEmpty() && stk.top() != '(')) {				
				str += stk.pop(); // ����� ������ ������� �������� �������
				str += ' ';
			}
			stk.push(ch);
		}


		/*4.4*/
		//---- �� ����� ����� ----//
		else if (ch >= '0' && ch <= '9') {
			str += ch; // ������ ���� �������

			//--- ����� �� ��� ��� ������� ��� ���� ----//
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

//------------------- postfix - � infix �������� ����� --------------------//
int calcPostfix(string postfix) {

	//----- ������ ����� ���� -----//
	StackList stk; // ������� ���� ����� *������* ����� ���� //

	int i = 0;
	while (i < postfix.length()) {

		char ch = postfix[i];

		if (ch >= '0' && ch <= '9') {
			string st; // ������ ���
			st += ch;

			//-- ����� �� �� ��� ���� ��� ���� �� �� ��� ���� ����� ������� ���� ������� ��� --//
			while (i + 1 != postfix.length() && postfix[i + 1] >= '0' && postfix[i + 1] <= '9') {
				st += postfix[i + 1];
				i++;
			}

			//--- ����� �� ������� ���� ��� �� ����� ---//
			stk.push(stoi(st)/* int ���� � st */);
		}

		else if (ch != ' ') {

			//---- ����� �� ���� �� ������ ������� ----//
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

	//--- ������ ���� ���� ������� ---//
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
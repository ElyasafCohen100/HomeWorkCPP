///*Odelya Yaakowich 207346784
//Workshop in c++
//Exercise 8 Question 1*/
//
//#include "StackList.h"
//#include <string>
//#include <iostream>
//using namespace std;
//
//string infixToPostfix(string myInfix);
//int calcPostfix(string postfix);
//
//
//int main()
//{
//	try
//	{
//		string exp;
//		cout << "enter an infix expression as a string" << endl;
//		cin >> exp;
//		string postfix = infixToPostfix(exp);
//		cout << postfix << endl;
//		cout << calcPostfix(postfix) << endl;
//	}
//	catch (const char* msg)
//	{
//		cout << msg << endl;
//	}
//	return 0;
//}
//
//	
//
//string infixToPostfix(string infix)
//{
//	string str;
//	Stack* stk = new StackList();
//	char ch = infix[0];
//	int i = 0;
//	while (infix[i])
//	{
//		if (ch == '(')
//			stk->push(ch);
//		else if (ch == ')')
//		{
//			while (stk->top() != '(')
//			{
//				str += ' ';
//				str += stk->pop();
//			}
//			stk->pop();
//		}
//		else if (ch == '+' || ch == '-')
//		{
//			while (!stk->isEmpty() && (stk->top() == '*' || stk->top() == '/'))
//			{
//				str += ' ';
//				str += stk->pop();
//			}
//			stk->push(ch);
//			str += ' ';
//		}
//		else if (ch == '*' || ch == '/')
//		{
//			stk->push(ch);
//			str += ' ';
//		}
//		else
//			str += ch;
//		i++;
//		ch = infix[i];
//	}
//	while (!stk->isEmpty())
//	{
//		str += ' ';
//		str += stk->top();
//		stk->pop();
//	}
//	return str;
//}
//
//
//int calcPostfix(string postfix)
//{
//	Stack* stk = new StackList();
//	char ch = postfix[0];
//	int i = 0;
//	while (postfix[i])
//	{
//		if (ch >= '0' && ch <= '9')
//		{
//			string str;
//			while (ch >= '0' && ch <= '9')
//			{
//				str += ch;
//				i++;
//				ch = postfix[i];
//			}
//			stk->push(stoi(str));
//		}
//		else if (ch != ' ')
//		{
//			float b = stk->pop();
//			float a = stk->pop();
//			float result = 0;
//			if (ch == '+')
//				result = a + b;
//			else if (ch == '-')
//				result = a - b;
//			else if (ch == '*')
//				result = a * b;
//			else if (ch == '/')
//				result = a / b;
//			stk->push(result);
//		}
//		i++;
//		ch = postfix[i];
//	}
//	int res = stk->pop();
//	return res;
//}
//
///*
//enter an infix expression as a string
//(5+3)*((20/10)+(8-6))
//5 3 + 20 10 / 8 6 - + *
//32
//*/
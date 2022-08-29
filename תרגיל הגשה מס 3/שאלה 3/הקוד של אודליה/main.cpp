#include "MyString.h"
#include<iostream>
using namespace std;
int main()
{
	char* a = new char[81];
	char* b = new char[81];
	int n;
	cin >> a;
	cin >> b;
	cin >> n;
	MyString s1(a), s2(b);
	if (s1 == s2)
		cout << "a=b" << endl;
	else if (s1 > s2)
		cout << "a>b" << endl;
	else if (s1 < s2)
		cout << "a<b" << endl;
	if (s1 == s2 && (n > s1.length() || n < 0))	
	{
		cout << "ERROR" << endl;
		exit(-1);
	}
	MyString s3(s2.insert(n, s1.getString()));
	s3.print();
	char tav;
	int index;
	cin >> tav;
	cin >> index;
	s3.print();
	delete[]a;
	delete[]b;
	return 0;
}
//World
//Hello
//5
//a > b
//HelloWorld
//!
//5
//Hello!orld

//Hello
//Hello
//2
//a == b
//HeHellollo
//h
//2
//Hehellollo

//Hello
//World
//2
//a < b
//WoHellorld
//?
//10
//ERROR

//Hello
//World
//0
//a < b
//HelloWorld
//-
//6
//HelloW - rld

//Hello
//World
//8
//a < b
//ERROR
//J
//3
//ERROR

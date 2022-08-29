#include "MyString.h"
void MyString::setString(const char* s)
{
	if (s)
	{
		int len = strlen(s) + 1;
		str = new char[len];
		strcpy(str,s);
	}
	else 
		str = NULL;
}
char* MyString::getString() const
{
	return str;
}
//Constructor.
MyString::MyString(char* s)
{
	setString(s);
}
//Copy Constructor.
MyString::MyString(const MyString& s)
{
	setString(s.getString());
}
//Move constructor.
//MyString::MyString(const MyString&& s)
//{
//
//	setString(s.getString());
//}
//Destructor.
MyString::~MyString()
{
	if (str)
		delete[] str;
	str = NULL;
}
MyString& MyString::operator=(const MyString& s)
{
	if (str)
		delete[] str;
	setString(s.getString());
	return *this;
}
MyString MyString::operator+(const MyString& s)const
{
	int sizeI = strlen(str);
	int sizeII = strlen(s.getString());
	char* temp = new char[sizeI + sizeII + 1];
	strcpy(temp,str);
	strcpy(temp + sizeI, s.getString());
	MyString x(temp);
	return x;
}
MyString MyString::operator*(const int& num)const
{
	char* temp;
	int len = strlen(str);
	temp = new char[len * num + 1];
	for (int i = 0; i < num; i++)
		strcpy(temp + i * len,str);
	MyString s(temp);
	return s;
}
//char* change(const char* str)
//{
//	int i = 0;
//	char* strLow= new char[strlen(str) + 1];
//	strcpy(strLow, str);
//	while (str[i] != '\0')
//	{
//		bool flag = false;
//		int ch = str[i];
//		if (ch >= 65 && ch<= 90)
//		{
//			strLow[i] =ch+32;
//			flag = true;
//		}
//		if (!flag)
//		{
//			strLow[i] = ch;
//		}
//		i++;
//	}
//	return strLow;
//}
bool MyString::operator==(const MyString& s) 
{
	if (this->length() != s.length())
		return false;
	else
	{
		for (int i = 0; i < this->length(); i++)
		{
			if (str[i] != s.str[i])
			{
				if (str[i] < s.str[i])
				{
					if (str[i] + 32 != s.str[i])
						return false;
				}
				else if (str[i] > s.str[i])
				{
					if (str[i] != s.str[i] + 32)
						return false;
				}
			}
		}
		return true;
	}
}
int MyString::length() const
{
	return strlen(str);
}
bool MyString::operator!=(const MyString& s)
{
	return !(*this == s);
}
bool MyString:: operator>(const MyString& s)
{
	if (*this != s)
	{
		int len;
		if (this->length() > s.length())
			len = s.length();
		else
			len = s.length();
		for (int i = 0; i < len; i++)
		{
			if (str[i] < s.str[i])
				return false;
			if (str[i] > s.str[i])
				return true;
		}
		return true;
	}
	else
		return false;
}
bool MyString::operator<(const MyString& s) 
{
	if (*this!=s)
	{
		int len;
		if (this->length() > s.length())
			len = s.length();
		else
			len = this->length();
		for (int i = 0; i < len; i++)
		{
			if (str[i] > s.str[i])
				return false;
			if (str[i] < s.str[i])
				return true;
		}
		return true;
	}
	else
		return false;
}
bool MyString::operator>=(const MyString&s) 
{
	if (strcmp(str,s.getString()) >=0)
		return true;
	else
		return false;
}
bool MyString::operator<=(const MyString& s) 
{
	if (strcmp(str, s.getString()) <=0)
		return true;
	else
		return false;
}
char& MyString::operator[](const int& index) const
{
	if (!str || index >= this->length() || index < 0)
	{
		cout << "ERROR" << endl;
		exit(-1);
	}
	else
		return str[index];
}
MyString MyString::insert(int index, const char* myStr) const
{
	int len = this->length() + strlen(str);
	if ((index + strlen(myStr) - 1) >=len || index < 0)
	{
		cout << "ERROR" << endl;
		MyString s;
		return s;
	}
	else
	{
		char* temp;
		temp = new char[len + 1];
		strcpy(temp,str);
		strcpy(temp + index, myStr);
		strcat(temp,str + index);
		MyString s(temp);
		return s;
	}
}
void MyString::print() const
{
	if (str) cout << str << endl;
}
#pragma once
#include <iostream>
#include <cstring>
#include<cstdlib>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning (disable:4996)
using namespace std;
class MyString
{
private:
    char* str;
    void setString(const char* s);
public:
    char* getString() const;
    MyString(char* s = NULL);
    MyString(const MyString& s);
    //MyString(const MyString&& s);
    ~MyString();
    int length() const;
    MyString& operator =(const MyString&);
    MyString operator+(const MyString&)const;
    MyString operator* (const int&)const;
    bool operator==(const MyString&);
    bool operator>(const MyString&);
    bool operator<(const MyString&);
    bool operator>=(const MyString&);
    bool operator<=(const MyString&);
    bool operator!=(const MyString&);
    char& operator[](const int& index) const;
    MyString insert(int index, const char* str)const;
    void print() const;
};

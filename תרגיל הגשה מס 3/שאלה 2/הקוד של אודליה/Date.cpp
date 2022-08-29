///*Odelya Yaakowich 207346784
//Workshop in c++
//Exercise 3 Question 2*/
//
//#include "Date.h"
//#include <iostream>
//using namespace std;
//
//
//void Date::setDay(int myDay)
//{
//	if (myDay < 1 || myDay > 30)
//	{
//		cout << "Error day" << endl;
//		day = 1;
//	}
//	else
//		day = myDay;
//}
//
//void Date::setMounth(int myMounth)
//{
//	if (myMounth < 1 || myMounth > 12)
//	{
//		cout << "Error month" << endl;
//		myMounth = 1;
//	}
//	else
//		mounth = myMounth;
//}
//
//
//void Date::setYear(int myYear)
//{
//	if (myYear < 1920 || myYear > 2099)
//	{
//		cout << "Error year" << endl;
//		year = 1920;
//	}
//	else
//		year = myYear;
//}
//
//
//int Date::getDay() const
//{
//	return day;
//}
//
//
//int Date::getMounth() const
//{
//	return mounth;
//}
//
//
//int Date::getYear() const
//{
//	return year;
//}
//
//
//Date::Date(int myDay, int myMounth, int myYear) //ctor
//{
//	setDay(myDay);
//	setMounth(myMounth);
//	setYear(myYear);
//}
//
//
//Date::Date(const Date& right) //copy - ctor
//{
//	day = right.getDay();
//	mounth = right.getMounth();
//	year = right.getYear();
//}
//
//
//Date::Date(const Date&& right) //move - ctor
//{
//	day = right.getDay();
//	mounth = right.getMounth();
//	year = right.getYear();
//}
//
//
//void Date::setDate(int myDay, int myMounth, int myYear)
//{
//	if (myDay >= 1 || myDay <= 30)
//		day = myDay;
//	if (myMounth >= 1 || myMounth <= 12)
//		mounth = myMounth;
//	if (myYear >= 1920 || myYear <= 2099)
//		year = myYear;
//}
//
//
//Date Date::operator++() // prefix
//{
//	if (day == 30 && mounth == 12 && year == 2099) // if the date is 30.12.2099
//	{
//		this->setDate(1, 1, 1920);
//	}
//	else
//	{
//		if (day == 30) // if we are at the end of the mounth
//		{
//			if (mounth == 12) // if we are at the end of the year
//			{
//				day = 1;
//				mounth = 1;
//				year += 1;
//			}
//			else
//			{
//				day = 1;
//				mounth += 1;
//			}
//		}
//		else
//			day += 1;
//	}
//	return *this;
//}
//
//
//Date Date::operator++(int notused) // postfix
//{
//	Date temp;
//	if (day == 30 && mounth == 12 && year == 2099) // if the date is 30.12.2099
//	{
//		return temp;
//	}
//	else
//	{
//		temp.setDate(day, mounth, year);
//		if (day == 30) // if we are at the end of the mounth
//		{
//			if (mounth == 12) // if we are at the end of the year
//			{
//				day = 1;
//				mounth = 1;
//				year += 1;
//			}
//			else
//			{
//				day = 1;
//				mounth += 1;
//			}
//		}
//		else
//			day += 1;
//		return temp;
//	}
//}
//
//
//void Date::operator+=(const int& num)
//{
//	day += num;
//
//	if (day > 30 && mounth == 12 && year == 2099) // if the date is later than 30.12.2099
//	{
//		this->setDate(1, 1, 1920);
//	}
//	else
//	{
//		if (day > 30) // if the date pass 30/mounth/year
//		{
//			if (mounth == 12)
//			{
//				day -= 30;
//				mounth = 1;
//				year += 1;
//			}
//			else
//			{
//				day -= 30;
//				mounth += 1;
//			}
//		}
//	}
//}
//
//
//bool Date::operator>(const Date& right) const // check if the left date is later then the right date
//{
//	bool flag = false;
//
//	if (year > right.getYear())
//		flag = true;
//
//	if (year == right.getYear() && mounth > right.getMounth())
//		flag = true;
//
//	if (year == right.getYear() && mounth == right.getMounth() && day > right.getDay())
//		flag = true;
//
//	return flag;
//}
//
//
//bool Date::operator<(const Date& right) const // check if the left date is earlier then the right date
//{
//	bool flag = false;
//
//	if (year < right.getYear())
//		flag = true;
//
//	if (year == right.getYear() && mounth < right.getMounth())
//		flag = true;
//
//	if (year == right.getYear() && mounth == right.getMounth() && day < right.getDay())
//		flag = true;
//
//	return flag;
//}
//
//
//bool Date::operator==(const Date& right) const // check if the left date is the same like the right date
//{
//	bool flag = false;
//
//	if (year == right.getYear() && mounth == right.getMounth() && day == right.getDay())
//		flag = true;
//
//	return flag;
//}
//
//
//void Date::print() const {
//	cout << day << "/" << mounth << "/" << year << endl;
//}
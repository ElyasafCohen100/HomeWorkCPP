///*Odelya Yaakowich 207346784
//Workshop in c++
//Exercise 3 Question 2*/
//
//
//#pragma once
//class Date
//{
//	int day;
//	int mounth;
//	int year;
//public:
//	int getDay() const;
//	int getMounth() const;
//	int getYear() const;
//	Date(int myDay = 1, int myMounth = 1, int myYear = 1920); //ctor
//	Date(const Date& right); //copy - ctor
//	Date(const Date&& right); //moove - ctor
//	Date operator++(); // prefix
//	Date operator++(int notused); // postfix
//	void setDate(int myDay, int myMounth, int myYear);
//	void operator+=(const int& num);
//	bool operator>(const Date& right) const;
//	bool operator<(const Date& right) const;
//	bool operator==(const Date& right) const;
//	void print() const;
//private:
//	void setDay(int myDay);
//	void setMounth(int myMounth);
//	void setYear(int myYear);
//};
//

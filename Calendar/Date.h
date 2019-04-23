#pragma once
#include<iostream>
#include<string>
using namespace std;
class Date
{
	int day;
	int month;
	int year;

public:
	Date(int day =1,int month =1,int year = 1970);
	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);
	int getDay()const;
	int getMonth()const;
	int getYear()const;
	void getDayWeek()const;

};

ostream& operator<<(ostream& os, const Date& obj);
istream& operator>>(istream& is, Date& obj);
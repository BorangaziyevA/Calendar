#include "Date.h"



Date::Date(int day,int month,int year)
{

	setMonth(month);
	setYear(year);
	setDay(day);
}

void Date::setDay(int day)
{
	switch (this->month)
	{
	case 1: 
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		if (day >= 1 && day < 32)
		{
			this->day = day;
		}
		else
			this->day = 1;
		break;
	case 2:
		if (this->year%4 == 0)
		{
			if (day >= 1 && day < 30)
			{
				this->day = day;
			}
			else
				this->day = 1;
		}
		else
		{
			if (day >= 1 && day < 29)
			{
				this->day = day;
			}
			else
				this->day = 1;
		}
		break;

	case 4:
	case 6:
	case 9:
	case 11:
		if (day >= 1 && day < 31)
		{
			this->day = day;
		}
		else
			this->day = 1;
		break;
	}

}

void Date::setMonth(int month)
{
	if (month >= 1 && month < 13)
	{
		this->month = month;
	}
	else
		this->month = 1;
}

void Date::setYear(int year)
{
	if (year >= 1970)
	{
		this->year = year;
	}
	else
		this->year = 1970;
}

int Date::getDay() const
{
	return day;
}

int Date::getMonth() const
{
	return month;
}

int Date::getYear() const
{
	return year;
}

void Date::getDayWeek() const
{
	int a = (14 - month) / 12;
	int y = year - a;
	int m = month + 12 * a - 2;

	int result = ((day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12)) % 7;

	switch (result)
	{
	case 0:
		cout << "Sunday";
		break;
	case 1:
		cout << "Monday";
		break;

	case 2:
		cout << "Tuesday";

		break;
	case 3:
		cout << "Wednesday";

		break;
	case 4:
		cout << "Thursday";
		break;

	case 5:
		cout << "Friday";
		break;

	case 6:
		cout << "Saturday";
		break;
	}
}


ostream & operator<<(ostream & os, const Date & obj)
{
	if (obj.getDay() < 10)
		os << "0";
	os << obj.getDay() << ".";
	if (obj.getMonth() < 10)
		os << "0";
	os << obj.getMonth() << "." << obj.getYear() << endl;
	return os;
}

istream & operator>>(istream & is, Date & obj)
{
	int tmp;
	cout << "Day:" << endl;
	cin >> tmp;
	obj.setDay(tmp);
	cout << "Month:" << endl;
	cin >> tmp;
	obj.setMonth(tmp);
	cout << "Year:" << endl;
	cin >> tmp;
	obj.setYear(tmp);

	return is;
}

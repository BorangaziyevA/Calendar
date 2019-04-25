#include "Date.h"

int x;

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

void Date::checkData()
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
			if (day > 31)
			{
				addMonth(1);
				day -= 31;
			}
			break;
		case 2:
			if (this->year % 4 == 0)
			{
				if (day > 29)
				{
					addMonth(1);
					day -= 29;
				}
			}

			else
			{
				if (day > 28)
				{
					addMonth(1);
					day -= 28;
				}
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if (day > 30)
			{
				addMonth(1);
				day -= 30;
			}
			break;
		}

}
void Date::addYears(int years)
{
	year += years;
}
void Date::addMonth(int months)
{
	month += months;
	if (month > 12)
	{
		year += (month / 12);
		month %= 12;
	}
}
void Date::addDays(int days)//Не больше 56 дней
{
	if (days >= 365)
	{
		addYears(days / 365);
		days %= 365;
	}

	switch (this->month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		if (days > 31)
		{
			x = days / 31;
			for (size_t i = 1; i <= x; i++)
			{
				addMonth(1);
				checkData();
			}
			days %= 31;
		}
		day += days;
		break;
	case 2:
		if (this->year % 4 == 0)
		{
			if (days > 29)
			{
				x = days / 29;
				for (size_t i = 1; i <= x; i++)
				{
					addMonth(1);
					checkData();
				}
				days %= 29;
			}
			day += days;

		}

		else
		{
			if (days >28)
			{
				x = days / 28;
				for (size_t i = 1; i <= x; i++)
				{
					addMonth(1);
					checkData();
				}
				days %= 28;
			}
			day += days;
		}
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		if (days>30)
		{
			x = days / 30;
			for (size_t i = 1; i <= x; i++)
			{
				addMonth(1);
				checkData();
			}
			days %= 30;
		}
		day += days;
		break;
	}
	checkData();

}

Date & Date::operator++()
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
		day++;
		if (day >= 1 && day < 32)
		{

		}
		else {
			this->day = 1;
			month++;
			if (month >= 1 && month < 13)
			{

			}
			else {
				this->month = 1;
				year++;
			}
		}
		break;
	case 2:
		if (this->year % 4 == 0)
		{
			if (day >= 1 && day < 30)
			{

			}
			else {
				this->day = 1;
				month++;
				if (month >= 1 && month < 13)
				{

				}
				else {
					this->month = 1;
					year++;
				}
			}
		}
		else
		{
			if (day >= 1 && day < 29)
			{

			}
			else {
				this->day = 1;
				month++;
				if (month >= 1 && month < 13)
				{

				}
				else {
					this->month = 1;
					year++;
				}
			}
		}
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		day++;
		if (day >= 1 && day < 31)
		{

		}
		else {

			this->day = 1;
			month++;
			if (month >= 1 && month < 13)
			{

			}
			else {
				this->month = 1;
				year++;
			}
		}
		break;
	}
	return *this;
}


Date Date::operator++(int)
{
	Date tmp = *this;
	switch (this->month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		day++;
		if (day >= 1 && day < 32)
		{

		}
		else {
			this->day = 1;
			month++;
			if (month >= 1 && month < 13)
			{

			}
			else {
				this->month = 1;
				year++;
			}
		}
		break;
	case 2:
		if (this->year % 4 == 0)
		{
			if (day >= 1 && day < 30)
			{

			}
			else {
				this->day = 1;
				month++;
				if (month >= 1 && month < 13)
				{

				}
				else {
					this->month = 1;
					year++;
				}
			}
		}
		else
		{
			if (day >= 1 && day < 29)
			{

			}
			else {
				this->day = 1;
				month++;
				if (month >= 1 && month < 13)
				{

				}
				else {
					this->month = 1;
					year++;
				}
			}
		}
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		day++;
		if (day >= 1 && day < 31)
		{

		}
		else {

			this->day = 1;
			month++;
			if (month >= 1 && month < 13)
			{

			}
			else {
				this->month = 1;
				year++;
			}
		}
		break;
	}
	return tmp;
}

Date & Date::operator--()
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
		day--;
		if (day >= 1 && day < 32)
		{

		}
		else {
			this->day = 31;
			month--;
			if (month >= 1 && month < 13)
			{

			}
			else {
				this->month = 12;
				year--;
			}
		}
		break;
	case 2:
		if (this->year % 4 == 0)
		{
			if (day >= 1 && day < 30)
			{

			}
			else {
				this->day = 29;
				month--;
				if (month >= 1 && month < 13)
				{

				}
				else {
					this->month = 12;
					year--;
				}
			}
		}
		else
		{
			if (day >= 1 && day < 29)
			{

			}
			else {
				this->day = 28;
				month--;
				if (month >= 1 && month < 13)
				{

				}
				else {
					this->month = 12;
					year--;
				}
			}
		}
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		day++;
		if (day >= 1 && day < 31)
		{

		}
		else {

			this->day = 31;
			month--;
			if (month >= 1 && month < 13)
			{

			}
			else {
				this->month = 12;
				year--;
			}
		}
		break;
	}
	return *this;
}

Date Date::operator--(int)
{
	Date tmp = *this;

	switch (this->month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		day--;
		if (day >= 1 && day < 32)
		{

		}
		else {
			this->day = 31;
			month--;
			if (month >= 1 && month < 13)
			{

			}
			else {
				this->month = 12;
				year--;
			}
		}
		break;
	case 2:
		if (this->year % 4 == 0)
		{
			if (day >= 1 && day < 30)
			{

			}
			else {
				this->day = 29;
				month--;
				if (month >= 1 && month < 13)
				{

				}
				else {
					this->month = 12;
					year--;
				}
			}
		}
		else
		{
			if (day >= 1 && day < 29)
			{

			}
			else {
				this->day = 28;
				month--;
				if (month >= 1 && month < 13)
				{

				}
				else {
					this->month = 12;
					year--;
				}
			}
		}
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		day++;
		if (day >= 1 && day < 31)
		{

		}
		else {

			this->day = 31;
			month--;
			if (month >= 1 && month < 13)
			{

			}
			else {
				this->month = 12;
				year--;
			}
		}
		break;
	}
	return tmp;
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

bool operator==(const Date & a, const Date & b)
{
	if (a.getDay() == b.getDay() && a.getMonth() == b.getMonth() && a.getYear() == b.getYear())
	{
		return 1;
	}
	return 0;
}

bool operator!=(const Date & a, const Date & b)
{
	if (a.getDay() == b.getDay() && a.getMonth() == b.getMonth() && a.getYear() == b.getYear())
	{
		return 0;
	}
	return 1;
}

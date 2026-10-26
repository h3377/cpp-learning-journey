// #11 #4 Data From Day Order In a Year.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

bool isLeapYear(short Year)
{
	// if year is divisible by 4 AND not divisible by 100
	// OR if year is divisible by 400
	// then it is a leap year
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 ==
		0);
}
short DayOfWeekOrder(short Day, short Month, short Year)
{
	short a, y, m;
	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + (12 * a) - 2;
	// Gregorian:
	//0:sun, 1:Mon, 2:Tue...etc
	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m)
		/ 12)) % 7;
}

short NumberOfDaysInAMonth(short Month, short Year)
{
	if (Month < 1 || Month>12)
		return 0;
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) :
		days[Month - 1];
}


struct sDate
{
	short Day;
	short Month;
	short Year;

};
short NumberOfDaysFromTheBeginningOfYear(short Days, short Month, short Year)
{
	short totalDay = 0;

	for (int i = 1; i <= Month - 1; i++)
	{
		totalDay += NumberOfDaysInAMonth(i, Year);

	}
	totalDay += Days;

	return totalDay;
}

sDate DateAddDays(short Days, sDate Date)
{
	

	short RemainingDays = Days + NumberOfDaysFromTheBeginningOfYear(Date.Day,Date.Month,Date.Year);
	short MonthDay = 0;

	Date.Month = 1;

	while (true)
	{
		MonthDay = NumberOfDaysInAMonth(Date.Month, Date.Year);

		if (RemainingDays > MonthDay)
		{
			RemainingDays -= MonthDay;
			Date.Month++;
			if (Date.Month > 12)
			{
				Date.Month = 1;
				Date.Year++;
			}
		}
		else
		{
			Date.Day = RemainingDays;
			break;
		}
	}
	return Date;
}





short ReadDay()
{
	short Day;
	cout << "\nEnter a Day to check?";
	cin >> Day;
	return Day;
}
short ReadMonth()
{
	short Month;
	cout << "\nEnter a Month to check?";
	cin >> Month;
	return Month;
}
short ReadYear()
{
	short Year;
	cout << "\nEnter a Year to check?";
	cin >> Year;
	return Year;
}
sDate ReadFullDate()
{
	sDate Date;

	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();

	return Date;
}
int DaysToAdd()
{
	int AddDays;
	cout << "\nHow Many Days to Add ?";
	cin >> AddDays;
	return AddDays;

}
int main()
{
	sDate Data = ReadFullDate();
	short Days = DaysToAdd();

	Data = DateAddDays(Days, Data);
	cout << "\nDate After Adding [" << Days << "] Days is :";
	cout << Data.Day << "/" << Data.Month << "/" << Data.Year;

	system("pause>0");

	return 0;

}


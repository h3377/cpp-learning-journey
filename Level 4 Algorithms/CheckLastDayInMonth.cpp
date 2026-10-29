// #15 #4 check date by last month in year.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

struct sDate
{
	short Day;
	short Month;
	short Year;

};

bool isLeapYear(short Year)
{
	// if year is divisible by 4 AND not divisible by 100
	// OR if year is divisible by 400
	// then it is a leap year
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 ==
		0);
}

short NumberOfDaysInAMonth(short Month, short Year)
{
	if (Month < 1 || Month>12)
		return 0;
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) :
		days[Month - 1];
}

bool IsDateLastDayInMonth(sDate Date)
{
	return ((Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year)));
}
bool IsLastMonthInYear(short Month)
{
	return (Month == 12);
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
	cout << "Enter a Month to check?";
	cin >> Month;
	return Month;
}
short ReadYear()
{
	short Year;
	cout << "Enter a Year to check?";
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

int main()
{

	sDate Date1 = ReadFullDate();
	

	if (IsDateLastDayInMonth(Date1))

		cout << "\nYes,Day Is Last Day In Month";

	else

		cout << "\nNo,Day Is  Not Last Day In Month";

	if (IsLastMonthInYear(Date1.Month))

		cout << "\nYes,Month Is last Month In Year";
	else

		cout << "\nNo,Month iS Not Last Month In Year";


	system("pause>0");
	return 0;
	



	
}


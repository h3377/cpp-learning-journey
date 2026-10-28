// #13#4 Check  Date1 is less than date 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
using namespace std;


struct sDate
{
	short Day;
	short Month;
	short Year;

};

bool IsDateBeforeDate2(sDate Date1, sDate Date2)
{
	return (Date1.Year > Date2.Year) ? true : (Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false;	
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
	sDate Date2 = ReadFullDate();

	if (IsDateBeforeDate2(Date1, Date2))

		cout << "\nYes, Date1 is Less than Date2.";
	else
		cout << "\nNo, Date1 is NOT Less than Date2.";

	system("pause>0");
	return 0;
}



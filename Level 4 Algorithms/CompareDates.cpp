// #57 #4 compare Date Function.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

struct stDate
{
	short Year;
	short Month;
	short Day;
};

enum  enCompareDate1
{
	Before = -1, Equal = 0, After = 1
};
bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year ==
		Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month ==
			Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year == Date2.Year) ? ((Date1.Month ==Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false): false;
}
bool IsDate1AfterDate2(stDate Date1, stDate Date2)
{
	return (!IsDate1BeforeDate2(Date1, Date2) && (!IsDate1EqualDate2(Date1, Date2)));
}
enCompareDate1 CompareDates(stDate Date1, stDate Date2)
{
	if (IsDate1BeforeDate2(Date1, Date2))
		return enCompareDate1::Before;
	if (IsDate1EqualDate2(Date1, Date2))
		return enCompareDate1::Equal;
	
	return enCompareDate1::After;
}


short ReadDay()
{
	short Day;
	cout << "\nPlease enter a Day? ";
	cin >> Day;
	return Day;
}
short ReadMonth()
{
	short Month;
	cout << "Please enter a Month? ";
	cin >> Month;
	return Month;
}
short ReadYear()
{
	short Year;
	cout << "Please enter a Year? ";
	cin >> Year;
	return Year;
}
stDate ReadFullDate()
{
	stDate Date;
	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();
	return Date;
}


int main()
{
	cout << "\nEnter Date1:\n";
	stDate Date1 = ReadFullDate();
	cout << "\nEnter Date2:";
	stDate Date2 = ReadFullDate();
	

	cout << "\nCompare Result:" << CompareDates(Date1, Date2) << "\n";
		
	
	system("pause>0");
	return 0;

}


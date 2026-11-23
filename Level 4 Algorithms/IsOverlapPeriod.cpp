// #58 # 4 Is Overlap Period.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

struct stDate
{
	short Year;
	short Month;
	short Day;
};

struct  stPriod
{
	stDate startDate;
	stDate EndDate;
};

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year ==
		Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month ==
			Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}
bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
}
bool IsDate1AfterDate2(stDate Date1, stDate Date2)
{
	return (!IsDate1BeforeDate2(Date1, Date2) && (!IsDate1EqualDate2(Date1, Date2)));
}
enum  enCompareDate1
{
	Before = -1, Equal = 0, After = 1
};
enCompareDate1 CompareDates(stDate Date1, stDate Date2)
{
	if (IsDate1BeforeDate2(Date1, Date2))
		return enCompareDate1::Before;
	if (IsDate1EqualDate2(Date1, Date2))
		return enCompareDate1::Equal;

	return enCompareDate1::After;
}

bool IsOverlapPeriod(stPriod Period1, stPriod Period2)
{
	if (CompareDates( Period2.EndDate, Period1.startDate )== enCompareDate1::Before || (CompareDates(Period2.startDate, Period1.EndDate) == enCompareDate1::After))
	{
		return false;
	}

	return true;
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
stPriod ReadPeriod()
{
	stPriod Period;
	cout << "\nEnter start date:\n";
	Period.startDate = ReadFullDate();
	cout << "\nEnter end date:\n";
	Period.EndDate = ReadFullDate();
	return Period;
}

int main()
{
	cout << "\nEnter period 1:";
	
	stPriod Period1 = ReadPeriod();
	
	cout << "\nEnter period 2:";
	
	stPriod Period2 = ReadPeriod();

	
	if (IsOverlapPeriod(Period1, Period2))
		cout << "\nYes,Is Overlap period";

	else
		cout << "\nNo,It Is NOT overlap period";

	system("pause>0");
	return 0;

}

// #8#4Write a calendar by month.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>


using namespace std;

bool IsleapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}
short DayOfWeekOrder(short Day, short Month, short Year)
{
	short a, y, m;
	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + (12 * a) - 2;
	// Gregorian:
	//0:sun, 1:Mon, 2:Tue...etc
	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}
string MonthShortName(short MonthNumber)
{
	string Months[12] = { "Jan","Feb","Mar","Apr","May","June","July","Aug","Sep","Oct","Nov","Dec"};

	return (Months[MonthNumber - 1]);

}
string DayShortName(short DayOfTheWeek)
{
	string arrDayNames[7] = { "Sun","Mon","Tue","wed","Thu","Fri","Sat" };
	return arrDayNames[DayOfTheWeek];
}
short NumberOfDaysMonth(short Month,short Year)
{
	if (Month < 1 || Month >12)
		return 0;
	int Days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	return (Month == 2) ? (IsleapYear(Year)) ? 29 : 28 : Days[Month - 1];
	
}
void PrintMonthCalander(short Month, short Year)
{
	int NumberOfDay;
	int current = DayOfWeekOrder(1, Month, Year);

	NumberOfDay = NumberOfDaysMonth(Month, Year);


	printf("\-----------------------%s-----------------------\n\n",MonthShortName(Month).c_str());

	printf(" sun   Mon   Tue  Wed  Thu  Fri  Sat\n");

	int K;
	for (K = 0; K < current; K++)
		printf("    ");

	for (int j = 1; j <= NumberOfDay; j++)
	{
		printf("%5d", j);

		if (++K == 7)
		{
			K = 0;
			printf( "\n");
		}
	}
	printf("\n-------------------------------------------------\n");

}
short ReadMonth()
{
	short Month;
	cout << "\nPlease enter a Month? ";
	cin >> Month;
	return Month;
}

short ReadYear()
{
	short Year;
	cout << "\nPlease enter a year? ";
	cin >> Year;
	return Year;
}


int main()
{
	short Year = ReadYear();
	short Month = ReadMonth();

	PrintMonthCalander(Month, Year);

	system("pause>0");
	return 0;


}
    

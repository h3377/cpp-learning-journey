// # 20 to #32  problems Increasing Date.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


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
bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
{
	return  (Date1.Year < Date2.Year) ? true : ((Date1.Year ==
		Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month ==
			Date2.Month ? Date1.Day < Date2.Day : false)) : false);
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

sDate IncreaseDateByDayOne(sDate& date)
{

	if (IsDateLastDayInMonth(date))
	{
		if (IsLastMonthInYear(date.Month))

		{
			date.Day = 1;
			date.Month = 1;
			date.Year++;
		}
		else
		{
			date.Day = 1;
			date.Month++;
		}
	}
	else
	{
		date.Day++;

	}
	return date;

}

sDate IncreaseDateOneByXDay(sDate Date,short DaysToAdd)
{
	for (short i = 1; i <= DaysToAdd; i++)
	{
		Date = IncreaseDateByDayOne(Date);
	}
	return Date;
}

sDate IncreaseDateByOneWeek(sDate Date)
{
	for (short i = 1; i <= 7; i++)
	{
		Date = IncreaseDateByDayOne(Date);
	}
	return Date;
}

sDate IncreasDateByXWeek(sDate Date,short week)
{
	for (short i = 0; i < week; i++)
	{
		Date = IncreaseDateByOneWeek(Date);
	}
	return Date;
}

sDate IncreaseDateByOneMonth(sDate& Date)
{
	if (Date.Month == 12)
	{
		Date.Month = 1;
		Date.Year++;

	}
	else
	{
		Date.Month++;
	}

	//last check day in date should not exceed max days in thecurrent month
		// example if date is 31/1/2022 increasing one month should not  be 31 / 2 / 2022, it should
		// be 28/2/2022
		short NumberOfDaysInCurrentMonth =
		NumberOfDaysInAMonth(Date.Month, Date.Year);
	if (Date.Day > NumberOfDaysInCurrentMonth)
	{
		Date.Day = NumberOfDaysInCurrentMonth;
	}
	return Date;
}


sDate IncreaseDateByxMonth(sDate& Date, short MonthToAdd)
{
	for (short i = 1; i <= MonthToAdd; i++)
	{
		Date = IncreaseDateByOneMonth(Date);
	}
	return Date;
}

sDate IncreaseDateByOneYear(sDate& Date)
{
	Date.Year++;
	return Date;
}

sDate IncreaseDateByXYear(sDate& Date, short AddYear)
{
	for (short i = 1; i <= AddYear; i++)
	{
		Date = IncreaseDateByOneYear(Date);
	}
	return Date;
}

sDate IncreaseDateByXYearFaster(sDate& Date, short AddYear)
{
	Date.Year += AddYear;

	return Date;

	
}


sDate IncreaseDateByDecade(sDate& Date)
{
	Date.Year += 10;
	return Date;
}

sDate IncreaseDateByXDecade(sDate& Date,short AddDecade)
{
	for (short i = 1; i <= AddDecade * 10; i++)
	{
		Date = IncreaseDateByDecade(Date);
	}
	return Date;
}
sDate IncreaseDateByXDecadeFaster(sDate& Date, short AddDecade)
{
	Date.Year += AddDecade * 10;
	return Date;
}

sDate IncreaseDateByOneCentury(sDate& Date)
{
	Date.Year += 100;
	return Date;
}

sDate IncreaseDateByOneMillennium(sDate& Date)
{
	Date.Year += 1000;
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


sDate ReadFullDateAdded()
{
	sDate AddDate;

	AddDate.Day = ReadDay();
	AddDate.Month = ReadMonth();
	AddDate.Year = ReadYear();

	return AddDate;
}
int main()
{
	sDate Date1 = ReadFullDate();



	printf("\nDays After");

	Date1 = IncreaseDateByDayOne(Date1);

	cout << "\n01-Adding one day is :"
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateOneByXDay(Date1,10);

	cout << "\n02-Adding 10 days is :"
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByOneWeek(Date1);

	cout << "\n03-Adding one week is :"
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreasDateByXWeek(Date1,10);

	cout << "\n04-Adding 10 weeks  is :"
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByOneYear(Date1);

	cout << "\n05-Adding one year is :"
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByXYear(Date1,10);

	cout << "\n06-Adding 10 years is :"
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByXYearFaster(Date1,10);

	cout << "\n07-Adding 10 years faster is :"
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByDecade(Date1);

	cout << "\n08-Adding one decade is :"
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByXDecade(Date1,10);

	cout << "\n09-Adding 10 decades is :"
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByXDecadeFaster(Date1,10);

	cout << "\n10-Adding 10 decades is :"
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByOneCentury(Date1);

	cout << "\n11-Adding one century is :"
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByOneMillennium(Date1);

	cout << "\n12-Adding one Millennium is :"
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;


	system("pause>0");

	return 0;

}

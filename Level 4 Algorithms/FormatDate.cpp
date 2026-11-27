// #65 #4 FromatDate.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>


using namespace std;
struct stDate
{
	short Year;
	short Month;
	short Day;
};
vector<string> SplitString(string S1, string Delim)
{
	vector<string> vString;
	short pos = 0;
	string sWord; // define a string variable
	// use find() function to get the position of the delimiters
	while ((pos = S1.find(Delim)) != std::string::npos)
	{
		sWord = S1.substr(0, pos); // store the word
		if (sWord != "")
		{
			vString.push_back(sWord);
		}
		S1.erase(0, pos + Delim.length());
	}
	if (S1 != "")
	{
		vString.push_back(S1); // it adds last word of the string.
	}
	return vString;
}
string ReversWordInString(string s1)
{
	vector<string> vString;
	string s2 = "";

	vString = SplitString(s1, " ");

	vector<string>::iterator iter = vString.end();

	while (iter != vString.begin())
	{
		--iter;
		s2 += *iter + " ";
	}


	s2 = s2.substr(0, s2.length() - 1);

	return s2;
}
string DateToString(stDate Date)
{
	return to_string(Date.Day) + "/" + to_string(Date.Month) +
		"/" + to_string(Date.Year);
}
stDate StringToDate(string DateString)
{
	stDate Date;
	vector <string> vDate;
	vDate = SplitString(DateString, "/");

	Date.Day = stoi(vDate[0]);
	Date.Month = stoi(vDate[1]);
	Date.Year = stoi(vDate[2]);
	return Date;
}
string ReplaceWordInString(string S1, string StringToReplace,string sRepalceTo)
{
	short pos = S1.find(StringToReplace);
	while (pos != std::string::npos)
	{
		S1 = S1.replace(pos, StringToReplace.length(),sRepalceTo);
		pos = S1.find(StringToReplace);//find next
	}
	return S1;
}
string FormattedDate(stDate Date, string FormatDate = "dd/mm/yyyy")
{
	string FormattedDateToString = FormatDate;

	FormattedDateToString = ReplaceWordInString(FormattedDateToString, "dd", to_string(Date.Day));
	FormattedDateToString = ReplaceWordInString(FormattedDateToString, "mm", to_string(Date.Month));
	FormattedDateToString = ReplaceWordInString(FormattedDateToString, "yyyy", to_string(Date.Year));

	return FormattedDateToString;
}
string ReadStringDate(string Message)
{
	string DateString;
	cout << Message;
	getline(cin >> ws, DateString);
	return DateString;
}
int main()
{
	
	string DateString = ReadStringDate("\nPlease Enter Date	dd / mm / yyyy ? ");
	

	stDate Date = StringToDate(DateString);
	
	cout << "\n" << FormattedDate(Date) << endl;

	cout << "\n" << FormattedDate(Date, "yyyy/dd/mm") << endl;

	cout << "\n" << FormattedDate(Date, "mm/dd/yyyy") << endl;

	cout << "\n" << FormattedDate(Date, "mm-dd-yyyy") << endl;

	cout << "\n" << FormattedDate(Date, "dd-mm-yyyy") << endl;
	
	cout << "\n" << FormattedDate(Date, "Day: dd, Month: mm, Year: yyyy");
	system("pause>0");
	return 0;
}

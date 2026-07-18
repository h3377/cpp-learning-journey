// #25 II 3 Lowercase.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

string ReadString()
{
	string s1;
	cout << "please enter your string \n";
	getline(cin, s1);
	return s1;
}

string Lowercase(string s1)
{
	bool IsLowercase = true;

	for (short i = 0; i < s1.length(); i++)
	{
		if (s1[i] != ' ' && IsLowercase)
		{
			s1[i] = tolower(s1[i]);
		}
		IsLowercase = (s1[i] == ' ' ? true : false);
	}
	return s1;
}

int main()
{
	string s1 = ReadString();
	cout << "\nstring after conversion\n";

	s1 = Lowercase(s1);
	cout << s1 << endl;

	system("pause>0");
}



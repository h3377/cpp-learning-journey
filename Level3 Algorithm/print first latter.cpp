// #23 II 3 print first  latter of each word.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

string Readstring()
{
	string s1;
	cout << "Print your string?\n\n";
	getline(cin, s1);
	return s1;
}
void PrintFirstLatter(string s1)
{
	bool IsfirstLatter = true;

	cout << "\nFirst letters of this string: \n";

	for (short i = 0; i < s1.length(); i++)
	{
		if (s1[i] != ' ' && IsfirstLatter)
		{
			cout << s1[i] << endl;
		}
		IsfirstLatter = (s1[i] == ' ' ? true : false);
	}
}

int main()
{
	PrintFirstLatter(Readstring());

	system("pause>0");

}

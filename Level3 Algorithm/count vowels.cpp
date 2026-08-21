// #33  II  3  count vowels.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>

using namespace std;

string ReadString()
{
	string s1;
	cout << "Please enter your string?\n";
	getline(cin, s1);
	return s1;
}
bool IsVolwe(char ch1)
{
	ch1 = tolower(ch1);

	return ((ch1 == 'a') || (ch1 == 'e') || (ch1 == 'i') || (ch1 == 'o') || (ch1 == 'u'));

}
short countvowels(string s1)
{
	
	short count = 0;
	

	for (short i = 0; i < s1.length(); i++)
	{
		if (IsVolwe(s1[i]))
		{
			
			count++;
			
		}
	}
	return count;


}

int main()
{
	string s1 = ReadString();
	
	
	cout << "\nNumber of vowels is : " << countvowels(s1) << endl;
	system("pause>0");
}


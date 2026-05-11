// #50 string object (common methods).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s1 = ("My name is Hamza Al-Maqtari, I love programming");

	//print the length of the string
	cout << s1.length() << endl;

	//returns the leeter at 3 postion
	cout << s1.at(3) << endl;
	
	//Adds @programing advice to the string
	s1.append("@Programming Advice");
	cout<< s1 << endl;

	//inserts Ali at postion 7
	s1.insert(15, "Ali");
	cout << s1 << endl;

	//Add on character to the end of the string
	s1.push_back('X');
	cout << s1 << endl;

	//Removes one character to the end of the string
	s1.pop_back();
	cout << s1 << endl;

	//prints all next  8 letter from postion 8
	cout << s1.substr(18, 8) << endl;

	//finds Ali in the string
	cout << s1.find("Ali") << endl;

	//finds ali in the string
	cout << s1.find("ali") << endl;

	
	if (s1.find("ali") == s1.npos)
	{
		cout << "ali not found";
	}

	s1.clear();
	cout << s1 << endl;

	return 0;


}


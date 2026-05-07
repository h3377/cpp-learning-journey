// #48 vector Iterators.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;


int main()
{
	vector<int> num = { 1,2,3,4,5 };

	//declare iterator
	vector<int>::iterator iter;

	//use iterator with for loop

	for (iter = num.begin(); iter != num.end(); iter++)

	{
		cout << *iter << " ";
	}
	return 0;

}


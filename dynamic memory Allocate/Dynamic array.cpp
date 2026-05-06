// #44 Dynamic arrays new and delete.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
	int num;
	cout << "enter total number of students: ";
	cin >> num;

	float* ptr;

	ptr= new float[num];

	cout << "enter grades of students." << endl;

	for (int i = 0; i < num; i++)
	{
		cout << "student" << i + 1;
		cin >> *(ptr + i);


	}

	cout << "\nDisplaying grades of students. " << endl;

	for (int i = 0; i < num; i++)
	{
		cout << "student" << i + 1 << ": " << *(ptr + i) << endl;
	}

  //ptr memory is released
	delete[] ptr;

	return 0;

}


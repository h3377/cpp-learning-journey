// #53 Append mode data to file.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

using namespace std;


int main()
{
    fstream MyFile;

    MyFile.open("MyFile.txt", ios::out | ios::app);

    if (MyFile.is_open())
    {
        MyFile << "Hi,This is the first line\n";
        MyFile << "Hi,This is the second file\n"; 

        MyFile.close();
    }

    return 0;
}


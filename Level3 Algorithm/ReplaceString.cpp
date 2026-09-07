// #42 II 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include <vector>

using namespace std;

string ReplaceWordInStringUsingBuiltInFunction(string S1, string StringToReplace, string sRepalceTo)
{
    short pos = S1.find(StringToReplace);
    while (pos != std::string::npos)
    {
        S1 = S1.replace(pos, StringToReplace.length(),sRepalceTo);
        pos = S1.find(StringToReplace);//find next
    }
    return S1;
}

int main()
{
    string s1 = "\nWELCOME TO QATAR,QATAR IS BEAUTAFULL COUNTRY\n";
    string StringToReplace = "QATAR";
    string stringReplaceTo = "YEMAN";

    cout << "\nOrginal string\n" << s1;
    cout << "\nstring after replace: ";
    cout << "\n" << ReplaceWordInStringUsingBuiltInFunction(s1,StringToReplace,stringReplaceTo);
   

    system("pause>0");
}

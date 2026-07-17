// #24 upper first latter of each word.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include<cstdio>

using namespace std;

string ReadString()
{
    string s1;
    cout << "print first upper latter\n";
    getline(cin, s1);
    return s1;

}   
string PrintFirstLatter(string s1)
{ 
    bool IsFirstUpperLatter = true;
    

    for (short i = 0; i < s1.length(); i++)
    {
        if (s1[i] != ' ' && IsFirstUpperLatter)
        {
            s1[i] = toupper(s1[i]); 
        }
        IsFirstUpperLatter = (s1[i] == ' ' ? true : false);
    }
    return s1;

        
            
}
		


int main()
{
    string s1 = ReadString();
    cout << "\nstring after conversion\n";

    s1 = PrintFirstLatter(s1);
    cout << s1 << endl;

	system("pause>0");
}


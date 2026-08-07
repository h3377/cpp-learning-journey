// #28 II 3 Invert All Letter in case.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>

using namespace std;

string ReadString()
{
    string Name;
    cout << "Please enter your string:\n";
    getline(cin, Name);
    return Name;
}
char InvertCharacterLatter(char ch1)
{
    return isupper(ch1) ? towlower(ch1) : towupper(ch1);

}
string InvertAllLatterInCase(string S1)
{
    for (short i = 0; i < S1.length(); i++)
    {
        S1[i] = InvertCharacterLatter(S1[i]);
    }
    return S1;
}

int main()
{
    string Name = ReadString();
    cout << "\nstring after inverting case:\n";
   Name= InvertAllLatterInCase(Name);
    cout << Name << endl;

    system("pause>0");
}


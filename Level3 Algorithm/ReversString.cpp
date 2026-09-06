// #42 II 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include <vector>

using namespace std;

string ReadString()
{
    string s1;
    cout << "please enter your string\n";
    getline(cin, s1);
    return s1;
}
vector<string>SpiletString(string s1, string delim)
{
    vector<string> vString;
    short pos = 0;
    string sWord;

    while ((pos = s1.find(delim)) != std::string::npos)
    {
        sWord = s1.substr(0, pos);
        if (sWord != "")
        {
            vString.push_back(sWord);

        }
        s1.erase(0, pos + delim.length());
    }
    if (s1 != "")
    {
        vString.push_back(s1);
    }
    return vString;
}
string ReversString(string s1)
{
    vector<string> vString;
    string s2 = " ";

    vString = SpiletString(s1, " ");

    vector<string>::iterator iter = vString.end();

    while (iter != vString.begin())
    {
        --iter;
        s2 += *iter + " ";
    }
    s2 = s2.substr(0, s2.length() - 1);

    return s2;
}

int main()
{
    string s1 = ReadString();

    cout << "\nstring After reversing\n";
    cout << "\n" << ReversString(s1);

    system("pause>0");
}

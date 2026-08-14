// #29 II 3 count small later and capital latter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>

using namespace std;

string ReadString()
{
    string s1;
    cout << "print your string:\n";
    getline(cin, s1);
    return s1;

}
enum enWhatToCount { SmallLatter = 0, Capitallatter = 1, All = 3 };

short CountLatters(string s1, enWhatToCount WhatToCount = enWhatToCount::All)
{
    short count = 0;

    for (short i = 0; i < s1.length(); i++)
    {
        if (WhatToCount = enWhatToCount::All)
        {
            return s1.length();
        }
        short counter = 0;
        for (short i = 0; i < s1.length(); i++)
        {
            if (WhatToCount == enWhatToCount::Capitallatter && isupper(s1[i]))
                counter++;
            if (WhatToCount == enWhatToCount::SmallLatter && islower(s1[i]))
                counter++;
        }
        return counter;
    }
}

short countCaptaillatter(string s1)
{
    short count = 0;
    for (short i = 0; i < s1.length(); i++)
    {
        if (isupper(s1[i]))
        {
            count++;
        }
    }
    return count;

}
short countsmallllatter(string s1)
{
    short count = 0;
    for (short i = 0; i < s1.length(); i++)
    {
        
        if (islower(s1[i]))
        {
            count++;
        }
    }
    return count;

}


int main()
{

    string name = ReadString();
    cout << "\nstring Length = " << name.length();
    cout << "\nCapatial Latter count = " << countCaptaillatter(name);
    cout << "\nSmall Latter count =" << countsmallllatter(name);

    cout << "\n\nMethod2\n";

    cout << "\nstring Length =" << CountLatters(name);

    cout << "\ncapatil latter =" << CountLatters(name, enWhatToCount::Capitallatter);
    
    cout << "\nsmall latter =" << CountLatters(name,enWhatToCount::SmallLatter);
    

    system("pause<0");
    
}


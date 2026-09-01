// #38 II 3 string trim right and left.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>


using namespace std;

string TrimLeft(string s1)
{
   
    for (short i = 0; s1.length(); i++)
    {
        if (s1[i] != ' ')
        {
            return s1.substr(i, s1.length() - i);
        }
        
    }
    return "";
   
}
string TrimRight(string s1)
{


    for (short i =s1.length();i >= 0; i--)
    {
        if (s1[i] != ' ')
        {
            return s1.substr(0,i + 1);
       }

    }
    return "";
}

string Trim(string s1)
{
    return TrimLeft(TrimRight(s1));
}

int main()
{
    string s1 = "    Hamzah abdulrhman   ";

    cout << "\nString      =" << s1;
    cout << "\nTrim left   =" << TrimLeft(s1);
    cout << "\nTrim Right  =" << TrimRight(s1);
    cout << "\nTrim        =" << Trim(s1);

    system("pause>0");
    
}

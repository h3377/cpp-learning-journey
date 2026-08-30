// #36 count each word in string.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

string ReadString()
{
    string s1;
    cout << "please enter your string\n";
    getline(cin, s1);

    return s1;
}
short CountString(string s1)
{
    string delim = " ";
  
    short pos = 0;
    short count = 0;
    string sWord;
   
    while ((pos = s1.find(delim)) != std::string::npos)
    {
        sWord = s1.substr(0, pos);
        if (sWord != "")
        {
            count++;
            
        }
        s1.erase(0, pos + delim.length());
    }

    if (s1 != "")
    {
        count++;
       
    }
    return count;

}
int main()
{
    string s1 = ReadString();

    cout << "The Number of words in your string is: ";
    cout << CountString(s1);
    


    system("Pause>0");
}


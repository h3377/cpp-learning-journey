// #37  II 3 split string.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<vector>

using namespace std;

string ReadString()
{
    string s1;
    cout << "Please enter your string:\n";
    getline(cin, s1);
    return s1;

}
vector <string> StringSplit(string S1, string delim)
{
    vector<string> vString;
    short Pos = 0;
    string sWord;

    while ((Pos = S1.find(delim)) != std::string::npos)
    {
        sWord = S1.substr(0, Pos);
        if (sWord != "")
        {
            vString.push_back(sWord);
        }
        S1.erase(0, Pos + delim.length());
    }

    if (S1 != "")
    {
        vString.push_back(S1);
    }
    return vString;
}

int main()
{
    vector<string> vString;

    vString = StringSplit(ReadString()," ");

    cout << "\nTokens =" << vString.size() << endl;

    for (string& s : vString)
    {
        cout << s << endl;
    }
    system("pause>0");
}


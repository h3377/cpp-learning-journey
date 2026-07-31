

#include <iostream>
#include <string>

using namespace std;

string ReadString()
{
    string s1;
    cout << "Please Enter Your String?\n";
    getline(cin, s1);
    return s1;
}
string UpperLatter(string s1)
{
    for (short i = 0; i < s1.length(); i++)
    {
        s1[i] = toupper(s1[i]);
    }

    return s1;        
}
string LowerLatter(string s1)
{
    for (short i = 0; i < s1.length(); i++)
    {
        s1[i] = tolower(s1[i]);
    }
    return s1;
}
int main()
{
    string s1=ReadString();
    cout << "\nstring after upper:\n";
    s1 = UpperLatter(s1);
    cout << s1 << endl;

    cout << "\n string after lower:\n";
    s1 = LowerLatter(s1);
    cout << s1 << endl;

    system("pause>0");
}


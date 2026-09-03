// #40 II 3 Joint string (Overloading).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<vector>

using namespace std;

string JointString(vector<string>& vString, string delim)
{
    string s1 = "";

    for (string& s : vString)
    {
        s1 = s1 + s + delim;
    }
    return s1.substr(0, s1.length() - delim.length());
}
string JointString(string arr[], short length, string delim)
{
    string s1 = "";

    for (short i = 0; i<length; i++)
    {
        s1 = s1 + arr[i] + delim;
    }
    return s1.substr(0, s1.length() - delim.length());
}

int main()
{
    vector<string> vString = { "Hamza","Abdulrahman","Abood","Faris","sara","Halima","khalid","Housam","Marques","fermin" };
    string arr[] = {"Hamza","Abdulrahman","Abood","Faris","sara","Halima","khalid","Housam","Marques","fermin"};
    

    string JointStringOverloadingB = JointString(vString, " , ");
    cout << "\n Joint string Before overloading\n";
    cout << JointStringOverloadingB << endl;


    string JointStringOverloadingA = JointString(arr, 4, " , ");
    cout << " Joint string After overloading\n";
    cout << JointStringOverloadingA << endl;

    system("pause>0");
}


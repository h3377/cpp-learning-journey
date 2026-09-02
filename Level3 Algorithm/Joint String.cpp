// #39 II 3 Join string.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<vector>

using namespace std;


string StringJoint(vector<string> vString, string delim)
{
    string  S1= "";
    
   
        for (string& s : vString)
        {
            S1 = S1 + s + delim;
        }

        return S1.substr(0, S1.length() - delim.length());
}

int main()
{
    vector<string> vString = { "Hamza" ,"sad", "abdulrhma","Faris","Aboody"};

    string JointString = StringJoint(vString,"\n");

    cout << "\nVector elemnts After joining\n";
    cout << JointString << endl;


   
    system("pause>0");
}


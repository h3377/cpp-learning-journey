// #51 CCType Functions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cctype>

using namespace std;


int main()
{
    char x = 'a';
    char w = 'A';

    x = toupper('a');
    w = tolower('A');



    cout << "convert a to A:" << x << endl;
    cout << "convert A to a:" << w << endl;

    //Digits A to Z
    //return zero if not and non zero of yes
    cout << "Isupper('A')" << isupper('A') << endl;

    //lower case (a to z)
    //return zero if not and non zero of yes
    cout << "Islower('a')" << islower('a') << endl;

    //Digits (0 to 9)
    //return zero if not and non zero of yes
    cout << "isdigit('A') " << isdigit('A') << endl;

    // punctuation characters are !"#$%&'()*+,-./:;<=>?@[\]^_`{|}~
    // returns zero if not, and non zero of yes
    cout << "ispunct('A')" << ispunct('A') << endl;


    return 0;

}


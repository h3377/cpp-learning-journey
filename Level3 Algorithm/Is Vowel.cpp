// #32 is vowel.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>

using namespace std;

char Readchar()
{
    char ch1;
    cout << "Please enter your char\n";
    cin >> ch1;
    return ch1;
}

bool IsVolwe(char ch1)
{
    ch1 = towlower(ch1);

    return ((ch1 == 'a') || (ch1 == 'e') || (ch1 == 'i') || (ch1 == 'o') || (ch1 == 'u'));
    
}
int main()
{
    char ch1 = Readchar();

    if (IsVolwe(ch1))
    
        cout << "\nyes,Latter \'" << ch1 << "\' Is volwe";
    
    else
    
        cout << "\nNo,Latter \'" << ch1 << "\'  is Not volwe";
    

    system("pause>0");
    
   
}

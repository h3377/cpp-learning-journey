// 21 Fibonacci series.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<iomanip>


using namespace std;

void FiboncciSeries(short number)
{
    int febNumber = 0;
    int Prev1 = 1, Prev2 = 0;
    cout << "1   ";
  

    
         
    for (short i  = 2; i <= number; ++i)
    {
        febNumber = Prev1 + Prev2;
        cout << febNumber << "    ";
        Prev2 = Prev1;
        Prev1 = febNumber;


    }
 
   
    
}
int main()
{
    

   FiboncciSeries(10);

    system("pause>0");
}


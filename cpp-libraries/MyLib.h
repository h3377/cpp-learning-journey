#pragma once

#include <iostream>
using namespace std;

namespace Mylib
{
    void Test()
    {
        cout << "Hi, this is my first function in my first library!" << endl;
    }

    int sum2Numbers(int Num1, int Num2)
    {
        return Num1 + Num2;
    }
}

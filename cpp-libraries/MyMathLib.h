#pragma once

#include <iostream>
using namespace std;

namespace MyMathLib
{
    int Power(int base, int exponent)
    {
        int result = 1;
        for (int i = 0; i < exponent; i++)
        {
            result = result * base;
        }
        return result;
    }

    int Abs(int number)
    {
        if (number < 0)
            return -number;
        return number;
    }

    int Max(int a, int b)
    {
        return (a > b) ? a : b;
    }

    int Min(int a, int b)
    {
        return (a < b) ? a : b;
    }
}

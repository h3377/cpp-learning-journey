#pragma once

#include <iostream>
using namespace std;

namespace MyValidationLib
{
    bool IsPrime(int number)
    {
        if (number <= 1) return false;
        for (int i = 2; i <= number / 2; i++)
        {
            if (number % i == 0) return false;
        }
        return true;
    }

    bool IsPerfectNumber(int number)
    {
        int sum = 0;
        for (int i = 1; i < number; i++)
        {
            if (number % i == 0) sum += i;
        }
        return (sum == number);
    }

    bool IsPalindromeNumber(int number)
    {
        int original = number;
        int reversed = 0;
        
        while (number > 0)
        {
            int digit = number % 10;
            reversed = reversed * 10 + digit;
            number = number / 10;
        }
        
        return (original == reversed);
    }
}

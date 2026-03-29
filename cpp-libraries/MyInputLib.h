#pragma once

#include <iostream>
#include <string>
using namespace std;

namespace MyInputLib
{
    int ReadNumber(string message = "Please enter a number? ")
    {
        int Number;
        cout << message;
        cin >> Number;
        return Number;
    }

    int ReadPositiveNumber(string message = "Enter positive number? ")
    {
        int Number;
        do {
            cout << message;
            cin >> Number;
        } while (Number <= 0);
        return Number;
    }

    int ReadNumberInRange(int min, int max, string message = "Enter number? ")
    {
        int Number;
        do {
            cout << message << " (" << min << "-" << max << "): ";
            cin >> Number;
        } while (Number < min || Number > max);
        return Number;
    }

    double ReadDouble(string message = "Enter decimal number? ")
    {
        double Number;
        cout << message;
        cin >> Number;
        return Number;
    }
}

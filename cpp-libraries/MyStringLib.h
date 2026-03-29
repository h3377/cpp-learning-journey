#pragma once

#include <iostream>
#include <string>
using namespace std;

namespace MyStringLib
{
    string ReverseString(string text)
    {
        string reversed = "";
        for (int i = text.length() - 1; i >= 0; i--)
        {
            reversed += text[i];
        }
        return reversed;
    }

    int CountVowels(string text)
    {
        int count = 0;
        for (int i = 0; i < text.length(); i++)
        {
            char c = tolower(text[i]);
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                count++;
        }
        return count;
    }

    string ToUpper(string text)
    {
        string result = "";
        for (int i = 0; i < text.length(); i++)
        {
            result += toupper(text[i]);
        }
        return result;
    }
}

#include <iostream>
#include "MyLib.h"
#include "MyInputLib.h"
#include "MyMathLib.h"
#include "MyGeometryLib.h"
#include "MyStringLib.h"
#include "MyValidationLib.h"

using namespace std;

int main()
{
    cout << "=== My C++ Libraries Demo ===" << endl << endl;

    // MyLib test
    Mylib::Test();
    cout << "Sum: " << Mylib::sum2Numbers(10, 20) << endl << endl;

    // MyMathLib test
    cout << "=== Math Library ===" << endl;
    int base = MyInputLib::ReadNumber("Enter base for power: ");
    int exp = MyInputLib::ReadNumber("Enter exponent: ");
    cout << base << "^" << exp << " = " << MyMathLib::Power(base, exp) << endl;
    cout << "Max of 15 and 8: " << MyMathLib::Max(15, 8) << endl << endl;

    // MyGeometryLib test
    cout << "=== Geometry Library ===" << endl;
    double radius = MyInputLib::ReadDouble("Enter circle radius: ");
    cout << "Circle Area = " << MyGeometryLib::CircleArea(radius) << endl << endl;

    // MyStringLib test
    cout << "=== String Library ===" << endl;
    string name = "Hamza";
    cout << "Original: " << name << endl;
    cout << "Reversed: " << MyStringLib::ReverseString(name) << endl;
    cout << "To Upper: " << MyStringLib::ToUpper(name) << endl;
    cout << "Vowels in 'Hello World': " << MyStringLib::CountVowels("Hello World") << endl << endl;

    // MyValidationLib test
    cout << "=== Validation Library ===" << endl;
    int num = MyInputLib::ReadPositiveNumber("Enter number to check: ");
    cout << "Is Prime? " << (MyValidationLib::IsPrime(num) ? "Yes" : "No") << endl;
    cout << "Is Perfect? " << (MyValidationLib::IsPerfectNumber(num) ? "Yes" : "No") << endl;
    cout << "Is Palindrome? " << (MyValidationLib::IsPalindromeNumber(num) ? "Yes" : "No") << endl;

    return 0;
}

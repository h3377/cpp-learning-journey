
#include <iostream>

using namespace std;

int ReadNumber()
{
    int Number;
    cout << "Enter a Valid Number?" << endl;
    cin >> Number;

    while (cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits <std::streamsize > ::max(), '\n');

        cout << "Invalid Number,Enter a Valid one:" << endl;

        cin >> Number;
    }
    return Number;
}

int main()
{
    cout << "Your number is:" << ReadNumber();

}

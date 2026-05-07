// #47 change elements (vectors part II).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> num = { 1,2,3,4,5 };

    cout << "Initial vector:";

    for (const int& i : num)
    {
        cout << i << " ";
    }

    cout << "\n\nUpdated vector:";

    for (int& i : num)
    {
        i = 30;
        cout << i << " ";
    }

    num[1] = 20;
    num.at(2) = 40;
    num.at(4) = 90;
    num.at(3) = 77;

    cout << "\n\nUpdate Vectors";
    for (const int& i : num)
    {
        cout << i << " ";
    }
    return 0;
}


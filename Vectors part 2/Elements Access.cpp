// #46  Access Elements (Vectors part II).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;


int main()
{
    vector <int> num = { 1,2,3,4,5 };

    cout << "\n using at.(i) \n";
    cout << "Element at index 0" << num.at(0) << endl;
    cout << "Elements at index 2" << num.at(2) << endl;
    cout << "Elements at index 4" << num.at(4) << endl;

    cout << "\n using [i] \n";

    cout << "Elements at index 0" << num[0] << endl;
    cout << "Elments at index 2" << num[2] << endl;
    cout << "Elements at index 4" << num[4] << endl;

    return 0;
}


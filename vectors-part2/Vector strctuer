// #30 Vector of structer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

struct stEmployee
{
    string firstName;
    string LastName;
    float salary;
};

int main()
{
    vector <stEmployee> vEmployees;

    stEmployee tempEmployee;

    tempEmployee.firstName = "Mohammad";
    tempEmployee.LastName = "Abo-Hahdoud";
    tempEmployee.salary = 300;

    vEmployees.push_back(tempEmployee);

    tempEmployee.firstName = "Hamza";
    tempEmployee.LastName = "Al-Maqtari";
    tempEmployee.salary = 1000;

    vEmployees.push_back(tempEmployee);

    tempEmployee.firstName = "Sara";
    tempEmployee.LastName = " Al-Maqtari";
    tempEmployee.salary = 50;

    vEmployees.push_back(tempEmployee);
    
    cout << "Employee Vector: \n\n";
    for (stEmployee& Employee : vEmployees)
    {
        cout << "First Name:" << Employee.firstName << endl;
        cout << "Last Name :" << Employee.LastName << endl;
        cout << "salary    :" << Employee.salary << endl;

        cout << endl;
    }
    cout << endl;

    return 0;
}


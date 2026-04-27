// #30 Hw vector of strctuer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

struct stEmployee
{
    string FirstName;
    string LastName;
    float Salary;

};

void ReadEmployeeVector(vector<stEmployee> &vEmployee)
{
    char Addmore = 'Y';
    stEmployee Employee;
   


    while (Addmore == 'Y' || Addmore == 'y')
    {
        cout << "Enter Your first Name :";
        cin >> Employee.FirstName;

        cout << "Enter Your Last Name :";
        cin >> Employee.LastName;

        cout << "Enter your salary: ";
        cin >> Employee.Salary;

        vEmployee.push_back(Employee);

        cout << "\nDo you want to add more Elements? Y/N\n";
        cin >> Addmore;
    }
    cout << endl;
}

void PrintStrcuterVector(vector<stEmployee> &vEmployee)
{
    cout << "Vector Elements : \n";

    for (stEmployee &Employee : vEmployee)
    {
        cout << "First Name :"  << Employee.FirstName << endl;
        cout << "Last Name  :" <<Employee.LastName <<endl;
        cout << "Salary     :" << Employee.Salary<< endl;
        cout << endl;
    }
    cout << endl;
}

int main()
{
    vector<stEmployee> vEmployee;
    ReadEmployeeVector(vEmployee);
    PrintStrcuterVector(vEmployee);

    return 0;
}


// #47 II 3 Add Clint to file.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

const string ClientsFileName = "Clients.txt";

struct Sclint
{
    string AcountNumber;
    string pinCode;
    string Name;
    string phone;
    double AccountBalance;
};

Sclint ReadClintDataRecord()
{
    Sclint Clint;

    cout << "\nEnter Acount Number?\n";
    getline(cin >> ws, Clint.AcountNumber);

    cout << "\nEnter PinCode?\n";
    getline(cin, Clint.pinCode);

    cout << "Enter Name?\n";
    getline(cin, Clint.Name);

    cout << "\nEnter phone?\n";
    getline(cin, Clint.phone);

    cout << "\nEnter AccountBalance?\n";
    cin >> Clint.AccountBalance;

    return Clint;
}
string ConverRecordToLine(Sclint Clint, string Seperator = "#//#")
{
    string stClientRecord = "";

    stClientRecord += Clint.AcountNumber + Seperator;
    stClientRecord += Clint.pinCode + Seperator;
    stClientRecord += Clint.Name + Seperator;
    stClientRecord += Clint.phone + Seperator;
    stClientRecord += to_string(Clint.AccountBalance);

    return stClientRecord;
}

void MyFileClient(string client,string stData)
{
    fstream  MyClientF;

    MyClientF.open(client, ios::out |ios::app);
    {
        if (MyClientF.is_open())
        {
            MyClientF << stData << endl;

            MyClientF.close();

        }
    }
}    
void AddNewClint() 
{
    Sclint Clint;
    Clint = ReadClintDataRecord();
    MyFileClient(ClientsFileName,ConverRecordToLine(Clint));      
}

void AddClient()
{
    char AddMore = 'Y';

    do
    {
        system("cls");
        cout << "Adding New Clint:\n\n";

        ReadClintDataRecord();
        cout << "\nClint,Added Successfully,do You want to add more cilents?\n";
        cin >> AddMore;


    } while (toupper(AddMore) == 'Y');

}

int main()
{
    AddClient();
   

    system("pause>0");
}


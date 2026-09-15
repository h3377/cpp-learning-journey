#include <iostream>
#include <string>
#include <vector>

using namespace std;

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

int main()
{
    cout << "\\nPlease Enter Client Data:\\n\\n";
    Sclint client = ReadClintDataRecord();

    cout << "\nClient Data Recorded Successfully.\n";
    cout << "\n" << ConverRecordToLine(client);

    system("pause>0");
}

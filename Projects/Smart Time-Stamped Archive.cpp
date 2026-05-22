#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <iomanip>

using namespace std;

struct stLog {
    int ID;
    string Name;
    string Timestamp;
};

string GetCurrentTimestamp() {
    time_t t = time(0);
    tm* now = localtime(&t);
    char buffer[80]; 
    strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", now);
    return string(buffer);
}

vector<string> Split(string s1, string delim = "#//#")
{
    vector<string> vString;
    size_t pos = 0; 
    string sWord;

    while ((pos = s1.find(delim)) != string::npos) {
        sWord = s1.substr(0, pos);
        vString.push_back(sWord);
        s1.erase(0, pos + delim.length());
    }
    if (s1 != "") vString.push_back(s1);
    return vString;
}

string ConvertRecordToLine(stLog* Log, string Seperator = "#//#")
{
    return to_string(Log->ID) + Seperator + Log->Name + Seperator + Log->Timestamp;
}

stLog* ConvertLineToRecord(string Line) 
{
    vector<string> vData = Split(Line);

    if (vData.size() < 3) return nullptr; // ✅ Safety check

    stLog* Log = new stLog;
    Log->ID = stoi(vData[0]);      
    Log->Name = vData[1];          
    Log->Timestamp = vData[2]; 

    return Log;
}

void SaveVectorToFile(string FileName, const vector<stLog*>& vLogs) 
{

    fstream MyFile;

    MyFile.open(FileName, ios::out);
    if (MyFile.is_open()) {
        for (stLog* Log : vLogs) {
            MyFile << ConvertRecordToLine(Log) << endl;
        }
        MyFile.close();
    }
}

void LoadDataFromFile(string FileName, vector<stLog*>& vLogs)
{
    fstream MyFile;

    MyFile.open(FileName, ios::in);
    if (MyFile.is_open()) {
        string Line;
        while (getline(MyFile, Line)) {
            if (Line != "") {
                stLog* Log = ConvertLineToRecord(Line);
                if (Log != nullptr) vLogs.push_back(Log);
            }
        }
        MyFile.close();
    }
}

void AddNewLog(vector<stLog*>& vLogs, string FileName) 
{
    stLog* Log = new stLog;

    cout << "Enter ID: ";
    if (!(cin >> Log->ID)) { // ✅ Input validation
        cin.clear();
        cin.ignore(10000, '\n');
        delete Log;
        cout << "Invalid ID!\n";
        return;
    }

    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, Log->Name);

    Log->Timestamp = GetCurrentTimestamp();
    vLogs.push_back(Log);

    fstream MyFile;

    MyFile.open(FileName, ios::out | ios::app);
    if (MyFile.is_open()) {
        MyFile << ConvertRecordToLine(Log) << endl;
        MyFile.close();
        cout << "Log added and saved successfully!\n";
    }
    else {
        cout << "Warning: Could not open file, but kept in memory.\n";
    }
}

void PrintLogs(const vector<stLog*>& vLogs) {
    cout << "\n" << left << setw(10) << "ID" << setw(20) << "Name" << "Timestamp" << endl;
    cout << "------------------------------------------------------------\n";
    for (stLog* Log : vLogs) {
        cout << left << setw(10) << Log->ID
            << setw(20) << Log->Name
            << Log->Timestamp << endl;
    }
    if (vLogs.empty()) cout << "No records found.\n";
}

void DeleteLogByID(vector<stLog*>& vLogs, string FileName) 
{
    int ID;
    cout << "\nEnter ID to delete: ";

    if (!(cin >> ID)) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid ID!\n";
        return;
    }

    bool Found = false;
    for (auto it = vLogs.begin(); it != vLogs.end(); ) {
        if ((*it)->ID == ID) {
            delete* it;
            it = vLogs.erase(it);
            Found = true;
            break;
        }
        else {
            ++it;
        }
    }

    if (Found) {
        SaveVectorToFile(FileName, vLogs);
        cout << "Record deleted successfully.\n";
    }
    else {
        cout << "ID not found!\n";
    }
}

int main() {
    vector<stLog*> vLogs;
    string FileName = "Logs.txt";

    LoadDataFromFile(FileName, vLogs);

    int Choice = 0;
    while (Choice != 4) {
        cout << "\n--- Smart Archive Menu ---\n";
        cout << "1. Add New Log\n2. Show All Logs\n3. Delete Log\n4. Exit\n";
        cout << "Enter choice: ";

        if (!(cin >> Choice)) { 
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid choice! Please enter a number.\n";
            continue;
        }

        try {
            if (Choice == 1) AddNewLog(vLogs, FileName);
            else if (Choice == 2) PrintLogs(vLogs);
            else if (Choice == 3) DeleteLogByID(vLogs, FileName);
            else if (Choice != 4) cout << "Invalid option!\n";
        }
        catch (...) {
            cout << "An unexpected error occurred!\n";
        }
    }

    // Cleanup
    for (stLog* Log : vLogs) {
        delete Log;
    }
    vLogs.clear();

    return 0;
}

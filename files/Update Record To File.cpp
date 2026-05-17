

#include <iostream>
#include <string>
#include<fstream>
#include<vector>

using namespace std;

void LoadRecordData(string FileName, vector<string>& vFileContent)
{
    fstream MyFile;

    MyFile.open("MyFile.txt", ios::in);

    if (MyFile.is_open())
    {
        string Line;

        while (getline(MyFile, Line))
        {
            vFileContent.push_back(Line);

        }
        MyFile.close();
    }
}
void SaveVectorToFile(string FileName, vector<string>vFileName)
{
    fstream MyFile;

    MyFile.open("MyFile.txt", ios::out);

    if (MyFile.is_open())
    {
        for (string Line : vFileName)
        {
            if (Line != "")
            {
                MyFile << Line << endl;
            }
        }
        MyFile.close();
    }
}
void UpdateRecordToFile(string FileName, string Record, string UpdateTo)
{
    vector<string> vFileContent;

    LoadRecordData(FileName, vFileContent);

    for (string& Line : vFileContent)
    {
        if (Line == Record)
        {
            Line = UpdateTo;
        }

    }
    SaveVectorToFile(FileName, vFileContent);

    
}
void DeleteRecordFromFile(string FileName, string Record)
{
    vector<string> vFileContent;
    LoadRecordData(FileName, vFileContent);

    for (string& Line : vFileContent)
    {
        if (Line == Record)
        {
            Line = "";
        }
    }
    SaveVectorToFile(FileName, vFileContent);

}
void PrintFileContent(string FileName)
{
    fstream MyFile;

    MyFile.open(FileName, ios::in);//Read Mood

    if (MyFile.is_open())
    {
        string Line;
        while (getline(MyFile, Line))
        {
            cout << Line << endl;

        }
        MyFile.close();
    }

}
int main()
{
    cout << "File content Before Delete:\n";
    PrintFileContent("MyFile.txt");

    UpdateRecordToFile("MyFile.txt", "Ali","Omar");


    cout << "\n\nFile content After Delete\n";
    PrintFileContent("MyFile.txt");
    return 0;
}


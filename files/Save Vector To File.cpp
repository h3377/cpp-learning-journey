// #56 save vector to file.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<fstream>
#include <string>
#include<vector>


using namespace std;

void SaveVectorToFile(string FileName, vector<string>vFileName)
{
    fstream MyFile;

    MyFile.open("MyFile.txt", ios::out);

    if(MyFile.is_open())
    {
        

        for (string &Line : vFileName)
        {
            if (Line != "")
            {
                MyFile << Line << endl;
            }
        }
    }
    MyFile.close();

}



int main()
{
    vector<string>vFileContent{ "Ali","Hamza","Ahmed","sara","halima","Abdulrhman" };

    SaveVectorToFile("MyFile.txt", vFileContent);
    return 0;
}



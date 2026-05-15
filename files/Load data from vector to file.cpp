

#include <iostream>
#include<fstream>
#include <string>
#include <vector>

using namespace std;

void MyfileDataContenent(string FileName, vector<string>& vFilename)
{
    fstream MyFile;

    MyFile.open(FileName, ios::in);//Read Mood

    if (MyFile.is_open())
    {
        string Line;

        while (getline(MyFile , Line))
        {
            vFilename.push_back(Line);

        }
        MyFile.close();
    }
}

int main()
{
    vector <string> vFilename;

    MyfileDataContenent("MyFile.txt", vFilename);

    for (string& Line : vFilename)
    {
        cout << Line << endl;
    }

    return 0;

}

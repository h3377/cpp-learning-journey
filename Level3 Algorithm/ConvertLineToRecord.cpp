#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
struct sClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
};
sClient ReadNewClient()
{
	sClient Client;
	cout << "Enter Account Number? ";
	getline(cin, Client.AccountNumber);
	cout << "Enter PinCode? ";
	getline(cin, Client.PinCode);
	cout << "Enter Name? ";
	getline(cin, Client.Name);
	cout << "Enter Phone? ";
	getline(cin, Client.Phone);
	cout << "Enter AccountBalance? ";
	cin >> Client.AccountBalance;
	return Client;
}
vector<string> SplitString(string S1, string Delim)
{
	vector<string> vString;
	short pos = 0;
	string sWord; // define a string variable
	// use find() function to get the position of the delimiters
	while ((pos = S1.find(Delim)) != std::string::npos)
	{
		sWord = S1.substr(0, pos); // store the word
		if (sWord != "")
		{
			vString.push_back(sWord);
		}
		S1.erase(0, pos + Delim.length());
	}
	if (S1 != "")
	{
		vString.push_back(S1); // it adds last word of the string.
	}
	return vString;
}

sClient ConvertRecordToLine(string Line, string Seperator = "#//#")
{
	sClient Clint;
	vector<string> vClientData ;
	vClientData = SplitString(Line, Seperator);

	Clint.AccountNumber = vClientData[0];
	Clint.PinCode = vClientData[1];
	Clint.Name = vClientData[2];
	Clint.Phone = vClientData[3];
	Clint.AccountBalance = stod(vClientData[4]);//cast string to double

	return Clint;
	
}

void PrintData(sClient Clint)
{
	cout << "\n\nThe following is the extracted clint record:\n ";
	cout << "\nAccout Number: " << Clint.AccountNumber;
	cout << "\nPinCode: " << Clint.PinCode;
	cout << "\nName:" << Clint.Name;
	cout << "\nphone:" << Clint.Phone;
	cout << "\nAccount balance:" << Clint.AccountBalance;


}
int main()
{
	string stLine = "A150#//#1234#//#Hamza abdulrhman#//#079999#//#5270.000000";

	cout << "\n Line record is:\n";
	cout << stLine;

	sClient clint = ConvertRecordToLine(stLine);

	PrintData(clint);

	system("pause>0");
	return 0;
}

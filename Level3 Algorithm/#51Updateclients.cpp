// #51 II 3 update Client.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<vector>
#include<fstream>

using namespace std;

const string ClientsFile = "Client.txt";

struct sClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
	bool MarkDelete = false;
	
};


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
sClient ConvertLinetoRecord(string Line, string Seperator = "#//#")
{
	sClient Client;
	vector<string> vClientData;
	vClientData = SplitString(Line, Seperator);
	Client.AccountNumber = vClientData[0];
	Client.PinCode = vClientData[1];
	Client.Name = vClientData[2];
	Client.Phone = vClientData[3];
	Client.AccountBalance = stod(vClientData[4]);//cast string to double

	return Client;
}
string ConvertRecordToLine(sClient Client, string Seperator =
	"#//#")
{
	string stClientRecord = "";
	stClientRecord += Client.AccountNumber + Seperator;
	stClientRecord += Client.PinCode + Seperator;
	stClientRecord += Client.Name + Seperator;
	stClientRecord += Client.Phone + Seperator;
	stClientRecord += to_string(Client.AccountBalance);
	return stClientRecord;
}

vector <sClient> LoadCleintsDataFromFile(string FileName)
{
	vector <sClient> vClients;
	fstream MyFile;
	MyFile.open(FileName, ios::in);//read Mode
	if (MyFile.is_open())
	{
		string Line;
		sClient Client;
		while (getline(MyFile, Line))
		{
			Client = ConvertLinetoRecord(Line);
			vClients.push_back(Client);
		}
		MyFile.close();
	}
	return vClients;
}
void PrintClientRecord(sClient Client)
{
	cout << "\nThe following are the client details:\n";
	cout << "\nAccount Number: " << Client.AccountNumber;
	cout << "\nPin Code: " << Client.PinCode;
	cout << "\nName: " << Client.Name;
	cout << "\nPhone" << Client.Phone;
	cout << "\nAccount Balance" << Client.AccountBalance;
}


bool FindClientByAccountNumber(string AccountNumber, vector<sClient>& vClient, sClient& Client)
{


	for (sClient C : vClient)
	{
		if (C.AccountNumber == C.AccountNumber)
		{
			Client = C;
			return true;
		}
	}
	return false;


}
vector<sClient> SaveClientDataToFile(string FileName, vector<sClient>& vClient)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out);

	string DataLine;

	if (MyFile.is_open())
	{
		for (sClient C : vClient)
		{
			if (C.MarkDelete == true)
			{
				//we only write records that are not marked for delete.

				DataLine = ConvertRecordToLine(C);
				MyFile << DataLine << endl;
			}
		}
		MyFile.close();
	}
	return vClient;
}

sClient ChangeClientRecord(string AccountNumber)
{
	sClient Client;

	cout << "\n\nEnter pinCode? ";
	getline(cin >> ws, Client.PinCode);

	cout << "\n\nEnter Name? ";
	getline(cin, Client.Name);

	cout << "\n\nEnter Phone? ";
	getline(cin, Client.Phone);

	cout << "\n\nEnter Account Balance?";
	cin >> Client.AccountBalance;

	return Client;
}


bool UbdateClientData(string AccountNumber,vector<sClient>& vClient)
{
	sClient Client;
	char Answer = 'n';

	if (FindClientByAccountNumber(AccountNumber, vClient, Client))
	{
		PrintClientRecord(Client);
		cout <<"\n\nAre you sure do you want to delete this Client ? \n";
		cin >> Answer;

		if (Answer == 'y' || Answer== 'Y')
		{
			for (sClient& C : vClient)
			{
				if (C.AccountNumber == AccountNumber)
				{
					C = ChangeClientRecord(AccountNumber);
					break;
				}
				
			}

			SaveClientDataToFile(ClientsFile, vClient);

			

			cout << "\n\nClient Deleted successfully.\n";
			return true;

		}
	}
	else
	{
		cout << "\n\nClient with account number (" << AccountNumber << ") is not found!\n";
		return false;
	}
	return false;
}
string ReadClientsAccountNumber()
{
	string AccountNumber = "";
	cout << "\nPlease enter Account Number?";
	cin >> AccountNumber;

	return AccountNumber;
}

int main()
{
	vector<sClient> Vclient = LoadCleintsDataFromFile(ClientsFile);

	string AccountNumber = ReadClientsAccountNumber();

	UbdateClientData(AccountNumber, Vclient);

	system("pause>0");
	return 0;
}


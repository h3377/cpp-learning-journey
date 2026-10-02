#include <iostream>
#include<string>
#include<vector>
#include<iomanip>
#include <fstream>

using namespace std;

const string sClientFile = "Clients.txt";

void ShowMainMenue();

enum enShowmeinMenuOption
{
	eShowAllClient = 1, eAddNewClint = 2, eDeleteClient = 3, eUpdateClientInfo = 4, eFindClient = 5, eExit = 6

};

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
bool ClientExistsByAccountNumber(string AccountNumber, string
	FileName)
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
			if (Client.AccountNumber == AccountNumber)
			{
				MyFile.close();
				return true;
			}
			vClients.push_back(Client);
		}
		MyFile.close();
	}
	return false;
}

sClient ReadClintDataRecord()
{
	sClient Clint;

	cout << "\nEnter Acount Number?\n";
	getline(cin >> ws, Clint.AccountNumber);
	while (ClientExistsByAccountNumber(Clint.AccountNumber,sClientFile))
	{
		cout << "\nClient with [" << Clint.AccountNumber << "] already exists, Enter another Account Number? ";
		getline(cin >> ws, Clint.AccountNumber);

	}

	cout << "\nEnter PinCode?\n";
	getline(cin, Clint.PinCode);

	cout << "Enter Name?\n";
	getline(cin, Clint.Name);

	cout << "\nEnter phone?\n";
	getline(cin, Clint.Phone);

	cout << "\nEnter AccountBalance?\n";
	cin >> Clint.AccountBalance;

	return Clint;
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
	cout << "| " << setw(15) << left << Client.AccountNumber;
	cout << "| " << setw(10) << left << Client.PinCode;
	cout << "| " << setw(40) << left << Client.Name;
	cout << "| " << setw(12) << left << Client.Phone;
	cout << "| " << setw(12) << left << Client.AccountBalance;
}
void ShowAllClientsData()
{
	vector<sClient> vClient = LoadCleintsDataFromFile(sClientFile);

	cout << "\n\t\t\t\t\tClient List (" << vClient.size() << ")Client(s).";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
	cout << "| " << left << setw(15) << "Account Number";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(12) << "Phone";
	cout << "| " << left << setw(12) << "Balance";
	cout <<
		"\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
	for (sClient Client : vClient)
	{
		PrintClientRecord(Client);
		cout << endl;
	}
	cout <<
		"\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
}

void PrintClientRecords(sClient Client)
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
		if (C.AccountNumber == AccountNumber)
		{
			Client = C;
			return true;
		}
	}
	return false;


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


bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector<sClient>& vClient)
{
	for (sClient& C : vClient)
	{
		if (C.AccountNumber == AccountNumber)
		{
			C.MarkDelete = true;
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
			if (!C.MarkDelete)
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
void AddNewDataLineToFile(string FileName, string stDataLine)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out | ios::app);

	if (MyFile.is_open())
	{
		MyFile << stDataLine << endl;
		MyFile.close();
	}
}

void AddNewClintsFunc()
{
	sClient Clint;
	Clint = ReadClintDataRecord();
	AddNewDataLineToFile(sClientFile, ConvertRecordToLine(Clint));
}
void AddNewClients()
{
	char AddMore = 'Y';

	do
	{
		system("cls");
		cout << "Adding New Clint:\n\n";

		AddNewClintsFunc();
		cout << "\nClint,Added Successfully,do You want to add more cilents?\n";
		cin >> AddMore;


	} while (toupper(AddMore) == 'Y');

}



bool DeleteClientsByAccountNumber(string AccountNumber, vector<sClient>& vClient)
{
	sClient Client;
	char Answer = 'n';

	if (FindClientByAccountNumber(AccountNumber,vClient,Client))
	{
		PrintClientRecord(Client);
		cout << "\n\nAre you sure do you want to delete this Client?\n";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			MarkClientForDeleteByAccountNumber(AccountNumber, vClient);
			SaveClientDataToFile(sClientFile, vClient);

			vClient = LoadCleintsDataFromFile(sClientFile);

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
bool UbdateClientData(string AccountNumber, vector<sClient>& vClient)
{
	sClient Client;
	char Answer = 'n';

	if (FindClientByAccountNumber(AccountNumber,vClient, Client))
	{
		PrintClientRecord(Client);
		cout << "\n\nAre you sure do you want to Update this Client ? \n";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			for (sClient& C : vClient)
			{
				if (C.AccountNumber == AccountNumber)
				{
					C = ChangeClientRecord(AccountNumber);
					break;
				}

			}

			SaveClientDataToFile(sClientFile, vClient);



			cout << "\n\nClient updated successfully.\n";
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


void ShowDeleteClientScreen()
{
	cout << "\n---------------------------------------\n";
	cout << "\tDelete Client screen";
	cout << " \n--------------------------------------\n";

	vector<sClient> vClient = LoadCleintsDataFromFile(sClientFile);
	string AccountNumber = ReadClientsAccountNumber();
	DeleteClientsByAccountNumber(AccountNumber, vClient);
}

void ShowUpdateClientScreen()
{
	cout << "\n---------------------------------------\n";
	cout << "\tDelete Client screen";
	cout << " \n--------------------------------------\n";

	vector<sClient> vClient = LoadCleintsDataFromFile(sClientFile);
	string AccountNumber = ReadClientsAccountNumber();
	UbdateClientData(AccountNumber, vClient);

}
void ShowAddNewClientData()
{
	cout << "\n---------------------------------------\n";
	cout << "\tDelete Client screen";
	cout << " \n--------------------------------------\n";

	vector<sClient> vClient = LoadCleintsDataFromFile(sClientFile);
	string AccountNumber = ReadClientsAccountNumber();
	AddNewClients();
}
void ShowFindClientScreen()
{
	cout << "\n---------------------------------------\n";
	cout << "\tDelete Client screen";
	cout << " \n--------------------------------------\n";

	vector<sClient> vClient = LoadCleintsDataFromFile(sClientFile);
	sClient Clinet;

	string AccountNumber = ReadClientsAccountNumber();
	if (FindClientByAccountNumber(AccountNumber, vClient, Clinet))
	
		PrintClientRecord(Clinet);
	else
	{
		cout << "\nClient with Account Number[" << AccountNumber<< "] is not found!";
	}
}

void ShowEndScreen()
{
	cout << "\n-----------------------------------------\n";
	cout << "\tProgram Ends :-)";
	cout << "\n-----------------------------------------\n";
}
void GoToBackMainMenue()
{
	cout << "\n\nPress any key to go back to main menue....";
	system("pause>0");
	ShowMainMenue();
}

short ReadmainMenu()
{
	short Chois = 0;
	cout << "Choose Do You Want To Do? [1 To 6]:";
	cin >> Chois;
	return Chois;
}

void PreFormMainMeunOption(enShowmeinMenuOption Chois)
{
	

	switch (Chois)
	{
	case enShowmeinMenuOption::eShowAllClient:
		system("cls");
		ShowAllClientsData();
		GoToBackMainMenue();
		break;

	case enShowmeinMenuOption::eAddNewClint:
		system("cls");
		ShowAddNewClientData(); 
		GoToBackMainMenue();
		break;

	case enShowmeinMenuOption::eDeleteClient:
		system("cls");
		ShowDeleteClientScreen();
		GoToBackMainMenue();
		break;

	case enShowmeinMenuOption::eUpdateClientInfo:
		system("cls");
		ShowUpdateClientScreen();
		GoToBackMainMenue();
		break;

	case enShowmeinMenuOption::eFindClient:
		system("cls");
		ShowFindClientScreen();
		GoToBackMainMenue();

		break;

	case enShowmeinMenuOption::eExit:
		system("cls");
		ShowEndScreen();
		break;
	}
}
void ShowMainMenue()
{
	system("cls");
	cout << "=========================================================" << endl;
	cout << "\t\tMain Menu Screen" << endl;
	cout << "=========================================================" << endl;
	cout << "\t[1]Show Client List." << endl;
	cout << "\t[2]Add New Client." << endl;
	cout << "\t[3]Delete Client." << endl;
	cout << "\t[4]Update Client." << endl;
	cout << "\t[5]Find Client." << endl;
	cout << "\t[6]Exit." << endl;
	cout << "=========================================================" << endl;

	PreFormMainMeunOption((enShowmeinMenuOption)ReadmainMenu());

}





int main()
{
	

    ShowMainMenue();
    system("pause>0");

    return 0;
}


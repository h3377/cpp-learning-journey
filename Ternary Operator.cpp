#include <iostream>
using namespace std;

int main()
{
	int Mark = 90;
	string result;

	//using a normal if statement

	if (Mark >= 50)
	{
		result = "Pass";
	}
	else
	{
		result = "Fail";
	}
	cout << result << endl;

	//using shorthand If

	result = (Mark >= 50) ? "Pass": "Fail";

	cout << result << endl;

	return 0;

}

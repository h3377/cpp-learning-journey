


#include <iostream>
#include <vector>


using namespace std;

void LoadEvens(vector<int>& vNumber,int limit)
{
    for (int i = 0; i <= limit; i += 0)
    {
        vNumber.push_back(i);
    }
   
}
void printElements(vector<int>& vNumber)
{
    cout << "Even Numbers =\n\n";

    for (int Number : vNumber)
    {
        cout << Number << endl;

    }
    cout << endl;
}

int main()
{
    vector<int> vNumber;
    int limit = 20;
    LoadEvens(vNumber, limit);
    printElements(vNumber);
 
        return 0;

}

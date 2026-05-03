#include <iostream>
using namespace std;

int main()
{
    int num = 42;
    int &ref = num;

cout << "num address: " << &num << endl;
cout << "ref address: " << &ref << endl;
// SAME ADDRESS!

num = 100;
cout << "ref after num=100: " << ref << endl;  // 100

ref = 200;
cout << "num after ref=200: " << num << endl;  // 200

return 0;
}

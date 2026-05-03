
#include <iostream>

using namespace std;



int main()
{

int x = 50;
 int y = 100;



 int* ptr;

  ptr = &x;
 *ptr = *ptr + 10;



 ptr = &y;
 *ptr = *ptr * 2;  

 cout << "Final x: " << x << endl;
 cout << "Final y: " << y << endl; 

return 0;
}

#include <iostream>
using namespace std;

int main() {
    int original = 10;
int &a = original;
int &b = original;
int &c = original;

a = 20;  // original=20, a=20, b=20, c=20
b = 30;  // original=30, a=30, b=30, c=30
c = 40;  // original=40, a=40, b=40, c=40

// All 4 names, ONE memory cell!

return 0;
}

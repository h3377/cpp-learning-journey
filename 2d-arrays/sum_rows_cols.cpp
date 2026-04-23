#include <iostream>
using namespace std;

int main() {
    int x[4][4] = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    
    
    int mainDiag = 0, antiDiag = 0;

for (int i = 0; i < 4; i++) {
    mainDiag += x[i][i];        // (0,0), (1,1), (2,2), (3,3)
    antiDiag += x[i][3 - i];    // (0,3), (1,2), (2,1), (3,0)
}

cout << "Main diagonal: " << mainDiag << endl;  // 1+6+11+16 = 34
cout << "Anti diagonal: " << antiDiag << endl;  // 4+7+10+13 = 34
    return 0;
}

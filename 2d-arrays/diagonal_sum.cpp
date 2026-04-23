#include <iostream>
using namespace std;

int main() {
    int x[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    int transpose[4][3];

for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
        transpose[j][i] = x[i][j];
    }
}

// Print original
cout << "Original (3x4):" << endl;
for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
        cout << x[i][j] << "\t";
    }
    cout << endl;
}

// Print transpose
cout << "\nTranspose (4x3):" << endl;
for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 3; j++) {
        cout << transpose[i][j] << "\t";
    }
    cout << endl;
}
    
    return 0;
}

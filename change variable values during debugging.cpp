#include <iostream>
using namespace std;

int main() {
    int score = 75;  // Original value
    
    if (score >= 90) {
        cout << "A";
    } else if (score >= 80) {
        cout << "B";
    } else if (score >= 70) {
        cout << "C";        // Currently prints this (75 >= 70)
    } else {
        cout << "F";
    }
    
    return 0;
}

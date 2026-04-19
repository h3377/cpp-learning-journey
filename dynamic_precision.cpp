#include <cstdio>

void PrintWithPrecision(double num, int precision) {
   
    printf("%.*f\n", precision, num);
    // precision goes to *, num is the value

}

int main() {
    double pi = 3.141592653589793;
    
    PrintWithPrecision(pi, 2);   // 3.14
    PrintWithPrecision(pi, 5);   // 3.14159
    PrintWithPrecision(pi, 10);  // 3.1415926536
    
    return 0;
}

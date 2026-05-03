#include <iostream>
#include <cstdio>

using namespace std;



int main()
{
    float PI = 3.14159265;

    printf("Precision specification of %.*f \n", 2, PI);
    printf("Precision specification of %.*f \n", 3, PI);
    printf("Precision specification of %.*f \n", 4, PI);

    float X = 7.0, y = 8.0;

    printf("\nThe Float division is : %.3f / %.3f = %.3f \n\n", X, y,X / y);

    double d = 12.45;

    printf("The double value is : %.3f \n", d);
    printf("The double value is : %.4f \n", d);

    return 0;
}

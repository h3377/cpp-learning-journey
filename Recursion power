#include <iostream>

using namespace std;
//program to calculate power n^m
        // Fixed function to calculate power n^m recursively
 int MyPower(int Base , int Power)
        {
            // Base case: any number to the power of 0 is 1
            if (Power == 0)
           
                return 1;
            
            else
            {
                return (Base * MyPower(Base, Power - 1));
            }
            // Recursive case: multiply N by the result of N^(M-1)
          
        }

        int main()
        {
             
           cout << MyPower(2, 10);

            return 0;
        }

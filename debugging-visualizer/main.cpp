#include<iostream>
using namespace std;

// Function stored in CODE segment
// Parameters a, b stored in STACK when called
int MySum(int a, int b)
{
    int s = 0;      // Local variable 's' created on STACK
    s = a + b;      // Operation: values added, result stored in 's'
    return s;       // Value copied back to caller, 's' destroyed
}

int main()
{
    // STACK ALLOCATION: Array + 3 integers
    int arr1[5] = { 200,100,50,25,30 };  // Contiguous memory: 5 × 4 bytes = 20 bytes
    int a, b, c;                         // Uninitialized (garbage values initially)
    
    a = 10;      // a = 10  (0x0A)
    b = 20;      // b = 20  (0x14)
    a++;         // POST-increment: use value, then add 1 → a becomes 11
    ++b;         // PRE-increment: add 1 first → b becomes 21
    
    c = a + b;   // c = 11 + 21 = 32
    
    cout << a << endl;   // Output: 11
    cout << b << endl;   // Output: 21
    cout << c << endl;   // Output: 32
    
    // LOOP: Watch 'a' grow exponentially!
    for (int i = 1; i <= 5; i++)
    {
        cout << i << endl;           // i: 1,2,3,4,5
        a = a + a * i;               // CRITICAL LINE: a grows FAST
        // i=1: a = 11 + 11*1 = 22
        // i=2: a = 22 + 22*2 = 66  
        // i=3: a = 66 + 66*3 = 264
        // i=4: a = 264 + 264*4 = 1320
        // i=5: a = 1320 + 1320*5 = 7920
    }
    
    c = MySum(a, b);    // Call function: a=7920, b=21 → returns 7941
    cout << c;          // Output: 7941
    
    return 0;           // Program ends, stack cleaned up
}

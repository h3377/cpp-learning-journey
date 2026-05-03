
#include <iostream>

using namespace std;

// function declaration (tell compiler exists) 
void add(int, int);

int main()
{
    add(10, 20);// can call before defination

    return 0;
}

//function definition(actual implementaion)
void add(int a, int b)
{
    cout << (a + b);
}

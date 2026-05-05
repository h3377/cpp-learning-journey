// #43 Memory Management new and delete.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main()
{
    //declare an int pointer
    int* ptrx;
    //declare an float pointer
    float* ptry;


    //dynamiclly allocate memmory
    ptrx = new int;
    ptry = new float;

    //assigning value to the memory
    *ptrx = 50;
    *ptry = 65.887f;

    cout << *ptrx << endl;
    cout << *ptry << endl;
    //dealocate the memory
    delete ptrx;
    delete ptry;

    return 0;
}


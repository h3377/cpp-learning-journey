

#include <iostream>
#include<string>
#include <iomanip>


using namespace std;

void PrintFibonacciUsingRecursion(short Number, int newPrev1,int NewPrev2)

{
	int fibonacciNumber = 0;

	
	
	if (Number > 0)
	{
		fibonacciNumber = NewPrev2+newPrev1;
		NewPrev2=newPrev1;
		newPrev1 = fibonacciNumber;

		cout << fibonacciNumber << "      ";

		PrintFibonacciUsingRecursion(Number - 1, newPrev1, NewPrev2);
		
	}

	
}
int main()
{  
	PrintFibonacciUsingRecursion(10,0,1);

	system("pause>0");
}

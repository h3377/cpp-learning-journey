

#include <iostream>
#include<cstdio>

using namespace std;


int main()
{
    char Name[] = "Hamza Al-Maqtari";
    char schoolName[] = "Programming Advice";

    printf("Dear %s, How are you ?\n\n", Name);
    printf("Welcome to %s school! \n\n", schoolName);

    char C = 'S';
    printf("setting the width of C :%*c \n",1, C);
    printf("setting the width of C :%*c \n",2, C);
    printf("setting the width of C :%*c \n",3, C);
    printf("setting the width of C :%*c \n",4, C);
    printf("setting the width of C :%*c \n",5, C);

    return 0;
}


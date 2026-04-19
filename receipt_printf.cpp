#include<iostream>
#include <cstdio>

int main() {
    printf("==============================\n");
    printf("%-15s %3s %10s\n", "ITEM", "QTY", "PRICE");
    printf("==============================\n");
    
    printf("%-15s %3d $%8.2f\n", "Apple", 3, 2.50);
    printf("%-15s %3d $%8.2f\n", "Bread", 2, 3.25);
    printf("%-15s %3d $%8.2f\n", "Milk", 1, 4.00);
    
    printf("==============================\n");
    printf("%-15s %3s $%8.2f\n", "TOTAL", "", 14.25);
    printf("==============================\n");
    
    return 0;
}

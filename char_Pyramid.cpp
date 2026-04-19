#include <cstdio>

int main() {
    char letter = 'A';
    
    for (int row = 1; row <= 5; row++) {
        // Spaces before: decreasing
        int spaces = 5 - row;
        // Characters: 2*row - 1 (1, 3, 5, 7, 9)
        int chars = 2 * row - 1;
        
        // Print spaces
        printf("%*s", spaces, "");  // Empty string with width = spaces
        
        // Print characters
        for (int c = 0; c < chars; c++) {
            printf("%c", letter);
        }
        
        printf("\n");
        letter++;  // A → B → C → D → E
    }
    
    return 0;
}

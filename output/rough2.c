#include <stdio.h>

int main() {
    int rows = 5; // You can change the number of rows as needed

    // Outer loop for the number of rows
    for (int i = 0; i < rows; i++) {
        
        // Inner loop for printing spaces
        for (int j = 0; j < rows - i - 1; j++) {
            printf(" ");
        }

        // Inner loop for printing asterisks
        for (int k = 0; k < 2 * i + 1; k++) {
            printf("*");
        }

        // Move to the next line after each row
        printf("\n");
    }

    return 0;
}

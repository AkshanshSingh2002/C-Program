#include <stdio.h>

// Function to calculate factorial
unsigned long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int number;

    // Input the number
    printf("Enter a number: ");
    scanf("%d", &number);

    // Calculate and print the factorial
    printf("Factorial of %d is %llu\n", number, factorial(number));

    return 0;
}

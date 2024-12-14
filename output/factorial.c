#include <stdio.h>

int Factorial(int);

int main(void)
{
    int n, fact;
    printf("The factorial of num is:");
    scanf("%d ",&n);
    fact = Factorial(n);
    printf("The factorial of %d is: %d\n", n, fact);
    return 0;
}

int Factorial(int n) {
    if (n==1 || n==0)
    {
        return 1;
    }

    else {
        int f = n * Factorial(n-1);
        return f;
    }
    
}


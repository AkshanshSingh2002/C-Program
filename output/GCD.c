#include <stdio.h>

int findGCD(int, int);

int main(int argc, char const *argv[])
{
    int a, b;
    printf("Enter the value: ");
    scanf("%d %d", &a, &b);
    int GCD = findGCD(a, b);
    printf("The GCD of %d and %d is: %d\n", a, b, GCD);

    //printing number in assending order
    for (int i = 0; i < a; i++)
    {
        printf("%d ", i);
    }
    
    return 0;
}

int findGCD(int x, int y) {
    if (y==0)
    {
        return x;
    } else
    {
        return findGCD(y, x % y);
    }
    
    
}
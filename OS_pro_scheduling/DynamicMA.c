#include<stdio.h>
#include <stdlib.h>
void MemoryAllocation() {
    int n,*ptr;
    printf("Enter the num. of element:");
    scanf("%d", &n);
    ptr = (int*) malloc(n*sizeof(int));
    printf("Enter the value: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", ptr + i);
    }
    printf("The entered value: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(ptr + i));
    }
    free(ptr);
}
void ContiguiousAllocation() {
    int n,*ptr;
    printf("Enter the num. of element:");
    scanf("%d", &n);
    ptr = (int*) calloc(n, sizeof(int));
    printf("Enter the value: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", ptr + i);
    }
    printf("The entered value: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(ptr + i));
    }
    free(ptr);
}
void Reallocation () {
    int n,*ptr;
    printf("Enter the num. of element:");
    scanf("%d", &n);
    ptr = (int*) malloc(n*sizeof(int));
    printf("Enter the value: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", ptr + i);
    }
    printf("Enter updated size of n: ");
    scanf("%d", &n);
    int *ptr1 = (int *)realloc(ptr, n * sizeof(int));
    printf("Previous Address: %p, New Address: %p\n", ptr, ptr1);
    printf("The entered value: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(ptr1 + i));
    }
    free(ptr1);
}

int main() {
    //MemoryAllocation();
    //ContiguiousAllocation();
    //Reallocation();

    return 0;

}
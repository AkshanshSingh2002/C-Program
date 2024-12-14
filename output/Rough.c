/*
# include <stdio.h>
int main( )
{
int s[ 4 ][ 2 ] = {
{ 1234, 56 },
{ 1212, 33 },
{ 1434, 80 },
{ 1312, 78 }
} ;
int i ;
for ( i = 0 ; i <= 3 ; i++ )
printf ( "Address of %d th 1-D array = %u\n", i, s[ i ]) ;
return 0 ;
}


#include <stdio.h>

int main ()  
{
    int  arr[4][5] = {{1, 2, 3, 4, 5},
                    {6, 7,8, 9, 10},
                    {11, 12, 13, 14, 15},
                    {16, 17,18, 19, 20}
                    };
    printf("%p\n", arr);
    printf("%p\n",*arr);

    return(0);
}

#include <stdio.h>

int main() {
    int s[4][2] = {
        {1234, 56},
        {1212, 33},
        {1434, 80},
        {1312, 78}
    };

    int i;
    for (i = 0; i <= 3; i++) {
        // Using s[i] is used to print the entire row's address
        printf("Address of %dth 1-D array = %p\n", i, (void *)s[i]);


        // Using *s[i] to print the first element of the row
        printf("First element of %dth 1-D array = %d\n", i, *s[i]);

        //
        printf ( "Address of %d th 1-D array = %u\n", i, s[ i ] ) ;
    }

    return 0;
}


//Pointer notation to access 2-D array elements 
# include <stdio.h>
int main( )
{

int s[ 4 ][ 2 ] = {
                    { 1234, 56 },
                    { 1212, 33 },
                    { 1434, 80 },
                    { 1312, 78 }
                                    } ;

    int i, j ;
    
    //Accessing 2-D Array element using pointer notation 
    for ( i = 0 ; i <= 3 ; i++ )
    {
        for ( j = 0 ; j <= 1 ; j++ )
            printf ( "%d ", *( *( s + i ) + j ) ) ;
            printf ( "\n" ) ;
    }
    printf("\n");

    //Accessing 2-D Array element using Subscript notation
    for ( i = 0 ; i <= 3 ; i++ )
    {
        for ( j = 0 ; j <= 1 ; j++ )
            printf ( "%d ", s[i][j]);
            printf ( "\n" ) ;
    }
    return 0 ;
}


# include <stdio.h>
int main( )
{
    static int a[ ] = { 0, 1, 2, 3, 4 } ;
    int *p[ ] = { a, a + 1, a + 2, a + 3, a + 4 } ;
    //Chapter 14: Multidimensional Arrays 279
    printf("%p %p %d\n", (void *)p, (void *)*p, *(*p));
    printf ( "%u %u %d\n", p, *p, * ( *p ) ) ;
    printf("%u \n", p[0]);
    //printf("%d", )
    return 0 ;
}



// String

//Program to read a string and print it
# include <stdio.h>
int main( )
{
char name[ 25 ] ;

printf ( "Enter your name " ) ;
scanf ( "%s", &name ) ;
printf ( "Hello %s!\n", name ) ;
return 0 ;
}

*/

#include <stdio.h>

int main() {
    // Variables
    float marks[5], percentage;
    char grade;

    // Input marks for five subjects
    printf("Enter marks for five subjects:\n");
    for (int i = 0; i < 5; i++) {
        printf("Subject %d: ", i + 1);
        scanf("%f", &marks[i]);
    }

    // Calculate percentage
    percentage = (marks[0] + marks[1] + marks[2] + marks[3] + marks[4]) / 5.0;

    // Determine grade using else-if ladder
    if (percentage >= 85) {
        grade = 'A';
    } else if (percentage >= 70) {
        grade = 'B';
    } else if (percentage >= 50) {
        grade = 'C';
    } else if (percentage >= 40) {
        grade = 'D';
    } else {
        grade = 'E';
    }

    // Display the grade
    printf("Percentage: %.2f%%\n", percentage);
    printf("Grade: %c\n", grade);

    return 0;
}

/*

#include <stdio.h>

int main() {
    int rows, number = 1;

    // Get the number of rows from the user
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    // Iterate through rows
    for (int i = 1; i <= rows; ++i) {
        // Iterate through columns
        for (int j = 1; j <= i; ++j) {
            // Print the current number and increment it
            printf("%d ", number);
            
        }
        ++number;
        printf("\n");
    }

    return 0;
}


#include <stdio.h>

int main() {
    char choice; // Change from int to char
    do {
        // Display the menu
        printf("\nMenu:\n"
               "a) Even/Odd\n"
               "b) Greatest of two numbers\n"
               "c) Sum and average of three numbers\n"
               "d) Area and Perimeter of a circle\n"
               "e) Exit\n");


        // Get user choice
        printf("Enter your choice (a-e): ");
        scanf(" %c", &choice); // Ensure to use %c for character input

        // Switch case to perform the selected action
        switch (choice) {
            case 'a': // Even/Odd
            {
                int num;
                printf("Enter a number: ");
                scanf("%d", &num);

                if (num % 2 == 0)
                    printf("%d is even.\n", num);
                else
                    printf("%d is odd.\n", num);
                break;
            }

            case 'b': // Greatest of two numbers
            {
                int num1, num2;
                printf("Enter the first number: ");
                scanf("%d", &num1);
                printf("Enter the second number: ");
                scanf("%d", &num2);

                if (num1 > num2)
                    printf("%d is the greatest.\n", num1);
                else if (num2 > num1)
                    printf("%d is the greatest.\n", num2);
                else
                    printf("Both numbers are equal.\n");
                break;
            }

            case 'c': // Sum and average of three numbers
            {
                int num1, num2, num3;
                printf("Enter the first number: ");
                scanf("%d", &num1);
                printf("Enter the second number: ");
                scanf("%d", &num2);
                printf("Enter the third number: ");
                scanf("%d", &num3);

                int sum = num1 + num2 + num3;
                float average = sum / 3.0;

                printf("Sum: %d\n", sum);
                printf("Average: %.2f\n", average);
                break;
            }

            case 'd': // Area and Perimeter of a circle
            {
                float radius;
                printf("Enter the radius of the circle: ");
                scanf("%f", &radius);

                float area = 3.14 * radius * radius;
                float perimeter = 2 * 3.14 * radius;

                printf("Area: %.2f\n", area);
                printf("Perimeter: %.2f\n", perimeter);
                break;
            }

            case 'e': // Exit
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option (a-e).\n");
        }
    } while (choice != 'e');

    return 0;
}
*/
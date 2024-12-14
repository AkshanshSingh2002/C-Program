#include <stdio.h>
#include <stdlib.h>

struct NODE
{
    int info;
    struct NODE *link;
};
struct NODE *head = NULL, *top = NULL, *ptr = NULL;

void push();
void pop();
void display();

int main(int argc, char const *argv[])
{
    int opt;
    char shouldContinue;
    printf("PROGRAM USING LINKED LIST TO PERFORM STACK OPRATION\n\n");
    do
    {
        printf("MENU:\n"
               "1. Push element onto Stack.\n"
               "2. POP from top.\n"
               "3. Display Every Element.\n");

        printf("Choose your Option(1 to 3): ");
        scanf("%d", &opt);

        switch (opt)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;

        default:
            printf("Invalid option...!!\n");
            break;
        }
        printf("Do you want to perform More Oprations. Type (y/n): ");
        scanf(" %c", &shouldContinue);
    } while (shouldContinue == 'y' || shouldContinue == 'Y');
    return 0;
}

void push()
{
    char addMoreNode;
    top = (struct NODE *)malloc(sizeof(struct NODE));
    printf("Enter the Information:");
    scanf("%d", &top->info);
    head = top;
    do
    {
        ptr = (struct NODE *)malloc(sizeof(struct NODE));
        printf("Enter the Information: ");
        scanf("%d", &ptr->info);
        top->link = ptr;
        top = ptr;
        printf("Do you want to add more Stack(Nodes). Type (y/n): ");
        scanf(" %c", &addMoreNode);
    } while (addMoreNode == 'y' || addMoreNode == 'Y');
    top->link = NULL;
}

void display()
{
    if (top == NULL)
    {
        printf("List is Empty");
        return;
    }
    printf("Displaying the element of Linked List representing Stack: ");
    ptr = head;
    while (ptr != NULL)
    {
        printf(" %d", ptr->info);
        ptr = ptr->link;
    }
}

void pop()
{
    if (top == NULL)
    {
        printf("Stack Is Empty");
        return;
    }
    ptr = top;
    int data = top->info;
    top = top->link;
    printf("Deleated info in the top: %d", data);
}
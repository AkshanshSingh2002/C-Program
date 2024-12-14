#include <stdio.h>
#include <stdlib.h>

struct NODE
{
    int info;
    struct NODE *link;
};

struct NODE *head;

void create();
void traversing_LL();
void insertAtTheBeginning();
void insertAtTheEnd();
void insertAtTheSpecifiedLocation();
void Sum_Average();
void count_even_OR_odd();
void delAtTheBeginning();
void delAtTheEnd();
void delAtTheSpecifiedLocation();

int main()
{
    char repeatOrNot;
    do
    {
        int option, insertAt, delAt;
        printf("\tMENU\t\n"
               "1. Create node.\n"
               "2. Print value at the linked list.\n"
               "3. Insert value.\n"
               "4. Sum and Average.\n"
               "5. Frequency of EVEN and ODD numbers.\n"
               "6. Delete.\n");

        printf("Choose from above option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            create();
            break;
        case 2:
            traversing_LL();
            break;
        case 3:
            printf("\tWHERE DO YOU WANT TO INSERT:\t\n"
                   "1. At the beginning\n"
                   "2. At the end\n"
                   "3. At the specified position\n");

            printf("WHERE DO YOU WANT TO INSERT\n");
            scanf("%d", &insertAt);
            switch (insertAt)
            {
            case 1:
                insertAtTheBeginning();
                break;
            case 2:
                insertAtTheEnd();
                break;
            case 3:
                insertAtTheSpecifiedLocation();
                break;
            default:
                printf("Invalid opration...!!\n");
                break;
            }
            break;

        case 4:
            Sum_Average();
            break;
        case 5:
            count_even_OR_odd();
            break;
        case 6:
            printf("\tWHERE DO YOU WANT TO DELETE:\t\n"
                   "1. From beginning\n"
                   "2. From end\n"
                   "3. At the specified position\n");

            printf("FROM WHERE DO YOU WANT TO DELETE\n");
            scanf("%d", &delAt);
            switch (delAt)
            {
            case 1:
                delAtTheBeginning();
                break;
            case 2:
                delAtTheEnd();
                break;
            case 3:
                delAtTheSpecifiedLocation();
                break;

            default:
                break;
            }
            break;

        default:
            printf("Invalid opration...!!\n");
            break;
        }
        printf("\n");
        printf("Do you want to continue again (y/n): ");
        scanf(" %c", &repeatOrNot);
    } while (repeatOrNot == 'y' || repeatOrNot == 'Y');
    return 0;
}

void create()
{
    struct NODE *ptr, *cpt;
    char ch;
    ptr = (struct NODE *)malloc(sizeof(struct NODE));

    printf("Enter information: ");
    scanf("%d", &ptr->info); // Use & to get the address of ptr->info
    head = ptr;

    do
    {
        cpt = (struct NODE *)malloc(sizeof(struct NODE));
        printf("Enter the information: ");
        scanf("%d", &cpt->info);
        ptr->link = cpt; // This effectively links the current node to the newly created node in the linked list.
        ptr = cpt;       // Update ptr to point to the newly created node cpt
        printf("Pass y/n:");
        scanf(" %c", &ch); // Use space before %c to consume the newline character
    } while (ch == 'y');
    ptr->link = NULL;
}

void traversing_LL()
{
    struct NODE *ptr;
    if (head == NULL)
    {
        printf("List is Empty");
        return;
    }
    ptr = head;
    printf("Linked List Elements: ");
    while (ptr != NULL)
    {
        printf(" %d", ptr->info);
        ptr = ptr->link;
    }
}

void insertAtTheBeginning()
{
    int value;
    struct NODE *newNode;
    newNode = (struct NODE *)malloc(sizeof(struct NODE));
    if (newNode == NULL)
    {
        printf("Overflow");
        return;
    }
    printf("Enter the value to insert: ");
    scanf("%d", &value);
    newNode->info = value;
    newNode->link = head;
    head = newNode;
}

void insertAtTheEnd()
{
    int value;
    struct NODE *newNode, *temp; // we are using temp to traverse through linked list to append a new node at the end of it
    newNode = (struct NODE *)malloc(sizeof(struct NODE));
    if (newNode == NULL)
    {
        printf("Overflow");
    }
    printf("Enter the value: ");
    scanf("%d", &value);
    newNode->info = value;
    newNode->link = NULL;
    temp = head;
    while (temp->link != NULL)
    {
        temp = temp->link;
    }
    temp->link = newNode;
}

void insertAtTheSpecifiedLocation()
{
    int value;
    int key;
    struct NODE *newNode, *temp;
    newNode = (struct NODE *)malloc(sizeof(struct NODE));
    if (newNode == NULL)
    {
        printf("Overflow");
        return;
    }
    printf("Enter the the value to insert: ");
    scanf("%d", &value);
    newNode->info = value;
    printf("Enter the KEY after which to insert: ");
    scanf("%d", &key);
    temp = head;
    while (temp != NULL && temp->info != key)
    {
        temp = temp->link; // temp moves to the next node using temp->link.
    }
    // if (temp == NULL)
    // {
    //     printf("Key not found in the list.");
    //     free(newNode); // Free memory allocated for newNode
    //     return;
    // }  error handeling
    newNode->link = temp->link;
    temp->link = newNode;
}

void Sum_Average()
{
    int sum = 0, avg = 0, count = 0;
    struct NODE *sum_ptr;
    sum_ptr = head;
    printf("FIND THE SUM AND AVERAGE OF INFO IN THE LINKED LIST\n");
    if (sum_ptr == NULL)
    {
        printf("The list is empty.\n");
        return;
    }
    while (sum_ptr != NULL)
    {
        sum += sum_ptr->info;
        count++;
        sum_ptr = sum_ptr->link;
    }
    (float)avg = sum / count;
    printf("The Sum of Information is: %d\n", sum);
    printf("The average of Information is: %f\n", avg);
    printf("The")
}

void count_even_OR_odd()
{
    int count_even = 0, count_odd = 0;
    struct NODE *count_ptr;
    count_ptr = head;
    while (count_ptr != NULL)
    {
        if (count_ptr->info % 2 == 0)
        {
            count_even++;
        }
        else
        {
            count_odd++;
        }
    }
    printf("Frequency of EVEN and ODD numbers are %d and %d respectively.", count_even, count_odd);
}

void delAtTheBeginning()
{
    struct NODE *temp;
    if (head == NULL)
    {
        printf("Underflow");
        return;
    }
    temp = head;
    head = temp->link;
    free(temp);
}

void delAtTheEnd()
{
    struct NODE *temp_ptr, *p_ptr;
    if (head == NULL)
    {
        printf("Underflow");
        return;
    }
    temp_ptr = head;
    while (temp_ptr->link != NULL)
    {
        p_ptr = temp_ptr;
        temp_ptr = temp_ptr->link;
    }
    p_ptr->link = NULL;
    free(temp_ptr);
}

void delAtTheSpecifiedLocation()
{
    int data;
    struct NODE *temp_ptr, *p_ptr = NULL;
    if (head == NULL)
    {
        printf("Underflow");
        return;
    }
    printf("Read data which is to be deleted: ");
    scanf(" %d", &data);

    temp_ptr = head;
    while (temp_ptr != NULL)
    {
        if (temp_ptr->info == data)
        {
            if (p_ptr == NULL)
            {
                head = temp_ptr->link;
            }
            else
            {
                p_ptr->link = temp_ptr->link;
            }
            free(temp_ptr); // Free memory of the node to be deleted
            return;
        }
        p_ptr = temp_ptr;
        temp_ptr = temp_ptr->link;
    }
    printf("Node with data %d not found\n", data);
}

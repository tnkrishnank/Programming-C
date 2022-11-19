#include <stdio.h>
#include <stdlib.h>

void insBeg();
void insMid();
void insEnd();
void delBeg();
void delMid();
void delEnd();
void display();

typedef struct node
{
    int data;
    struct node *next;
}node;

node *head = NULL;

int main()
{
    int ch = 0;

    while(1)
    {
        printf("1. Insert a new node at beginning of  the list\n");
        printf("2. Insert a new node after the node which has the element 'd'\n");
        printf("3. Insert a new node at end to the list\n");
        printf("4. Delete the first node of the list\n");
        printf("5. Delete an existing node which is placed after the node which has the element 'd'\n");
        printf("6. Delete the last node of the list\n");
        printf("7. Display the elements of the list \n");
        printf("0. Exit\n");

        printf("\nEnter your choice : ");
        scanf("%d",&ch);

        printf("\n");
        switch(ch)
        {
            case 1:
                insBeg();
                break;
            case 2:
                insMid();
                break;
            case 3:
                insEnd();
                break;
            case 4:
                delBeg();
                break;
            case 5:
                delMid();
                break;
            case 6:
                delEnd();
                break;
            case 7:
                display();
                break;
            case 0:
                exit(0);
            default:
                printf("INVALID CHOICE !!!\n");
        }

        printf("\n");
    }

    return 0;
}

void insBeg()
{
    node *newnode;
    newnode = (node*)malloc(sizeof(node));

    printf("Enter the data to insert : ");
    scanf("%d",&newnode->data);

    if(head == NULL)
    {
        head = newnode;
        newnode->next = NULL;
    }
    else
    {
        newnode->next = head;
        head = newnode;
    }
    printf("\nDATA INSERTED SUCCESSFULLY\n");
}

void insMid()
{
    int after;

    node *newnode, *current = head;
    newnode = (node*)malloc(sizeof(node));

    if(head == NULL)
    {
        printf("Your list is empty, node will be inserted at the beginning\n");
        insBeg();
        printf("\nDATA INSERTED SUCCESSFULLY\n");
    }
    else
    {
        printf("Enter the data to insert : ");
        scanf("%d",&newnode->data);

        printf("Enter the data after which you want to insert the node : ");
        scanf("%d",&after);

        while((current->data != after) && (current->next != NULL))
        {
            current = current->next;
        }
        if((current->data == after) && (current->next == NULL))
        {
            newnode->next = NULL;
            current->next = newnode;
            printf("\nDATA INSERTED SUCCESSFULLY\n");
        }
        else if(current->data == after)
        {
            newnode->next = current->next;
            current->next = newnode;
            printf("\nDATA INSERTED SUCCESSFULLY\n");
        }
        else
        {
            printf("The data after which you want to insert is not available\n");
        }
    }
}

void insEnd()
{
    node *newnode, *current = head;
    newnode = (node*)malloc(sizeof(node));

    if(head == NULL)
    {
        insBeg();
    }
    else
    {
        printf("Enter the data to insert : ");
        scanf("%d",&newnode->data);

        while((current->next) != NULL)
        {
            current = current->next;
        }

        newnode->next = NULL;
        current->next = newnode;
    }
    printf("\nDATA INSERTED SUCCESSFULLY\n");
}

void delBeg()
{
    node *delnode;
    delnode = (node*)malloc(sizeof(node));

    if(head == NULL)
    {
        printf("The list is empty\n");
    }
    else
    {
        delnode = head;
        head = delnode->next;
        free(delnode);
        printf("DATA DELETED SUCCESSFULLY\n");
    }
}

void delMid()
{
    int after;

    node *delnode, *current = head;
    delnode = (node*)malloc(sizeof(node));

    if(head == NULL)
    {
        printf("The list is empty\n");
    }
    else
    {
        printf("Enter the data after which you want to delete the node : ");
        scanf("%d",&after);

        while((current->data != after) && (current->next != NULL))
        {
            current = current->next;
        }
        if((current->data == after) && (current->next != NULL) && ((current->next)->next != NULL))
        {
            delnode = current->next;
            current->next = delnode->next;
            free(delnode);
            printf("\nDATA DELETED SUCCESSFULLY\n");
        }
        else if((current->data == after) && ((current->next)->next == NULL))
        {
            delnode = current->next;
            current->next = NULL;
            free(delnode);
            printf("\nDATA DELETED SUCCESSFULLY\n");
        }
        else if(current->data == after)
        {
            printf("There is no node available after the data you selected\n");
        }
        else
        {
            printf("The data after which you want to delete is not available\n");
        }
    }
}

void delEnd()
{
    int temp;

    node *delnode, *current = head;
    delnode = (node*)malloc(sizeof(node));

    if(head == NULL)
    {
        printf("The list is empty\n");
    }
    else
    {
        while((current->next) != NULL)
        {
            delnode = current;
            current = current->next;
            temp = 1;
        }

        if(temp == 0)
        {
            head = NULL;
            printf("DATA DELETED SUCCESSFULLY\n");
        }
        else
        {
            delnode->next = NULL;
            printf("DATA DELETED SUCCESSFULLY\n");
        }
        free(current);
    }
}

void display()
{
    node *current = head;

    printf("HEAD --> ");
    while(current != NULL)
    {
        printf("%d --> ",current->data);
        current = current->next;
    }
    printf("NULL\n");
}

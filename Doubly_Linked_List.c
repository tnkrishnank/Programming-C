#include <stdio.h>
#include <stdlib.h>

void insBeg();
void insMidA();
void insMidB();
void insEnd();
void delBeg();
void delMidA();
void delMidB();
void delMid();
void delEnd();
void display();

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
}node;

node *head = NULL;

int main()
{
    int ch = 0;

    while(1)
    {
        printf("1.  Insert a new node at beginning of  the list\n");
        printf("2.  Insert a new node after the node which has the element 'd'\n");
        printf("3.  Insert a new node before the node which has the element 'd'\n");
        printf("4.  Insert a new node at end to the list\n");
        printf("5.  Delete the first node of the list\n");
        printf("6.  Delete an existing node which is placed after the node which has the element 'd'\n");
        printf("7.  Delete an existing node which is placed before the node which has the element 'd'\n");
        printf("8.  Delete an existing node which has the element 'd'\n");
        printf("9.  Delete the last node of the list\n");
        printf("10. Display the elements of the list \n");
        printf("0.  Exit\n");

        printf("\nEnter your choice : ");
        scanf("%d",&ch);

        printf("\n");
        switch(ch)
        {
            case 1:
                insBeg();
                break;
            case 2:
                insMidA();
                break;
            case 3:
                insMidB();
                break;
            case 4:
                insEnd();
                break;
            case 5:
                delBeg();
                break;
            case 6:
                delMidA();
                break;
            case 7:
                delMidB();
                break;
            case 8:
                delMid();
                break;
            case 9:
                delEnd();
                break;
            case 10:
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
        newnode->prev = NULL;
        newnode->next = NULL;
    }
    else
    {
        newnode->prev = NULL;
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
    printf("\nDATA INSERTED SUCCESSFULLY\n");
}

void insMidA()
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
            newnode->prev = current;
            current->next = newnode;
            printf("\nDATA INSERTED SUCCESSFULLY\n");
        }
        else if(current->data == after)
        {
            newnode->next = current->next;
            (current->next)->prev = newnode;
            current->next = newnode;
            newnode->prev = current;
            printf("\nDATA INSERTED SUCCESSFULLY\n");
        }
        else
        {
            printf("The data after which you want to insert is not available\n");
        }
    }
}

void insMidB()
{
    int before;

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

        printf("Enter the data before which you want to insert the node : ");
        scanf("%d",&before);

        while((current->data != before) && (current->next != NULL))
        {
            current = current->next;
        }
        if(current == head && current->data == before)
        {
            newnode->prev = NULL;
            newnode->next = current;
            current->prev = newnode;
            head = newnode;
            printf("\nDATA INSERTED SUCCESSFULLY\n");
        }
        else if(current->data == before)
        {
            newnode->prev = current->prev;
            (current->prev)->next = newnode;
            newnode->next = current;
            current->prev = newnode;
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
        newnode->prev = current;
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
        head->prev = NULL;
        printf("DATA DELETED SUCCESSFULLY\n");
    }
}

void delMidA()
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
        if((current->data == after) && (current->next != NULL))
        {
            if ((current->next)->next == NULL)
            {
                delnode = current->next;
                current->next = NULL;
                free(delnode);
                printf("\nDATA DELETED SUCCESSFULLY\n");
            }
            else
            {
                delnode = current->next;
                current->next = delnode->next;
                (delnode->next)->prev = current;
                free(delnode);
                printf("\nDATA DELETED SUCCESSFULLY\n");
            }
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

void delMidB()
{
    int before;

    node *delnode, *current = head;
    delnode = (node*)malloc(sizeof(node));

    if(head == NULL)
    {
        printf("The list is empty\n");
    }
    else
    {
        printf("Enter the data before which you want to delete the node : ");
        scanf("%d",&before);

        while((current->data != before) && (current->next != NULL))
        {
            current = current->next;
        }
        if((current == head) && (current->data == before))
        {
            printf("There is no node available before the data you selected\n");
        }
        else if((current->data == before) && ((current->prev)->prev != NULL))
        {
            delnode = current->prev;
            current->prev = delnode->prev;
            (delnode->prev)->next = current;
            free(delnode);
            printf("\nDATA DELETED SUCCESSFULLY\n");
        }
        else if((current->data == before) && ((current->prev)->prev == NULL))
        {
            delnode = current->prev;
            current->prev = NULL;
            head = current;
            free(delnode);
            printf("\nDATA DELETED SUCCESSFULLY\n");
        }
        else
        {
            printf("The data before which you want to delete is not available\n");
        }
    }
}

void delMid()
{
    int del;

    node *current = head;

    if(head == NULL)
    {
        printf("The list is empty\n");
    }
    else
    {
        printf("Enter the data which you want to delete : ");
        scanf("%d",&del);

        while((current->data != del) && (current->next != NULL))
        {
            current = current->next;
        }
        if(current == head && current->data == del)
        {
            head = current->next;
            (current->next)->prev = NULL;
            free(current);
            printf("\nDATA DELETED SUCCESSFULLY\n");
        }
        else if(current->next == NULL && current->data == del)
        {
            (current->prev)->next = NULL;
            free(current);
            printf("\nDATA DELETED SUCCESSFULLY\n");
        }
        else if(current->data == del)
        {
            (current->prev)->next = current->next;
            (current->next)->prev = current->prev;
            free(current);
            printf("\nDATA DELETED SUCCESSFULLY\n");
        }
        else
        {
            printf("There is no node available with the data you selected\n");
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

#include <stdio.h>
#include <stdlib.h>

void append();
void concat();
void nfree();
void reverse();
void dellast();
void deln(int c);
void forCombine(int d);
void combine();
int check(int d);
void lunion();
void intersect();
void insert();
void delsec();
void incorder();
int sum();
int number();
void move();
void copy();
void display();
int chooselist();
void change(int h);

typedef struct node
{
    int data;
    struct node *next;
}node;

node *head1 = NULL;
node *head2 = NULL;
node *head3 = NULL;
node *head = NULL;

int main()
{
    int ch;
    int h;
    int c;

    h = chooselist();

    while(1)
    {
        printf("\n");
        printf("1.  Append an element to the end of a list\n");
        printf("2.  Concatenate two lists\n");
        printf("3.  Free all the nodes in a list\n");
        printf("4.  Reverse a list, so that the last element becomes the first, and so on\n");
        printf("5.  Delete the last element from a list\n");
        printf("6.  Delete the nth element from a list\n");
        printf("7.  Combine two ordered lists into a single ordered list\n");
        printf("8.  Form a list containing the union of the elements of two lists\n");
        printf("9.  Form a list containing the intersection of the elements of two lists\n");
        printf("10. Insert an element after the nth element of a list\n");
        printf("11. Delete every second element from a list\n");
        printf("12. Place the elements of a list in increasing order\n");
        printf("13. Return the sum of the integers in a list\n");
        printf("14. Return the number of elements in a list\n");
        printf("15. Move node(p) forward n positions in a list\n");
        printf("16. Make a second copy of a list\n");
        printf("17. Change list\n");
        printf("0.  Exit\n");

        printf("\nENTER YOUR CHOICE : ");
        scanf("%d",&ch);
        printf("\n");

        switch(ch)
        {
        case 1:
            append();
            display();
            break;
        case 2:
            concat();
            display();
            break;
        case 3:
            nfree();
            display();
            break;
        case 4:
            reverse();
            display();
            break;
        case 5:
            dellast();
            display();
            break;
        case 6:
            printf("ENTER POSITION OF ELEMENT TO BE DELETED : ");
            scanf("%d",&c);
            deln(c);
            display();
            break;
        case 7:
            combine();
            display();
            break;
        case 8:
            lunion();
            break;
        case 9:
            intersect();
            break;
        case 10:
            insert();
            display();
            break;
        case 11:
            delsec();
            display();
            break;
        case 12:
            incorder();
            display();
            break;
        case 13:
            printf("SUM OF ALL ELEMENTS : %d\n",sum());
            break;
        case 14:
            printf("NUMBER OF ELEMENTS : %d\n",number());
            break;
        case 15:
            move();
            display();
            break;
        case 16:
            copy();
            display();
            break;
        case 17:
            h = chooselist();
            break;
        case 0:
            exit(0);
        default :
            printf("INVALID CHOICE !!!\n");
        }

        change(h);
    }

    return 0;
}

void append()
{
    node *newnode, *current = head;
    newnode = (node*)malloc(sizeof(node));

    printf("ENTER DATA TO INSERT : ");
    scanf("%d",&newnode->data);

    if(head == NULL)
    {
        head = newnode;
        newnode->next = NULL;
    }
    else
    {
        while((current->next) != NULL)
        {
            current = current->next;
        }
        newnode->next = NULL;
        current->next = newnode;
    }

    printf("\nDATA INSERTED SUCCESSFULLY\n");
}

void concat()
{
    node *newnode, *current, *temp, *store;
    current = (node*)malloc(sizeof(node));

    store = head;

    current = head;
    while(current != NULL)
    {
        temp = current;
        current = current->next;
    }

    if(head == head1)
    {
        if(head2 != NULL)
        {
            temp->next = head2;
            head2 = NULL;
        }
    }
    else
    {
        if(head1 != NULL)
        {
            temp->next = head1;
            head1 = NULL;
        }
    }

    temp = temp->next;

    if(temp != NULL)
    {
        head = temp;

        copy();

        head = store;

        if(head == head1)
        {
            head2 = head3;
        }
        else
        {
            head1 = head3;
        }
        head3 = NULL;
    }
}

void nfree()
{
    node *current = head, *temp;

    while(current != NULL)
    {
        temp = current;
        current = current->next;
        free(temp);
    }

    head = current;
}

void reverse()
{
    node *current, *prev, *next;

    current = head;
    if(current != NULL)
    {
        prev = current;
        next = current->next;
        prev->next = NULL;
        current = next;
    }
    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
}

void dellast()
{
    int temp = 0;

    node *delnode, *current = head;
    delnode = (node*)malloc(sizeof(node));

    if(head == NULL)
    {
        printf("LIST IS EMPTY\n");
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

void deln(int c)
{
    int n;

    node *current, *temp;
    current = (node*)malloc(sizeof(node));
    temp = (node*)malloc(sizeof(node));

    n = number();

    if(c < n)
    {
        n = 0;

        if(head == NULL)
        {
            printf("LIST IS EMPTY\n");
        }
        else
        {
            current = head;

            if(c == 0)
            {
                head = current->next;
            }
            else
            {
                temp = current;

                while(n != c)
                {
                    n++;
                    temp = current;
                    current = current->next;
                }

                temp->next = current->next;
            }

            free(current);
        }
    }
    else
    {
        printf("POSITION NOT AVAILABLE\n");
    }
}

void forCombine(int d)
{
    node *current, *newnode;
    current = (node*)malloc(sizeof(node));
    newnode = (node*)malloc(sizeof(node));

    newnode->data = d;

    if(head3 == NULL)
    {
        head3 = newnode;
        newnode->next = NULL;
    }
    else
    {
        current = head3;
        while((current->next) != NULL)
        {
            current = current->next;
        }

        current->next = newnode;
        newnode->next = NULL;
    }
}

void combine()
{
    concat();
    incorder();
}

int check(int d)
{
    node *current;
    current = (node*)malloc(sizeof(node));

    current = head3;

    while(current != NULL)
    {
        if((current->data) == d)
            return 1;

        current = current->next;
    }

    return 0;
}


void lunion()
{
    int f;

    node *current, *store;
    current = (node*)malloc(sizeof(node));

    store = head;

    current = head;

    if(head3 != NULL)
    {
        head = head3;
        nfree();
        head3 = head;
    }

    while(current != NULL)
    {
        forCombine(current->data);
        current = current->next;
    }

    if(head == head1)
    {
        if(head2 != NULL)
        {
            current = head2;
        }
    }
    else
    {
        if(head1 != NULL)
        {
            current = head1;
        }
    }

    while(current != NULL)
    {
        f = check(current->data);

        if(f == 0)
            forCombine(current->data);

        current = current->next;
    }

    head = head3;
    display();
    head = store;
}

void intersect()
{
    node *current1, *current2, *store, *temp;
    current1 = (node*)malloc(sizeof(node));
    current2 = (node*)malloc(sizeof(node));

    store = head;

    if(head3 != NULL)
    {
        head = head3;
        nfree();
        head3 = head;
    }

    if(head == head1)
    {
        if(head2 != NULL)
        {
            current2 = head2;
            temp = head2;
        }
    }
    else
    {
        if(head1 != NULL)
        {
            current2 = head1;
            temp = head1;
        }
    }

    current1 = head;
    while(current1 != NULL)
    {
        current2 = temp;
        while(current2 != NULL)
        {
            if((current1->data) == (current2->data))
                forCombine(current1->data);

            current2 = current2->next;
        }
        current1 = current1->next;
    }

    head = head3;
    display();
    head = store;
}

void insert()
{
    int c;
    int n;

    node *current, *newnode;
    current = (node*)malloc(sizeof(node));
    newnode = (node*)malloc(sizeof(node));

    printf("ENTER THE POSITION AFTER WHICH YOU WANT TO INSERT AN ELEMENT : ");
    scanf("%d",&n);
    printf("ENTER THE ELEMENT TO INSERT : ");
    scanf("%d",&newnode->data);

    c = number();

    if(n < c)
    {
        c = 0;

        if(head == NULL)
        {
            printf("LIST IS EMPTY\n");
        }
        else
        {
            current = head;
            while(c < n)
            {
                c++;
                current = current->next;
            }
            newnode->next = current->next;
            current->next = newnode;
        }
    }
    else
    {
        printf("POSITION OUT OF RANGE\n");
    }
}

void delsec()
{
    int n;
    int i;

    n = number();
    if(n != 0)
    {
        n = n - 1;

        if((n % 2) == 0)
            n = n - 1;

        for(i = n; i >= 0; i -= 2)
            deln(i);
    }
    else
    {
        printf("LIST IS EMPTY\n");
    }
}

void incorder()
{
    node *current1, *current2;

    int n;

    current1 = head;
    while(current1->next != NULL)
    {
        n = current1->data;
        current2 = current1->next;
        while(current2 != NULL)
        {
            if(current2->data < n)
            {
                n = current2->data;
                current2->data = current1->data;
                current1->data = n;
            }
            current2 = current2->next;
        }
        current1 = current1->next;
    }
}

int sum()
{
    int n = 0;

    node *current, *temp;
    current = (node*)malloc(sizeof(node));

    current = head;
    while(current != NULL)
    {
        n += current->data;
        current = current->next;
    }

    return n;
}

int number()
{
    int n = 1;

    node *current;
    current = (node*)malloc(sizeof(node));

    if(head == NULL)
    {
        n = 0;
    }
    else
    {
        current = head;
        while(current->next != NULL)
        {
            n++;
            current = current->next;
        }
    }

    return n;
}

void move()
{
    node *current, *temp;
    int n;
    int p;
    int c;

    n = number();

    printf("ENTER THE POSITION OF THE NODE TO MOVE : ");
    scanf("%d",&p);

    printf("ENTER THE NUMBER OF POSITIONS TO MOVE FORWARD : ");
    scanf("%d",&c);

    if((p+c) >= n)
    {
        printf("OUT OF RANGE\n");
    }
    else if(p != 0)
    {
        n = 0;

        current = head;
        while(n < p)
        {
            n++;
            temp = current;
            current = current->next;
        }
        temp->next = current->next;

        n = 0;

        while(n < c)
        {
            n++;
            temp = temp->next;
        }
        current->next = temp->next;
        temp->next = current;
    }
    else
    {
        current = head;
        head = head->next;
        temp = head;

        n = 0;

        while(n < (c-1))
        {
            n++;
            temp = temp->next;
        }
        current->next = temp->next;
        temp->next = current;
    }
}

void copy()
{
    node *newnode, *current, *temp;

    current = head;

    if(head3 != NULL)
    {
        head = head3;
        nfree();
        head3 = head;
    }

    head = current;

    newnode = (node*)malloc(sizeof(node));
    newnode->next = NULL;
    head3 = newnode;
    newnode->data = current->data;
    temp = newnode;

    while(current->next != NULL)
    {
        current = current->next;
        temp->next = (node*)malloc(sizeof(node));
        (temp->next)->data = current->data;
        temp = temp->next;
        temp->next = NULL;
    }
}

void display()
{
    node *current = head;
    printf("\n");
    printf("HEAD --> ");
    while(current != NULL)
    {
        printf("%d --> ",current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int chooselist()
{
    int ch;

    printf("ENTER THE LIST NUMBER TO MAKE CHANGES (1 OR 2) : ");
    scanf("%d",&ch);

    if(ch == 1)
    {
        head = head1;
        display();
        return 1;
    }
    else if(ch == 2)
    {
        head = head2;
        display();
        return 2;
    }
    else
    {
        printf("\nINVALID CHOICE !!!\n\n");
        chooselist();
    }
}

void change(int h)
{
    if(h == 1)
    {
        head1 = head;
    }
    else
    {
        head2 = head;
    }
}

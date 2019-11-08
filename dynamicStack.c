#include <stdio.h>  //LIFO
#include <conio.h>

struct number
{
    int n;
    struct number *next;
};

typedef struct number node;  // allows us to create a short form for something,,,so here node now is = struct number,,,,so where ever there is node it = struct number

node *head=NULL;  // node isnt a keyword , but it is used. its a one unit in a list
// global var
void push(int x)
{
    node *tmp=(node *)malloc(sizeof(node));
    if(tmp==NULL)
    {
        printf("memory over");
    }
    else
    {
        tmp -> n=x;
        tmp -> next=NULL;
        if(head==NULL)
        {
            head=tmp;
        }
        else
        {
            tmp -> next=head;
            head =tmp;
        }
    }
}

void pop()
{
    node *ptr=head;
    if(ptr==NULL)
    {
        printf("stack is empty");
    }
    else
    {
        printf("%d\n",ptr->n);
        head=head->next;
        free(ptr); //dletes where ptr is
    }
}

void count()
{
    node *ptr=head;
    int c=0;
    while(ptr!=NULL)
    {
        c++;
        ptr= ptr->next;
    }
    printf("no. of nodes %d\n",c);
}

void display()
{
    node *ptr=head;
    if(ptr==NULL)
    {
        printf("stack is empty");
    }
    else
    {
        while(ptr!=NULL)
        {
            printf("%d\n",ptr->n);
            ptr=ptr->next;
        }
    }
}

void main()
{
     int ch,a;
    do
    {
        printf("\nMENU\n1.PUSH\n2.POP\n3.COUNT\n4.DISPLAY\n5.EXIT\nENTER CHOICE\n\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("enter a no.\n");
                scanf("%d",&a);
                push(a);
                break;

            case 2:
                pop();
                break;

            case 3:
                count();
                break;
            case 4:
                printf("\n");
                display();
                break;
            case 5:
                printf("Exiting, thank you :-)");
                break;
            default:
                printf("Invalid");
        }
    }while(ch!=5);
}


//undo redo lifo
//recurssion
// infix to postfix
// benches
// plate dispenser





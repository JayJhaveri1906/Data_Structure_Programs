#include <stdio.h>  //LIFO
#include <conio.h>
#include <string.h>

struct number
{
    char n[100];
    struct number *next;
};

typedef struct number node;  // allows us to create a short form for something,,,so here node now is = struct number,,,,so where ever there is node it = struct number

node *head=NULL;  // node isnt a keyword , but it is used. its a one unit in a list
// global var
void push()
{
    node *tmp=(node *)malloc(sizeof(node));
    if(tmp==NULL)
    {
        printf("memory over");
    }
    else
    {
        printf("enter a string\n");
        scanf("%s",tmp ->n);
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
        printf("%s\n",ptr->n);
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
            puts(ptr->n);
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

                push();
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





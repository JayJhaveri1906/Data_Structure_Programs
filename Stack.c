//STACK     LIFO

#include <stdio.h>
int a[5],top=-1;

void push(int x)
{
    if(top==4)
    {
        printf("STACK is FULL");
    }
    else
    {
        a[++top]=x;
    }
}


void pop()
{
    if(top==-1)
    {
        printf("STACK is EMPTY");
    }
    else
    {
        printf("%d\n",a[top--]);
    }
}

void count()
{
    printf("%d\n",top+1);
}

void display()
{
    if(top==-1)
    {
        printf("STACK is EMPTY");
    }
    else
    {
        int i;
        for(i=top;i>=0;i--)
            printf("%d\n",a[i]);
    }
}

void main()
{
    int ch,n;
    do
    {
        printf("\nMENU\n1.PUSH\n2.POP\n3.COUNT\n4.DISPLAY\n5.EXIT\nENTER CHOICE");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("ENTER A NUMBER ");
            scanf("%d",&n);
            push(n);
            break;
        case 2:
            pop();
            break;
        case 3:
            count();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Exiting");
            break;
        default:
            printf("Invalid");
        }
    }while(ch!=5);
}

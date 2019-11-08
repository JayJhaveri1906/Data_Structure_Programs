//QUEUE     FIFO

#include <stdio.h>
int a[5],front=-1,rear=-1;

void addElement(int x)
{
    if(rear==4)
    {
        printf("Q is FULL\n");
    }
    else
    {
        if(front==-1)
        {
            front=rear=0;
        }
        else
        {
            rear++;
        }
        a[rear]=x;
    }
}


void removeElement()
{
    if(rear==-1)
    {
        printf("Q is EMPTY\n");
    }
    else
    {
        printf("%d\n",a[front]);
        front++;

        if(front>rear)
            front=rear=-1;
    }
}

void count()
{
    printf("%d\n",rear-front+1);
}

void display()
{
    if(rear==-1)
    {
        printf("Q is EMPTY");
    }
    else
    {
        int i;
        for(i=front;i<=rear;i++)
            printf("%d\n",a[i]);
    }
}

void main()
{
    int ch,n;
    do
    {
        printf("\nMENU\n1.ADD ELEMENT\n2.REMOVE ELEMENT\n3.COUNT\n4.DISPLAY\n5.EXIT\nENTER CHOICE");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("ENTER A NUMBER ");
            scanf("%d",&n);
            addElement(n);
            break;
        case 2:
            removeElement();
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

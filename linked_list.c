#include <stdio.h>

struct Number
{
    int n;
    struct Number *next;
};

typedef struct Number Node;

Node *head=NULL;
Node *head2=NULL;


void addAtBegin(int x)
{
    Node *temp=(Node *)malloc(sizeof(Node));
    if(temp==NULL)
    {
        printf("insufficient memory");
    }
    else
    {
        temp ->n=x;
        temp ->next=NULL;
        if(head==NULL)
        {
            head=temp;
        }
        else
        {
            temp->next=head;
            head=temp;
        }
    }

}

void addAtEnd(int x)
{
    Node *temp=(Node *)malloc(sizeof(Node));
    if(temp==NULL)
    {
        printf("insufficient memory");
    }
    else
    {
        temp ->n=x;
        temp ->next=NULL;
        if(head==NULL)
        {
            head=temp;
        }
        else
        {
            Node *ptr=head;
            while(ptr->next!=NULL)   // if written ptr!=NULL then ptr ka n will also go till null lul
            {
                ptr=ptr->next;
            }
            ptr->next=temp;
        }
    }
}

void insertByPos(int x,int p)
{
    int c=count();
    if(p<1 || p>c+1)
    {
        printf("Invalid pos");
    }
    else if(p==1)
    {
        addAtBegin(x);
    }
    else if(p==c+1)
    {
        addAtEnd(x);
    }
    else
    {
        Node *temp=(Node *)malloc(sizeof(Node));
        if(temp==NULL)
        {
            printf("insufficient memory");
        }
        else
        {
            temp ->n=x;
            temp->next=NULL;
            int i;
            Node *ptr2=head,*ptr1=head;
            for(i=1;i<p;i++)
            {
                ptr2=ptr1;
                ptr1=ptr1->next;
            }
            temp->next=ptr1;
            ptr2->next=temp;
        }
    }
}
void display()
{
    Node *ptr=head;
    if(ptr==NULL)
    {
        printf("stack is empty\n");
    }
    else
    {
        printf("\n");
        while(ptr!=NULL)
        {
            printf("%d\n",ptr->n);
            ptr=ptr->next;
        }
    }

    if(head2!=NULL)
    {
        Node *ptr1=head2;
        printf("\nprinting 2nd part \n");
        while(ptr1!=NULL)
        {
            printf("%d\n",ptr1->n);
            ptr1=ptr1->next;
        }
    }
}

int count()
{
    Node *ptr=head;
    int c;
    if(head==NULL)
    {
        c=0;
    }
    else
    {
        printf("\n");
        while(ptr!=NULL)
        {
            c++;
            ptr=ptr->next;

        }
    }
    return c;
}


void deleteAtBegin()
{
    Node *ptr=head;
    if(ptr==NULL)
    {
        printf("stack is empty\n");
    }
    else
    {
        printf("%d\n",ptr->n);
        head=head->next;
        free(ptr); //deletes where ptr is
    }
}

void deleteAtEnd()
{
    if(head==NULL)
    {
        printf("stack is empty\n");
    }
    else
    {
        if(head->next==NULL)
        {
            printf("removing %d \n",head->n);
            head=NULL;
        }
        else
        {
            Node *ptr1=head;
            Node *ptr2=head;
            while(ptr2->next!=NULL)
            {
                ptr1=ptr2;
                ptr2=ptr2->next;
            }
            ptr1->next=NULL;
            printf("removing %d \n",ptr2->n);
            ptr2=NULL;
        }
    }
}

void deleteByPos(int p)
{
    int c=count();
    if(p<1 || p>c)
    {
        printf("Invalid pos\n");
    }
    else if(p==1)
    {
        deleteAtBegin();
    }
    else if(p==c)
    {
        deleteAtEnd();
    }
    else
    {
        Node *ptr1=head;
        Node *ptr2=head;
        int i;
        for(i=1;i<p;i++)
        {
            ptr1=ptr2;
            ptr2=ptr2->next;
        }
        ptr1->next=ptr2->next;
        printf("removing %d \n",ptr2->n);
        free(ptr2);
    }
}

void search(int x)
{
    if(head == NULL)
    {
        printf("empty");
    }
    else
    {
        Node *ptr=head;
        int f=0,i=0;
        while(ptr!=NULL)
        {
            if(ptr->n==x)
            {
                printf("found at %d",(i+1));
                f=1;
            }
            ptr=ptr->next;
            i++;
        }
        if(f==0)
        {
            printf("Not found");
        }
    }
}

void largest()
{
    if(head==NULL)
    {
        printf("empty");
    }
    else if(head->next==NULL)
    {
        printf("max = %d", head ->n);
    }
    else
    {
        Node *ptr = head;
        int max=-1;
        int i=0;
        for(i=0;ptr!=NULL;i++,ptr= ptr->next)
        {
            if(ptr->n>max)
            {
                max = ptr->n;
            }
        }
        printf("max = %d",max);
    }
}

void smallest()
{
    if(head==NULL)
    {
        printf("empty");
    }
    else if(head->next==NULL)
    {
        printf("Smallest = %d", head ->n);
    }
    else
    {
        Node *ptr = head;
        int small=-1;
        int i=0;
        for(i=0;ptr!=NULL;i++,ptr= ptr->next)
        {
            if(ptr->n>small)
            {
                small = ptr->n;
            }
        }
        printf("smallest = %d",small);
    }
}


void split(int p)
{
    int c=count();
    if(p<1 || p>c)
    {
        printf("Invalid pos");
    }
    else
    {
        if(head2!=NULL)
        {
            printf("already splitted sorry");
        }
        else
        {
            Node *ptr1=head;
            Node *ptr2=head;
            int i;
            for(i=1;i<p;i++)
            {
                ptr1=ptr2;
                ptr2=ptr2->next;
            }
            ptr1->next=NULL;
            head2=ptr2;
        }
    }
}

void merge()
{
    if(head2==NULL)
    {
        printf("not splitted yet\n");
    }
    else if(head==NULL)
    {
        printf("list 1 empty\n");
    }
    else
    {
        Node *ptr=head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=head2;
        head2=NULL;
        printf("Successfully merged\n");
    }
}

void main()
{
    int c,a,b;
    do
    {

        printf("\nMenu\n1)Add at beginning\n2)Add at end\n3)Insert by Pos\n4)Delete at begin\n5)Delete at end\n6)Delete by pos\n7)search\n8)display\n9)count\n10)Find Largest\n11)find smallest\n12)Split List\n13)Merge list\n14)Exit\nEnter your choice\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
                printf("Enter a no.\n");
                scanf("%d",&a);
                addAtBegin(a);
                break;

            case 2:
                printf("Enter a no.\n");
                scanf("%d",&a);
                addAtEnd(a);
                break;

            case 3:
                printf("Enter a no. and pos\n");
                scanf("%d%d",&a,&b);
                insertByPos(a,b);
                break;

            case 4:
                deleteAtBegin();
                break;

            case 5:
                deleteAtEnd();
                break;

            case 6:
                printf("Enter pos \n");
                scanf("%d",&a);
                deleteByPos(a);
                break;
            case 7:
                printf("Enter no. to be searched \n");
                scanf("%d",&a);
                search(a);
                break;
            case 8:
                display();
                break;
            case 9:
                printf("%d\n",count());
                break;
            case 10:
                largest();
                break;
            case 11:
                smallest();
                break;
            case 12:
                printf("Enter pos to be splitted from\n");
                scanf("%d",&a);
                split(a);
                break;
            case 13:
                merge();
                break;
            case 14:
                printf("Bye\n Thank you :)\n");
                break;
            default:
                printf("invalid\n");


        }
    }while(c!=14);
}





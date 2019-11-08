#include <stdio.h>
#include <conio.h>
#include <string.h>

void LinearSearchno(int a[],int n)
{
    int i,c=0;
    for(i=0;i<10;i++)
    {
        if(a[i]==n)
        {
            c=1;
            break;
        }
    }
    if(c!=0)
    {
        printf("found at %d\n",i+1);
    }
    else
    {
        printf("not found lol\n");
    }
}

void LinearSearchname(char a[][26],char n[])
{
    int i,c=0;
    for(i=0;i<10;i++)
    {
        if(strcmpi(a[i],n)==0)
        {
            c=1;
            break;
        }
    }
    if(c!=0)
    {
        printf("found at %d\n",i+1);
    }
    else
    {
        printf("not found lol\n");
    }
}

void binarySearchNO(int a[],int n)
{
    int ub=10,lb=0,m,c=0;
    while(ub>lb)
    {
        m=(lb+ub)/2;
        if(a[m]==n)
        {
            c=1;
            break;
        }
        else if(a[m]>n)
        {
            ub=m;
        }
        else if(a[m]<n)
        {
            lb=m+1;
        }
    }
     if(c!=0)
    {
        printf("found at %d\n",m+1);
    }
    else
    {
        printf("not found lol\n");
    }
}

void binarySearchName(char a[26],char n[])
{
    int ub=10,lb=0,m,c=0;
    while(ub>lb)
    {
        m=(lb+ub)/2;
        if(strcmpi(a[m],n)==0)
        {
            c=1;
            break;
        }
        else if(strcmpi(a[m],n)==1)
        {
            ub=m;
        }
        else if(strcmpi(a[m],n)==-1)
        {
            lb=m+1;
        }
    }
     if(c!=0)
    {
        printf("found at %d\n",m+1);
    }
    else
    {
        printf("not found lol\n");
    }
}

void main()
{
    int ch;
    int a[10],a1,i,n;
char b[10][26],b1[26];
    printf("enter 10 nos\n");
    for(i=0;i<10;i++)
    {

        printf("enter %d no\n",i+1);
        scanf("%d",&a[i]);
    }

    for(i=0;i<10;i++)
    {

        printf("enter %d name\n",i+1);
        scanf("%s",b[i]);
    }


    do
    {
        printf("\n1) Linear Search for nos \n2)Linear Search for names\n3)Binary search for nos.\n4)Binary search for name.\n5)exit\nEnter ur choice...\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("enter a no to be searched\n");
            scanf("%d",&n);
            LinearSearchno(a,n);
            break;

        case 2:
            printf("enter a name to be searched\n");
            scanf("%s",b1);
            LinearSearchname(b,b1);
            break;

        case 3:
            printf("enter a no to be searched\n");
            scanf("%d",&n);
            binarySearchNO(a,n);
            break;

        case 4:
            printf("enter a name to be searched\n");
            scanf("%s",b1);
            binarySearchName(b,b1);
            break;

        case 5:
            printf("bye thnx:-)\n");
            break;

        default:
            printf("invalid\n");
            break;

        }
    }while(ch!=5);

}

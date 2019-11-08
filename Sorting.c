#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void fillArray(int a[])
{
    int i;
    for(i=0;i<10;i++)
    {
        a[i]=(int)(rand()%100);
    }
}


void fillArrayNoLimit(int a[])
{
    int i;
    for(i=0;i<10;i++)
    {
        a[i]=(int)(rand()%2147483647);
    }
}


void display(int a[])
{
    int i;
    for(i=0;i<10;i++)
    {
        printf("%d\t",a[i]);
    }
}
void exchangeSelectionSort(int a[])
{
    int i,j,t;
    for(i=0;i<9;i++)
    {
        for(j=i+1;j<10;j++)
        {
            if(a[i]>a[j])
            {
                t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
    }
}

void selectionSort(int a[])
{
    int i,j,t,small,pos;
    for(i=0;i<10;i++)
    {
        pos=i;
        for(j=i+1;j<10;j++)
        {
            if(a[pos]>a[j])
            {
                pos=j;
            }
        }
        t=a[i];
        a[i]=a[pos];
        a[pos]=t;
    }
}


void bubbleSort(int a[])
{
    int i,j,t;
    for(i=9;i>=0;i--)
    {
        for(j=0;j<i;j++)
        {
            if(a[j]>a[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
}

void modifiedBubbleSort(int a[])
{
    int i,j,t,flag;
    for(i=9;i>=0;i--)
    {
        flag=0;
        for(j=0;j<i;j++)
        {
            if(a[j]>a[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
                flag=1;
            }
        }

        if(flag==0)
            break;
    }
}

/*void insertionSort(int a[])
{
    int i,j,temp,start=1;

    for(i=0;i<10;i++)
    {
        int t=start;
        temp=a[t];
        for(j=1;j<10;j++)
        {
            if(t-1==-1)
            {
                break;
            }
            else if(a[t-1]<a[t])
                break;
            else
            {

            }
        }
    }
}*/

// quick:-
void quickS(int a[],int st,int end)
{
    if(st<end)
    {
        int pIndex = part(a,st,end);
        quickS(a,st,pIndex-1);
        quickS(a,pIndex+1,end);
    }
}

int part(int a[],int st,int end)
{
    int pivot=a[end];
    int pIndex=st;
    int t;

    for(int i=st;i<=end-1;i++) // <=end - 1 because last one is pivot and we dont want to compare it
    {
        if(a[i]<=pivot)
        {
            t=a[i];
            a[i]=a[pIndex];
            a[pIndex]=t;
            pIndex++;
        }
    }
    a[end]=a[pIndex];
    a[pIndex]=pivot;
    return pIndex;
}

//merge sort:-

/*void Merge(int L[],int R[], int a[], int LC,int RC)
{
    int i,j,k;
    // i - to mark the index of left aubarray (L)
	// j - to mark the index of right sub-raay (R)
	// k - to mark the index of merged subarray (A)
	i=j=k=0;

	while(i<LC && j<RC)
    {
        if(L[i]<R[j])
        {
            A[k]=L[i];
            i++;
            k++;
        }
        else
        {
            A[k]=R[j];
            j++;
            k++;
        }
    }
    while(i<LC)
    {
        a[k]=L[i];
        i++;
        k++;
    }
    while(j<RC)
    {
        a[k]=R[j];
        j++;
        k++;
    }
}

void mergeS(int a[],int size)
{
    int mid,i,
}*/

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

//insertion sort
void insertionSort(int a[])
{
    int hole,value;
    for(int i=1;i<10;i++)
    {
        hole=i;
        value=a[i];
        while(hole>0 && value<a[hole-1])
        {
            a[hole]=a[hole-1];
            hole--;
        }
        a[hole]=value;
    }
}

void radixSortBucketSort(int a[]) // the dd array will always have 10 columns(0-9) and rows=no of eles,this is called bucket
{
    int bucket[10][10]; //here no. of eles=10
    int r=10,c=10,mod=10,mod2=1;
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            bucket[i][j]=-1;
    int max=findMax(a);
    printf("max = %d",max);
    while(max!=0) // to know how many times it should work...
    {
        for(int i=0;i<r;i++)
        {
            int temp=((a[i]%mod))/mod2; // to get only 1 digit and every time it should decrease by mod 10
            for(int j=0;j<c;j++)
            {
                if(temp==j)
                    bucket[i][j]=a[i];
            }
        }
        int counter=0;
        for(int k=0;k<c;k++)
            for(int l=0;l<r;l++) //normal sae uulta cause we want to go downwards first
            {
                if(bucket[l][k]!=-1)
                {
                    a[counter++]=bucket[l][k];
                    bucket[l][k]=-1; // added re initialise here it self...
                }
            }
    //  for(int k=0;i<r;i++)
    //      for(int l=0;j<c;j++)
    //          bucket[i][j]=-1;
        mod*=10;
        mod2*=10;
        max/=10;
    }
}

int findMax(int a[])
{
    int max=a[0];
    for(int i=1;i<10;i++)
    {
        if(a[i]>max)
            max=a[i];
    }
    return max;
}
void underConst()
{
    printf("Under Construction...");
}

void main()
{
    int ch,i;
    int a[10];

    fillArray(a);

    do
    {
        printf("\n0)Fill Array within 0-99\n1) Exchange selection sort \n2)selection sort\n3)Bubble sort\n4)Modified Bubble sort\n5)Insertion sort\n6)Merge sort\n7)Shell sort\n8)Bucket sort\n9)quick sort\n10)Heap sort\n11)Display\n12)Manual add\n13)Fill Array Pure Random\n14)exit\nEnter ur choice...\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 0:
                fillArray(a);
                break;
            case 1:
                exchangeSelectionSort(a);
                break;
            case 2:
                selectionSort(a);
                break;
            case 3:
                bubbleSort(a);
                break;
            case 4:
                modifiedBubbleSort(a);
                break;
            case 5:
                insertionSort(a);
                break;
            case 6:
                mergeSort(a,0,9);
                break;
            case 7:
                underConst();
                break;
            case 8:
                radixSortBucketSort(a);
            case 9:
                quickS(a,0,9);
                break;
            case 10:
                underConst();
                break;
            case 11:
                display(a);
                break;
            case 12:
                printf("enter the eles\n");
                for(i=0;i<10;i++)
                {
                    printf("enter %d ele\n",(i+1));
                    scanf("%d",&a[i]);
                }
                break;
            case 13:
                fillArrayNoLimit(a);
                break;
            case 14:
                printf("bye thank you :)\n");
                break;
            default:
                printf("invalid\n");

        }
    }while(ch!=14);
}

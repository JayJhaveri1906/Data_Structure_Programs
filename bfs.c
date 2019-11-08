#include<stdio.h>
#define MAX 5
int main()
{
    int v[MAX]={0};
    int adj[MAX][MAX],i,j,start;
    printf("ENTER THE ADJACENCY MATRIX:\n");
    for(i=0;i<MAX;i++)
    {
        for(j=0;j<MAX;j++)
        {
            scanf("%d",&adj[i][j]);
        }
    }
    breadth(adj,v,0);
    printf("THE ADJACENCY MATRIX IS:\n");
    for(i=0;i<MAX;i++)
    {
        for(j=0;j<MAX;j++)
        {
            printf("%d\t",adj[i][j]);
        }
        printf("\n");
    }
    return 0;
}

void breadth(int adj[][MAX],int v[],int start)
{
    int q[MAX],rear=-1,front=-1,i;
    q[++rear]=start;
    v[start]=1;
    while(rear!=front)
    {
        start=q[++front];
        if(start == 4)
        {
            printf("E\n");
        }
        else
        {
            printf("%c \t",start+65);
        }
        for(i=0;i<MAX;i++)
        {
            if(adj[start][i]==1 && v[i]==0)
            {

                q[++rear]=i;
                v[i]=1;
            }
        }
    }
}

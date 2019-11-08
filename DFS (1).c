#include <stdio.h>

int n=10,v;
int visited[10];
int adj[10][10];


void dfs(int st)
{
    int i;
    printf("%d\t",st+1);
    visited[st]=1;

    for(i=0;i<v;i++)
    {
        if(visited[i]!=1 && adj[st][i]==1)
        {
            dfs(i);
        }
    }
}

void main()
{
    int i,j;
    int ch=1;
    printf("NUMBER of vertices in graph?\n");
    scanf("%d",&v);
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            printf("IS VERTEX %d ADJACENT TO %d?\n",j+1,i+1);
            printf("IF YES ENTER 1 ELSE 0\n");
            scanf("%d",&adj[i][j]);
        }
    }

    do
    {
        for(i=0;i<v;i++)
        {
            visited[i]=0;
        }

        printf("Enter a no. to start.\n");
        int st;
        scanf("%d",&st);

        dfs(st-1);

        printf("\n press 0 to exit,anything else to give a new start:)\n");
        scanf("%d",&ch);
    }while(ch!=0);
}



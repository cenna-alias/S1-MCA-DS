#include <stdio.h>
#include <stdlib.h>
int graph[10][10];
int visited[10];
int n;
void dfs(int v)
{
    int i;
    printf("%d ",v);
    visited[v] = 1;
    for(i=1;i<=n;i++)
    {
        if(graph[v][i]==1&&visited[i]==0)
        {
            dfs(i);
        }
    }
}
int main()
{
    int i,j,start;
    printf("Enter number of vertices: ");
    scanf("%d",&n);
    printf("Enter adjacency matrix:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&graph[i][j]);
            
        }
    }
    for(i=1;i<=n;i++)
    {
        visited[i] = 0;
    }
    printf("Enter starting vertex: ");
    scanf("%d",&start);
    printf("DFS Traversal: ");
    dfs(start);
    return 0;
}
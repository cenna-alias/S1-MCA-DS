#include <stdio.h>
#include <stdlib.h>
int graph[10][10];
int visited[10];
int n;
int queue[10];
int front=-1,rear=-1;
void enqueue(int v)
{
    queue[++rear]=v;
}
int dequeue()
{
    return queue[++front];
}
int isEmpty()
{
    return front==rear;
}
void bfs(int start)
{
    int v,i;
    enqueue(start);
    visited[start]=1;
    printf("%d ",start);
    while(!isEmpty())
    {
        v=dequeue();
        for(i=1;i<=n;i++)
        {
            if(graph[v][i]==1&&visited[i]==0)
            {
                printf("%d ",i);
                visited[i]=1;
                enqueue(i);
            }
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
    for(i=0;i<n;i++)
    {
        visited[i]=0;
    }
    printf("Enter starting vertex: ");
    scanf("%d",&start);
    printf("BFS Traversal: ");
    bfs(start);
    return 0;
}
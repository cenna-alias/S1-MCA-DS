#include<stdio.h>
int adj[10][10], stack[10], top = -1;
int visited[10] = {0,0,0,0,0,0,0,0,0,0};
void push(int item)
{
    if (top == 11)
        printf("Stack is full\n");
    else
    {
        top++;
        stack[top] = item;
    }
}
int pop()
{
    int p;
    if (top == -1)
        return 0;
    else
    {
        p = stack[top];
        top--;
        return p;
    }
}
void dfs(int s, int v)
{
    int p, i;
    push(s);
    visited[s] = 1;
    p = pop();
    if (p != 0)
        printf("%d", p);
    while (p != 0)
    {
        for (i = 1; i <= v; i++)
        {
            if (adj[p][i] == 1 && visited[i] == 0)
            {
                push(i);
                visited[i] = 1;
            }
        }
        p = pop();
        if (p != 0)
            printf("%d", p);
    }
}
int main()
{
    int i, j, v, s;
    printf("Enter the number of vertices: ");
    scanf("%d", &v);
    printf("Enter the adjacency matrix:\n");
    for (i = 1; i <= v; i++)
    {
        for (j = 1; j <= v; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }
    printf("Enter the starting vertex: ");
    scanf("%d", &s);
    dfs(s, v);
    return 0;
}


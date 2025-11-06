#include <stdio.h>
#include <stdlib.h>
#define INF 999
int parent[20];
int find(int i) {
    if (parent[i] != i)
        parent[i] = find(parent[i]);
    return parent[i];
}
void union_set(int a, int b) {
    int parentA = find(a);
    int parentB = find(b);
    parent[parentB] = parentA;
}
int main() {
    int v, i, j;
    int adj[10][10];
    int edge_count = 0, mincost = 0;
    printf("Enter the number of vertices: ");
    scanf("%d", &v);
    printf("Enter the adjacency matrix:\n");
    for (i = 1; i <= v; i++) {
        for (j = 1; j <= v; j++) {
            scanf("%d", &adj[i][j]);
            if (adj[i][j] == 0)
                adj[i][j] = INF; 
        }
    }
    for (i = 1; i <= v; i++)
        parent[i] = i;
    printf("\nEdges in the Minimum Spanning Tree are:\n");
    while (edge_count < v - 1) {
        int a = -1, b = -1, min = INF;
        for (i = 1; i <= v; i++) {
            for (j = 1; j <= v; j++) {
                if (adj[i][j] < min) {
                    min = adj[i][j];
                    a = i;
                    b = j;
                }
            }
        }
        if (a == -1 || b == -1)
            break;
        int u = find(a);
        int v_set = find(b);
        if (u != v_set) {
            printf("%d -> %d cost = %d\n", a, b, min);
            union_set(u, v_set);
            mincost += min;
            edge_count++;
        }
        adj[a][b] = adj[b][a] = INF;
    }
    printf("Total cost of Minimum Spanning Tree = %d\n", mincost);
    return 0;
}


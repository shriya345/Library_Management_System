#include <stdio.h>

int prim(int n, int a[10][10], int src) {
    int visited[10] = {0};
    int dist[10];
    int totalCost = 0, i, j, u, v, min;

    for(i = 1; i <= n; i++)
        dist[i] = a[src][i];
    
    visited[src] = 1;

    for(i = 1; i < n; i++) {
        min = 999;
        for(j = 1; j <= n; j++) {
            if(!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }

        visited[u] = 1;
        totalCost += dist[u];

        for(v = 1; v <= n; v++) {
            if(!visited[v] && a[u][v] < dist[v])
                dist[v] = a[u][v];
        }
    }

    return totalCost;
}

int main() {
    int n, a[10][10], i, j, src;

    printf("Enter number of nodes:\n");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
            if(i != j && a[i][j] == 0)
                a[i][j] = 999;
        }

    printf("Enter the source node:\n");
    scanf("%d", &src);

    int mstCost = prim(n, a, src);
    printf("The cost of the Minimum Spanning Tree is %d\n", mstCost);

    return 0;
}

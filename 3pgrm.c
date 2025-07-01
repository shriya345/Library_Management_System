#include <stdio.h>

void dfs(int n, int adj[10][10], int node, int visited[10]) {
    printf("%d ", node);
    visited[node] = 1;

    for (int i = 1; i <= n; i++) {
        if (!visited[i] && adj[node][i] == 1) {
            dfs(n, adj, i, visited);
        }
    }
}

int main() {
    int n, adj[10][10], visited[10], source;

    printf("Enter number of nodes:\n");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &adj[i][j]);

    printf("Enter the source node:\n");
    scanf("%d", &source);

    for (int i = 1; i <= n; i++)
        visited[i] = 0;

    printf("Nodes reachable using DFS:\n");
    dfs(n, adj, source, visited);

    return 0;
}

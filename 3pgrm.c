#include <stdio.h>

void dfs(int n, int a[10][10], int v, int visited[]) {
    printf("%d ", v);
    visited[v] = 1;
    for (int i = 1; i <= n; i++)
        if (a[v][i] && !visited[i])
            dfs(n, a, i, visited);
}

int main() {
    int n, a[10][10], source, visited[10] = {0};
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);

    printf("Enter source node: ");
    scanf("%d", &source);

    printf("DFS traversal: ");
    dfs(n, a, source, visited);
}

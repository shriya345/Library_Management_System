#include <stdio.h>

void bfs(int n, int adj[10][10], int source, int visited[10]) {
    int queue[10], front = 0, rear = 0;
    visited[source] = 1;
    queue[rear++] = source;

    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);

        for (int i = 1; i <= n; i++) {
            if (adj[node][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
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

    printf("Nodes reachable using BFS:\n");
    bfs(n, adj, source, visited);

    return 0;
}

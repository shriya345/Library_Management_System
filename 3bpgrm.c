#include <stdio.h>

void bfs(int n, int a[10][10], int source, int visited[]) {
    int q[10], front = 0, rear = 0;
    visited[source] = 1;
    q[rear++] = source;

    while (front < rear) {
        int v = q[front++];
        printf("%d ", v);
        for (int i = 1; i <= n; i++) {
            if (a[v][i] && !visited[i]) {
                visited[i] = 1;
                q[rear++] = i;
            }
        }
    }
}

int main() {
    int n, a[10][10], visited[10] = {0}, source;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);

    printf("Enter source node: ");
    scanf("%d", &source);

    printf("BFS traversal: ");
    bfs(n, a, source, visited);

    return 0;
}

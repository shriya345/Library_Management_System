##include <stdio.h>

int dijkstra(int n, int a[10][10], int src) {
    int visited[10] = {0}, dist[10];
    int i, j, u, v, min;

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

        for(v = 1; v <= n; v++) {
            if(!visited[v] && dist[v] > dist[u] + a[u][v])
                dist[v] = dist[u] + a[u][v];
        }
    }

    for(i = 1; i <= n; i++)
        printf("The shortest distance from %d to %d is %d\n", src, i, dist[i]);

    return 0;
}

int main() {
    int n, a[10][10], i, j, src;

    printf("Enter number of nodes:\n");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
            if(i != j && a[i][j] == 0)
                a[i][j] = 999;
        }
    }

    printf("Enter the source node:\n");
    scanf("%d", &src);

    dijkstra(n, a, src);

    return 0;
}

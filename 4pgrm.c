#include <stdio.h>

// Topological Sort using Source Removal
void topologicalSort(int n, int adj[10][10], int indegree[10]) {
    int i, j;

    for (i = 1; i <= n; i++) {
        for (int node = 1; node <= n; node++) {
            if (indegree[node] == 0) {
                printf("%d ", node);         // print this node
                indegree[node] = -1;         // mark it as removed

                // Decrease indegree of its neighbors
                for (j = 1; j <= n; j++) {
                    if (adj[node][j] == 1)
                        indegree[j]--;
                }

                break; // restart loop to find new source node
            }
        }
    }
}

int main() {
    int adj[10][10], indegree[10], n, i, j;

    printf("Enter number of nodes:\n");
    scanf("%d", &n);

    // Initialize indegree array
    for (i = 1; i <= n; i++)
        indegree[i] = 0;

    printf("Enter adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &adj[i][j]);
            if (adj[i][j] == 1)
                indegree[j]++; // Count incoming edges
        }
    }

    printf("Topological order of the graph:\n");
    topologicalSort(n, adj, indegree);

    return 0;
}

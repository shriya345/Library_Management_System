#include <stdio.h>

int parent[10];


int find(int i) {
    while(parent[i])
        i = parent[i];
    return i;
}


int union_set(int i, int j) {
    if(i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int kruskal(int n, int cost[10][10]) {
    int min, a, b, u, v, i, j;
    int ne = 1, minCost = 0;

    while(ne < n) {
        min = 999;
        a = b = -1;

        for(i = 1; i <= n; i++) {
            for(j = 1; j <= n; j++) {
                if(cost[i][j] < min) {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        u = find(a);
        v = find(b);

        if(union_set(u, v)) {
            printf("%d. Edge (%d, %d) = %d\n", ne++, a, b, min);
            minCost += min;
        }

        cost[a][b] = cost[b][a] = 999; 
    }

    return minCost;
}


int main() {
    int n, cost[10][10], i, j;

    printf("Enter the number of nodes:\n");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if(i != j && cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    int totalCost = kruskal(n, cost);
    printf("The cost of the Minimum Spanning Tree is %d\n", totalCost);

    return 0;
}

#include <stdio.h>


void topologicalSort(int nodes, int matrix[10][10], int indegree[10]) {
    int i, j;

    for (i = 1; i <= nodes; i++) {
        for (int current = 1; current <= nodes; current++) {
            if (indegree[current] == 0) {
             
                printf("%d ", current);
                indegree[current] = -1; 

               
                for (j = 1; j <= nodes; j++) {
                    if (matrix[current][j] == 1)
                        indegree[j]--;
                }

                break; 
            }
        }
    }
}

int main() {
    int matrix[10][10], indegree[10], nodes, i, j;

    printf("Enter number of nodes:\n");
    scanf("%d", &nodes);


    for (i = 1; i <= nodes; i++)
        indegree[i] = 0;

    printf("Enter the adjacency matrix:\n");
    for (i = 1; i <= nodes; i++) {
        for (j = 1; j <= nodes; j++) {
            scanf("%d", &matrix[i][j]);

            
            if (matrix[i][j] == 1)
                indegree[j]++;
        }
    }

    printf("Topological order of the graph:\n");
    topologicalSort(nodes, matrix, indegree);

    return 0;
}

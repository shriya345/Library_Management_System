#include <stdio.h>


void topology(int n, int a[10][10], int sc[10]) {
    for (int i = 1; i <= n; i++) {
       
        if (sc[i] == 0) {
            printf("%d ", i);   
            sc[i] = -1;         

           
            for (int j = 1; j <= n; j++)
                if (a[i][j] == 1)
                    sc[j]--;    

            i = 0; 
        }
    }
}

int main() {
    int n, a[10][10], sc[10] = {0};  

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
            if (a[i][j] == 1)
                sc[j]++;  
        }
    }

    printf("Topological Order: ");
    topology(n, a, sc);

    return 0;
}

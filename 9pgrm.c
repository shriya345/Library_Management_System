#include <stdio.h>
#include <stdlib.h>  


int place(int x[10], int k) {
    int i;
    for (i = 1; i <= k - 1; i++) {
        if (x[k] == x[i])                  
            return 0;
        if (abs(x[k] - x[i]) == abs(i - k)) 
            return 0;
    }
    return 1;
}


void nqueen(int n) {
    int x[10], k = 1, i, count = 0;
    x[k] = 0;

    while (k != 0) {
        x[k] = x[k] + 1;
        while (x[k] <= n && !place(x, k))
            x[k]++;

        if (x[k] <= n) {
            if (k == n) {
                count++;
                printf("\nSolution %d is:\n", count);
                for (i = 1; i <= n; i++)
                    printf("%d\t", x[i]);
                printf("\n");
            } else {
                k++;
                x[k] = 0;
            }
        } else {
            k--;
        }
    }
}


int main() {
    int n;
    printf("Enter the number of queens:\n");
    scanf("%d", &n);

    if (n == 1 || n == 2 || n == 3)
        printf("Solution is not possible.\n");
    else
        nqueen(n);

    return 0;
}

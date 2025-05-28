#include <stdio.h>
#include <string.h>

// Max Function
int max(int a, int b) {
    return (a > b) ? a : b;
}

// LCS Function
int lcs(char X[], char Y[], int m, int n, char result[]) {
    int L[100][100], i, j;

    // Fill LCS table
    for(i = 0; i <= m; i++) {
        for(j = 0; j <= n; j++) {
            if(i == 0 || j == 0)
                L[i][j] = 0;
            else if(X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }

    // Build LCS string
    int len = L[m][n];
    result[len] = '\0'; // Null-terminate
    i = m;
    j = n;
    while(i > 0 && j > 0) {
        if(X[i - 1] == Y[j - 1]) {
            result[len - 1] = X[i - 1];
            i--; j--; len--;
        }
        else if(L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }

    return L[m][n];
}

// Main Function
int main() {
    char X[100], Y[100], result[100];
    int m, n, len;

    printf("Enter the first string:\n");
    gets(X);
    printf("Enter the second string:\n");
    gets(Y);

    m = strlen(X);
    n = strlen(Y);

    len = lcs(X, Y, m, n, result);
    if(len == 0)
        printf("No common subsequence found!\n");
    else {
        printf("LCS length is %d\n", len);
        printf("The LCS is %s\n", result);
    }

    return 0;
}

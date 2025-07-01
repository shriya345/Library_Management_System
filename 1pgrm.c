##include <stdio.h>

void quicksort(int a[], int low, int high) {
    int i = low, j = high, pivot = a[(low + high) / 2], temp;
    while (i <= j) {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;
        if (i <= j) {
            temp = a[i]; a[i] = a[j]; a[j] = temp;
            i++; j--;
        }
    }
    if (low < j) quicksort(a, low, j);
    if (i < high) quicksort(a, i, high);
}

int main() {
    int a[100], n, i;
    printf("Enter number of elements:\n");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) scanf("%d", &a[i]);

    quicksort(a, 0, n - 1);

    printf("Sorted elements:\n");
    for(i = 0; i < n; i++) printf("%d ", a[i]);
    return 0;
}

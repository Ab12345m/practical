#include <stdio.h>

void quickSort(int a[], int low, int high) {
  
    int i = low, j = high, pivot = a[(low + high) / 2], temp;

    while (i <= j) {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;

        if (i <= j) {

            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++; 
            j--;
        }
    }

    if (low < j)
        quickSort(a, low, j);
    if (i < high)
        quickSort(a, i, high);
}

int main() {
    int a[] = {5, 3, 8, 4, 2};
    int n = 5, i;

    quickSort(a, 0, n - 1);

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
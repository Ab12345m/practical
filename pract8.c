#include <stdio.h>
#include <stdlib.h>   // for abs()

int x[20]; // supports up to 20 queens

// Function to check safe position
int place(int k, int i) {
    for (int j = 1; j < k; j++) {
        if (x[j] == i || abs(x[j] - i) == abs(j - k))
            return 0;
    }
    return 1;
}

// Backtracking function
void queen(int k, int n) {
    for (int i = 1; i <= n; i++) {
        if (place(k, i)) {
            x[k] = i;

            if (k == n) {
                // Print solution
                for (int j = 1; j <= n; j++)
                    printf("%d ", x[j]);
                printf("\n");
            } else {
                queen(k + 1, n);
            }
        }
    }
}

int main() {
    int n;

    printf("Enter number of queens: ");
    scanf("%d", &n);

    queen(1, n);

    return 0;
}
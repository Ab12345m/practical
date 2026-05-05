#include <stdio.h>
#define INF 999

int n = 4;  // number of cities
int cost[10][10] = {
    {INF, 10, 15, 20},
    {10, INF, 35, 25},
    {15, 35, INF, 30},
    {20, 25, 30, INF}
};

int visited[10];

int tsp(int city) {
    int i, min = INF, next;

    visited[city] = 1;

    for (i = 0; i < n; i++) {
        if (!visited[i] && cost[city][i] != INF) {
            int temp = cost[city][i] + tsp(i);
            if (temp < min)
                min = temp;
        }
    }

    visited[city] = 0;

    return (min == INF) ? cost[city][0] : min;
}

int main() {
    printf("Minimum Cost = %d", tsp(0));
    return 0;
}
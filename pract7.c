#include <stdio.h>
#define INF 999

int main() {
    int n = 4, i, j, u, min;
    int cost[10][10] = {
        {0, 1, 4, INF},
        {1, 0, 2, 6},
        {4, 2, 0, 3},
        {INF, 6, 3, 0}
    };

    int dist[10], visited[10] = {0};

    // Initialize distances
    for (i = 0; i < n; i++)
        dist[i] = cost[0][i];

    visited[0] = 1;

    for (i = 1; i < n; i++) {
        min = INF;

        // Find minimum distance vertex
        for (j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }

        visited[u] = 1;

        // Update distances
        for (j = 0; j < n; j++) {
            if (!visited[j] && dist[u] + cost[u][j] < dist[j]) {
                dist[j] = dist[u] + cost[u][j];
            }
        }
    }

    printf("Shortest distances from source:\n");
    for (i = 0; i < n; i++)
        printf("%d ", dist[i]);

    return 0;
}
#include <stdio.h>
#include <limits.h>

#define MAX 10

void tspNearestNeighbor(int graph[MAX][MAX], int n, int start) {
    int visited[MAX] = {0};         // To keep track of visited cities
    int path[MAX];                  // To store the final path
    int totalCost = 0;
    int count = 1;
    
    int current = start;
    visited[current] = 1;
    path[0] = current;

    while (count < n) {
        int nearest = -1;
        int minDist = INT_MAX;

        // Find nearest unvisited city
        for (int i = 0; i < n; i++) {
            if (!visited[i] && graph[current][i] != 0 && graph[current][i] < minDist) {
                minDist = graph[current][i];
                nearest = i;
            }
        }

        if (nearest != -1) {
            visited[nearest] = 1;
            totalCost += minDist;
            current = nearest;
            path[count++] = current;
        }
    }

    // Return to starting city
    totalCost += graph[current][start];
    path[count] = start;

    // Print result
    printf("TSP Path (Nearest Neighbor): ");
    for (int i = 0; i <= n; i++) {
        printf("%d ", path[i]);
    }

    printf("\nTotal Cost: %d\n", totalCost);
}

int main() {
    // Example graph with 4 cities
    int graph[MAX][MAX] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int n = 4; // Number of cities
    int startCity = 0; // Starting city

    tspNearestNeighbor(graph, n, startCity);

    return 0;
}


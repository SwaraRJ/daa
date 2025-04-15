#include <stdio.h>
#include <stdbool.h>
#define V 4

int graph[V][V] = {
    {0, 1, 1, 1},
    {1, 0, 1, 0},
    {1, 1, 0, 1},
    {1, 0, 1, 0}
};

int path[V];

// Check if vertex v can be added at position pos in the path
bool isSafe(int v, int pos) {
    // Check if this vertex is adjacent to the previous one
    if (graph[path[pos - 1]][v] == 0)
        return false;

    // Check if the vertex has already been included
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

// Recursive function to build the Hamiltonian Cycle
bool hamCycleUtil(int pos) {
    if (pos == V) {
        // Check if the last vertex connects to the first
        return graph[path[pos - 1]][path[0]] == 1;
    }

    // Try different vertices as next candidate
    for (int v = 1; v < V; v++) {
        if (isSafe(v, pos)) {
            path[pos] = v;
            if (hamCycleUtil(pos + 1))
                return true;
            path[pos] = -1; // backtrack
        }
    }

    return false;
}

// Main function to check if Hamiltonian Cycle exists
void hamiltonianCycle() {
    for (int i = 0; i < V; i++)
        path[i] = -1;

    path[0] = 0; // start from vertex 0

    if (hamCycleUtil(1)) {
        printf("Hamiltonian Cycle: ");
        for (int i = 0; i < V; i++)
            printf("%d ", path[i]);
        printf("%d\n", path[0]); // return to start
    } else {
        printf("No Hamiltonian Cycle Found.\n");
    }
}

int main() {
    hamiltonianCycle();
    return 0;
}


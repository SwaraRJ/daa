#include <stdio.h>
#include <limits.h>

#define N 4  // Number of keys

// Function to calculate sum of frequencies from i to j
int sum(int freq[], int i, int j) {
    int s = 0;
    for (int k = i; k <= j; k++) {
        s = s + freq[k];
    }
    return s;
}

// Function to find minimum cost of Optimal BST
int optimalBST(int keys[], int freq[], int n) {
    int cost[N][N];

    // Initialize diagonal values (single keys)
    for (int i = 0; i < n; i++) {
        cost[i][i] = freq[i];
    }

    // L is chain length (number of keys in the current subproblem)
    for (int L = 2; L <= n; L++) {
        for (int i = 0; i <= n - L; i++) {
            int j = i + L - 1;
            cost[i][j] = INT_MAX;

            // Try all keys as root from i to j
            for (int r = i; r <= j; r++) {
                int left = 0;
                int right = 0;

                if (r > i) {
                    left = cost[i][r - 1];
                }
                if (r < j) {
                    right = cost[r + 1][j];
                }

                int total = left + right + sum(freq, i, j);

                if (total < cost[i][j]) {
                    cost[i][j] = total;
                }
            }
        }
    }

    return cost[0][n - 1];
}

int main() {
    int keys[] = {10, 20, 30, 40};
    int freq[] = {4, 2, 6, 3};

    int result = optimalBST(keys, freq, N);
    printf("Minimum cost of Optimal BST is: %d\n", result);

    return 0;
}


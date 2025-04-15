#include <stdio.h>
#include <limits.h>

#define INF INT_MAX

// Function to find the minimum number of multiplications
int MatrixChainOrder(int p[], int n) 
{
    int m[n][n];
    int i, j, k, l, q;

    // Step 1: Initialize diagonal elements (one matrix = 0 multiplication)
    for (i = 1; i < n; i++)
        m[i][i] = 0;

    // Step 2: l is chain length (from 2 matrices to full chain)
    for (l = 2; l < n; l++) 
    {
        for (i = 1; i < n - l + 1; i++)
        {
            j = i + l - 1;
            m[i][j] = INF;

            // Step 3: Try all places to split the chain
            for (k = i; k <= j - 1; k++) 
            {
                // Cost = cost of left + cost of right + cost of multiplying them
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];

                if (q < m[i][j])
                    m[i][j] = q;  // Choose min cost
            }
        }
    }

    return m[1][n - 1];  // Minimum cost to multiply full chain
}

int main()
{
    int n, arr[10], i, size;

    printf("\nEnter size n: ");
    scanf("%d", &size);

    printf("Enter matrix chain elements: ");
    for(i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    printf("Minimum number of multiplications is %d\n",
           MatrixChainOrder(arr, size));

    return 0;
}


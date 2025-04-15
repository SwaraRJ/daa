#include <stdio.h>
#include <stdbool.h>
#include<stdlib.h>

#define N 4  // Change this to solve for different board sizes

int board[N];

// Check if it's safe to place queen at board[row] = col
bool isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return false;
    }
    return true;
}

// Solve N-Queens using backtracking
bool solveNQueens(int row) {
    if (row == N) {
        // Print solution
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i] == j)
                    printf(" Q ");
                else
                    printf(" * ");
            }
            printf("\n");
        }
        printf("\n");
        return true;  // To find only one solution, return here
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            board[row] = col;
            if (solveNQueens(row + 1))
                return true;  // comment this to print all solutions
        }
    }
    return false;
}

int main() {
    if (!solveNQueens(0))
        printf("No solution exists\n");
    return 0;
}


#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

bool isSafe(const vector<int>& board, int row, int col) {
    // Check previous rows for conflicts with the new queen at (row, col)
    for (int i = 0; i < row; i++) {
        int placedCol = board[i];
        // Check column conflict and both diagonals
        if (placedCol == col || abs(placedCol - col) == abs(i - row))
            return false;
    }
    return true;
}

bool solveNQueensUtil(vector<int>& board, int row, int n) {
    if (row == n) return true; // All queens are placed successfully

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col)) {
            board[row] = col; // Place queen at (row, col)

            if (solveNQueensUtil(board, row + 1, n))
                return true; // Recursive call

            board[row] = -1; // Backtrack
        }
    }
    return false;
}

void printSolution(const vector<int>& board, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << (board[i] == j ? "Q " : ". ");
            // cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the value of N: ";
    cin >> n;

    if (n < 1) {
        cout << "Invalid board size." << endl;
        return 1;
    }

    vector<int> board(n, -1); // Initialize board with -1 to indicate no queens placed

    clock_t start = clock();

    if (solveNQueensUtil(board, 0, n)) {
        printSolution(board, n);
    } else {
        cout << "No solution exists for N = " << n << endl;
    }

    clock_t end = clock();
    double time_taken = double(end - start) / CLOCKS_PER_SEC;
    int memory_usage = sizeof(int) * (n + n); // Rough memory estimation

    cout << "Execution time: " << time_taken << " seconds" << endl;
    cout << "Memory used: " << memory_usage << " bytes" << endl;

    return 0;
}

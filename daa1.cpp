#include <iostream>
#include <ctime> // For measuring time
using namespace std;

// Iterative Fibonacci series generator
void fib_series_iterative(int n) {
    int a = 0, b = 1;

    // Generate and print Fibonacci series up to n terms
    cout << "Iterative Fibonacci Series up to " << n << " terms: ";
    for (int i = 0; i < n; i++) {
        cout << a << " ";
        int c = a + b;
        a = b;
        b = c;
    }
    cout << endl;
}

// Recursive Fibonacci function
int fib_recursive(int n) {
    if (n <= 1) return n;
    return fib_recursive(n - 1) + fib_recursive(n - 2);
}

// Function to print Fibonacci series using recursion up to n terms
void fib_series_recursive(int n) {
    cout << "Recursive Fibonacci Series up to " << n << " terms: ";
    for (int i = 0; i < n; i++) {
        cout << fib_recursive(i) << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of terms: ";
    cin >> n;

    // Measure and print iterative Fibonacci series
    clock_t start_iter = clock();
    fib_series_iterative(n);
    clock_t end_iter = clock();
    double duration_iter = double(end_iter - start_iter) / CLOCKS_PER_SEC;
    cout << "Time required (iterative): " << duration_iter << " seconds" << endl;

    // Calculate space for iterative approach
    int space_iter = sizeof(n) + sizeof(int) * 3;  // n, a, b, c variables
    cout << "Space required (iterative): " << space_iter << " bytes" << endl;

    // Measure and print recursive Fibonacci series
    clock_t start_rec = clock();
    fib_series_recursive(n);
    clock_t end_rec = clock();
    double duration_rec = double(end_rec - start_rec) / CLOCKS_PER_SEC;
    cout << "Time required (recursive): " << duration_rec << " seconds" << endl;

    int space_rec = sizeof(int) * n;  // Recursive calls' space on stack
    cout << "Space required (recursive): " << space_rec << " bytes" << endl;

    return 0;
}
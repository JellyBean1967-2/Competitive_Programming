/*
calculate A^k where A is a square matrix
explain why the value of f(n) can be calculated in o (log n) time (pg. 221)
223 - how to find a path
*/

#include <iostream>
#include <vector>
using namespace std;

// Matrix multiplication
/*
vector<vector<int>> multiply(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    
    return C;
}

// Matrix exponentiation using fast exponentiation
vector<vector<int>> matrixPower(vector<vector<int>> A, int k) {
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n, 0));
    
    // Initialize result as identity matrix
    for (int i = 0; i < n; i++) {
        result[i][i] = 1;
    }
    
    while (k > 0) {
        if (k & 1) {
            result = multiply(result, A);
        }
        A = multiply(A, A);
        k >>= 1;
    }
    
    return result;
}

// Print matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    // Sample matrix for P1
    vector<vector<int>> A = {
        {3, 12, 4},
        {5, 9, 15},
        {0, 2, 4}
    };
    
    int k;
    cout << "Enter k to calculate A^k: ";
    cin >> k;
    
    cout << "\nOriginal matrix A:" << endl;
    printMatrix(A);
    
    vector<vector<int>> result = matrixPower(A, k);
    
    cout << "\nA^" << k << " =" << endl;
    printMatrix(result);
    
    return 0;
}
*/



//2.

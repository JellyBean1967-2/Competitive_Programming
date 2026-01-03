/*
calculate A^k where A is a square matrix
explain why the value of f(n) can be calculated in o (log n) time (pg. 221)
223 - how to find a path
*/

//1.
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

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
//f(n) can be computed in O(log n) time because it is obtained by 
//computing X^n using repeated squaring, which requires only log n matrix 
//multiplications.

//3.
//To recover the shortest path, start at the source node and repeatedly
//follow the stored next pointer toward the destination exactly n times,
//because next[i][j] always records the first step of an optimal path 
//from i to j.

const long long INF = 1e18;

struct Cell {
  long long dist;
  int next;
  long long ways;
};

using Matrix = vector<vector<Cell>>;

int firstStep(const Matrix &A, const Matrix &B, int i, int k, int j) {
  if (A[i][k].next == -1) return B[k][j].next;
  return A[i][k].next;
}

// Matrix multiplication for shortest paths
// Uses min + instead of sum * for path distances
Matrix multiply(const Matrix &A, const Matrix &B) {
  int n = A.size();
  Matrix C(n, vector<Cell>(n, {INF, -1, 0}));

  for (int i = 0; i < n; i++) {
    for (int k = 0; k < n; k++) {
      if (A[i][k].dist == INF) continue;

      for (int j = 0; j < n; j++) {
        if (B[k][j].dist == INF) continue;

        long long cand = A[i][k].dist + B[k][j].dist;

        if (cand < C[i][j].dist) {
          C[i][j].dist = cand;
          C[i][j].next = firstStep(A, B, i, k, j);
          C[i][j].ways = A[i][k].ways * B[k][j].ways;
        }
        else if (cand == C[i][j].dist) {
          C[i][j].ways += A[i][k].ways * B[k][j].ways;
        }
      }
    }
  }
  return C;
}

// Fast matrix exponentiation - computes base^exp in O(log exp) time
Matrix matrixPower(Matrix base, int exp) {
  int n = base.size();
  Matrix result(n, vector<Cell>(n, {INF, -1, 0}));

  for (int i = 0; i < n; i++) {
    result[i][i].dist = 0;
    result[i][i].ways = 1;
  }

  while (exp > 0) {
    if (exp & 1) result = multiply(result, base);
    base = multiply(base, base);
    exp >>= 1;
  }
  return result;
}

// Store matrices for each power to enable path reconstruction
vector<Matrix> powers;

Matrix matrixPowerWithHistory(Matrix base, int exp) {
  int n = base.size();
  Matrix result(n, vector<Cell>(n, {INF, -1, 0}));
  
  // Clear and rebuild powers array
  powers.clear();
  powers.push_back(base); // V^1
  
  // Initialize result as identity matrix
  for (int i = 0; i < n; i++) {
    result[i][i].dist = 0;
    result[i][i].ways = 1;
  }
  
  Matrix current = base;
  for (int p = 1; p <= exp; p++) {
    if (p > 1) {
      current = multiply(powers[p-2], base);
      powers.push_back(current);
    }
    if (p == exp) result = current;
  }
  
  return result;
}

// DFS to find any path with exactly k edges to target
// This reconstructs the actual path sequence
vector<int> findPath(const Matrix &V, int cur, int target, int steps, vector<int> &path) {
  if (steps == 0) {
    return (cur == target) ? path : vector<int>{};
  }
  
  for (int next = 0; next < V.size(); next++) {
    if (V[cur][next].dist != INF) {
      path.push_back(next);
      auto result = findPath(V, next, target, steps - 1, path);
      if (!result.empty()) return result;
      path.pop_back();
    }
  }
  
  return {};
}

vector<int> recoverPath(int s, int t, int k) {
  vector<int> path = {s};
  return findPath(powers[0], s, t, k, path);
}

int main() {
  int n = 6;
  int k = 4;

  Matrix V(n, vector<Cell>(n, {INF, -1, 0}));

  auto addEdge = [&](int u, int v, int w) {
    V[u][v] = {w, v, 1};
  };

  // Graph from textbook example (page 222) 
  // Testing the path 2->1->4->2->5 with exactly 4 edges
  addEdge(1,0,2);  // 2->1 weight 2
  addEdge(0,3,4);  // 1->4 weight 4  
  addEdge(3,1,2);  // 4->2 weight 2
  addEdge(1,4,2);  // 2->5 weight 2
  addEdge(1,5,2);  // 2->6 weight 2
  addEdge(2,1,4);  // 3->2 weight 4
  addEdge(5,2,3);  // 6->3 weight 3
  addEdge(5,4,2);  // 6->5 weight 2

  int s = 1; // node 2 (0-indexed)
  int t = 4; // node 5 (0-indexed)

  Matrix R = matrixPowerWithHistory(V, k);

  if (R[s][t].dist == INF) {
    cout << "No path with exactly " << k << " edges\n";
    return 0;
  }

  cout << "Distance = " << R[s][t].dist << endl;

  if (R[s][t].ways > 1)
    cout << "Ambiguous: " << R[s][t].ways << " shortest paths\n";

  auto path = recoverPath(s, t, k);

  cout << "Path: ";
  for (int x : path) cout << x + 1 << " ";
  cout << endl;
}

#include <iostream>
#include <vector>
using namespace std;

int n;
int solutionCount = 0;
vector<vector<vector<int>>> allSolutions;

void search(int row, vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2, vector<vector<int>>& board) {
    if (row == n) {
        allSolutions.push_back(board);
        solutionCount++;
        return;
    }
    for (int c = 0; c < n; ++c) {
        if (!cols[c] && !diag1[row + c] && !diag2[row - c + n - 1]) {
            board[row][c] = 1;
            cols[c] = diag1[row + c] = diag2[row - c + n - 1] = true;
            search(row + 1, cols, diag1, diag2, board);
            cols[c] = diag1[row + c] = diag2[row - c + n - 1] = false;
            board[row][c] = 0;
        }
    }
}

int main() {
    cout << "Enter the size of the chessboard: ";
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<bool> cols(n, false);
    vector<bool> diag1(2 * n - 1, false);
    vector<bool> diag2(2 * n - 1, false);

    search(0, cols, diag1, diag2, board);

    cout << "There are " << solutionCount << " solutions\n\n";

    for (int i = 0; i < allSolutions.size(); ++i) {
        cout << "Solution " << i + 1 << "\n";
        for (const auto& row : allSolutions[i]) {
            for (int cell : row) {
                cout << cell << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }

    return 0;
}

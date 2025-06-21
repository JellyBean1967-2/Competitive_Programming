// THE UNGRAND PLAN™:
// 1. Make a grid
// 2. Read (x, y) and start BFS from there
// 3. Only move UP, DOWN, UP-LEFT, and DOWN-RIGHT
// 4. Don't step on walls (1 = wall, 0 = floor)
// 5. Keep track of what you've already visited
// 6. Don't ✨YEET✨ yourself out of the boundary
// 7. Count how many places you reach
// 8. Print that number
// 9. Hope for no bugs 🪲
// 10. Maybe clean your space bar again ✨🧼⌨️
// 11. Dance break 🕺🥳 if the code actually works

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int n;
int x, y;
int tilesReached = 0;  // renamed to avoid conflict with std::count

int dx[4] = {-1, 1, -1, 1};
int dy[4] = {0, 0, -1, 1};

vector<vector<int>> maze;
vector<vector<bool>> visited;

bool isValid(int x, int y) {
    return x >= 0 && x < n &&
           y >= 0 && y < n &&
           maze[x][y] == 0 &&
           !visited[x][y];
}

void bfs(int startX, int startY) {
    queue<pair<int, int>> q;
    q.push({startX, startY});
    visited[startX][startY] = true;
    tilesReached++;

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int newX = curr.first + dx[i];
            int newY = curr.second + dy[i];

            if (isValid(newX, newY)) {
                q.push({newX, newY});
                visited[newX][newY] = true;
                tilesReached++;
            }
        }
    }
}

int main() {
    cin >> n >> x >> y;
    maze.resize(n, vector<int>(n));
    visited.resize(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> maze[i][j];
        }
    }

    if (maze[x][y] == 0) {
        bfs(x, y);
    }

    cout << tilesReached << endl;
}

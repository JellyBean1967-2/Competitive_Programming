/*
find out if a graph has a eulerian path, if so find it with the hierholzer's algorithm
implement maximum flow using scaling algorithm
for bipartite graph, find the maximum matching of that graph.
*/

#include <vector>
#include <iostream>
#include <stack>
#include <tuple>
using namespace std;

//1. Eulerian path with Hierholzer's algorithm
vector<vector<int>> adj;
vector<vector<bool>> used;
int n;

vector<tuple<int,int,int>> edges;

bool hasEulerianPath(int& start) {
    vector<int> inDegree(n, 0);
    vector<int> outDegree(n, 0);
    
    for (int i = 0; i < n; i++) {
        outDegree[i] = adj[i].size();
        for (int v : adj[i]) {
            inDegree[v]++;
        }
    }
    
    int startNodes = 0, endNodes = 0;
    start = 0;
    
    for (int i = 0; i < n; i++) {
        if (outDegree[i] - inDegree[i] == 1) {
            startNodes++;
            start = i;
        } else if (inDegree[i] - outDegree[i] == 1) {
            endNodes++;
        } else if (inDegree[i] != outDegree[i]) {
            return false;
        }
    }
    
    return (startNodes == 0 && endNodes == 0) || (startNodes == 1 && endNodes == 1);
}

vector<int> hierholzer() {
    int start;
    if (!hasEulerianPath(start)) {
        return {};
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            used[i][j] = false;
        }
    }
    
    stack<int> st;
    vector<int> path;
    
    st.push(start);
    
    while (!st.empty()) {
        int curr = st.top();
        bool found = false;
        
        for (int next : adj[curr]) {
            if (!used[curr][next]) {
                used[curr][next] = true;
                st.push(next);
                found = true;
                break;
            }
        }
        
        if (!found) {
            path.push_back(curr);
            st.pop();
        }
    }
    
    for (int i = 0; i < path.size() / 2; i++) {
        int temp = path[i];
        path[i] = path[path.size() - 1 - i];
        path[path.size() - 1 - i] = temp;
    }
    
    return path;
}

int main() {
    // Format: (weight, node2, node1) for proper sorting
    edges.push_back({3,2,1});
    edges.push_back({5,3,1});
    edges.push_back({2,4,3});
    edges.push_back({3,2,4});
    edges.push_back({6,6,2});
    edges.push_back({8,6,4});
    edges.push_back({11,7,6});
    edges.push_back({2,8,7});
    edges.push_back({9,8,6});
    edges.push_back({2,5,4});
    
    n = 11;
    adj.resize(n);
    for (auto& edge : edges) {
        int u = get<2>(edge);
        int v = get<1>(edge);
        adj[u].push_back(v);
    }
    used.resize(n, vector<bool>(n, false));
    
    vector<int> path = hierholzer();
    if (!path.empty()) {
        cout << "Eulerian path: ";
        for (int v : path) {
            cout << v << " ";
        }
        cout << endl;
    } else {
        cout << "No Eulerian path" << endl;
    }
    
    return 0;
}
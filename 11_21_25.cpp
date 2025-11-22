/*
wif directed graph i gave u last week,
find # of strongly connected components
...and print it.
*/
#include <vector>
#include <iostream>
#include <algorithm>
#include <tuple>
#include <map>
#include <set>
#include <stack>
using namespace std;

// DFS for first pass (fill finish times)
void dfs1(int node, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& finishOrder) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs1(neighbor, adj, visited, finishOrder);
        }
    }
    finishOrder.push(node);
}

// DFS for second pass (find SCC)
void dfs2(int node, vector<vector<int>>& revAdj, vector<bool>& visited, vector<int>& component) {
    visited[node] = true;
    component.push_back(node);
    for (int neighbor : revAdj[node]) {
        if (!visited[neighbor]) {
            dfs2(neighbor, revAdj, visited, component);
        }
    }
}

// Kosaraju's algorithm
vector<vector<int>> kosaraju(vector<tuple<int,int,int>>& edges, int maxNode) {
    // Build adjacency list and reverse adjacency list
    vector<vector<int>> adj(maxNode + 1);
    vector<vector<int>> revAdj(maxNode + 1);
    
    for (auto& edge : edges) {
        int from = get<1>(edge);
        int to = get<2>(edge);
        adj[from].push_back(to);
        revAdj[to].push_back(from);
    }
    
    // Step 1: DFS on original graph, fill finish order
    vector<bool> visited(maxNode + 1, false);
    stack<int> finishOrder;
    
    for (int i = 1; i <= maxNode; i++) {
        if (!visited[i]) {
            dfs1(i, adj, visited, finishOrder);
        }
    }
    
    // Step 2: DFS on reversed graph in reverse finish order
    fill(visited.begin(), visited.end(), false);
    vector<vector<int>> sccs;
    
    while (!finishOrder.empty()) {
        int node = finishOrder.top();
        finishOrder.pop();
        
        if (!visited[node]) {
            vector<int> component;
            dfs2(node, revAdj, visited, component);
            sccs.push_back(component);
        }
    }
    
    return sccs;
}

int main(){
    vector<tuple<int,int,int>> edges;
    // Format: (weight, node1, node2) for proper sorting
    edges.push_back({15,1,5});
    edges.push_back({6,5,4});
    edges.push_back({3,4,6});
    edges.push_back({2,6,7});
    edges.push_back({4,3,7});
    edges.push_back({3,2,3});
    edges.push_back({7,9,7});
    edges.push_back({4,7,8});
    edges.push_back({1,8,10});
    edges.push_back({2,10,9});
    
    // Find maximum node number
    int maxNode = 0;
    for (auto& edge : edges) {
        maxNode = max(maxNode, max(get<1>(edge), get<2>(edge)));
    }
    
    // Find strongly connected components using Kosaraju's algorithm
    vector<vector<int>> sccs = kosaraju(edges, maxNode);
    
    cout << "Number of strongly connected components: " << sccs.size() << endl;
    
    cout << "Strongly Connected Components:" << endl;
    for (int i = 0; i < sccs.size(); i++) {
        cout << "SCC " << (i + 1) << ": ";
        for (int j = 0; j < sccs[i].size(); j++) {
            cout << sccs[i][j];
            if (j < sccs[i].size() - 1) cout << ", ";
        }
        cout << endl;
    }
    
}
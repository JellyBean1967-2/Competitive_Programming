/*given a directed graph
test if it has a cycle
if it has no cycle
output topological order
otherwise say 'uh oh pip does not approve'*/

#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

vector<vector<int>> adj;
vector<int> state; // 0=white, 1=gray, 2=black
vector<int> finish_order;
bool has_cycle = false;

void dfs(int u) {
    state[u] = 1; // gray (processing)
    
    for (int v : adj[u]) {
        if (state[v] == 1) {
            // Found back edge - cycle detected
            has_cycle = true;
            return;
        }
        if (state[v] == 0) {
            dfs(v);
        }
        if (has_cycle) return;
    }
    
    state[u] = 2; // black (finished)
    finish_order.push_back(u);
}

int main(){
    vector<tuple<int,int,int>> edges;
    // Format: (weight, node1, node2) for directed edges
    edges.push_back({8,2,1});
    edges.push_back({7,1,3});
    edges.push_back({15,1,5});
    edges.push_back({3,3,2});
    edges.push_back({3,4,3});
    edges.push_back({4,3,7});
    edges.push_back({6,5,4});
    edges.push_back({3,4,6});
    edges.push_back({2,7,6});
    edges.push_back({4,7,8});
    edges.push_back({7,7,9});
    edges.push_back({1,8,10});
    edges.push_back({2,9,10});
    
    // Find number of nodes
    int n = 0;
    for (auto edge : edges) {
        n = max(n, max(get<1>(edge), get<2>(edge)));
    }
    
    // Build adjacency list
    adj.resize(n + 1);
    state.resize(n + 1, 0);
    
    for (auto edge : edges) {
        int u = get<1>(edge);
        int v = get<2>(edge);
        adj[u].push_back(v);
    }
    
    // DFS-based cycle detection and topological sorting
    for (int i = 1; i <= n; i++) {
        if (state[i] == 0) {
            dfs(i);
            if (has_cycle) break;
        }
    }
    
    if (has_cycle) {
        cout << "uh oh pip does not approve" << endl;
    } else {
        cout << "Topological order: ";
        // Reverse the finish order for topological sort
        for (int i = finish_order.size() - 1; i >= 0; i--) {
            cout << finish_order[i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
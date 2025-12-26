/*
find out if a graph has a eulerian path, if so find it with the hierholzer's algorithm
implement maximum flow using scaling algorithm
for bipartite graph, find the maximum matching of that graph.
*/

#include <vector>
#include <iostream>
#include <stack>
#include <tuple>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

//1. Eulerian path with Hierholzer's algorithm
/*
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
    */


//2. Maximum flow using scaling algorithm
vector<vector<int>> capacity;
vector<vector<int>> flow;
int n;
vector<tuple<int,int,int>> edges;

bool bfs(int source, int sink, vector<int>& parent, int minCapacity) {
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(source);
    visited[source] = true;
    parent[source] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < n; v++) {
            if (!visited[v] && capacity[u][v] - flow[u][v] >= minCapacity) {
                q.push(v);
                visited[v] = true;
                parent[v] = u;
                if (v == sink) {
                    return true;
                }
            }
        }
    }

    return false;
}

int scalingMaxFlow(int source, int sink) {
    capacity.assign(n, vector<int>(n, 0));
    flow.assign(n, vector<int>(n,0));

    for (auto& edge : edges) {
        int weight = get<0>(edge);
        int u = get<2>(edge);
        int v = get<1>(edge);
        capacity[u][v] = weight;
    }

    int maxFlow = 0;
    int maxCapacity = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            maxCapacity = max(maxCapacity, capacity[i][j]);
        }
    }

    int scale = 1;
    while (scale <= maxCapacity) scale *= 2;
    scale /= 2;

    while (scale >= 1) {
        vector<int> parent(n);

        while (bfs(source, sink, parent, scale)) {
            int pathFlow = INT_MAX;
            for (int v = sink; v != source; v = parent[v]) {
                int u = parent[v];
                pathFlow = min(pathFlow, capacity[u][v] - flow[u][v]);
            }

            for (int v = sink; v != source; v = parent[v]) {
                int u = parent[v];
                flow[u][v] += pathFlow;
                flow[v][u] -= pathFlow;
            }

            maxFlow += pathFlow;
        }

        scale /= 2;
    }

    return maxFlow;
}

int main() {
    // Same edge list as in Eulerian path problem
    // Format: (weight, node2, node1) - weight is capacity for max flow
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
    
    n = 9; // nodes 1-8
    
    // Test max flow from node 1 to node 8
    int source = 1;
    int sink = 8;
    int maxFlowValue = scalingMaxFlow(source, sink);
    
    cout << "Maximum flow from " << source << " to " << sink << ": " << maxFlowValue << endl;
    
    // Debug: Print capacity matrix
    cout << "\nCapacity matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (capacity[i][j] > 0) {
                cout << "Edge " << i << " -> " << j << ": " << capacity[i][j] << endl;
            }
        }
    }
    
    return 0;
}
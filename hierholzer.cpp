/*
1. First find out if a given graph has an Eulerian path.
If so, find out the path via Hierholzer's algorithm.

the given graph:
(edges will be presented in form a to b, weight c)
1 to 2, weight 3
1 to 3, weight 5
2 to 6, weight 6
3 to 4, weight 2
4 to 2, weight 3
4 to 5, weight 2
4 to 6, weight 8
6 to 7, weight 11
6 to 8, weight 9
7 to 8, weight 2
*/
#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int from, to;
};

int main() {
    bool directed = true;   // 🔁 change this if needed

    vector<Edge> edges = {
        {1,2},{1,3},{2,6},{3,4},{4,2},{4,5},{4,6},{6,7},{6,8},{7,8}
    };

    unordered_map<int, vector<pair<int,int>>> adj;
    unordered_map<int,int> in, out, degree;
    vector<bool> used(edges.size(), false);

    // Build graph
    for (int i = 0; i < edges.size(); i++) {
        auto &e = edges[i];
        adj[e.from].push_back({e.to, i});
        out[e.from]++;
        in[e.to]++;

        if (!directed) {
            adj[e.to].push_back({e.from, i});
            degree[e.from]++;
            degree[e.to]++;
        }
    }

    int start = -1, end = -1;

    if (directed) {
        for (auto &p : adj) {
            int v = p.first;
            int diff = out[v] - in[v];
            if (diff == 1) start = v;
            else if (diff == -1) end = v;
            else if (diff != 0) {
                cout << "No Eulerian path\n";
                return 0;
            }
        }
        if (start == -1) start = edges[0].from;
    }
    else {
        vector<int> odd;
        for (auto &p : degree)
            if (p.second % 2) odd.push_back(p.first);

        if (!(odd.size() == 0 || odd.size() == 2)) {
            cout << "No Eulerian path\n";
            return 0;
        }
        start = odd.empty() ? edges[0].from : odd[0];
    }

    // Hierholzer
    vector<int> path;
    function<void(int)> dfs = [&](int u){
        while (!adj[u].empty()) {
            auto [v, id] = adj[u].back();
            adj[u].pop_back();
            if (used[id]) continue;
            used[id] = true;
            dfs(v);
        }
        path.push_back(u);
    };

    dfs(start);
    reverse(path.begin(), path.end());

    if (path.size() != edges.size() + 1) {
        cout << "No Eulerian path\n";
        return 0;
    }

    cout << "Eulerian path:\n";
    for (int x : path) cout << x << " ";
    cout << "\n";
}
/*
2. Implement the maximal flow using Ford-Fulkerson and more specifically scaling algorithm
*/

/*
3. For bipartite graph, find out the maximal matching of that bipartite graph.
*/
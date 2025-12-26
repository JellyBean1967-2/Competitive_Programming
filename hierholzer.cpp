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
    int from, to, capacity;
};

struct FlowEdge {
    int to, cap, rev;
};

unordered_map<int, vector<FlowEdge>> flowGraph;

void addFlowEdge(int u, int v, int cap) {
    FlowEdge a = {v, cap, (int)flowGraph[v].size()};
    FlowEdge b = {u, 0,   (int)flowGraph[u].size()};
    flowGraph[u].push_back(a);
    flowGraph[v].push_back(b);
}

int dfsFlow(int u, int t, int f, int delta,
            unordered_set<int>& vis,
            vector<int>& path) {
    if (u == t) return f;
    vis.insert(u);

    for (auto &ed : flowGraph[u]) {
        if (!vis.count(ed.to) && ed.cap >= delta) {
            path.push_back(ed.to);
            int pushed = dfsFlow(ed.to, t, min(f, ed.cap), delta, vis, path);
            if (pushed) {
                ed.cap -= pushed;
                flowGraph[ed.to][ed.rev].cap += pushed;
                return pushed;
            }
            path.pop_back();
        }
    }
    return 0;
}

int main() {
    vector<Edge> edges = {
        {1,2,3},{1,3,5},{2,6,6},{3,4,2},{4,2,3},
        {4,5,2},{4,6,8},{6,7,11},{6,8,9},{7,8,2}
    };
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
    unordered_map<int,int> in, out;
    unordered_set<int> nodes;

    for (auto &e : edges) {
        out[e.from]++;
        in[e.to]++;
        nodes.insert(e.from);
        nodes.insert(e.to);
    }

    int plus = 0, minus = 0, start = -1;
    bool hasEuler = true;

    for (int v : nodes) {
        int diff = out[v] - in[v];
        if (diff == 1) { start = v; plus++; }
        else if (diff == -1) minus++;
        else if (diff != 0) hasEuler = false;
    }

    if (!((plus == 1 && minus == 1) || (plus == 0 && minus == 0)))
        hasEuler = false;

    if (!hasEuler)
        cout << "No Eulerian path\n";
    else
        cout << "Eulerian path exists\n";

/*
2. Implement the maximal flow using Ford-Fulkerson and more specifically scaling algorithm
*/
    for (auto &e : edges)
        addFlowEdge(e.from, e.to, e.capacity);

    int maxCap = 0;
    for (auto &e : edges) maxCap = max(maxCap, e.capacity);

    int delta = 1;
    while (delta * 2 <= maxCap) delta *= 2;

    int source = 1, sink = 8, maxFlow = 0;

    while (delta) {
        while (true) {
            unordered_set<int> visited;
            vector<int> path = {source};

            int pushed = dfsFlow(source, sink, INT_MAX, delta, visited, path);
            if (!pushed) break;

            cout << "Augmenting path: ";
            for (int v : path) cout << v << " ";
            cout << "| pushed = " << pushed << "\n";

            maxFlow += pushed;
        }
        delta /= 2;
    }

    cout << "Max Flow from " << source << " to " << sink
         << " = " << maxFlow << "\n";
}
/*
3. For bipartite graph, find out the maximal matching of that bipartite graph.
*/
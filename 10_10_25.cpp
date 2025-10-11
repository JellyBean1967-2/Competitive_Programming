/*
HW
i will give you a graph
implement this kruskal algorithm by using union_find structure
 1-(15)-5-(6)-4-(3)-6                  9-(2)-10
 | \        /      |                   |    /
(8) \     (3)     (2)                  |  (1)
 |  (7)   /        |                  (7) /
 |    \ /          |                   | /
 2-(3)-3----(4)-----7-------(4)--------8
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <tuple>
using namespace std;

const int MAXN = 11;
int link[MAXN], sz[MAXN];
int n = 10;

int find(int x) {
    while (x != link[x]) x = link[x];
    return x;
}

bool same(int a, int b) {
    return find(a) == find(b);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (sz[a] < sz[b]) swap(a,b);
    sz[a] += sz[b];
    link[b] = a;
}

int main(){
    for (int i = 1; i <= n; i++) link[i] = i;
    for (int i = 1; i <= n; i++) sz[i] = 1;
    vector<tuple<int,int,int>> edges;
    // Format: (weight, node1, node2) for proper sorting
    edges.push_back({8,1,2});
    edges.push_back({7,1,3});
    edges.push_back({15,1,5});
    edges.push_back({3,2,3});
    edges.push_back({3,3,4});
    edges.push_back({4,3,7});
    edges.push_back({6,4,5});
    edges.push_back({3,4,6});
    edges.push_back({2,6,7});
    edges.push_back({4,7,8});
    edges.push_back({7,8,9});
    edges.push_back({1,8,10});
    edges.push_back({2,9,10});
    
    // Sort edges by weight for Kruskal's algorithm
    sort(edges.begin(), edges.end());
    
    cout << "Sorted edges by weight:\n";
    for (auto edge : edges) {
        cout << "Weight: " << get<0>(edge) << ", Edge: " << get<1>(edge) << "-" << get<2>(edge) << "\n";
    }
    
    // Kruskal's algorithm
    vector<tuple<int,int,int>> mst;
    int total_weight = 0;
    
    cout << "\nMST construction:\n";
    for (auto edge : edges) {
        int w = get<0>(edge);
        int u = get<1>(edge);
        int v = get<2>(edge);
        
        if (!same(u, v)) {
            unite(u, v);
            mst.push_back(edge);
            total_weight += w;
            cout << "Added edge: " << u << "-" << v << " (weight: " << w << ")\n";
        }
    }
    
    cout << "\nminimum spanning tree total weight: " << total_weight << "\n";
    cout << "minimum spanning tree edges: " << mst.size() << "\n";
}
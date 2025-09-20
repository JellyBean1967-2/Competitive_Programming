//find max length from node x
// 1
// |  \
// 3  2
// |  | \
// 4  5  6
//   / \  \
//  7  8   9
// /        \
// 10       11
#include <vector>
#include <iostream>
using namespace std;

int making_adjacencylist_inprogress(vector<pair<int,int>> adj[]){
    // Add edges in both directions for undirected tree
    adj[1].push_back({3,1}); adj[3].push_back({1,1});
    adj[1].push_back({2,1}); adj[2].push_back({1,1});
    adj[2].push_back({5,1}); adj[5].push_back({2,1});
    adj[2].push_back({6,1}); adj[6].push_back({2,1});
    adj[3].push_back({4,1}); adj[4].push_back({3,1});
    adj[5].push_back({7,1}); adj[7].push_back({5,1});
    adj[5].push_back({8,1}); adj[8].push_back({5,1});
    adj[6].push_back({9,1}); adj[9].push_back({6,1});
    adj[7].push_back({10,1}); adj[10].push_back({7,1});
    adj[9].push_back({11,1}); adj[11].push_back({9,1});
    return 0;
}

void dfs1(int s, int parent, vector<int>& maxlength_1, vector<pair<int,int>> adj[]) {
    maxlength_1[s] = 0;
    for (auto u : adj[s]) {
        auto [n, w] = u;
        if (n == parent) continue;
        dfs1(n, s, maxlength_1, adj);
        maxlength_1[s] = max(maxlength_1[s], maxlength_1[n] + w);
    }
}

void dfs2(int s, int parent, vector<int>& maxlength_1, vector<int>& maxlength_2, vector<pair<int,int>> adj[]) {
    for (auto u : adj[s]) {
        auto [n, w] = u;
        if (n == parent) continue;
        
        // Compute upward path for child n
        maxlength_2[n] = maxlength_2[s] + w;
        
        // Find best path through siblings
        int best_sibling = 0;
        for (auto v : adj[s]) {
            auto [sibling, w2] = v;
            if (sibling == parent || sibling == n) continue;
            best_sibling = max(best_sibling, maxlength_1[sibling] + w2);
        }
        
        maxlength_2[n] = max(maxlength_2[n], best_sibling + w);
        
        dfs2(n, s, maxlength_1, maxlength_2, adj);
    }
}

int main(){
    vector<pair<int,int>> adj[12];
    vector<int> maxlength_1(12), maxlength_2(12);
    
    making_adjacencylist_inprogress(adj);
    
    dfs1(1, -1, maxlength_1, adj);
    maxlength_2[1] = 0;
    dfs2(1, -1, maxlength_1, maxlength_2, adj);
    
    for (int i = 1; i <= 11; i++) {
        cout << "Max length from node " << i << ": " << max(maxlength_1[i], maxlength_2[i]) << endl;
    }
    
    return 0;
}
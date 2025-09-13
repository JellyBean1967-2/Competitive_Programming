//given fixed tree, ask user to type node id calculate number of nodes in subtree
// 1
// |  \
// 3  2
// |  | \
// 4  5  6
//   / \  \
//  7  8   9
// /        \
// 10       11
#include <iostream>
#include <vector>
using namespace std;

int making_adjacencylist_inprogress(vector<pair<int,int>> adj[]){
    adj[1].push_back({3,1});
    adj[1].push_back({2,1});
    adj[2].push_back({5,1});
    adj[2].push_back({6,1});
    adj[3].push_back({4,1});
    adj[5].push_back({7,1});
    adj[5].push_back({8,1});
    adj[6].push_back({9,1});
    adj[7].push_back({10,1});
    adj[9].push_back({11,1});
    return 0;
}

void dfs(int s, int e, int count[], vector<pair<int,int>> adj[]) {
    count[s] = 1;
    for (auto u : adj[s]) {
        auto [n,m] = u;
        if (n == e) continue;
        dfs(n, s, count, adj);
        count[s] += count[n];
    }
}

int main(){
    int count[12];
    vector<pair<int,int>> adj[12];
    int id;
    cout << "Please give me the id of the node you chose from this tree: " << endl;
    cin >> id;
    making_adjacencylist_inprogress(adj);
    dfs(1, 0, count, adj);
    cout << "This is the number of nodes in the subtree of the node you chose: " << count[id] << endl;
}

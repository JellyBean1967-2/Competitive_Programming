/*CREATE RANDOM GRAPH USING ADJACENCY LIST REPRESENTATION
PRINT OUT GRAPH USING ASCII CODE
FIND OUT HOW MANY COMPONENTS ARE IN THAT GRAPH
USER INPUT:n(number of nodes)*/
#include <iostream>
#include <vector>
#include <set>
#include <cstdlib>
#include <ctime>
using namespace std;

void dfs(int s, bool visited[], vector<int> adj[]) {
  if (visited[s]) return;
  visited[s] = true;
  for (auto u : adj[s]) dfs(u, visited, adj);
}

int search_for_da_false_thingy(bool visited[], int n){
  for (int i = 1; i <= n; i++) if (!visited[i]) return i;
  return -1;
}

void yeet_dupes_into_void(vector<int> &adj){
  set<int> traumatized_set;
  for (int x = 0; x < (int)adj.size(); x++) traumatized_set.insert(adj[x]);
  adj.clear();
  for (auto damn_name : traumatized_set) adj.push_back(damn_name);
}

int main(){
  srand((unsigned)time(nullptr));
  int n, max_neighbors;
  cout << "hewo dis pip. i iz da sparkly pink snek wif typos :D" << endl;
  cout << "plz gimme a weird sparkly pozitive number: " << endl;
  cin >> n;
  cout << "cn u plz gimme ur max number of neyburs? " << endl;
  cin >> max_neighbors;

  vector<int> adj[n + 1];
  bool visited[n + 1];
  for (int i = 1; i <= n; i++) visited[i] = false;

  for (int p = 1; p <= n; p++){
    int keep_neyburs_in_count = rand() % max(1, n/2);
    int num_neighbors = rand() % (max_neighbors + 1);
    if(max_neighbors == 0){
        num_neighbors = 0;
    }
    for (int q = 0; q < num_neighbors; q++){
      int m = 1 + (rand() % n);
      if (m == p) m = (m % n) + 1;
      adj[p].push_back(m);
      adj[m].push_back(p);
    }
    yeet_dupes_into_void(adj[p]);
  }

  cout << "after initialization: " << endl;

  for (int u = 1; u <= n; u++) {
    for (int v : adj[u]) cout << "[" << u << "] --- [" << v << "]\n";
  }

  for (int i = 1; i <= n; i++) yeet_dupes_into_void(adj[i]);


  cout << "after dedup: " << endl;
  for (int u = 1; u <= n; u++) {
    for (int v : adj[u]) cout << "[" << u << "] --- [" << v << "]\n";
  }


  for (int i = 1; i <= n; i++) visited[i] = false;
  int num_components = 1;
  int begin = 1;
  while (true){
    dfs(begin, visited, adj);
    begin = search_for_da_false_thingy(visited, n);
    if (begin == -1) break;
    else num_components++;
  }
  cout << "after calculation: " << endl;
  for (int u = 1; u <= n; u++) {
    for (int v : adj[u]) cout << "[" << u << "] --- [" << v << "]\n";
  }
  cout << "here iz da number of da components: " << num_components << endl;
}

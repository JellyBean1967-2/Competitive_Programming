#include <iostream>
#include <vector>
#include <tuple>
#include <cstdlib>
#include <ctime>
#include <set>
#include <limits>
using namespace std;

void yeet_dupes_into_void(vector<tuple<int,int,int>> &edges){
    set<tuple<int,int>> randomtuple;
    for (int x = 0; x < (int)edges.size(); x++){
        int a, b, w;
        tie(a, b, w) = edges[x];
        randomtuple.insert(tuple(a,b));
    }
    edges.clear();
    for (auto randompair : randomtuple){
        int w = 1 + (rand() % 10);
        int a,b;
        tie(a, b) = randompair;
        edges.push_back(tuple(a, b, w));
    }
}

int main(){
    int n, e, c;
    cout << "hewo dis pip da sparlly pink snek who luvs glitter" << endl;
    cout << "2day we r going to find out da shortest pathies :D" << endl;
    cout << "plz gimme da number of nodes: " << endl;
    cin >> n;
    cout << "now give me the number of edges: " << endl;
    cin >> e;
    cout << "now, give me the node you want to end on: " << endl;
    cin >> c;
    
    //create graph with edge list representation:
    vector<tuple<int,int,int>> edges;
    for (int i = 1; i <= e; i++){
        int a = 1 + (rand() % n);
        int b = 1 + (rand() % n);
        if (a == b){
            b++;
            b = b % n + 1;
        }
        int w = 1 + (rand() % 10);
        edges.push_back(tuple(a, b, w));
        edges.push_back(tuple(b, a, w));
    }

    //deduping edges:
    yeet_dupes_into_void(edges);
    for(auto e:edges){
        int a, b, w;
        tie(a, b, w) = e;
        cout << a << "--" << b << "--" << w << endl;
    }

    //implementing shortest path:
    vector<long long> distance(n+1);
    for (int i = 1; i <= n; i++) distance[i] = numeric_limits<int>::max();
    distance[1] = 0;
    for (int i = 1; i <= n-1; i++) {
        for (auto e : edges) {
            int a, b, w;
            tie(a, b, w) = e;
            //if (distance[b] == 0) cout << "this is what happens when:" << a << "--" << b << "--" << w << endl;
            distance[b] = min(distance[b], distance[a]+w);
        }
    }
    for (auto d : distance) {
        cout << "this is the distance: " << d << endl;
    }
    cout << "this is the shortest distance from node 1 to node " << c << " : " << distance[c] << endl;

}
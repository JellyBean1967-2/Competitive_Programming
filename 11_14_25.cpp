/*
homerk!!!
giveu a graph
whatever you have last time
first check if its a successor graph
second start from node one
succ(1, input value)
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <tuple>
#include <map>
#include <set>
using namespace std;

int succ(int x, int k, map<int, int>& graph) {
    int current = x;
    for (int i = 0; i < k; i++) {
        if (graph.find(current) == graph.end()) {
            cout << "No outgoing edge from node " << current << endl;
            return -1;
        }
        current = graph[current];
    }
    return current;
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
    
    // Build adjacency map for successor graph
    map<int, int> graph;
    for (auto& edge : edges) {
        int weight = get<0>(edge);
        int from = get<1>(edge);
        int to = get<2>(edge);
        graph[from] = to;
    }
    
    cout << "here is the graph's edge list :D" << endl;
    for (auto& edge : edges) {
        cout << "(" << get<0>(edge) << ", " << get<1>(edge) << ", " << get<2>(edge) << ")" << endl;
    }
    // Check if this is a successor graph (each node has exactly one outgoing edge)
    cout << "Checking if this is a successor graph..." << endl;
    bool isSuccessorGraph = true;
    set<int> seenNodes;
    for (auto& edge : edges) {
        int from = get<1>(edge);
        if (seenNodes.count(from)) {
            cout << "Node " << from << " has multiple outgoing edges - NOT a successor graph!" << endl;
            isSuccessorGraph = false;
            break;
        }
        seenNodes.insert(from);
    }
    
    if (isSuccessorGraph) {
        cout << "this graph is a successor graph :D" << endl;
        cout << "Path from node 1: ";
        int current = 1;
        set<int> visited;
        while (true) {
            cout << current;
            if (visited.count(current)) {
                cout << endl;
                break;
            }
            visited.insert(current);
            if (graph.find(current) != graph.end()) {
                current = graph[current];
                cout << " -> ";
            } else {
                cout << endl;
                break;
            }
        }
        
        cout << "Path from node 2: ";
        current = 2;
        visited.clear();
        while (true) {
            cout << current;
            if (visited.count(current)) {
                cout << endl;
                break;
            }
            visited.insert(current);
            if (graph.find(current) != graph.end()) {
                current = graph[current];
                cout << " -> ";
            } else {
                cout << endl;
                break;
            }
        }
    } else {
        cout << "this is NOT a successor graph :(" << endl;
    }
    cout << "pls give me a random number so that i cn walk on nodes :3" << endl;
    int k;
    cin >> k;
    
    int result = succ(1, k, graph);
    if (result != -1) {
        cout << "this is the ending node: " << result << endl;
    }
    
    return 0;
}
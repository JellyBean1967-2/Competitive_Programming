/*hi dis adele
given one(1) graph
uhh code up da three representations of da graph
ok lets be more specific
ok?yes?yes?
given number nodes constract a - nonono simple connected graph
adjacency list, matrix, edge list
*/
#include <iostream>
using namespace std;
int making_adjacencylist_inprogress(int n){
    vector<pair<int,int>> adj[n];
    for (int p = 1; p < n; p++){
        int m = rand() % 10;
        if(m == 0){
            m++;
        }
        adj[0].push_back({p,m});
    }
    return 0;
}

int making_matrix_inprogress(int n){
    int adj[n][n];
    //initialize matrix!
    for (int p = 0; p < n; p++){
        for (int wutever = 0; wutever < n; wutever++){
           adj[p][wutever] = 0;
        }
    }
    for (int p = 1; p < n; p++){
        int m = rand() % 10;
        if(m == 0){
            m++;
        }
        adj[0][p] = m;
    }
    for (int p = 0; p < n; p++){
        for (int wutever = 0; wutever < n; wutever++){
            cout << adj[p][wutever] << " ";
        }
        cout << endl;
    }
    return 0;
}

int making_edgelist_inprogress(int n){
    vector<tuple<int,int,int>> edges;
    for (int p = 1; p < n; p++){
        int m = rand() % 10;
        if(m == 0){
            m++;
        }
        edges.push_back({0,p,m});
    }
    return 0;
}

int main(){
    int n;
    cout << "hi dis pip. me iz sparkly chaos bean wif typos:D" << endl;
    cout << "cn u gimme random integer: " << endl;
    cin >> n;
    cout << "thx! now me gonna process. pls wait a millisecond :D" << endl;
    making_adjacencylist_inprogress(n);
    cout << "here is ur lovely matrix: " << endl;
    making_matrix_inprogress(n);
    making_edgelist_inprogress(n);

}


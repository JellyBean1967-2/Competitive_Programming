#include <iostream>
using namespace std;

int main(){
    cout << "hi! me rice.wif wainbow gwittewy cawwots.:D" << endl;
    cout << "anyway. TODAY, WE YEET PPL...into elavaders." << endl;
    int n,x;
    cout << "OK first tell me da numba of doomed ppl u wanna put on da elavader. --> " << endl;
    cin >> n;
    cout << "ookie. now tell me da numba of pounds dat da elavader can hold before spontaneously combusting.:D" << endl;
    cin >> x;
    cout << "tank u! now me processing..." << endl;
    int* weight = new int[n];
    for (int i = 0; i < n; i++) {
        weight[i] = rand() % 500;
        cout << weight[i] << endl;
    }
    pair<int,int> best[1<<n];
    best[0] = {1,0};
    for (int s = 1; s < (1<<n); s++) {
        // initial value: n+1 rides are needed
        best[s] = {n+1,0};
        for (int p = 0; p < n; p++) {
            if (s&(1<<p)) {
                auto option = best[s^(1<<p)];
                if (option.second+weight[p] <= x) {
                    // add p to an existing ride
                    option.second += weight[p];
                } else {
                    // reserve a new ride for p
                    option.first++;
                    option.second = weight[p];
                }
                best[s] = min(best[s], option);
            }
        }
    }
    delete []weight;
    cout << "ok da best rideys are: " << best[(1 << n) - 1].first << endl;
}
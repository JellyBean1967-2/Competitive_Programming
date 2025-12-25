// 1. given an arbitrary number, list the optimal way to represent it as a sum of powers of 2
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cout << "Please enter a number n: ";
    cin >> n;
    cout << "Powers used: ";
    int power = 0;
    while (n > 0) {
        if (n & 1) {
            cout << (1 << power) << " ";
        }
        n >>= 1;
        power++;
    }
}
// 2. whats a seg tree and why is it used
/*
seg tree = a data struct that really, really supports range queries
used for when u want to reuse precomputed info a bajillion times over

use when:
u have lots of range queries
AND the array changes over time
AND the size is big
*/
// 3. why a range min query has a time complexity of o(1) after preprocessing
/*
range min query uses a sparse table
it works cuz the minimum function is idempotent -> min(x, x) = x
and for the minimum function
we use a data struct called heap (min-heap)
time complexity is o(1) cuz we pick up the top one
*/
// 4. what is union-find data structure and what are its major applications?
/*
union-find (aka DSU) is a data struct that keeps track of disjoint groups
it lets u check fast whether 2 elements are in the same group and also merge groups fast
used mainly for connectivity problems in graph theory (e.g., kruskal algorithm)
and with optimizations it runs in almost o(1) time
cuz the tree become FLAT :)
*/
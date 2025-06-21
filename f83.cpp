#include <iostream>
#include <vector>
#include <numeric>   // For std::adjacent_difference
using namespace std;

// Custom function (instead of a lambda) to compute our formula:
// For each adjacent pair, compute:
//    (current - previous) + (current * current) / 2
int custom_adjacent_diff(int current, int previous) {
    return (current - previous) + (current * current) / 2;
}

int main() {
    // Original vector a
    vector<int> a = {10, 3, 5, 7, 2, 8, 6};
    
    // Perform in-place adjacent_difference on vector a.
    // After this call:
    //   a[0] remains a copy of the original a[0],
    //   a[1] becomes the computed value for the pair (a[0], a[1]),
    //   a[2] becomes the computed value for the pair (a[1], a[2]), etc.
    adjacent_difference(a.begin(), a.end(), a.begin(), custom_adjacent_diff);
    
    // The first element (a[0]) is just the original first element.
    // Our computed values start from a[1] onward.
    cout << "Modified vector: ";
    for (auto it = a.begin() + 1; it != a.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    return 0;
}

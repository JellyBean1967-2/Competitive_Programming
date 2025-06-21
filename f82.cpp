#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // Example vector of integers
    vector<int> v = {10, 3, 5, 7, 2, 8, 6};

    // Create a max-heap from the vector
    make_heap(v.begin(), v.end());

    // Number of top elements to extract
    int i = 3; // For example, the top 3 elements

    cout << "Top " << i << " largest elements: ";
    for (int j = 0; j < i; ++j) {
        // The largest element is at the front of the heap
        cout << v.front() << " ";

        // Move the largest element to the end and adjust the heap
        pop_heap(v.begin(), v.end());
        // Remove the last element (which is the largest just extracted)
        v.pop_back();
    }
    cout << endl;

    return 0;
}

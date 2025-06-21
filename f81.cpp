#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int find_ith_largest(vector<int>& vec, int i) {
    // We are looking for the (i-1)th largest element in a 0-based index
    int index = vec.size() - i;
    nth_element(vec.begin(), vec.begin() + index, vec.end());
    return vec[index];
}

int main() {
    vector<int> vec = {12, 3, 5, 7, 19, 10};
    int i = 3;
    int result = find_ith_largest(vec, i);
    cout << "The " << i << "th largest element is: " << result << endl;
    return 0;
}
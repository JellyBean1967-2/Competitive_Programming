#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <set>
#include <algorithm>
#include <unordered_set>

using namespace std;

vector<int> generateRandomVector(int size, int range) {
    srand(time(0));
    set<int> uniqueSet;

    while (uniqueSet.size() < size) {
        uniqueSet.insert(rand() % (range + 1));
    }

    vector<int> vec(uniqueSet.begin(), uniqueSet.end());
    return vec;
}


//1. Using set to find common elements
vector<int> hashSetCommon(const vector<int>& vec1, const vector<int>& vec2) {
    set<int> set1(vec1.begin(), vec1.end());
    vector<int> common;
    
    for (int num : vec2) {
        if (set1.find(num) != set1.end()) {
            common.push_back(num);
        }
    }
    return common;
}

//2. Using unordered_set to find common elements
vector<int> hashUnorderedSetCommon(const vector<int>& vec1, const vector<int>& vec2) {
    unordered_set<int> set1(vec1.begin(), vec1.end());
    vector<int> common;
    
    for (int num : vec2) {
        if (set1.find(num) != set1.end()) {
            common.push_back(num);
        }
    }
    return common;
}

//3. Using sorting and two-pointer technique to find common elements
vector<int> sortCommon(const vector<int>& vec1, const vector<int>& vec2) {
    vector<int> common;
    vector<int> sortedVec1 = vec1;
    vector<int> sortedVec2 = vec2;

    sort(sortedVec1.begin(), sortedVec1.end());
    sort(sortedVec2.begin(), sortedVec2.end());

    int i = 0, j = 0;
    while (i < sortedVec1.size() && j < sortedVec2.size()) {
        if (sortedVec1[i] == sortedVec2[j]) {
            common.push_back(sortedVec1[i]);
            ++i;
            ++j;
        } else if (sortedVec1[i] < sortedVec2[j]) {
            ++i;
        } else {
            ++j;
        }
    }

    return common;
}

int main() {
    int n, m;
    cout << "Enter size of first array (n): ";
    cin >> n;
    cout << "Enter size of second array (m): ";
    cin >> m;

    vector<int> vec1 = generateRandomVector(n, 2 * n); 
    vector<int> vec2 = generateRandomVector(m, 2 * m); 

    vector<int> common1 = sortCommon(vec1, vec2);
    vector<int> common2 = hashUnorderedSetCommon(vec1, vec2);
    vector<int> common3 = hashSetCommon(vec1,vec2);

    cout << "Number of common elements(1): " << common1.size() << endl;
    cout << "Number of common elements(2): " << common2.size() << endl;
    cout << "Number of common elements(3): " << common3.size() << endl;
    
    cout << endl;

    return 0;
}

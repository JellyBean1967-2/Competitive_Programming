#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

vector<int> generateRandomVector(int n) {
    srand(time(0)); 
    vector<int> vec(n);

    for (int i = 0; i < n; ++i) {
        vec[i] = rand() % (2 * n + 1);
    }

    return vec;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int> randomVector = generateRandomVector(n);

    cout << "Random Vector: ";
    for (int num : randomVector) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}



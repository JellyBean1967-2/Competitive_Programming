#include <iostream>
#include <vector>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For srand(time(0))

using namespace std;

int calculateTree(int k, vector<int> arr) {
    int startIndex = k - (k & -k) + 1;
    int sum = 0;
    for (int i = startIndex; i <= k; i++){
        sum = sum + arr[i];
    }
    return sum;
}

int sum(int k, vector<int> tree) {
    int s = 0;
    while (k >= 1) {
        s += tree[k];
        k -= k&-k;
    }
    return s;
}

void add(int n, int k, int x, vector<int> & tree) {
    while (k <= n) {
        tree[k] += x;
        k += k&-k;
    }
}

int main() {
    // Seed the random number generator
    srand(time(0));

    int n, a, b, c, d;
    cout << "Please enter the size of the array: ";
    cin >> n;

    vector<int> stupidarr(n + 1);
    vector<int> stupidtree(n + 1);
    vector<int> stupidsum(n + 1);


    // Fill stupidarr with random numbers
    for (int i = 1; i < n + 1; i++) {
        stupidarr[i] = rand() % 100;
    }

    // Print the original array
    cout << "Original array (1-indexed):" << endl;
    for (int i = 1; i < n + 1; i++) {
        cout << stupidarr[i] << " ";
    }
    cout << endl;

    // Fill stupidTree with random numbers
     for (int i = 1; i < n + 1; i++) {
        stupidtree[i] = calculateTree(i, stupidarr);
    }

    // Print the original array
    cout << "Fenwick Tree (1-indexed):" << endl;
    for (int i = 1; i < n + 1; i++) {
        cout << stupidtree[i] << " ";
    }
    cout << endl;
    
    for (int i = 1; i < n + 1; i++) {
        stupidsum[i] = sum(i, stupidtree);
    }

    cout << "Sum Array (1-indexed):" << endl;
    for (int i = 1; i < n + 1; i++) {
        cout << stupidsum[i] << " ";
    }
    cout << endl;

    // Example of a range sum query (sum of elements from index a to b, inclusive)
    // If you want 0-indexed range queries on the original array from 'a' to 'b' (inclusive):
    // The sum is from index 'a' to 'b' in the original array (0-indexed).
    // In Fenwick tree terms (1-based indexing), this means sum up to index (b+1) minus sum up to index 'a'.
    // Example: original array indices 0 to 5. Fenwick tree indices 1 to 6.
    // To get sum of arr[a] to arr[b] (0-indexed), we do sum(b+1) - sum(a)

    cout << "Please enter the start and end indexes of the subarray (0-indexed): ";
    cin >> a >> b;
    if(a <= n && b <= n && a > 0 && b > 0 && a < b) {
        int sum = stupidsum[b] - stupidsum[a - 1];
        cout << "The output is: " << sum << endl;
    }
    else {
        cout << "Inputed wrong number.";
    }
    cout << "Please enter the index and the value that you want to change it to: ";
    cin >> c >> d;
    if (c <= n && c >= a && c <= b) {
        int x = d - stupidarr[c];
        cout << "here is x: " << x << endl;
        add(n, c, x, stupidtree);
        for (int i = 1; i < n + 1; i++) {
            cout << stupidtree[i] << " ";
        }
        cout << endl;

        for (int i = c; i < n + 1; i++) {
            stupidsum[i] = sum(i, stupidtree);
        }
        cout << "Sum Array (1-indexed):" << endl;
        for (int i = 1; i < n + 1; i++) {
            cout << stupidsum[i] << " ";
        }
        cout << endl;
        int sum = stupidsum[b] - stupidsum[a - 1];
        cout << "The updated sum is: " << sum << endl;
    }
    else {
        cout << "Inputed wrong number.";
    }
    
    return 0;
}



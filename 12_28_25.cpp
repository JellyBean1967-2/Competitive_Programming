//given input n, find out if there are perfect number(s) less than n.
//If so, output said numbers.

//Given two numbers, compute the gcd and lcm.

#include <iostream>
#include <vector>
using namespace std;

bool isPerfect(int num) {
    if (num <= 1) return false;

    int sum = 1;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            sum += i;
            if (i != num / i) {
                sum += num / i;
            }
        }
    }

    return sum == num;
}

int main() {
    int n;
    cout << "Enter the number: ";
    cin >> n;

    vector<int> perfectNumbers;
    for (int i = 1; i < n; i++) {
        if (isPerfect(i)) {
            perfectNumbers.push_back(i);
        }
    }

    if (perfectNumbers.empty()) {
        cout << "No perfect numbers less than " << n << endl;
    } else {
        cout << "Perfect numbers less than " << n << ": ";
        for (int num : perfectNumbers) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
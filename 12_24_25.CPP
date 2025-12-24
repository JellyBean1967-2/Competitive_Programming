#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

//1. Given an arbitrary number, find the most optimal arrangement of its sum with powers of 2
void findPowersOfTwo(int n) {
    cout << "Finding powers of 2 for: " << n << endl;
    cout << n << " = ";
    
    vector<int> powers;
    int temp = n;
    int power = 0;
    
    while (temp > 0) {
        if (temp & 1) {  // if least significant bit is 1
            powers.push_back(power);
        }
        temp >>= 1;  // right shift by 1
        power++;
    }
    
    // Print the powers
    for (int i = powers.size() - 1; i >= 0; i--) {
        cout << "2^" << powers[i];
        if (i > 0) cout << " + ";
    }
    cout << endl;
    
    // Print actual values
    cout << n << " = ";
    for (int i = powers.size() - 1; i >= 0; i--) {
        cout << (1 << powers[i]);  // 2^power[i]
        if (i > 0) cout << " + ";
    }
    cout << endl;
    cout << "Binary: ";
    
    // Print binary representation
    for (int i = power - 1; i >= 0; i--) {
        cout << ((n >> i) & 1);
    }
    cout << endl << endl;
}

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;
    
    findPowersOfTwo(number);
    return 0;
}
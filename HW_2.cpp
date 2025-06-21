#include <iostream>
#include <vector>
using namespace std;

int main(){
    int array[3] = {197,37,58};
    vector<int> myvector(array,array + 3);
    for (int number :myvector){
        cout << number << " ";
    }
    cout << endl;
    return 0;
}
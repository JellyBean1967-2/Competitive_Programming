#include <iostream>
using namespace std;

void reverse(char arr[], int start_index, int end_index){
    for (int n = start_index; n < (start_index + end_index) / 2; n++){
        int m = end_index - n + start_index;
        char tmp = arr[m];
        arr[m] = arr[n];
        arr[n] = tmp;
    }
}

int main (){
    char str[] = "hello, world";
    cout << "Before reversing: " << str << endl;
    reverse(str, 0, 11);
    cout << "After reversing: " << str << endl;
}
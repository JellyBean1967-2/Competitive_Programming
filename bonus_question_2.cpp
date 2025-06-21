#include <iostream>
using namespace std;    

void find_sum(int array[], int length, int sum, int &first_index, int &end_index){
    for(int n = 0; n<length; n++){
        int value = array[n];
        for(int m = n + 1; m<length; m++){
            if(sum - value == array[m]){
                first_index = n;
                end_index = m;
                return;
            }
        }
    }
}

int main (){
    int myarray[] = {1067,465,873,532,1000};
    int first_index, end_index;
    find_sum(myarray,5,1532,first_index,end_index);
    cout << "The first index is:" << first_index << endl;
    cout << "The second index is:" << end_index << endl;
}
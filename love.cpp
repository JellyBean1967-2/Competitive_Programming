#include<iostream>
#include<fstream>
using namespace std;

int main(){
    fstream lovefile;
    lovefile.open ("love_family.txt", ios::out);
    for(int i = 0; i < 100; i++){
        lovefile << "I LUV MAMA!!!" << endl << endl << endl;
        lovefile << "I LUV DADDY TOO!!!" << endl << endl << endl;
        lovefile << "I ALSO LUV MY SIS!!!(but not when we chao jia)" << endl << endl << endl;
    }
    lovefile.close();
    return 0; 
}
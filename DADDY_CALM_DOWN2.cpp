#include<iostream>
using namespace std;

int main(){
    long long daddyEssence;
    cout << "PLS INPUT RANDOMETH INTEGERETH HERETH: " << endl;
    cin >> daddyEssence;
    int umsampletest = sizeof(daddyEssence);
    cout << umsampletest << endl;
    cout << "THOU SHALT VIOLENTLY RECIEVE THE BINARY REPRESENTATIONNNNN!" << endl;
    for (int i = (sizeof(daddyEssence) << 3) - 1; i >= 0; i--) {
        long long wutever = 1;
        if (daddyEssence&(wutever << i)) cout << "1";
        else cout << "0";
    }
    cout << endl;
    if ((daddyEssence & (daddyEssence - 1)) == 0){
        cout << "I HATH CONCLUDED THAT THIS daddyEssenceTM IS A POWER OF TWO." << endl;
    } else{
        cout << "ERROR 404. THE VERY DISSAPOINTING daddyEssenceTM IS NOT A POWER OF TWO." << endl;
    }
}





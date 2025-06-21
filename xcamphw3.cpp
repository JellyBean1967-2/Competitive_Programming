/*
MY VERY VERY UNGRAND PLAN.
OK, SO:
1. make a queue
2. identify # of ppl there
3. 1st enters,second =yeeted to back of queue,
   3rd enters,..... and so on
4. write the order(who knows how)
*/
#include <iostream>
#include <queue>
using namespace std;

// Recursive function to print the entering order
void kickout(queue<int>& losc) {
    if (!losc.empty()) {
        if (losc.size() >= 2) {
             /*
            Sista comment: 
            1. establish variable which is losc.front()
            2. print it
            3. kick it out permanently
            4. second kid: another variable but also losc.front()
            note that losc.front() does not update as the queue changes
            5. second kid escapes (pop him out and push him in. he would be at the back)
            */
            int first = losc.front();
            cout << first << " ";
            losc.pop();

            int second = losc.front();
            losc.pop();
            losc.push(second);

            kickout(losc);
        } else {
            int last = losc.front();
            cout << last << " ";
            losc.pop();
        }
    }
}

int main() {
    queue<int> losc;
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        losc.push(i);
    }

    kickout(losc);
    cout << endl;
}

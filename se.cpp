// THE UNGRAND PLAN™ - STRANGE ELEVATOR EDITION 🛗😩
// 1. Input: number of floors, start floor, target floor
// 2. Input the cursed elevator values 😤
// 3. Build a BFS queue to explore reachable floors
// 4. Keep track of what floors you’ve already visited (or perish)
// 5. From each floor i, try to go to i + k[i] and i - k[i]
// 6. Don’t go below floor 1 or above floor n (unless you want WA 💀)
// 7. Count the number of button presses it takes
// 8. If you reach the target floor: scream and print the count 🎉
// 9. If queue is empty and you never reached target: cry and print -1 😭
// 10. Re-evaluate your trust in elevators forever 🚪🫠
// 🛗 STRANGE ELEVATOR SIMULATOR: YEET EDITION 🛗
// Featuring panic, buttons, and floor-based despair 🎢🧼

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Global suffering indicators
int numberOfSufferingFloors;
int floorWherePainBegins;
int floorWhereItAllEnds;

vector<int> floorYeetPower;             // floor i launches k[i] steps
vector<int> panicPressCounter;          // number of presses to get to floor i
queue<int> sadnessElevatorQueue;        // BFS queue of emotional damage

void pressButtonsAndCry() {
    // Start BFS from the floor of origin sadness
    panicPressCounter[floorWherePainBegins] = 0;
    sadnessElevatorQueue.push(floorWherePainBegins);

    while (!sadnessElevatorQueue.empty()) {
        int currentlyTrapped = sadnessElevatorQueue.front();
        sadnessElevatorQueue.pop();

        int jump = floorYeetPower[currentlyTrapped];
        int up = currentlyTrapped + jump;
        int down = currentlyTrapped - jump;

        // Yeet upward
        if (up <= numberOfSufferingFloors && panicPressCounter[up] == -1) {
            panicPressCounter[up] = panicPressCounter[currentlyTrapped] + 1;
            sadnessElevatorQueue.push(up);
        }

        // Fall downward
        if (down >= 1 && panicPressCounter[down] == -1) {
            panicPressCounter[down] = panicPressCounter[currentlyTrapped] + 1;
            sadnessElevatorQueue.push(down);
        }
    }
}

int main() {
    // Input: floors, starting point, and target
    cin >> numberOfSufferingFloors >> floorWherePainBegins >> floorWhereItAllEnds;

    floorYeetPower.resize(numberOfSufferingFloors + 1);
    panicPressCounter.resize(numberOfSufferingFloors + 1, -1);

    // Input jump values
    for (int i = 1; i <= numberOfSufferingFloors; i++) {
        cin >> floorYeetPower[i];
    }

    pressButtonsAndCry();

    cout << panicPressCounter[floorWhereItAllEnds] << endl;
}

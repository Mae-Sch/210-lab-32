#include "Car.h"
#include <deque>
#include <iostream>
#include <iomanip>

using namespace std;

const int NUM_LANES = 4;
const int INITIAL_LENGTH = 2;
// integers from 0-100 represent chance of a given event
// sum of all values should be 100, 
// else the last chance may not be reflected in the progream
const int CAR_PAY = 46;
const int CAR_JOIN = 39;
const int CAR_SHIFT = 15;

int main() {
    srand(time(0));

    deque<Car> lanes[NUM_LANES];
    // populating lanes
    for (int i = 0; i < NUM_LANES; ++i) {
        deque<Car> newLane;
        for (int j = 0; j < INITIAL_LENGTH; ++j) {
            newLane.push_back(Car());
        }
        lanes[i] = newLane;
    }

    // deque<Car> lane1;
    for (int i = 0; i < INITIAL_LENGTH; ++i) {
        lanes[i].push_back(Car());
    }

    cout << "Initial Queue:\n";
    for (int i = 0; i < NUM_LANES; ++i) {
        cout << "Lane " << i + 1 << ":\n";
        for (Car currentCar : lanes[i]) {
            cout << "     ";
            currentCar.print();
        }
    }

    int time = 1;

    while (time <= 3) {
        cout << "Time: " << time << endl;
        // loop for all car operations
        time++;

        // for debugging only:
        cin >> time;

        for (int i = 0; i < NUM_LANES; ++i) {
            cout << "Lane: " << i + 1;
            int random = (rand() % 100) + 1;
            if ((random < CAR_PAY) && !lanes[i].empty()) 
            {
                // car pays
                cout << " Paid: ";
                lanes[i].front().print();
                lanes[i].pop_front();
            } 
            else if (random < (CAR_PAY + CAR_JOIN)) 
            {
                // car joins
                Car newCar = Car();
                cout << " Joined: ";
                newCar.print(); 
                lanes[i].push_back(newCar);
            } 
            else if (!lanes[i].empty())
            {
                // car switches
                // we want cars to only switch to adjacent lanes
                // so if in first lane, has to move up one
                // and if in last lane, has to move down one
                // otherwise pick randomly between adjacent lanes
                int targetLane = 0;
                if (i = 0) {
                    targetLane = 1;
                }
                else if (i = NUM_LANES - 1) {
                    targetLane = i - 1;
                }
                else {
                    random = rand() % 2;
                    if (random == 0)
                        targetLane = i - 1;
                    else
                        targetLane = i + 1;
                }
                Car switchingCar = lanes[i].back();
                lanes[i].pop_back();
                if (lanes[targetLane].empty())
                    cout << "\n Target lane empty \n";
                lanes[targetLane].push_back(switchingCar);
                cout << " Switched to Lane " << targetLane + 1 << ": ";
                switchingCar.print();
            } 
            else 
            {
                cout << " Remains empty\n";
            }
        }
        // loop for lane outputs
        for (int i = 0; i < NUM_LANES; ++i) {
            cout << "Lane " << i + 1 << " Queue:\n";
            if (lanes[i].empty()) 
            {
                cout << "     Empty\n"; 
            } 
            else 
            {
                for (Car currentCar : lanes[i]) {
                    cout << "     ";
                    currentCar.print();
            }
            }
        }
    }
}

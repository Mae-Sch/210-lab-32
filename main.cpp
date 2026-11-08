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

    int time = 0;

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
        lanes[0].push_back(Car());
    }

    cout << "Initial Queue:\n";
    for (int i = 0; i < NUM_LANES; ++i) {
        cout << "Lane " << i << ":\n";
        for (Car currentCar : lanes[0]) {
            cout << "     ";
            currentCar.print();
        }
        cout << endl;
    }

    while (time < 20) {
        cout << "Time: " << time << endl;
        // loop for all car operations
        for (int i = 0; i < NUM_LANES; ++i) {
            time++;
            cout << "Lane: " << i + 1;
            int random = (rand() % 100) + 1;
            if ((random < CAR_PAY) && !lanes[0].empty()) 
            {
                // car pays
                cout << " Paid: ";
                lanes[0].front().print();
                lanes[0].pop_front();
            } 
            else if (random < (CAR_PAY + CAR_JOIN)) 
            {
                // car joins
                Car newCar = Car();
                cout << " Joined: ";
                newCar.print(); 
                lanes[0].push_back(newCar);
            } else 
            {/*
                // car switches
                // we want cars to only switch to adjacent lanes
                // so if in first lane, has to move up one
                // and if in last lane, has to move down one
                // otherwise pick randomly between adjacent lanes
                int targetLane;
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
                lanes[targetLane].push_back(switchingCar);
                cout << " Switched to Lane " << targetLane << ": ";
                switchingCar.print();
            */}
        }
        // loop for lane outputs
        for (int i = 0; i < NUM_LANES; ++i) {
            cout << "Lane " << i + 1 << " Queue:\n";
            if (lanes[0].empty()) 
            {
                cout << "     Empty"; 
            } 
            else 
            {
                for (Car currentCar : lanes[0]) {
                    cout << "     ";
                    currentCar.print();
            }
            }
        }
    }
}

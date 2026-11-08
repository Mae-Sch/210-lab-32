#include "Car.h"
#include <deque>
#include <iostream>
#include <iomanip>

using namespace std;

const int INITIAL_LENGTH = 2;

int main() {
    srand(time(0));

    int time = 0;

    deque<Car> lane1;
    for (int i = 0; i < INITIAL_LENGTH; ++i) {
        lane1.push_back(Car());
    }

    cout << "Initial Queue:\n";
    for (Car currentCar : lane1) {
        cout << "     ";
        currentCar.print();
    }
    cout << endl;

    while (!lane1.empty()) {
        time++;
        cout << "Time: " << time << " Operation: ";
        int random = (rand() % 100) + 1;
        if (random >= 45) {
            // car pays
            cout << "Car paid: ";
            lane1.front().print();
            lane1.pop_front();
        } else {
            // car joins
            Car newCar = Car();
            cout << "Joined lane: ";
            newCar.print(); 
            lane1.push_back(newCar);
        }
        cout << "Queue:\n";
        if (lane1.empty()) {
            cout << "     Empty"; 
        } else {
            for (Car currentCar : lane1) {
                cout << "     ";
                currentCar.print();
        }
    }
    cout << endl;
    }
}

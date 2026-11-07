#include "Car.h"
#include <deque>
#include <iostream>
#include <iomanip>

using namespace std;

const int INITIAL_LENGTH = 2;

int main() {
    srand(time(0));

    int time = 0;

    deque<Car> cars;
    for (int i = 0; i < INITIAL_LENGTH; ++i) {
        cars.push_back(Car());
    }

    cout << "Initial Queue:\n";
    for (Car currentCar : cars) {
        cout << "     ";
        currentCar.print();
    }
    cout << endl;

    while (!cars.empty()) {
        time++;
        cout << "Time: " << time << " Operation: ";
        int random = (rand() % 100) + 1;
        if (random >= 45) {
            // car pays
            cout << "Car paid: ";
            cars.front().print();
            cars.pop_front();
        } else {
            // car joins
            Car newCar = Car();
            cout << "Joined lane: ";
            newCar.print(); 
            cars.push_back(newCar);
        }
        cout << "Queue:\n";
        if (cars.empty()) {
            cout << "     Empty"; 
        } else {
            for (Car currentCar : cars) {
                cout << "     ";
                currentCar.print();
        }
    }
    cout << endl;
    }
}

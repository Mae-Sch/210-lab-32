#include <car.h>
#include <deque>
#include <iostream>
#include <iomanip>

using namesapce std;

void event(deque<Car>&);

const int INITIAL_LENGTH = 2;

int main() {
    int time = 0;

    deque<Car> cars;
    for (int i = 0; i < INITIAL_LENGTH; ++i) {
        cars.pushback(Car());
    }

    cout << "Initial Queue:\n";
    for (Car currentCar : cars) {
        cout << "     " << currentCar.print();
    }

    while (!cars.is_empty()) {
        time++;
        event(cars);
        cout << "Time: " << time << "Operation: ";
        random = (rand() % 100) + 1;
        if (random >= 45) {
            // car pays
            newCar = 
            cout << "Joined lane: "
        } else {
            // car joins
        }
    }
}

#include Car.h
#include <deque>
#include <iostream>
#include <iomanip>

using namespace std;

void event(deque<Car>&);

const int INITIAL_LENGTH = 2;

int main() {
    int time = 0;

    deque<Car> cars;
    for (int i = 0; i < INITIAL_LENGTH; ++i) {
        cars.push_back(Car());
    }

    cout << "Initial Queue:\n";
    for (currentCar : cars) {
        cout << "     ";
        currentCar.print()
        cout << endl;
    }
    cout << endl;

    while (!cars.is_empty()) {
        time++;
        event(cars);
        cout << "Time: " << time << "Operation: ";
        random = (rand() % 100) + 1;
        if (random >= 45) {
            // car pays
            cout << "Car paid: ";
            cars.front().print();
            cout << endl;
            cars.pop_front();
        } else {
            // car joins
            newCar = Car();
            cout << "Joined lane: ";
            newCar.print(); 
            cout << endl;
            cars.push_back(newCar);
        }
        cout << "Queue:\n";
        if (cars.is_empty()) {
            cout << "     Empty"; 
        } else {
            for (currentCar : cars) {
                cout << "     ";
                currentCar.print();
                cout << endl;
        }
    }
    cout << endl;
    }
}

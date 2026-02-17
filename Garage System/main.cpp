#include <iostream>
#include <string>
using namespace std;

const int maxSize = 10;

class Vehicle {
    string name;
    int pass;
    int fuelCap;
    int mpg;

public:
    Vehicle(string vehicleName, int passengers, int fuelCapacity, int mpgallon) {
        name = vehicleName;
        pass = passengers;
        fuelCap = fuelCapacity;
        mpg = mpgallon;
    }
    int range() const{
        return fuelCap * mpg;
    }
    void printVehicle() const {
        cout<<"Name: "<<name<<endl;
        cout<<"Passengers: "<<pass<<endl;
        cout<<"Fuel Capacity: "<<fuelCap<<endl;
        cout<<"Miles per Gallon: "<<mpg<<endl;
    }
    string getName() const {
        return name;
    }
};

class Garage {
    Vehicle *vehicle[maxSize];
    int count = 0;
public:
    //constructor
    Garage() {
        //sets all the objects to nullptr
        for (int i = 0; i < maxSize; ++i) {
            vehicle[i] = nullptr;
        }
    }
    //destructor
    ~Garage() {
        //removes the vehicle[i] from memory
        for (int i = 0; i < maxSize; ++i) {
            delete vehicle[i];
        }
    }
    bool addVehicle(Vehicle *v) {
        if (count >= maxSize) {
            cout << "Garage is full!" << endl;
            return false;
        }
        vehicle[count] = v;
        count++;
        return true;
    }
    void listAllVehicles() {
        for (int i = 0; i < count; ++i) {
            cout << vehicle[i]->getName() << endl;
        }
    }
    Vehicle *bestRange() const {
        if (count == 0) {
            cout << "Garage is empty!" << endl;
            return nullptr;
        }
        Vehicle *best = vehicle[0];
        for (int i = 1; i < count; ++i) {
            if (vehicle[i]->range() > best->range()) {
                best = vehicle[i];
            }
        }
        return best;
    }
    bool removeVehicleByName(string vehicleName) {
        for (int i = 0; i < count; ++i) {
            //check whether there is a value + names match
            if (vehicle[i] && vehicle[i]->getName() == vehicleName) {
                //free memory
                delete vehicle[i];
                //shift left
                for (int j = i; j < maxSize - 1; ++j) {
                    vehicle[j] = vehicle[j + 1];
                }
                //set the last index as a nullptr and decrement the count
                vehicle[count - 1] = nullptr;
                count--;

                return true;
            }
        }
        return false;
    }
};

void printConsole();

int main() {

    Garage garage;
    int input;

    do {
        printConsole();
        cin >> input;
        switch (input) {
            case 1: {
                string name;
                int passengers, fuelCapacity, mpg;

                cout << "Enter name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter passengers: ";
                cin >> passengers;
                cout << "Enter fuel capacity: ";
                cin >> fuelCapacity;
                cout << "Enter miles per gallon: ";
                cin >> mpg;

                garage.addVehicle(new Vehicle(name, passengers, fuelCapacity, mpg));
                break;
            }
            case 2: {
                string name;
                cout << "Enter name: ";
                cin.ignore();
                getline(cin, name);
                garage.removeVehicleByName(name);
                break;
            }
            case 3:
                garage.listAllVehicles();
                break;
            case 4: {
                Vehicle *best = garage.bestRange();
                if (!best) {
                    cout << "Garage is empty!" << endl;
                }
                else {
                    best->printVehicle();
                }
                break;
            }
            default: cout << "Invalid input!" << endl;
        }

    }while (input != 0);


    return 0;
}
void printConsole() {
    cout << "1. Add vehicle: " << endl;
    cout << "2. Remove vehicle: " << endl;
    cout << "3. List all vehicles: " << endl;
    cout << "4. Best Range: " << endl;
}

#include <iostream>
using namespace std;

// Base class (Parent)
class Animal {
public:
    string name;

    void eat() {
        cout << name << " is eating." << endl;
    }

    void sleep() {
        cout << name << " is sleeping." << endl;
    }
};

// Derived class (Child) inheriting from Animal
class Dog : public Animal {
public:
    string breed;

    void bark() {
        cout << name << " is barking." << endl;
    }
};

int main() {
    // Create an object of the derived class
    Dog myDog;

    // Accessing members of the base class
    myDog.name = "Buddy";
    myDog.breed = "Golden Retriever";

    // Calling base class methods
    myDog.eat();
    myDog.sleep();

    // Calling derived class method
    myDog.bark();

    return 0;
}


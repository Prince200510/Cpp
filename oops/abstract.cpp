#include<bits/stdc++.h>
using namespace std;

// class containing at least one pure virtual function is called an abstract class. It cannot create objects of an abstract class, but it can be used as a base class for other classes that provide implementations for the pure virtual functions.
class Animal {
    public:
    virtual void sound() = 0; // Pure virtual function makes this class abstract
};
// Means: No implmentation
// cannot create objects of an abstract class, but it can be used as a base class for other classes that provide implementations for the pure virtual functions.
// Animal a; error
// Must be implemented in derived class

class Dog : public Animal {
    public:
    void sound() {
        cout << "Bark" << endl;
    }
};

// Interface: c++ doesn't have a special keyword like java.
// we simulate it.
class Shape {
    public:
    virtual void draw() = 0; // Pure virtual function makes this class abstract
};
// All functions pure virtual. Acts as interface.

int main() {
    Dog d;
    d.sound();
    return 0;
}
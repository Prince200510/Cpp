#include<bits/stdc++.h>
using namespace std;

// Polymorphism is a fundamental concept in object-oriented programming (OOP) that allows objects of different classes to be treated as objects of a common base class. It enables a single interface to represent different underlying forms (data types). Polymorphism is typically achieved through function overloading, operator overloading, and inheritance with virtual functions.
// Types of Polymorphism:
// 1. Compile-time Polymorphism (Static Polymorphism):
//    - Function Overloading: Multiple functions with the same name but different parameters.
//    - Operator Overloading: Defining custom behavior for operators when applied to user-defined types
// 2. Runtime Polymorphism (Dynamic Polymorphism):
//    - Achieved through inheritance and virtual functions. It allows a derived class to override a
//      base class function, and the appropriate function is called based on the type of the object at runtime.
// Example of Compile-time Polymorphism (Function Overloading)
class Calculator {
    public:
    int add(int a, int b) {
        return a + b;
    }

    double add(double a, double b) {
        return a + b;
    }
};

// Example of Runtime Polymorphism (Virtual Functions)
class Shape {
    public:
    virtual void draw() {
        cout << "Drawing a shape" << endl;
    }
};

class Circle : public Shape {
    public:
    void draw() override {
        cout << "Drawing a circle" << endl;
    }
};

// What happens Internally?
// complier creates: vtable virtual table
// vtable is a table of function pointers created by the compiler for classes that have virtual functions
// and each object gets: vptr virtual pointer which points to the vtable of the class it belongs to.
// Dog Object
// 
// +------+
// | vptr |
// +------+
// | data |
// +------+
// pure virtaul function 
class Animal {
    public:
    virtual void sound() = 0; // Pure virtual function makes this class abstract
};
// Means: No implmentation
// Abstract class containing at least one pure virtual function.
// It cannot create objects of an abstract class, but it can be used as a base class for other classes that provide implementations for the pure virtual functions.
// Animal a
// error
// why virtual?
// without virtual: complier decides
// with virtual: runtime decides
int main() {
    Calculator calc;
    cout << calc.add(5, 10) << endl;
    cout << calc.add(5.5, 10.5) << endl;

    Shape* shapePtr;
    Circle circle;
    Shape* ptr = new Circle(); // Base class pointer pointing to derived class object
    // ptr = &circle;
    ptr->draw(); // Calls Circle's draw() due to runtime polymorphism

    return 0;
}
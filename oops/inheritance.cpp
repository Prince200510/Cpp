#include<bits/stdc++.h>
using namespace std;

// Inheritance is a fundamental concept in object-oriented programming (OOP) that allows a class (called the derived or child class) to inherit
// child gets properties of parent class
// It promotes code reusability and establishes a hierarchical relationship between classes.
// Base class (Parent class)
// Types of inheritance:
// 1. Single Inheritance: A derived class inherits from a single base class.
// 2. Multiple Inheritance: A derived class inherits from more than one base class.
// 3. Multilevel Inheritance: A derived class inherits from a base class, and
// that base class is also derived from another base class.
// 4. Hierarchical Inheritance: Multiple derived classes inherit from a single base class.
// 5. Hybrid Inheritance: A combination of two or more types of inheritance.
// Example of Single Inheritance
class A {
    public:
    void displayA() {
        cout << "This is class A" << endl;
    }
};

class B : public A {
    public:
    void displayB() {
        cout << "This is class B" << endl;
    }
};

// Example of Multiple Inheritance
class C {
    public:
    void displayC() {
        cout << "This is class C" << endl;
    }
};

// Example of Multiple Inheritance
class D : public B, public C {
    public:
    void displayD() {
        cout << "This is class D" << endl;
    }
};

// Example of Multilevel Inheritance
class A1  {
    public:
    void displayA1() {
        cout << "This is class A1" << endl;
    }
};

class B1 : public A1 {
    public:
    void displayB1() {
        cout << "This is class B1" << endl;
    }
};

class C1 : public B1 {
    public:
    void displayC1() {
        cout << "This is class C1" << endl;
    }
};

// Example of Hierarchical Inheritance
class A2 {
    public:
    void displayA2() {
        cout << "This is class A2" << endl;
    }
};

class B2 : public A2 {
    public:
    void displayB2() {
        cout << "This is class B2" << endl;
    }
};

class C2 : public A2 {
    public:
    void displayC2() {
        cout << "This is class C2" << endl;
    }
};

int main() {
    B obj;
    obj.displayA();
    obj.displayB();

    D obj2;
    obj2.displayA();
    obj2.displayB();
    obj2.displayC();
    obj2.displayD();

    C1 obj3;
    obj3.displayA1();
    obj3.displayB1();
    obj3.displayC1();

    B2 obj4;
    obj4.displayA2();
    obj4.displayB2();
    obj4.displayC2();
    return 0;
}
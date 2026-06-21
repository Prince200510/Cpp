#include<bits/stdc++.h>
using namespace std;

// Constructor: A constructor is a special member function of a class that is automatically called when an object of that class is created. It is used to initialize the object's data members and allocate resources if needed. Constructors have the same name as the class and do not have a return type, not even void.
// Normal function:
class Student {
    public:
    void show() {
        cout << "Hello from show function" << endl;
    }
};

// Constructor function:
class Student2 {
    public:
    Student2() {
        cout << "Hello from constructor" << endl;
    }
};

// Parameterized constructor: A parameterized constructor is a constructor that takes parameters to initialize the object's data members with specific values. It allows for more flexibility in object creation, as you can provide different values for each object.
// Pass values while creating an object of the class. The constructor will use these values to initialize the object's data members accordingly.
class Student3 {
    public:
    int roll;
    string name;
    double cpga;

    // Parameterized constructor
    Student3(int r, string n, double c) {
        roll = r;
        name = n;
        cpga = c;
    }

    void show() {
        cout << "Roll: " << roll << ", Name: " << name << ", CPGA: " << cpga << endl;
    }
};

// Problem: Variable shadowing occurs when a local variable in a method or constructor has the same name as a class member variable. In such cases, the local variable takes precedence over the class member variable, leading to confusion and potential bugs. To resolve this issue, we can use the "this" pointer, which refers to the current object instance and allows us to differentiate between the local variable and the class member variable.
class Student4{
    public:
    string name;
    Student4(string name) {
        name = name;
    }
};
// Memory:
// object name member - name
// constructor parameter - name
// complier see: name = name;
// as parameter = parameter;
// Solution this pointer:
// means current object address
class Student5{
    public:
    string name;
    Student5(string name) {
        this->name = name;
    }
};

// Constructor overloading: Constructor overloading is a feature in object-oriented programming that allows a class to have multiple constructors with different parameter lists. This enables the creation of objects with different initializations based on the provided arguments. The appropriate constructor is selected based on the number and types of arguments passed during object creation.
// Multiple constructors with different parameter lists
class Student6 {
    public:
    Student6() {
        cout << "Default constructor called" << endl;
    }
    Student6(int roll) {
        cout << "Parameterized constructor with roll: " << roll << endl;
    }
};

// Destructor: A destructor is a special member function of a class that is automatically called when an object of that class goes out of scope or is explicitly deleted. It is used to release resources, perform cleanup tasks, and free memory allocated for the object. Destructors have the same name as the class, preceded by a tilde (~), and do not have a return type or parameters.
// Opposite of constructor, called automatically when object goes out of scope or deleted. It is used to free memory allocated for the object and perform cleanup tasks. Destructor has same name as class preceded by a tilde (~) and does not have return type or parameters.
// Syntax: 
// ~ClassName()
class Student7 {
    public:
    ~Student7() {
        cout << "Destructor called" << endl;
    }
};

// Professional constructor style
// Instead of:
// Student(string n,int a) {
//     name = n;
//     age = a;
// }
// Use:
// Student(string n,int a) : name(n), age(a) {

// }
int main() {
    // Create an object of the Student class
    Student s;
    // Need to call manually:
    s.show();
    // Create an object of the Student2 class
    // Output: Hello from constructor
    // No return type, not even void & called automatically
    Student2 s2;

    // Create an object of the Student3 class
    // Output: Roll: 66, Name: Prince Maurya, CPGA: 9.65
    Student3 s3(66, "Prince Maurya", 9.65);
    s3.show();

    Student5 s5("Prince Maurya");
    // Equivalent to: s5.name = "Prince Maurya";
    cout << "Student name: " << s5.name << endl;

    // Create an object of the Student6 class
    Student6 s6;
    Student6 s7(101);

    // Create an object of the Student7 class
    // Called automatically when object goes out of scope or deleted
    Student7 s8;

    // Dynamic Objects
    Student3* s33 = new Student3(66, "Prince Maurya", 9.65);
    // Constructor runs.
    // Will destructor run? No, because object is created dynamically. So, we need to delete it manually.
    // Not unitl:
    delete s33;
    // Why destructor need because of te memory leak. If we don't delete the object, it will remain in memory until the program ends, leading to memory wastage and potential performance issues.
    
    // copy constructor: A copy constructor is a special constructor in C++ that initializes a new object as a copy of an existing object. It is automatically called when an object is passed by value, returned from a function, or explicitly copied. The copy constructor takes a reference to the existing object as its parameter and creates a new object with the same values for its data members. If not defined by the programmer, the compiler provides a default copy constructor that performs a shallow copy of the object's data members.
    Student3 s9(66, "Prince Maurya", 9.65);
    // Copy constructor is called when we create a new object and initialize it with an existing object
    Student3 s10 = s9; // Copy constructor is called here
    s10.show();
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

// Friend function is a function that is not a member of a class but has access to its private and protected members. It is declared using the friend keyword inside the class definition. Friend functions can be useful when you want to allow a non-member function to access the private data of a class without making it a member of that class.
class Test {
    private:
    int x = 10;
    friend void show(Test);
};

void show(Test t) {
    cout << "Value of x: " << t.x << endl; // Accessing private member x
}
// Normally impossible. But friend bypasses access restrictions.

// Static Member: Shared by all objects of the class.
class Student {
    public:
    static int count;
};

int Student::count = 0; // Definition of static member outside the class
// Usage
// Student::count++; // Incrementing the static member count

int main() {
    // No object needed to access static members
    Student::count++; // Incrementing the static member count
    cout << "Total students: " << Student::count << endl;
    return 0;
}

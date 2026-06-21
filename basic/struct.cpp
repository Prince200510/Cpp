#include<bits/stdc++.h>
using namespace std;

// struct -> public by default
// class -> private by default

// why we need struct/class?
// 1. To group related data together
// 2. To create user-defined data types
// without struct
// int roll = 66;
// string name = "Prince Maurya";
// double cpga = 9.65;
// Now image 100 students
// You'd need:
// int roll1, roll2, roll3, ..., roll100;
// string name1, name2, name3, ..., name100;
// double cpga1, cpga2, cpga3, ..., cpga100;
// So we group realetd data together using struct/class

struct Student {
    int roll;
    string name;
    double cpga;
};

int main() {
    // Now create a student;
    Student s1;
    s1.roll = 66;
    s1.name = "Prince Maurya";
    s1.cpga = 9.65;
    // Memory layout of s1:
    // s1
    // +----------------+
    // | Prince Maurya  |
    // +----------------+
    // | 66             |
    // +----------------+
    // | 9.65           |
    // +----------------+

    // Accessing members
    // using dot operator
    cout << s1.name << " has roll number " << s1.roll << " and cpga " << s1.cpga << endl;

    // Array of struct
    Student students[3];
    for(int i = 0; i < 3; i++) {
        cin >> students[i].roll >> students[i].name >> students[i].cpga;
    }

    // structure constructor
    struct Student2 {
        int roll;
        string name;
        double cpga;

        // constructor
        Student2(int r, string n, double c) {
            roll = r;
            name = n;
            cpga = c;
        }
    };

    // usage of constructor
    Student2 s2(67, "John Doe", 8.75);
    
    // struct can have functions
    struct Student3 {
        int roll;
        string name;
        double cpga;

        // constructor
        Student3(int r, string n, double c) {
            roll = r;
            name = n;
            cpga = c;
        }

        void display() {
            cout << name << " has roll number " << roll << " and cpga " << cpga << endl;
        }
    };

    // usage of struct with function
    Student3 s3(66, "Prince Maurya", 9.65);
    s3.display();
    // Output
    // Prince Maurya has roll number 66 and cpga 9.65

    // Pointer to struct
    struct Node {
        int data;
    };

    // create dynamically
    Node* ptr = new Node();
    // Access
    ptr->data = 10;
    // Equivalent to (*ptr).data = 10;
    // The -> operator is heavily used in linked lists and trees.

    // Interview Question:
    struct test {
        int a;
        char b;
    }

    // what is a size? 
    // 8 as a = 4 bytes, b = 1 byte & padding = 3 bytes but due to padding it becomes 8 bytes
    cout << sizeof(test) << endl; // Output: 8
    return 0;
}
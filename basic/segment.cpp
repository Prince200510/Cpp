#include<bits/stdc++.h>
using namespace std;

int main() {
    // When a C++ program runs, the OS divides memory into several regions:
    // +------------------+
    // |   Code Segment   |
    // +------------------+
    // | Data Segment     |
    // | (Global/Static)  |
    // +------------------+
    // |      Heap        |
    // |      ↑ grows     |
    // +------------------+
    // |      Stack       |
    // |      ↓ grows     |
    // +------------------+

    // code segment (Text segment) - contains the compiled program code (machine code). It is usually read-only to prevent accidental modification of instructions.
    // machine code for main() and greet() functions are stored in the code segment.
    void greet() {
        cout << "Hello, World!" << endl;
    }

    // data segment - contains global and static variables. It is divided into two parts: initialized data segment and uninitialized data segment (BSS).
    int global_var = 10; // initialized data segment
    static int static_var = 20; // initialized data segment

    void fun() {
        int local_var = 30; // local variable stored in stack segment
    }

    // stack memory - stores local variables, function parameters, and return addresses. It grows downwards (towards lower memory addresses) as functions are called and shrinks upwards as functions return.
    void fun1() {
        int x = 10; // x is stored in stack segment
    }

    int b = 20;
    // before stack
    // Stack 
    // +------+
    // | a=10 |
    // +------+

    // During fun1()
    // Stack 
    // +------+
    // | b=20 |
    // +------+
    // | a=10 |
    // +------+

    // after fun1() returns
    // Stack 
    // +------+
    // | a=10 |
    // +------+
    // b is automaically destroyed when fun1() returns, and the stack pointer is adjusted accordingly.

    // stack overflow
    void recursive_function() {
        recursive_function(); // This will cause a stack overflow due to infinite recursion
    }

    // Heap Memory - used for dynamic memory allocation. Memory is allocated and deallocated manually using new and delete operators. It grows upwards (towards higher memory addresses) as more memory is allocated.
    int* ptr = new int(100); // dynamically allocated memory on the heap
    // stack   heap
    // ptr     100

    int* arr = new int[5]; // dynamically allocated array on the heap
    // memory Heap
    // +----+
    // |    |
    // +----+
    // |    |
    // +----+
    // |    |
    // +----+
    // |    |
    // +----+
    // |    |
    // +----+
    
    // Heap Memory must be freed
    delete ptr; // free the dynamically allocated memory
    // otherwise it will lead to memory leak, which can cause the program to run out of memory over time.

    // What happens here?
    int* fun() {
        int x = 10;
        return &x;
    }

    // worng x is on the stack
    // x destroyed returned address becomes invalid, dereferencing it will lead to undefined behavior.
    // called: dangling pointer, which is a pointer that points to a memory location that has been deallocated or is no longer valid.
    return 0;
}
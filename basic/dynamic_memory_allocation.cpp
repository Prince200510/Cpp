#include<bits/stdc++.h>
using namesapce std;

int main() {
    // Why Dynamic Memory Allocation?
    // Normal Variables are created on the stack.
    int x = 10; // created on stack
    // Memory
    // stack x = 10
    // size must often be known beforehand
    // Variables is destroyed when the function ends

    void func() {
        int y = 20; // created on stack
        // Memory
        // stack y = 20
        // size must often be known beforehand
        // Variables is destroyed when the function ends
    }
    // Dynamic Memory Allocation allows us to allocate memory on the heap at runtime. It is useful when we don't know the size of the data beforehand or when we want to create data that should persist beyond the scope of a function.
    int* ptr = new int; // allocate memory for an integer on the heap
    // Memory
    // stack ptr -------> heap (uninitialized)
    // The heap memory remains until you delete it.
    // Allocate a sinle interger 
    *ptr = 10; // assign value to the allocated memory
    cout << *ptr; // Output: 10

    // Shortcut
    int* ptr2 = new int(20); // allocate memory for an integer and initialize it to 20
    cout << *ptr2; // Output: 20

    // Free the allocated memory
    delete ptr; // free the memory allocated for ptr

    // Dynamic Memory Allocation for Arrays
    int n;
    cin >> n; // size of the array
    // int arr[n]; cannot do tis safely in standard modern c++
    int* arr = new int[n]; // allocate memory for an array of n integers
    // input values into the array
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    // Free the allocated memory for the array
    delete[] arr; // free the memory allocated for arr
    
    // Memory Leak: If we forget to free the allocated memory, it will lead to a memory leak. A memory leak occurs when a program allocates memory but fails to deallocate it, leading to a gradual increase in memory usage over time, which can eventually cause the program to crash or slow down.
    int* leak = new int(10); // memory allocated but not freed
    // No delete
    // programs end: heap memory never freed, memory leak occurs
    // called: leaking memory

    // Dangling Pointer: A dangling pointer is a pointer that points to a memory location that has been deallocated. Accessing a dangling pointer can lead to undefined behavior, as the memory it points to may have been reallocated for other purposes or may be inaccessible.
    int* arr2 = new int[1000000]; 
    delete[] arr2; // memory deallocated
    // arr2 is now a dangling pointer
    cout << arr2[0]; // Accessing arr2 leads to undefined behavior, as it points to deallocated memory
    // pointer still contains old address

    // dynamic memory allocation for 2D arrays
    // 3 rows and 4 columns
    int row = 3;
    int col = 4;
    int** matrix = new int*[row]; // allocate memory for an array of pointers (rows)

    for (int i = 0; i < row; i++) {
        matrix[i] = new int[col]; // allocate memory for each row (columns)
    }

    // free the allocated memory for the 2D array
    for (int i = 0; i < row; i++) {
        delete[] matrix[i]; // free memory for each row
    }
    delete[] matrix; // free memory for the array of pointers

    // whats happens here?
    int* ptr = new int(10); // allocate memory for an integer and initialize it to 10
    ptr = new int(20);
    // Memory leaking

    // modern c++
    // instead of
    int* ptr = new int(10);
    // prefer
    auto ptr = make_unique<int>(10); // unique pointer, automatically deallocated when it goes out of scope
    // or
    auto ptr2 = make_shared<int>(10); // shared pointer, reference counted, automatically deallocated when no longer used
}
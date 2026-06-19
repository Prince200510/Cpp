#include<bits/stdc++.h>
using namespace std;

int main() {
    // A pointer store the address of another variable. It is a variable that holds the memory address of another variable as its value. Pointers are used for dynamic memory allocation, arrays, and function arguments.
    int x = 10;
    // Memory
    // address value
    // 0x1234 10
    int* ptr = &x; // & is the address of operator
    // Address value
    // 0x1234 10
    // 0x5678 0x1234
    // ptr stores the address of x
    cout << &x;
    // Output: 0x1234 Address where x is stored
    // * Operator (Dereference operator) is used to access the value stored at the address pointed by the pointer.
    cout << *ptr; // Output: 10 Value stored at the address pointed by ptr
    // We can also change the value of x using the pointer
    // & Reference is an alias 
    int b = 10;
    int& ref = b; // ref is a reference to b
    cout << ref; // Output: 10
    // pointer vs reference 
    // pointer can change target
    // reference cannot change target
    // reference allows copies 
    // Bad
    void print(vector<int> v)
    // Good
    void print(const vector<int>& v) // no copy & fast
    // pointer aritmetic
    int arr[5] = {1, 2, 3, 4, 5};
    int* p = arr; // p points to the first element of arr
    p++; // p now points to the second element of arr
    cout << *p; // Output: 2
    // double pointer
    int c = 10;
    int* ptr1 = &c; // ptr1 points to c
    int** ptr2 = &ptr1; // ptr2 points to ptr1
    // memory
    // c = 10
    // ptr1 = c
    // ptr2 = ptr1

}
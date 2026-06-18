#include<stdc++.h>
using namespace std;

int main() {
    // Naming rules
    int age;
    int studentAge;
    int _count;
    int marks2026;

    // Invalid variable names
    // int 1age;
    // int student-age;
    // int @count;
    // int marks 2026;

    // short = 2 bytes
    // int = 4 bytes
    // long = 4 or 8 bytes
    // long long = 8 bytes

    // character
    char grade = 'A';
    // Memory A = ASCII 65
    cout << (int)'A' << endl;
    // output 65

    // float = 4 bytes 7 digits after decimal point
    // double = 8 bytes 15 digits after decimal point
    float pi = 3.14f;
    double pi2 = 3.1415926535897932384626433832795;

    // boolean
    bool isplace = true;
    cout << isplace << endl; // output 1
    
    cout << INT_MAX << endl; // output 2147483647
    cout << INT_MIN << endl; // output -2147483648

    // int range: -2^31 to 2^31 - 1
    // unsigned int range: 0 to 2^32 - 1
    // long long range: -2^63 to 2^63 - 1

    // overflow
    int x = INT_MAX;
    cout << x + 1 << endl; // output -2147483648 (overflow)

    // static variable: created once, stored in data segment, retains value between function calls & exist till program ends
    static int count = 0; // Only once initialized
    count++;
    cout << count << endl; // output 1

    // stack -> Normal Variables
    // heap -> Dynamic Variables
    // data segment -> static variables

    // Makes variables read only
    const int y = 10;
    // y = 20; // error: assignment of read-only variable 'y'

    // const pointer: pointer itself is constant, cannot point to another address but value at that address can be changed
    int a = 5;
    const int *ptr = &a; // pointer to constant integer
    ptr = &a; // allowed, pointer can point to another address
    // *ptr = 10; // error: assignment of read-only location '*ptr'

    // Neither can move nor modify
    const int *const ptr2 = &a; // constant pointer to constant integer

    // Auto keyword
    // without auto
    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int>::iterator it1 = v1.begin();
    // with auto
    auto it1 = v1.begin(); // compiler deduces the type of it1 as vector<int>::iterator
}
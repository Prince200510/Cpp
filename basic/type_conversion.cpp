#include<stdc++.h>
using namespace std;

int main() {
    // Implicit type conversion
    int x = 10;
    double y = x; // int to double (widening conversion) // safe
    cout << y << endl; // output 10.0

    // Narrowing conversion (explicit type conversion)
    double a = 3.14;
    int b = a; // double to int (narrowing conversion) // dangerous
    cout << b << endl; // output 3 (fractional part truncated) 

    // c style
    double c = 3.14;
    int d = (int)c; // double to int (narrowing conversion) //

    // c++ style
    double e = 3.14;
    int f = static_cast<int>(e); // double to int (narrowing conversion) //

    int a = 5;
    double b = 2;
    cout << a / b << endl; // output 2.5 (a promoted to double before division) int + double = double automatic type promotion

    return 0;
}
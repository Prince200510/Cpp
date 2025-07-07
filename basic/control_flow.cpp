#include<iostream>
using namespace std;

int main() {
    int num;

    cout << "Enter a number :";
    cin >> num;

    if(num > 0){
        cout << "Postive";
    } else if(num < 0){
        cout << "Negative";
    } else {
        cout << "Zero";
    }

    int day = 2;

    switch(day){
        case 1:
            cout << "Monday";
            break;
        case 2:
            cout << "Tuesday";
            break;
        case 3:
            cout << "Wednesday";
            break;
        default:
            cout << "Invalid day";
    }
    return 0;
}
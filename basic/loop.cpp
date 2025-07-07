#include<iostream>
using namespace std;

int main() {
    for(int i = 0; i <= 5; i++){
        cout<< "For loop :" << i << endl;
    }

    int j = 1;

    while(j <= 5){
        cout<< "While loop :" << j << endl;
        j++;
    }

    int k = 1;
    do{
        cout<< "Do While loop :" << k << endl;
        k++;
    } while(k <= 5);

    return 0;
}
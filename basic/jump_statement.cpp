#include<iostream>
using namespace std;

int main(){
    for(int i = 0; i <= 5; i++){
        if(i == 2){
            break;
        }
        cout << "For loop: " << i << endl;
    }

    for(int i = 0; i <= 5; i++){
        if(i == 2){
            continue;
        }
        cout << "For loop with continue: " << i << endl;
    }

    int x = 1;
    if(x == 1){
        goto skip;
    }
    cout<<"This will not be printed" << endl;
    skip:
    cout<<"Skipped to this line" << endl;
    
    return 0;
}
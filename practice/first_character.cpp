#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    vector<int> freq(256, 0);
    for(char c : s) {
        freq[c]++;
    }

    for(char c : s) {
        if(freq[c] == 1) {
            cout << c << endl;
            return 0;
        }
    }
}
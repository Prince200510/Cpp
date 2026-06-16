#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    for(char &c : s) {
        if(c == ' ') {
            cout << "Error" << endl;
        }
    }

    for(int i = 0; i < s.length(); i++) {
        char c = s[i];
        int shift;

        if(i % 2 == 0) {
            shift = 2;
        } else {
            shift = -1;
        }

        if(c >= 'A' && c <= 'Z') {
            c = ((c - 'A' + shift + 26) % 26) + 'A';
        }

        if(c >= 'a' && c <= 'z') {
            c = ((c - 'a' + shift + 26) % 26) + 'a';
        }

        if(c >= '0' && c <= '9') {
            c = ((c - '0' + shift + 10) % 10) + '0';
        }

        s[i] = c;

    }
    cout << s << endl;
}
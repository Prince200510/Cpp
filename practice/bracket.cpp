#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    stack<char> st;
    bool balanced = true;

    for(char c : s) {
        if(c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else {
            if(st.empty()) {
                balanced = false;
                break;
            } else {
                char top = st.top();
                st.pop();

                if((top == '(' && c == ')') || (top == '[' && c == ']') || (top == '{' && c == '}')) {
                } else {
                    balanced = false;
                    break;
                }
            }
        }
    }

    if(balanced && st.empty()) {
        cout << "Balanced" << endl;
    } else {
        cout << "Not Balanced" << endl;
    }
}
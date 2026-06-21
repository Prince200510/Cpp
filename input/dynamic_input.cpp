#include<bits/stdc++.h>
using namespace std;

int main() {
    // Dynamic Array (Unknown size)
    string line;
    getline(cin, line); // Input: 1 2 3 4 5
    
    stringstream ss(line); // create a stringstream object to parse the line
    vector<int> arr; // declare a vector to store the integers
    int x;

    while(ss >> x) {
        arr.push_back(x); // add the integer to the vector
    }

    // pair input
    pair<int, int> p;
    cin >> p.first >> p.second; // Input: 10 20

    // vector of pairs input
    int n;
    cin >> n;
    vector<pair<int, int>> vp(n); // declare a vector of pairs of size n

    for(int i = 0; i < n; i++) {
        cin >> vp[i].first >> vp[i].second; // Input: 1 2
                                            //        3 4
                                            //        5 6
    }

    // set input
    int p;
    cin >> p;

    set<int> s; // declare a set to store the integers
    for(int i = 0; i < p; i++) {
        int x;
        cin >> x; // Input: 1 2 3 4 5
        s.insert(x); // add the integer to the set
    }

    // freq input
    map<int, int> freq;
    for(int i = 0; i < 5; i++) {
        int x;
        cin >> x;
        freq[x]++;
    }

    // EOF input
    // 10
    // 20
    // 30
    // 40
    int x;
    while(cin >> x) {
        cout << x << " "; // Input: 1 2 3 4 5 (Ctrl+D to end input)
    }

    // Entire file input
    // HEllo
    // World
    string line;

    whil(getline(cin, line)) {
        cout << line << endl; // Input: Hello World (Ctrl+D to end input)
    }

    // fast input 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
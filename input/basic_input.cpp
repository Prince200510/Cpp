#include<bits/stdc++.h>
using namespace std;

int main() {
    // Single Input
    int x;
    cin >> x; // Input: 10

    // Multiple Inputs
    int a, b;   
    cin >> a >> b; // Input: 10 20

    // String (No spaces)
    string s;
    cin >> s; // Input: Hello

    // String (With spaces)
    strin str;
    getline(cin, str); // Input: Hello World

    // Array Input
    // 5
    // 1 2 3 4 5
    int n;
    cin >> n; // size of the array
    int arr[n]; // declare an array of size n
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; // Input: 1 2 3 4 5
    }

    // character Input
    char ch;
    cin >> ch; // Input: A

    // Matrix Input
    // 3 3
    // 1 2 3
    // 4 5 6
    // 7 8 9
    int n, m;
    cin >> n >> m; // size of the matrix
    vector<vector<int>> matrix(n, vector<int>(m)); // declare a matrix of size n x m
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j]; // Input: 1 2 3
                                 //       4 5 6
                                 //       7 8 9
        }
    }
    
}
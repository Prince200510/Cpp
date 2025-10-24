#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n = 5;
    vector<vector<int>> graph(n);

    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[1].push_back(3);
    graph[2].push_back(4);

    for(int i = 0; i < n; i++){
        for(int nb : graph[i]){
            cout << i << "->" << nb << endl;
        }
    }
    return 0;
}

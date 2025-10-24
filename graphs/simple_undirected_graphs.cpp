#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n = 5;
    vector<vector<int>> graph(n);
    vector<vector<int>> edges = {{0,1}, {0,2}, {1,3}, {1,4}, {2, 4}};

    for(auto edge : edges){
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }

    for(int i = 0; i < n; i++){
        for(int nb : graph[i]){
            if(i < nb) cout << i << "->" << nb << endl;
        }
    }
    return 0;
}
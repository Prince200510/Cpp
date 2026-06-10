#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void dfs(int start, vector<vector<int>>& graph, vector<bool>& visited){
    visited[start] = true;
    cout<< start;

    for(int nb : graph[start]){
        if(!visited[nb]){
            dfs(nb, graph, visited);
        }
    }
}

int main(){
    int n = 5;
    vector<vector<int>> graph(n);
    vector<vector<int>> edges = {
        {0, 1},
        {0, 2},
        {1, 3},
        {2, 4}
    };
    for(auto edge : edges){
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    vector<bool> visited(n, false);
    dfs(0, graph, visited);
    return 0;
}
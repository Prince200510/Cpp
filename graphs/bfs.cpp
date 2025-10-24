#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void bfs(int start, vector<vector<int>>& graph){
    int n = graph.size();
    vector<bool> visited(n, false);
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout << node;

        for(int nb : graph[node]){
            if(!visited[nb]){
                visited[nb] = true;
                q.push(nb);
            }
        }
    }
}

int main(){
    int n = 5;
    vector<vector<int>> graph(n);

    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[1].push_back(3);
    graph[2].push_back(4);

    bfs(0, graph);
    return 0;
}
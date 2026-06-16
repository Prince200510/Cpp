#include<bits/stdc++.h>
using namespace std;

void bfs(int start, vector<vector<int>>& adj, vector<int>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = 1;

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for(int nb : adj[node]) {
            if(!visited[nb]) {
                visited[nb] = 1;
                q.push(nb);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    for(int i = 0; i < m ; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int components = 0;
    vector<int> visited(n, 0);

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            components++;
            bfs(i, adj, visited);
        }
    }
    cout << components << endl;
}
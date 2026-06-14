#include<bits/stdc++.h>
using namespace std;

bool bfs(int start, vector<vector<int>>& adj, vector<int>& visited) {
    queue<pair<int, int>> q;
    q.push({start, -1});
    visited[start] = 1;

    while(!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto nb : adj[node]) {
            if(!visited[nb]) {
                visited[nb] = 1;
                q.push({nb, node});
            } else if(nb != parent) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);

    for(int i = 0; i < m ; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> visited(n + 1, 0);

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            if(bfs(i, adj, visited)) {
                cout << "Cycle detected" << endl;
                return 0;
            }
        }
    }
    cout << "No cycle detected" << endl;
    return 0;
}
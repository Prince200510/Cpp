#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> adj[n + 1];

    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<bool> visited(n + 1, false);
    queue<int> q;
    visited[1] = true;
    q.push(1);

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for(auto it : adj[node]) {
            int neighbor = it.first;
            int weight = it.second;

            cout << "Neighbor: " << neighbor << ", Weight: " << weight << endl;
            if(!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}
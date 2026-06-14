#include<bits/stdc++.h>
using namespace std;

int shortest(int src, int dest, vector<vector<int>>& adj, int n) {
    vector<int> dist(n, -1);
    queue<int> q;
    q.push(src);
    dist[src] = 0;

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for(auto nb : adj[node]) {
            if(dist[nb] == -1) {
                dist[nb] = dist[node] + 1;
                q.push(nb);
            }
        }
    }
    return dist[dest];
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int src, dest;
    cin >> src >> dest;

    cout << shortest(src, dest, adj, n) << endl;
}
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);

    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> dist(n + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[1] = 0;
    pq.push({0, 1});

    while(!pq.empty()) {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(d != dist[node]) {
            continue;
        }

        for(auto it : adj[node]) {
            int neighbor = it.first;
            int weight = it.second;

            if(dist[node] + weight < dist[neighbor]) {
                dist[neighbor] = dist[node] + weight;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }

    cout << "Shortest distances from node 1:" << endl;

    for(int i = 1; i <= n; i++) {
        cout << "Distance from 1 to " << i << " = ";
        if(dist[i] == INT_MAX) {
            cout << "INF";
        } else {
            cout << dist[i];
        }
        cout << endl;
    }
}
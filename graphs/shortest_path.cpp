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

    int src, dest;
    cin >> src >> dest;

    vector<int> dist(n + 1, INT_MAX);
    vector<int> parent(n + 1);

    for(int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    dist[src] = 0;
    pq.push({0, src});

    while(!pq.empty()) {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(d != dist[node]) {
            continue;
        }

        if(node == dest) break;

        for(auto it : adj[node]) {
            int neighbor = it.first;
            int weight = it.second;

            if(dist[node] + weight < dist[neighbor]) {
                dist[neighbor] = dist[node] + weight;
                parent[neighbor] = node; 
                pq.push({dist[neighbor], neighbor});
            }
        }
    }

    if(dist[dest] == INT_MAX) {
        cout << "No path exists between " << src << " and " << dest << endl;
    } else {
        vector<int> path;
        int current = dest;
        
        while(parent[current] != current) {
            path.push_back(current);
            current = parent[current];
        }
        path.push_back(src);
        reverse(path.begin(), path.end());

        cout << "Path: ";
        for(int i = 0; i < path.size(); i++) {
            cout << path[i];
            if(i < path.size() - 1) cout << " -> ";
        }
        cout << endl;
        cout << "Distance: " << dist[dest] << endl;
    }

    return 0;
}
// #include<bits/stdc++.h>
// using namespace std;

// int shortest(int src, int dest, vector<vector<int>>& adj, int n) {
//     vector<int> dist(n, -1);
//     queue<int> q;
//     q.push(src);
//     dist[src] = 0;

//     while(!q.empty()) {
//         int node = q.front();
//         q.pop();

//         for(auto nb : adj[node]) {
//             if(dist[nb] == -1) {
//                 dist[nb] = dist[node] + 1;
//                 q.push(nb);
//             }
//         }
//     }
//     return dist[dest];
// }

// int main() {
//     int n, m;
//     cin >> n >> m;

//     vector<vector<int>> adj(n);

//     for(int i = 0; i < m; i++) {
//         int u, v;
//         cin >> u >> v;

//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }

//     int src, dest;
//     cin >> src >> dest;

//     cout << shortest(src, dest, adj, n) << endl;
// }
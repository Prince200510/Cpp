#include<bits/stdc++.h>
using namespace std;

void bfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& visited) {
    int n = grid.size();
    int m = grid[0].size();

    queue<pair<int, int>> q;
    q.push({r, c});
    visited[r][c] = 1;

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while(!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dr[i];
            int ny = y + dc[i];

            if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1 && !visited[nx][ny]) {
                visited[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));

    for(int i= 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> visited(n, vector<int>(m, 0));
    int count = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 1 && !visited[i][j]) {
                bfs(i, j, grid, visited);
                count++;
            }
        }
    }
    cout << count << endl;
}
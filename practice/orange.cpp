#include<bits/stdc++.h>
using namespace std;

int orange(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    int fresh = 0, time = 0;
    queue<pair<int, int>> q;
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(matrix[i][j] == 2) {
                q.push({i, j});
            } else if(matrix[i][j] == 1) {
                fresh++;
            }
        }
    }

    while(!q.empty() && fresh > 0) {
        int size = q.size();
        time++;

        while(size--) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= 0 && nx < n && ny >= 0 && ny < m && matrix[nx][ny] == 1) {
                    matrix[nx][ny] = 2;
                    fresh--;
                    q.push({nx, ny});
                }
            }
        }
    }
    return fresh ? -1 : time;
}

int main() {
    vector<vector<int>> matrix;
    int n, m;
    cin >> n >> m;
    matrix.resize(n, vector<int>(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    cout << orange(matrix) << endl;
}
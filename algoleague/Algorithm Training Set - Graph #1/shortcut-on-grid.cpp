#include <bits/stdc++.h>
using namespace std;

int shortestPath(vector<vector<char>>& grid, pair<int, int> src, pair<int, int> dest) {
    if (src == dest) return 0; 

    queue<pair<int, pair<int, int>>> q; // (distance, (row, col))
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    dist[src.first][src.second] = 0;

    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    q.push({0, src});

    while (!q.empty()) {
        auto it = q.front();
        q.pop();
        int dis = it.first;
        int r = it.second.first;
        int c = it.second.second;

        for (auto d : directions) {
            int nr = r + d.first;
            int nc = c + d.second;

            if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] != '*' && dis + 1 < dist[nr][nc]) {
                dist[nr][nc] = dis + 1;
                if (nr == dest.first && nc == dest.second) {
                    return dis + 1;
                }
                q.push({dis + 1, {nr, nc}});
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));

    pair<int, int> src, dest;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char x; cin >> x;
            grid[i][j] = x;
            if (x == 'A') {
                src = {i, j};
            }
            if (x == 'B') {
                dest = {i, j};
            }
        }
    }
    
    int result = shortestPath(grid, src, dest);
    cout << result << '\n'; 

    return 0;
}

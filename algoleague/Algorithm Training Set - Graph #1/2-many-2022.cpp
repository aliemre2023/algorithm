#include <bits/stdc++.h>
using namespace std;

int total = 0;
void bfs(queue<pair<pair<int, int>, int>>& q, vector<vector<char>>& grid, const string& word) {
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int n = grid.size();
    int m = grid[0].size();

    while (!q.empty()) {
        auto [pos, len] = q.front();
        auto [r, c] = pos;
        q.pop();

        if (len == word.size() - 1) {
            total++;
            continue;
        }

        for (auto d : directions) {
            int ni = r + d.first;
            int nj = c + d.second;

            if (ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == word[len + 1]) {
                q.push({{ni, nj}, len + 1});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    string word = "2022";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == word[0]) {
                queue<pair<pair<int, int>, int>> q;
                q.push({{i, j}, 0});
                bfs(q, grid, word);
            }
        }
    }

    cout << total << endl;
    return 0;
}

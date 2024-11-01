#include <bits/stdc++.h>

using namespace std;
#define int long long

class Solution {
public:
    vector<vector<int>> monsterTime(vector<vector<char>>& grid, vector<pair<int, int>>& monsters) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> monster_dist(n, vector<int>(m, 1e9));
        queue<pair<int, int>> q;

        for (auto& monster : monsters) {
            q.push(monster);
            monster_dist[monster.first][monster.second] = 0;
        }

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty()) {
            auto [r, c] = q.front();
            int dis = monster_dist[r][c];
            q.pop();

            for (auto& d : directions) {
                int nr = r + d.first, nc = c + d.second;
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] != '#' && dis + 1 < monster_dist[nr][nc]) {
                    monster_dist[nr][nc] = dis + 1;
                    q.push({nr, nc});
                }
            }
        }
        return monster_dist;
    }

    bool canEscape(vector<vector<char>>& grid, pair<int, int> me, vector<vector<int>>& monster_dist) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> my_dist(n, vector<int>(m, 1e9));

        queue<pair<int, int>> q;
        q.push(me);
        my_dist[me.first][me.second] = 0;

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty()) {
            auto [r, c] = q.front();
            int dis = my_dist[r][c];
            q.pop();

            if ((r == 0 || r == n - 1 || c == 0 || c == m - 1) && dis < monster_dist[r][c]) {
                return true;
            }

            for (auto& d : directions) {
                int nr = r + d.first, nc = c + d.second;
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] != '#' && dis + 1 < my_dist[nr][nc]) {
                    if (dis + 1 < monster_dist[nr][nc]) {  
                        my_dist[nr][nc] = dis + 1;
                        q.push({nr, nc});
                    }
                }
            }
        }
        return false;
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> monsters;
    pair<int, int> me;
    vector<vector<char>> grid(n, vector<char>(m, '#'));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char x;
            cin >> x;
            grid[i][j] = x;

            if (x == 'A') {
                me = {i, j};
            } else if (x == 'M') {
                monsters.push_back({i, j});
            }
        }
    }

    Solution sol;
    vector<vector<int>> monster_dist = sol.monsterTime(grid, monsters);

    if (sol.canEscape(grid, me, monster_dist)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}

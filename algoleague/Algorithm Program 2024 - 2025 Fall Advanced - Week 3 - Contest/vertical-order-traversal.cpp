#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    void bfs(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& vis) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = 1;
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty()) {
            int ci = q.front().first;
            int cj = q.front().second;
            q.pop();
            for (auto d : directions) {
                int ni = ci + d.first;
                int nj = cj + d.second;
                if (ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == '1' && !vis[ni][nj]) {
                    q.push({ni, nj});
                    vis[ni][nj] = 1;
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), 0));
        int island = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    island++;
                    bfs(i, j, grid, vis);
                } 
            }
        }
        return island;
    }
};

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    
    int n, m; 
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m, '0'));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char x; 
            cin >> x;
            if (x == '0' || x == '1') {
                grid[i][j] = x;
            }
        }
    }

    Solution sol;
    int res = sol.numIslands(grid);
    cout << res << "\n";
    return 0;
}

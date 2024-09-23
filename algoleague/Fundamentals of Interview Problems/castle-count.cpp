#include <bits/stdc++.h>
#define int long long
using namespace std;

void dfs_iterative(int i, int j, vector<vector<char>>& adj, vector<vector<int>>& vis){
    int n = adj.size();
    int m = adj[0].size();

    stack<pair<int, int>> s;
    s.push({i, j});
    vis[i][j] = 1;

    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    while(!s.empty()){
        auto [x, y] = s.top();
        s.pop();

        for(auto d : directions) {
            int ni = x + d.first;
            int nj = y + d.second;

            if(ni >= 0 && ni < n && nj >= 0 && nj < m && adj[ni][nj] == '1' && !vis[ni][nj]){
                vis[ni][nj] = 1;
                s.push({ni, nj});
            }
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<char>> grid(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char x;
            cin >> x;
            grid[i].push_back(x);
        }
    }
    
    vector<vector<int>> vis(n, vector<int>(m, 0));
    
    int island = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == '1' && !vis[i][j]){
                island += 1;
                dfs_iterative(i, j, grid, vis); 
            } 
        }
    }
    
    cout << island << "\n"; 

    return 0;
}

class Solution {
public:
    bool dfs(int i, int j, int pi, int pj, vector<vector<char>>& adj, vector<vector<int>>& vis, char theChar){
        int n = adj.size();
        int m = adj[0].size();

        vis[i][j] = 1;

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for(auto d : directions) {
            int ni = i + d.first;
            int nj = j + d.second;

            if(ni >= 0 && ni < n && nj >= 0 && nj < m && adj[ni][nj] == theChar){
                if(!vis[ni][nj]){
                    if(dfs(ni, nj, i, j, adj, vis, theChar)) {
                        return true;
                    }
                }
                else if(ni != pi || nj != pj) {
                    return true;
                }
            }
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(),0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j]){
                    char theChar = grid[i][j];
                    if(dfs(i, j, -1, -1, grid, vis, theChar)) {
                        return true;
                    }
                } 
            }
        }
        return false;
    }
};
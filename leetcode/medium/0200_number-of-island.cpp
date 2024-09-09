class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& adj, vector<vector<int>>& vis){
        int n = adj.size();
        int m = adj[0].size();

        vis[i][j] = 1;

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for(auto d : directions) {
            int ni = i + d.first;
            int nj = j + d.second;

            if(ni >= 0 && ni < n && nj >= 0 && nj < m && adj[ni][nj] == '1' && !vis[ni][nj]){
                dfs(ni, nj, adj, vis); 
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(),0));
        int island = 0;

        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    island += 1;
                    dfs(i, j, grid, vis);
                } 
            }
        }
        return island;
    }
};
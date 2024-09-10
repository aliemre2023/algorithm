class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& adj, vector<vector<int>>& vis, int& counter, bool& isOut){
        int n = adj.size();
        int m = adj[0].size();

        vis[i][j] = 1;
        counter += 1;

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for(auto d : directions) {
            int ni = i + d.first;
            int nj = j + d.second;

            if(ni < 0 || ni >= n || nj < 0 || nj >= m){
                isOut = true;
            }
            if(ni >= 0 && ni < n && nj >= 0 && nj < m && adj[ni][nj] == 1 && !vis[ni][nj]){
                dfs(ni, nj, adj, vis, counter, isOut); 
            }
        }

    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        int total_cells = 0;
        for(int i =0 ; i < n; i++){
            for(int j = 0 ;j< m; j++){
                int counter = 0;
                bool isOut = false;
                if(grid[i][j] == 1 && !vis[i][j]){
                    dfs(i, j, grid, vis, counter, isOut);
                }
                if(!isOut){
                    total_cells += counter;
                }
            }
        }
        return total_cells;
    }
};
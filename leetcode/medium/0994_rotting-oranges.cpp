class Solution {
public:
    int bfs(queue<pair<pair<int,int>, int>> q, vector<vector<int>>& adj, vector<vector<int>>& vis){
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int n = adj.size();
        int m = adj[0].size();
        int time = 0;


        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            time = max(time, t);

            for(auto d : directions) {
                int ni = r + d.first;
                int nj = c + d.second;

                if(ni >= 0 && ni < n && nj >= 0 && nj < m && adj[ni][nj] == 1 && !vis[ni][nj]){
                    vis[ni][nj] = 1;
                    adj[ni][nj] = 2;
                    q.push({{ni, nj}, t + 1});
                }
            }
        }
        return time;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>, int>> q;
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(),0));
        int x_idx = 0;
        int y_idx = 0;

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                }
            }
        }
        int time = bfs(q, grid, vis);

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(vis[i][j] != 1 && grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return time;
    }
};
class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& adj, vector<vector<int>>& vis, int num, int color){
        int n = adj.size();
        int m = adj[0].size();

        vis[i][j] = 1;
        adj[i][j] = color;
        
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for(auto d : directions) {
            int ni = i + d.first;
            int nj = j + d.second;

            if(ni >= 0 && ni < n && nj >= 0 && nj < m && adj[ni][nj] == num && !vis[ni][nj]){
                dfs(ni, nj, adj, vis, num, color); 
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> vis(image.size(), vector<int>(image[0].size(),0));
        int thenum = image[sr][sc];
        dfs(sr, sc, image, vis, thenum, color);

        return image;
    }
};
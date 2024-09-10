class Solution {
public:
    vector<vector<int>> bfs(queue<pair<pair<int,int>, int>> q, vector<vector<int>>& adj, vector<vector<int>>& vis){
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int n = adj.size();
        int m = adj[0].size();
        vector<vector<int>> res(n, vector<int>(m, 0));

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();

            for(auto d : directions) {
                int ni = r + d.first;
                int nj = c + d.second;

                if(ni >= 0 && ni < n && nj >= 0 && nj < m && adj[ni][nj] == 1 && !vis[ni][nj]){
                    vis[ni][nj] = 1;
                    res[ni][nj] += 1;
                    q.push({{ni, nj}, t + 1});    
                }
            }
        }
        return res;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> vis(mat.size(), vector<int>(mat[0].size(),0));
        queue<pair<pair<int,int>, int>> q;
        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[0].size(); j++){
                if(mat[i][j] == 0){
                    vis[i][j] = 1;
                    q.push({{i, j}, 0});
                }
            }
        }
        vector<vector<int>> arr = bfs(q, mat, vis);
        return arr;
    }
};
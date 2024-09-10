class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& adj, vector<vector<int>>& vis, vector<vector<int>>& pathRecognizer, bool& isOut){
        int n = adj.size();
        int m = adj[0].size();

        vis[i][j] = 1;
        pathRecognizer.push_back({i, j});

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for(auto d : directions) {
            int ni = i + d.first;
            int nj = j + d.second;

            if(ni < 0 || ni >= n || nj < 0 || nj >= m){
                isOut = false;
            }
            if(ni >= 0 && ni < n && nj >= 0 && nj < m && adj[ni][nj] == 'O' && !vis[ni][nj]){
                dfs(ni, nj, adj, vis, pathRecognizer, isOut); 
            }
        }

    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i =0 ; i < n; i++){
            for(int j = 0 ;j< m; j++){
                vector<vector<int>> pathRecognizer;
                bool isOut = true;
                if(board[i][j] == 'O' && !vis[i][j]){
                    dfs(i, j, board, vis, pathRecognizer, isOut);
                }
                if(isOut){
                    for(int x = 0; x < pathRecognizer.size(); x++){
                        board[pathRecognizer[x][0]][pathRecognizer[x][1]] = 'X';
                    }
                }
            }
        }
    }
};
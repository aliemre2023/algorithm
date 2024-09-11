class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        pair<int,int> src = {0,0};
        pair<int,int> dest = {grid.size()-1, grid.size()-1};
        if(grid[src.first][src.second] == 1 || grid[dest.first][dest.second] == 1) return -1;
        if(src.first==dest.first && src.second==dest.second) return 1;
        

        queue<pair<int, pair<int, int>>> q;

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[src.first][src.second] = 1;

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {1, -1}, {-1, 1}, {1, 1}};

        q.push({1, {src.first, src.second}});

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;

            for(auto d : directions){
                int nr = r + d.first;
                int nc = c + d.second;

                if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 0 && dis + 1 < dist[nr][nc]){
                    dist[nr][nc] = 1 + dis;
                    if(nr == dest.first && nc == dest.second){
                        return dis + 1;
                    }
                    q.push({1 + dis, {nr, nc}});
                }
            }
        }
        return -1;
    }
};
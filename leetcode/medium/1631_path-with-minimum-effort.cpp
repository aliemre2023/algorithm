class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        // {diff, {row, col}}
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>> pq;

        int n = heights.size();
        int m = heights[0].size();

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;
        pq.push({0, {0,0}});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;

            for(auto d : directions){
                int nr = row + d.first;
                int nc = col + d.second;

                if(nr >= 0 && nr < n && nc >= 0 && nc < m){
                    int newEffort = max(abs(heights[row][col] - heights[nr][nc]), diff);
                    
                    if(newEffort < dist[nr][nc]){
                        dist[nr][nc] = newEffort;
                        pq.push({dist[nr][nc], {nr, nc}});
                    }
                }
            }
        }
        return dist[n-1][m-1]; //unreachable
    }
};
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int total_edges = 0;

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    int edges = 4;
                    
                    for(auto d : directions) {
                        int ni = i + d.first;
                        int nj = j + d.second;

                        if(ni >= 0 && ni < n && nj >= 0 && nj < m) {
                            if(grid[ni][nj] == 1) {
                                edges--;
                            }
                        }
                    }
                    total_edges += edges;
                }
            }
        }
        return total_edges;
    }
};
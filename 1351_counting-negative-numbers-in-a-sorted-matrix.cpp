// Time Complexity = O(grid.size() * grid[0].size())
// Space Complexity = O(1)

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = grid[0].size()-1; 0 <= j; j--){
                if(grid[i][j] >= 0) break;
                else count++;
            }
        }
        return count;
    }
};
// Time Complexity = O(mat.size())
// Space Complexity = O(1)

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0;
        
        if(mat.size() % 2) {
            sum -= mat[(mat.size()-1)/2][(mat.size()-1)/2];
        }
        
        for(int i = 0; i < mat.size(); i++){
            sum += mat[i][i];
            sum += mat[i][mat.size()-1-i];
        }
        return sum;
    }
};
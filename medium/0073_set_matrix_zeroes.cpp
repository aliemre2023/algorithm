// Time Complexity = O(n^4)
// Space Complexity = O(1) 

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    matrix[i][j] == INT_MAX -12345; 
                    for(int x = 0; x < matrix.size(); x++){
                        if(matrix[x][j] != 0) matrix[x][j] = INT_MAX -12345;
                        
                    }
                    for(int y = 0; y < matrix[0].size(); y++){
                        if(matrix[i][y] != 0) matrix[i][y] = INT_MAX -12345;
                    }
                }
            }
        }
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == INT_MAX -12345) matrix[i][j] = 0;
            }
        }
    }
};
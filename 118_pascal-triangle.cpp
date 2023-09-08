// Time Complexity = O(numRows * (numRows / 2))
// Space Complexity = O((numRows * (numRows + 1)) / 2)
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal;
        pascal.push_back({1});
        for(int i = 1; i < numRows; i++){
            vector<int> row;
            row.push_back(1);
            for(int j = 1; j < size(pascal[i-1]); j++){
                int num = pascal[i-1][j-1] + pascal[i-1][j];
                row.push_back(num);
            }
            row.push_back(1);
            pascal.push_back(row);
        }
        return pascal;
    }
};
// Time Complexity = O(m * n * log(k)) // log(k) is the tiem complexity of pop and push method's
// Space Complexity = O(k)
// Question Link = https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;

        int row = matrix.size();
        int col = matrix.size();

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                pq.push(matrix[i][j]);

                if(pq.size() == k+1){
                    pq.pop();
                }
            }
        }

        return pq.top();
    }
};
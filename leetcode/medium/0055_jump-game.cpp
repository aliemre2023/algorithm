// Time Complexity = O(n)
// Space Complexity = O(1)
// Question Link = https://leetcode.com/problems/jump-game/

// this solution is shorter than old one,  
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;

        for(int i = 0; i < nums.size() && i <= maxi; i++){
            maxi = max(maxi, i+nums[i]);    
        }

        return maxi >= n-1;
    }
};
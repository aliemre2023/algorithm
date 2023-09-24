// Time Complexity = O(n)
// Space Complexity = O(1)
// Question Link = https://leetcode.com/problems/jump-game-ii/

class Solution {
public:
    int jump(vector<int>& nums) {
        int i = 0;
        int returned = 0;
        if(nums.size() == 1) return returned;
        while (i < nums.size()) {
            returned++;
            int best_jump = 0;
            int best_jump_idx = i;
            
            if ((best_jump_idx + nums[best_jump_idx]) >= nums.size() - 1) {
                return returned;
            }
            for (int j = i + 1; j <= i + nums[i]; j++) {
                if (j + nums[j] > best_jump) {
                    best_jump = j + nums[j];
                    best_jump_idx = j;
                }
            }
            i = best_jump_idx;
        }
        return returned;
    }
};
// Time Complexity = O(n)
// Space Complexity = O(1)
// Question Link = https://leetcode.com/problems/jump-game/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = 0;
        while (i < nums.size()) {
            int best_jump = 0;
            int best_jump_idx = i;
            if ((best_jump_idx + nums[best_jump_idx]) >= nums.size() - 1) {
                return true;
            }

            for (int j = i + 1; j <= i + nums[i]; j++) {
                if (j + nums[j] > best_jump) {
                    best_jump = j + nums[j];
                    best_jump_idx = j;
                }
            }

            if (best_jump_idx == i) {
                return false;
            }
            
            i = best_jump_idx;
        }
        return false;
    }
};
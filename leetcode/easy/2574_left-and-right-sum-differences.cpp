// Time Comlexity = O(n)
// Space Complexity = O(n)
// Question Link = https://leetcode.com/problems/left-and-right-sum-differences/


class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> left; 
        left.push_back(0);
        left.push_back(nums[0]);

        for(int i = 1; i < nums.size() - 1; i++){
            left.push_back(left[i] + nums[i]);
        }
        int sum = 0;
        for(int i = 1; i < nums.size(); i++){
            sum += nums[i];
        }
        nums[0] = sum;
        for(int i = 0; i < nums.size()-1; i++){
            nums[i + 1] = (nums[i] - nums[i+1]);
        }

        for(int i = 0; i < nums.size(); i++){
            nums[i] = abs(left[i] - nums[i]);
        }

        return nums; 
    }
};
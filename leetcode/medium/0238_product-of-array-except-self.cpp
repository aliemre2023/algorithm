// Time Complexity = O(n)
// Space Complexity = O(n)
// Question Link = https://leetcode.com/problems/product-of-array-except-self/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left(nums.size(), 0);
        vector<int> right(nums.size(), 0);

        left[0] = 1;
        for(int i = 1; i < nums.size(); i++){
            left[i] = left[i - 1] * nums[i - 1];
        }

        right[nums.size() - 1] = 1;
        for(int i = nums.size() - 2; 0 <= i; i--){
            right[i] = right[i + 1] * nums[i + 1];
        }

        for(int i = 0; i < nums.size(); i++){
            nums[i] = left[i] * right[i];
        }

        return nums;
    }
};
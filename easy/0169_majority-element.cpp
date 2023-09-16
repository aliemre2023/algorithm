// Time Complexity = O(n * log(n))
// Space Complexity = O(1) 

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};
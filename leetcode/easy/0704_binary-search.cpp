// Time Complexity = O(long(n))
// Space Complexity = O(1)
// Question Link = https://leetcode.com/problems/binary-search/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int max = nums.size()-1;
        int min = 0;
        int mid = (max + min) / 2;

        if(nums[max] == target) return max;

        int prev_mid = mid;
        while(nums[mid] != target){
            if(nums[mid] < target) min = mid;
            else max = mid;
            mid = (max + min) / 2;

            if(prev_mid == mid) return -1;
            else prev_mid = mid;
        }
        return mid;
    }
};
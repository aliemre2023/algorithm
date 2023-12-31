// Time Complexity = O(log(n))
// Space Complexity = O(1)
// Question Link = https://leetcode.com/problems/search-insert-position/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int end = nums.size() - 1;
        int start = 0;
        int mid;
        while(start <= end){
            mid = (end + start) / 2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        return start;
    }
};
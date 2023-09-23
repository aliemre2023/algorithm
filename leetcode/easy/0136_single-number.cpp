// Time Complexity = O(n * log(n))
// Space Complexity = O0)
// Question Link = https://leetcode.com/problems/single-number

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int temp = nums[0];
        for(int i = 1; i < nums.size(); i+=2){
            if(nums[i] == temp){
                temp = nums[i+1];
            }
            else{
                return temp;
            }
        }
        return temp;
    }
};
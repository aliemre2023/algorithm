// Time Complexity = O(n*n)
// Space Complexity = O(n*n)
// Question Link = https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        for(int i = 0; i < nums.size(); i++){
            int target = -nums[i];
            int front = i+1;
            int back = nums.size()-1;

            while(front < back){
                int sum = nums[front] + nums[back];
                if(sum < target) front++;
                else if(sum > target) back--;
                else{
                    vector<int> temp = {-target, nums[front], nums[back]};
                    res.push_back(temp);

                    while(temp[1] == nums[front] && front < back) front++;
                    while(temp[2] == nums[back] && front < back) back--;
                }
            }
            while(i+1 < nums.size() && nums[i] == nums[i+1]) i++;
        }
        return res;
    }
};
// Time Complexity = O(n)
// Space Complexity = O(n)
// Question Link = https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> myMap;

        for(int i = 0; i < nums.size(); i++){
            int comp = target - nums[i];

            if(myMap.count(comp)){
                return {myMap[comp], i};
            }
            myMap[nums[i]] = i; 
        }
        return {};
    }
};

// Time Complexity = O(n)
// Space Complexity = O(n)

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int> mp;

        for(int i = 0; i < nums.size(); i++){
            if(mp.count(nums[i])){
                if(k >= i - mp[nums[i]]){
                    return true;
                }
            }
            mp[nums[i]] = i;
        }
        return false;
    }
};
// Time Complexity = O(n* log(n))
// Space Complexity = O(1)

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int avr = 0;
        sort(nums.begin(), nums.end());
        avr += nums[nums.size()/2];

        int move = 0;
        for(int i = 0; i < nums.size(); i++){
            move += abs(nums[i] - nums[nums.size()/2]);
        }
        return move;
    }
};
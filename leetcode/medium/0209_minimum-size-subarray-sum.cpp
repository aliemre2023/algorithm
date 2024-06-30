class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0;
        int j = 0;
        int res = INT_MAX;
        bool exist = false;

        int sum = 0;
        while(j < nums.size()){
            sum += nums[j];
            j++;

            while(sum >= target){
                exist = true;

                if(j-i < res) res = j-i;
                sum -= nums[i];
                i++; 
            }
        }
        if(exist) return res;
        else return 0;
    }
};
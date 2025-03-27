class Solution {
    public:
        void moveZeroes(vector<int>& nums) {
            int zero_count = 0;
            for(int i = 0; i < nums.size() - zero_count; i++){
                if(nums[i] == 0){
                    zero_count++;
                    int j = i;
                    while(j+1 < nums.size()){
                        // weird swapping
                        nums[j] = nums[j]^nums[j+1];
                        nums[j+1] = nums[j]^nums[j+1];
                        nums[j] = nums[j]^nums[j+1];
                        j++;
                    }
                    i--;
                }
            }
        }
    };
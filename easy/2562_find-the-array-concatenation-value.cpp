// Time Complexity = O(nums.size() / 2)
// Space Complexity = O(1)

class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long sum = 0;
        while(nums.size() > 1){
            int first = nums.front();
            int last = nums.back();

            int length = 0;
            for(int i = 1; i <= last; i *= 10){
                length++;
            }
            
            sum +=  first * pow(10, length) + last;

            nums.erase(nums.end() - 1);
            nums.erase(nums.begin());
        }

        while(!nums.empty()){
            sum += nums[0];
            nums.erase(nums.begin());
        }

        return sum;
    }
};
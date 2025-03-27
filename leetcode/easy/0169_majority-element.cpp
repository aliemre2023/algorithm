// Time O(n)
// Space O(1)
class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            int curr = nums[0];
            int counter = 1;
    
            for(int i = 1; i < nums.size(); i++){
                if(curr == nums[i]){
                    counter++;
                }
                else{
                    counter--;
                    if(counter <= 0){
                        curr = nums[i];
                        counter = 1;
                    }
                }
            }
            return curr;
        }
    };



// Bad 
// Time Complexity = O(n * log(n))
// Space Complexity = O(1) 

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};
class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            long long maxi = 0;
            long long dist_max = nums[0];
            long long dist_min = nums[1];
            long long dist_max_temp = max(nums[0], nums[1]);
    
            for(int i = 2; i < nums.size(); i++){
                maxi = max(maxi, (dist_max-dist_min)*(long long)nums[i]);
                if(dist_max_temp - (long long)nums[i] >= dist_max - dist_min  || dist_min >= (long long)nums[i]){
                    
                    dist_max = max(dist_min, dist_max_temp);
                    dist_min = (long long)nums[i];
                    dist_max_temp = dist_max;
                    cout << dist_max <<  " - " << dist_min << "\n";
                }
                else{
                    dist_max_temp = max(dist_max_temp, (long long)nums[i]);
                    
                }   
    
                
                
            }
    
            return maxi;
        }
    };
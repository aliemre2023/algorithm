class Solution {
public:
    int trap(vector<int>& height) {
        int wall_unit = 0;
        int water_unit = 0;

        vector<int> left2right(height.size(), 0);

        int lmax = height[0];
        for(int i = 0; i < height.size(); i++){
            if(lmax < height[i]) lmax = height[i];
            left2right[i] = lmax;

            wall_unit += height[i];
        }
        
        int rmax = height[height.size()-1];
        for(int i = height.size()-1; i >= 0; i--){
            if(rmax < height[i]) rmax = height[i];
            if(rmax < left2right[i]){
                water_unit += rmax;
            }
            else{
                water_unit += left2right[i];
            }
        }

        return water_unit - wall_unit;
    }
};
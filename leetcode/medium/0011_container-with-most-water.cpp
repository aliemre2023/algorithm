// Time Complexity = O(n)
// Space Complexity = O(1)
// Question Link = https://leetcode.com/problems/container-with-most-water/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int idx_left = 0;
        int idx_right = height.size()-1;
        int h_left = height[idx_left];
        int h_right = height[idx_right];
        int width = idx_right - idx_left;

        int area = 0;
        while(width != 0){
            int temp_area;
            
            temp_area = min(h_left, h_right) * width;
            width--;
            if(temp_area > area){
                area = temp_area;
            }

            if(h_left > h_right){
                idx_right--;
                h_right = height[idx_right];
            }
            else{
                idx_left++;
                h_left = height[idx_left];
            }
            width = idx_right - idx_left;
        }

        return area;


    }
};
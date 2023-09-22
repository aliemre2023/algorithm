// Time Complexity = O(m + n) 
// Space Complexity = O(1)
// Question Link: https://leetcode.com/problems/merge-sorted-array/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx1 = m - 1;
        int idx2 = n - 1;
        int idx = m + n - 1;

        while(0 <= idx1 && 0 <= idx2){
            if(nums1[idx1] > nums2[idx2]){
                nums1[idx] = nums1[idx1];
                idx1--;  
            }
            else{
                nums1[idx] = nums2[idx2];
                idx2--;
            }
            idx--;
        }
        while(0 <= idx2){
            nums1[idx] = nums2[idx2];
            idx2--;
            idx--;
        }
    }
};
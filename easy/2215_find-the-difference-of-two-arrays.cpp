// Time Complexity = O(num1.size() * num2.size())
// Space Complexity = O(max(num1.size(), num2.size())

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> res;
        set<int> diff1;
        set<int> diff2;

        for(int i = 0; i < nums1.size(); i++){
            int cont1 = 0;
            for(int j = 0; j < nums2.size(); j++){
                if(nums1[i] == nums2[j]){
                    cont1++;
                }
            }
            if(cont1 == 0){
                diff1.insert(nums1[i]);
            }
        }
        for(int i = 0; i < nums2.size(); i++){
            int cont2 = 0;
            for(int j = 0; j < nums1.size(); j++){
                if(nums2[i] == nums1[j]){
                    cont2++;
                }
            }
            if(cont2 == 0){
                diff2.insert(nums2[i]);
            }
        }
        if(diff1.empty()) res.push_back({});
        else {
            vector<int> diff1Vector(diff1.begin(), diff1.end());
            res.push_back(diff1Vector);
        }
        if(diff2.empty()) res.push_back({});
        else {
            vector<int> diff2Vector(diff2.begin(), diff2.end());
            res.push_back(diff2Vector);
        }
        return res;

    }
};
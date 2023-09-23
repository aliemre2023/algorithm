// Time Complexity = O(m * n) // m = strs size, n = long-comm-pref size
// Space Complexity = O(n)
// Question Link = https://leetcode.com/problems/longest-common-prefix

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string substr;

        int min_str = strs[0].size();
        for(int i = 1; i < strs.size(); i++){
            if(min_str > strs[i].size()){
                min_str = strs[i].size();
            }
        }

        int idx = 0;
        while(idx < min_str){
            for(int i = 1; i < strs.size(); i++){
                if(strs[0][idx] != strs[i][idx]){
                    return substr;
                }
            }
            substr.push_back(strs[0][idx]);
            idx++;   
        }

        return substr;
    }
};
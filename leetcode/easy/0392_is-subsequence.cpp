// Time Complexity = O(n)
// Space Complexity = O(1)
// Question Link = https://leetcode.com/problems/is-subsequence/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ptr_S = 0;
        int ptr_T = 0;

        for(; ptr_T < t.size(); ptr_T++){
            if(s[ptr_S] == t[ptr_T]){
                ptr_S++;
            }
        }

        return ptr_S == s.size();
    }
};
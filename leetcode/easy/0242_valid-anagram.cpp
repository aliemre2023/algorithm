// Time Complexity = O(n)
// Space Complexity = O(26)
// Question Link = https://leetcode.com/problems/valid-anagram/

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> chars(26, 0);

        for(auto ch : s){
            chars[ch - 'a']++;
        }
        for(auto ch : t){
            chars[ch - 'a']--;
        }
        for(auto i : chars){
            if(i != 0){
                return false;
            }
        }
        return true;
    }
};
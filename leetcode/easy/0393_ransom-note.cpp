// Time Complexity = O(n)
// Space Complexity = O(26)
// Question Link = https://leetcode.com/problems/ransom-note/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> char_count(26, 0);

        for(auto ch : magazine){
            char_count[ch - 'a']++;
        }
        for(int ch: ransomNote){
            char_count[ch - 'a']--;
            if(char_count[ch - 'a'] == -1){
                return false;
            }
        }
        return true;
    }
};
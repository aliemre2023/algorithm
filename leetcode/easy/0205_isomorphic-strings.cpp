// Time Complexity = O(n)
// Space Complexity = O(n)
// Question Link = https://leetcode.com/problems/isomorphic-strings/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> char_map;
        unordered_map<char, bool> bool_map;

        for(int i = 0; i < s.size(); i++){
            if(char_map.count(s[i])){
                if(char_map[s[i]] != t[i]){
                    return false;
                }
            }
            else{
                if(bool_map[t[i]]){
                    return false;
                }
                char_map[s[i]] = t[i]; 
                bool_map[t[i]] = true;
            }
        }
        return true;  
    }
};
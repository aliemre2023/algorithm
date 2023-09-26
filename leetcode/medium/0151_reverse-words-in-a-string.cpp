// Time Complexity = O(n)
// Space Complexity = O(n)
// Question Link = https://leetcode.com/problems/reverse-words-in-a-string/

class Solution {
public:
    string reverseWords(string s) {
        vector<string> parts;
        string temp;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] != ' ') {
                temp.push_back(s[i]);
            } else {
                if(!temp.empty()) parts.push_back(temp);
                temp = "";
            }
        }

        if(!(temp.empty())) parts.push_back(temp);

        vector<string> vec(1);
        for(int i = parts.size() - 1; i >= 0; i--) {
            vec[0] += parts[i];
            if (i > 0) vec[0] += " ";
        }

        return vec[0];
    }
};

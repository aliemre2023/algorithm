class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> charmap;
        int start = 0;
        int maxres = 0;
        for(int i = 0; i < s.size(); i++){
            if (charmap.find(s[i]) != charmap.end() && charmap[s[i]] >= start) {
                start = charmap[s[i]] + 1;
            }

            charmap[s[i]] = i;

            int res = i - start + 1;

            if (maxres < res) {
                maxres = res;
            }
        }
        return maxres;
    }
};
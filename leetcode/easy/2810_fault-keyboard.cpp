// Time Complexity = O(n^2)
// Space C0mplexity = O(1)

class Solution {
public:
    string finalString(string s) {
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'i'){
                for(int j = 0; j < i / 2; j++){
                    swap(s[j], s[i-j-1]);
                }
                s.erase(s.begin() + i);
                i--;
            }
        }
        return s;
    }
};
// Time Complexity = O(s.size())
// Space Comlexity = O(1)

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;

        for(int i = s.size()-1; i >= 0; i--){
            if(len == 0 && s[i] == ' '){
                continue;
            }
            else{
                if(s[i] == ' '){
                    break;
                }
                else{
                    len++;
                }
            }
        }
        return len;
    }
};
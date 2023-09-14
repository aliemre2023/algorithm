// haystack.size = m, needle.size = n;
// Time Complexity = O(m * n)
// Space Complexity = O(1)

class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int i = 0; i < haystack.size(); i++){
            if(haystack[i] == needle[0]){
                int count = 1;
                for(int j = 1; j < needle.size(); j++){
                    if((i + j < haystack.size()) && (haystack[i + j] == needle[j])){
                        count++;
                    }
                }
                if(count == needle.size()){
                    return i;
                }
            } 
        }
        return -1;

   }
};
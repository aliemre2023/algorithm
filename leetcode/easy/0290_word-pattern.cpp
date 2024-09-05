class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mp;
        unordered_map<string, int> existing_words;
        
        int rest = 0;
        for(int i = 0; i < pattern.size(); i++){
           
           string word = "";
            while(rest < s.size() && s[rest] != ' '){
                word += s[rest];
                rest++;
            }
            rest++;
            
            if(mp.find(pattern[i]) == mp.end() && existing_words.find(word) == existing_words.end()){
                existing_words[word] = 1;
                mp[pattern[i]] = word;
            }
            else{
                if(mp[pattern[i]] != word) return false;
            }
        }
        if(rest != s.size()+1) return false;
        return true;
    }
};
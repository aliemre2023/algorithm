class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<pair<string,int>> strs_copy;
        for(int i = 0; i < strs.size(); i++){
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            strs_copy.push_back({temp, i});
        }
        sort(strs_copy.begin(), strs_copy.end());

        vector<vector<string>> result;
        vector<string> temp;
        for(int i = 0; i < strs_copy.size()-1; i++){
            temp.push_back(strs[strs_copy[i].second]);
            if(strs_copy[i].first != strs_copy[i+1].first){
                result.push_back(temp);
                temp.clear();
            }  
        }
        temp.push_back(strs[strs_copy[strs_copy.size()-1].second]);
        result.push_back(temp);

        return result;
    }
};
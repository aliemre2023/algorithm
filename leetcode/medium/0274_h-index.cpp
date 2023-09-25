// Time Complexity = O(n * log(n))
// Space Complexity = O(1)
// Question Link = https://leetcode.com/problems/h-index/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());

        int hold = 0;
        for(int i = 0; i < citations.size(); i++){
            if(citations[i] > i)
                hold = i + 1;
        }
        return hold;
    }
};
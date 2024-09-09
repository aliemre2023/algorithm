class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int,int> mp;
        int maxi = 0;
        for(int i = 0; i < edges.size(); i++){
            mp[edges[i][0]]++;
            mp[edges[i][1]]++;

            if(mp[edges[i][0]] > maxi) maxi = edges[i][0];
            if(mp[edges[i][1]] > maxi) maxi = edges[i][1];
        }
        return maxi;
    }
};
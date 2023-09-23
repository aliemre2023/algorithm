// Time Complexity = O(n * log(n))
// Space Complexity = O(n)

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> output;
        vector<pair<int,int>> clost;
        for(int i = 0; i < points.size(); i++){
            int cl = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            clost.push_back({cl, i});
        }

        sort(clost.begin(), clost.end());

        for(int i = 0; i < k; i++){
            int idx = clost[i].second;
            output.push_back(points[idx]);
        }
        return output;
    }
};
class Solution {
public:  
    bool dfsCheck(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathVis) {
        vis[node] = 1;
        pathVis[node] = 1;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (dfsCheck(it, adj, vis, pathVis)) {
                    return true;  // If we find a cycle, return true
                }
            }
            else if (pathVis[it]) {
                return true;  // Cycle detected
            }
        }
        
        pathVis[node] = 0;  // Backtrack by unmarking the path
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> vis(n, 0);      
        vector<int> pathVis(n, 0);  

        vector<vector<int>> adj(n);
        for(int i = 0; i < prerequisites.size(); i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
            if(prerequisites[i][0] == prerequisites[i][1]){
                return false;
            }
        }

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if(dfsCheck(i, adj, vis, pathVis)){
                    return false;
                }
            }
        } 
        return true;
    } 
};
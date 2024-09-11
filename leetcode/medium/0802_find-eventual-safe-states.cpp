class Solution {
public:
    bool dfsCheck(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathVis, vector<int>& check) {
        vis[node] = 1;
        pathVis[node] = 1;
        check[node] = 0;  // Marking this node as unsafe initially

        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (dfsCheck(it, adj, vis, pathVis, check)) {
                    return true;  // If we find a cycle, return true
                }
            }
            else if (pathVis[it]) {
                return true;  // Cycle detected
            }
        }
        
        // After the DFS traversal, we mark the node as safe
        check[node] = 1;
        pathVis[node] = 0;  // Backtrack by unmarking the path
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0);      
        vector<int> pathVis(n, 0);  
        vector<int> check(n, 0);     

        vector<int> safeNodes;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfsCheck(i, graph, vis, pathVis, check);
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (check[i]) safeNodes.push_back(i);
        }
        return safeNodes;
    }
};
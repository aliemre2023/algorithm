class Solution {
public:
    void dfs(int i, vector<vector<int>>& adj, long long& cnt, vector<int>& vis) {
        vis[i] = 1;
        cnt++;

        for (auto it : adj[i]) {
            if (!vis[it]) {
                dfs(it, adj, cnt, vis);
            }
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        // Build the adjacency list
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> visited(n);
        long long ans = 0;
        long long totalNodes = n; 
        
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                long long count = 0;
                dfs(i, adj, count, visited);
                ans += count * (totalNodes - count);
            }
        }
        return ans / 2;  
    }
};
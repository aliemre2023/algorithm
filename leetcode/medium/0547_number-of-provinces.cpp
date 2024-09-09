class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis){
        vis[node] = 1;

        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it, adj, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>> adj(isConnected.size() + 1);  
        adj.push_back({0});

        for(int i = 1; i < isConnected.size()+1; i++){
            for(int j = 1; j < isConnected[0].size()+1; j++){
                if(isConnected[i-1][j-1] == 1 && i != j){
                    adj[i].push_back(j);
                }
            }
        }

        vector<int> vis(isConnected.size() + 1, 0);
        vis[0] = 1;
        int res = 0;

        for(int i = 1; i < isConnected.size() + 1; i++){
            if(!vis[i]){
                dfs(i, adj, vis);
                res += 1;
            }
        }

        return res;
    }
};
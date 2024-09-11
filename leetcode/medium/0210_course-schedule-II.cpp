class Solution {
public:
    vector<int> topoSort(vector<vector<int>> adj, int n){
        vector<int> indegree(n, 0);
        for(int i = 0; i < n; i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        return topo;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites){
        int n = numCourses;
        vector<int> vis(n, 0);      
        vector<int> pathVis(n, 0);  

        vector<vector<int>> adj(n);
        for(int i = 0; i < prerequisites.size(); i++){
            //adj[prerequisites[i][0]].push_back(prerequisites[i][1]);     
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);     
        }

        vector<int> topo = topoSort(adj, n);
        if(topo.size() == n){
            return topo;
        }
        vector<int> empty;
        return empty;
    }
};
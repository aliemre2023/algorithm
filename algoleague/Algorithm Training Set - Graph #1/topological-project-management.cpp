#include <bits/stdc++.h>
using namespace std;

vector<int> topoSort(vector<vector<int>> adj, int n){
    vector<int> indegree(n, 0);
    for(int i = 0; i < n; i++){
        for(auto it : adj[i]){
            indegree[it]++;
        }
    }
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i = 0; i < n; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    vector<int> topo;
    while(!q.empty()){
        int node = q.top();
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        adj[y].push_back(x);
    }
    //sort(adj.begin(), adj.end());
    
    vector<int> vis(n+1, 0);      
    vector<int> topo = topoSort(adj, n+1);
    if(topo.size() == n+1){ // one plus is for 0
        for(int i = 1; i < topo.size(); i++){
            cout << topo[i] << " ";
        }
        return 0;
    }
    cout << "IMPOSSIBLE";

    
    return 0;
}

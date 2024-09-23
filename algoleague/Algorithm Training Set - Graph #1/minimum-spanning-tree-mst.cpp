//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;
#define int long long

int spanningTree(int V, vector<vector<pair<int,int>>>& adj){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    V++;
    vector<int> vis(V, 0);
    vis[0] = 1;
    // {wt, node}
    pq.push({0, 1});

    int sum = 0;
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();

        int node = it.second;
        int wt = it.first;

        if(vis[node]) continue;
        vis[node] = 1;
        sum += wt;

        for(auto it: adj[node]){
            int adjNode = it.first;
            int edW = it.second;
            if(!vis[adjNode]){
                pq.push({edW, adjNode});
            }
        }
    }
    return sum;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m; cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i = 0; i < m; i++){
        int x, y, w; cin >> x >> y >> w;
        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
    }
    
    int res = spanningTree(n, adj);
    cout << res;


	return 0;
}

//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;
#define int long long

vector<int> shortestPath(int n, int m, vector<vector<pair<int, int>>>& adj) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n+m+1, LLONG_MAX); 

    // populAr cities, distance 0
    for (int i = n + 1; i <= n + m; i++) {
        dist[i] = 0;
        pq.push({0, i});
    }

    while(!pq.empty()){
        auto it = pq.top();
        int node = it.second;
        int dis = it.first;
        pq.pop();
        
        if (dis > dist[node]) continue; // Skip outdated entries

        for(auto it : adj[node]){
            int adjNode = it.first;
            int edW = it.second;
            if(dis + edW < dist[adjNode]){
                dist[adjNode] = dis + edW;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    
    return dist ;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, k; cin >> n >> m >> k;
    
    vector<int> inds;
    vector<int> popu;
    for(int i = 1; i < n+1; i++){
        inds.push_back(i);
    }
    for(int i = n+1; i < n+m+1; i++){
        popu.push_back(i);
    }
    
    vector<vector<pair<int,int>>> adj(n+m+1); 
    for(int i = 0; i < k; i++){
        int x, y, z; cin >> x >> y >> z;
        adj[x].push_back({y, z});
        adj[y].push_back({x, z});
    }
    

    vector<int> dist = shortestPath(n, m, adj);
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
       
	return 0;
}

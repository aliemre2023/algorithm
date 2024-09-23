#include <bits/stdc++.h>

using namespace std;

// Comparator for priority queue
int shortestPath(int n, vector<vector<pair<int, int>>>& adj, int start, int end) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n+1, INT_MAX); 

    dist[start] = 0;
    pq.push({0, start}); 

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
                pq.push({dis + edW, adjNode});
            }
        }
    }
    if(dist[n] == INT_MAX){ 
        return -1;
    }

    return dist[end] ;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m; cin >> n >> m;
    int start, end; cin >> start >> end;
    vector<vector<pair<int, int>>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int x, y, w; cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
    
    int res = shortestPath(n, adj, start, end);
    cout << res;
    
    

    return 0;
}

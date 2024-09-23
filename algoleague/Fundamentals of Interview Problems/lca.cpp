//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

#define int long long

vector<int> shortestPath(int n, vector<vector<pair<int, int>>>& adj, int start, int end) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n+1, LLONG_MAX); 
    vector<int> prev(n+1, -1);

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
                prev[adjNode] = node;
            }
        }
    }
    if(dist[n] == LLONG_MAX){ 
        return {};
    }
    
    vector<int> path;
    for(int at = end; at != -1; at = prev[at]){
        path.push_back(at);
    }
    reverse(path.begin(), path.end());

    return path;


}

int32_t main() {
// write your code here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i = 0; i < n-1; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back({y,1});
        adj[y].push_back({x,1});
    }
    int q, w; cin >> q >> w;
    
    vector<int> res1 = shortestPath(n, adj, 1, q);
    vector<int> res2 = shortestPath(n, adj, 1, w);
    vector<int> res;
    int edge_count = 0;
    int ancestor = -1;
    for(int i = 0; i < min(res1.size(),res2.size()); i++){
        if(res1[i] != res2[i]){
            edge_count += (res1.size() - i); 
            edge_count += (res2.size() - i);
            ancestor = res1[i-1];
            break;
        }
    }
    
    // identical
    if (ancestor == -1) {
        if(res1.size() < res2.size()){
            ancestor = res1[res1.size()-1];  
            edge_count = res2.size() - res1.size();
        }
        else{
            ancestor = res2[res2.size()-1];  
            edge_count = res1.size() - res2.size();
        }
    }
    
    cout << ancestor << " " << edge_count;
    
    

	return 0;
}

#pragma GCC optimize("O3,unroll-loops") 
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("fast-math")
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define int long long
using namespace std;

vector<int> shortestPath(int n, vector<vector<pair<int, int>>>& adj, vector<int>& theta, vector<bool>&is_theta,  vector<bool>& is_omega) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n+1, LLONG_MAX);

    
    for(int theta_node : theta) {
        dist[theta_node] = 0;
        pq.push({0, theta_node});
    }
    
    while(!pq.empty()) {
        auto [dis, node] = pq.top();
        pq.pop();
        
        if(dis > dist[node]) continue;
        
        for(auto [adjNode, edW] : adj[node]) { // cycy?
            if((is_theta[node] && is_theta[adjNode]) || (is_omega[node] && is_omega[adjNode])) {
                continue;
            }
            
            if(dis + edW < dist[adjNode]) {
                dist[adjNode] = dis + edW;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    
    for(int i = 0 ; i < dist.size(); i++){
        if(dist[i] == LLONG_MAX) dist[i] = -1;
    }
    return dist;
}

int32_t main() {
    fastio
    int n, e; 
    cin >> n >> e;
    
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i = 0; i < e; i++) {
        int a, b, w; cin >> a >> b >> w;
        adj[a].emplace_back(b, w);
        adj[b].emplace_back(a, w);
    }
    
    int theta_c; cin >> theta_c;
    vector<bool> is_theta(n+1, false);
    
    vector<int> theta(theta_c);
    for(int i = 0; i < theta_c; i++) {
        cin >> theta[i];
        is_theta[theta[i]] = true;
    }
    
    int omega_c; 
    cin >> omega_c;
    vector<int> omega(omega_c);
    
    vector<bool> is_omega(n+1, false);
    for(int i = 0; i < omega_c; i++) {
        cin >> omega[i];
        is_omega[omega[i]] = true;
    }
    
    vector<int> distances = shortestPath(n, adj, theta, is_theta, is_omega);
    
    int max_distance = -1;
    for(int omega_node : omega) {
        max_distance = max(max_distance, distances[omega_node]);
    }
    
    cout << max_distance << "\n";
    return 0;
}
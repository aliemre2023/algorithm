#include <bits/stdc++.h>
using namespace std;
#define int long long

class Solution {
private:
    int findMST(int start, vector<vector<pair<int, int>>>& adj, vector<int>& vis, vector<int>& weights) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, start});
        int sum = 0;
        int node_count = 0;
        
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int wt = it.first;
            
            if (vis[node]) continue;
            node_count++;
            vis[node] = 1;
            sum += wt;
            if (wt != 0) { 
                weights.push_back(wt);
            }
            
            for (auto edge : adj[node]) {
                int adjNode = edge.first;
                int edgeWeight = edge.second;
                if (!vis[adjNode]) {
                    pq.push({edgeWeight, adjNode});
                }
            }
        }
        return sum;
    }
public:
    pair<int, int> spanningTree(int V, vector<vector<pair<int, int>>>& adj, vector<int>& weights, vector<int>& ext) {
        vector<int> vis(V+1, 0);
        int total_sum = 0;
        int component_count = 0;
        
        for (int i = 1; i <= V; i++) {
            if (!vis[i]) {
                int component_sum = findMST(i, adj, vis, weights);
                total_sum += component_sum;
                component_count++;
            }
        }
        
        return {total_sum, component_count};
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, a;
    cin >> n >> m >> a;
    vector<vector<pair<int, int>>> adj(n+1);
    
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back({y, z});
        adj[y].push_back({x, z});
    }
    
    vector<int> ext;
    for (int i = 0; i < a; i++) {
        int x;
        cin >> x;
        ext.push_back(x);
    }
    sort(ext.begin(), ext.end());
    
    Solution sol;
    vector<int> weights;
    auto [baseCost, component_count] = sol.spanningTree(n, adj, weights, ext);
    sort(weights.rbegin(), weights.rend());
    
    if(component_count > 1){
        for (int i = 0; i <= a; i++) {
            if (component_count > 1 && i < component_count - 1) {
                // Zeort
                cout << "0" << " ";
            } else {
                int totalCost = baseCost;
                
                if (component_count > 1) {
                    for (int j = 0; j < component_count - 1; j++) {
                        totalCost += ext[j];
                    }
                }
            
                int remaining = i - (component_count - 1);
                if (remaining > 0) {
                    for (int j = 0; j < remaining; j++) {
                        if (j < weights.size()) {
                            totalCost = totalCost - weights[j] + ext[j + component_count - 1];
                        }
                    }
                }
                
                cout << totalCost << " ";
            }
        }
    }
    else{
        int totalCost = baseCost;
        
        
        
        
        int weight_idx = 0;
        cout << totalCost << " ";

        for(int i = 0; i < a; i++){
            totalCost -=  weights[weight_idx++];
            totalCost += ext[i];
            if(weight_idx >= weights.size()){
                weight_idx = 0;
                sort(weights.rbegin(), weights.rend());
            }
            
            cout << totalCost << " ";
            
        }
    }
    
    return 0;
}
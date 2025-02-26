#include <bits/stdc++.h>
using namespace std;
#define int long long

int postorder(pair<int,int> node, vector<vector<pair<int,int>>>& adj) {
    int node_val = node.first;
    int node_cur = node.second;
    int total = 1;

    for(auto& child : adj[node_val]) {
        int curr = postorder(child, adj);
        child.second = curr;
        total += curr; 
    }
    
    return total;
}

int32_t main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
  
    int n; cin >> n;
    
    //vector<set<pair<int,int>>> adj(n+1);
    vector<vector<pair<int,int>>> adj(n+1);
    // ww -1
    for(int i = 0; i < n-1; i++) {
        int x, y; 
        cin >> x >> y;
        adj[x].push_back({y, 0}); // own 1
    }
    //adj[0].push_back({1, 1});
    postorder({1, 1}, adj);
    
    
    int balance = n;
    for(int i = 1; i <= n; i++) {
        if(adj[i].size() > 1){
            for(int j = 0; j < adj[i].size()-1; j++){
                if(adj[i][j].second != adj[i][j+1].second){
                    balance--;
                    break;
                }
            }
        }
    }
    cout << balance<< "\n"; //cuz zero start

    
    
    
    
    return 0;
}
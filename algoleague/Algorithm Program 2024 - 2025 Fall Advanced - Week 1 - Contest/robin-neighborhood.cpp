#include <bits/stdc++.h>


using namespace std;

#define int long long
void dfs(vector<vector<int>>& adj, int current, int parent, vector<int>& coins, vector<pair<int,int>>& take){
    take[current].first = coins[current]; 
    take[current].second = 0;

    for(auto adj_node : adj[current]){
        if(adj_node != parent){
            dfs(adj, adj_node, current, coins, take);

            take[current].first += take[adj_node].second; 
            take[current].second += max(take[adj_node].first, take[adj_node].second);
        
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    vector<vector<int>> adj(n+1);
    vector<int> coins(n+1);
    vector<pair<int,int>> take(n+1); // take, no take
    
    for(int i = 0; i < n-1; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    coins.push_back(0); // 0 indexed
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        coins[i] = x;
    }

    take[0] = {0,0};
    
    dfs(adj, 1, -1, coins, take);

    cout << max(take[1].first, take[1].second);

}

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[200001]; // 2*10^5  + 1


int dfs(int node, vector<int>& vis) {
    vis[node] = 1;
    int count = 1;

    for (int child : adj[node]) {
        if (!vis[child]) {
            count += dfs(child, vis);
        }
    }

    return count; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; 
    cin >> n;
    
    for (int i = 2; i <= n; i++) {
        int x; cin >> x;
        adj[x].push_back(i);
    }

    int k; cin >> k; 

    vector<int> vis(n + 1, 0); 

    int subtree_size = dfs(k, vis);

    cout << subtree_size << "\n";

    return 0;
}

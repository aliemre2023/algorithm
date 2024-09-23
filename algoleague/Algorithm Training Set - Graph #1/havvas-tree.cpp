//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

int total = 0;
void depthOfLeafs(int node, int depth, vector<vector<int>>& adj, vector<int>& vis){
    vis[node] = 1;
    bool isLeafNode = true;

    for(int it : adj[node]){
        if(!vis[it]){
            isLeafNode = false;
            depthOfLeafs(it, depth+1, adj, vis);
        }
    }

    if(isLeafNode){
        total += depth;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<vector<int>> adj(n+1);
    for(int i = 0 ; i< n-1; i++){
        int x,y ;cin >>  x>> y;
        adj[x].push_back(y);
        adj[y].push_back(x);  
    }

    vector<int> vis(n + 1, 0);
    depthOfLeafs(1, 0, adj, vis);
    cout << total*2;
	return 0;
}

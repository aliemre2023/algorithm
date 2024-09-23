//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    vector<vector<int>> adj(n+1);
    vector<int> degree(n+1, 0);
    
    for(int i = 0; i < n-1; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        degree[x]++;
        degree[y]++;
    }
    
    queue<int> leafNodes;
    for(int i = 1; i <= n; i++){
        if(degree[i] == 1){
            leafNodes.push(i);
        }
    }
    
    int total_nodes = n;
    int jump = 0;
    while(total_nodes > 1){
        int leafCount = leafNodes.size();
        total_nodes -= leafCount;
        jump++;
        
        for(int i = 0; i < leafCount; i++){
            int leaf = leafNodes.front();
            leafNodes.pop();
            
            for (auto it : adj[leaf]) {
                degree[it]--;
                if (degree[it] == 1) {
                    leafNodes.push(it);  
                }
            }
        }
    }
    
    
    cout << jump;
    
    
    
	return 0;
}

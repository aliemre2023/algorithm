//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

vector<int> shortestPath(int n, vector<vector<pair<int, int>>>& adj, int start, int end) {
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

    return dist ;

}

int main() {
// write your code here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    n++;
    int m; cin >> m;
    int q; cin >> q;
    
    vector<vector<pair<int, int>>> adj(n);

    for (int i = 0; i < m; i++) {
        int x, y, w; cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
    
    map<int ,vector<int>> storage;
    for(int i = 0; i < q; i++){
        int x, y; cin >> x >> y;
        if(storage.find(min(x, y)) == storage.end()){
            vector<int> newDistances = shortestPath(n, adj, min(x,y), max(x,y));
            storage[min(x,y)] = newDistances;
        }
        if(storage[min(x,y)][max(x,y)] != INT_MAX){
            cout << storage[min(x,y)][max(x,y)] << "\n";
        }
        else{
            cout << -1 << "\n";
        }
    }
	return 0;
}
